#ifndef PRACTICUM__LINKED_HASHMAP_H_
#define PRACTICUM__LINKED_HASHMAP_H_

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// An element consisting of a key-value pair.
typedef struct element {
  int key;
  float value;
} element_t;

// Each node holds a key and a value, next & prev pointer to traverse on the same index, after &
// before to traverse on the linked list bucket
typedef struct node {
  element_t *element;
  struct node *next; // next node on the same bucket
  struct node *prev;  // prev node on the same bucket
  struct node *after; // the next index on bucket
  struct node *before; // the prev index on bucket
} node_t;

// double linked list
typedef struct dList {
  node_t *head;
  node_t *tail;
} dlist_t;

// linked hashmap
typedef struct dLinkedHashmap {
  dlist_t *bucket; // bucket is implemented by double linkedlist
  node_t *header; // newest node pointer
  node_t *oldest; // least used node pointer, store this for hash eviction

  int hashSize; // when to evict oldest value
  int capacity; // max capacity
  float loadFactor; // percentage to rehash
  int size; // dynamic storage
} dLinkedHashmap_t;

// Creates a new hashmap
dLinkedHashmap_t *create(int capacity, float loadFactor) {
  pthread_mutex_lock(&mutex);

  dLinkedHashmap_t *dLinkedHashmap = (dLinkedHashmap_t *) malloc(sizeof(dLinkedHashmap_t));
  dLinkedHashmap->capacity = capacity;
  dLinkedHashmap->hashSize = capacity * loadFactor;
  dLinkedHashmap->loadFactor = loadFactor;
  dLinkedHashmap->bucket = (dlist_t *) malloc(sizeof(dlist_t) * dLinkedHashmap->
      hashSize);
  dLinkedHashmap->header = NULL;
  dLinkedHashmap->oldest = NULL;
  dLinkedHashmap->size = 0;

  for (int i = 0; i < dLinkedHashmap->hashSize;
       i++) {
    dLinkedHashmap->bucket[i].head = NULL;
    dLinkedHashmap->bucket[i].tail = NULL;
  }
  pthread_mutex_unlock(&mutex);

  return dLinkedHashmap;
}

// hash func
int hash(int key, int hashSize) {
  int hashValue = key * (key + 2); // any better hash func?
  return hashValue % hashSize;
}

// remove from bucket O(1)
void bucketRemove(dlist_t *bucket, node_t *cur) {
  if (cur == bucket->tail && cur == bucket->head) {
    bucket->head = NULL;
    bucket->tail = NULL;
  } else if (cur == bucket->tail) {
    bucket->tail = cur->before;
    bucket->tail->after = NULL;
  } else if (cur == bucket->head) {
    bucket->head = cur->after;
    bucket->head->before = NULL;
  } else {
    cur->before->after = cur->after;
    cur->after->before = cur->before;
  }
}

// remove from hashmap O(1)
void hashRemove(dLinkedHashmap_t *linked_hashmap, node_t *cur) {
  if ((cur == linked_hashmap->header) && (cur == linked_hashmap->oldest)) {
    linked_hashmap->header = NULL;
    linked_hashmap->oldest = NULL;
  } else if (cur == linked_hashmap->oldest) {
    linked_hashmap->oldest = linked_hashmap->oldest->next;
    linked_hashmap->oldest->prev = NULL;
  } else if (cur == linked_hashmap->header) {
    linked_hashmap->header = linked_hashmap->header->prev;
    linked_hashmap->header->next = NULL;
  } else {
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
  }
}

// create a node O(1)
node_t *createNode(int key, float value) {
  pthread_mutex_lock(&mutex);

  node_t *node = (node_t *) malloc(sizeof(node_t));
  node->prev = NULL;
  node->next = NULL;
  node->after = NULL;
  node->before = NULL;

  node->element = (element_t *) malloc(sizeof(element_t));
  node->element->key = key;
  node->element->value = value;

  pthread_mutex_unlock(&mutex);

  return node;
}

// return bucket head with given key O(n), n is the number of dll within bucket
node_t *getNode(dlist_t *bucket, int key) {
  if (bucket->head == NULL) {
    return NULL;
  }

  node_t *cur = bucket->head;
  while (cur->element->key != key) {
    cur = cur->after;

    if (cur == NULL) {
      return NULL;
    }
  }
  return cur;
}

// update bucket with new node when keeping insertion order, O(1)
void updateBucketNode(dLinkedHashmap_t *linked_hashmap, dlist_t *bucket, node_t *cur) {
  if (bucket->head == NULL) {
    bucket->head = cur;
    bucket->tail = cur;
    linked_hashmap->size++;
  } else {
    cur->before = bucket->tail;
    bucket->tail->after = cur;
    bucket->tail = cur;
    linked_hashmap->size++;
  }
}

// update bucket with new node for ascend order, O(n) n is the number of dll within bucket
void updateBucketNodeAsc(dLinkedHashmap_t *linked_hashmap, dlist_t *bucket, node_t *cur) {
  if (bucket->head == NULL) { // no dlist in bucket
    bucket->head = cur;
    bucket->tail = cur;
    linked_hashmap->size++;
  } else if (bucket->head->element->key == bucket->tail->element->key) { // only one dlist in bucket
    bucket->head->after = cur;
    cur->before = bucket->head;
    cur->after = bucket->tail;
    bucket->tail->before = cur;
    linked_hashmap->size++;
  } else if (cur->element->key < bucket->head->element->key) { // cur.key< head.key, push
    bucket->head->before = cur;
    cur->after = bucket->head;
    bucket->head = cur;
    linked_hashmap->size++;
  } else if (cur->element->key > bucket->tail->element->key) { // cur.key>tail.key, append
    bucket->tail->after = cur;
    cur->before = bucket->tail;
    bucket->tail = cur;
    linked_hashmap->size++;
  } else {
    // cur.key > head.after.key and at least two dlist within buckets,keep traverse till find
    // right position(cur.key < head.after.key).
    node_t *after = bucket->head->after;
    while (cur->element->key > after->element->key) {
      after = after->after;
    }
    after->before->after = cur;
    cur->before = after->before;
    cur->after = after;
    after->before = cur; // ?
    linked_hashmap->size++;
  }
}

// update header to track the newest added / modified node, O(1)
void updateHeader(dLinkedHashmap_t *linked_hashmap, node_t *cur) {
  if (linked_hashmap->oldest == NULL) {
    linked_hashmap->header = cur;
    linked_hashmap->oldest = cur;
  } else {
    node_t *pastHeader = linked_hashmap->header;
    pastHeader->next = cur;
    cur->prev = pastHeader;
    linked_hashmap->header = cur;
  }
}

// remove a bucket with given key, O(n)
void removeKey(dLinkedHashmap_t *linked_hashmap, int key) {
  pthread_mutex_lock(&mutex);

  int index = hash(key, linked_hashmap->hashSize);
  dlist_t *bucket = &linked_hashmap->bucket[index];

  node_t *cur = getNode(bucket, key);

  if (cur == NULL) {
    perror("given key is not existing");
    pthread_mutex_unlock(&mutex);
    return;
  }

  bucketRemove(bucket, cur);
  hashRemove(linked_hashmap, cur);
  free(cur);
  cur = NULL;
  pthread_mutex_unlock(&mutex);
}

// add a node with given key and value; if no key exist before, create a new bucket index; if
// duplicate key, overwrite with new value; if reach hashSize, evict oldest key bucket. O(1)
void put(dLinkedHashmap_t *linked_hashmap, int key, float value) { // insert & update
//  pthread_mutex_lock(&mutex);

  int index = hash(key, linked_hashmap->hashSize);
  dlist_t *bucket = &linked_hashmap->bucket[index];

  if (bucket->head != NULL) {
    if (key == bucket->tail->element->key) { // handle collision, overwrite value
      bucket->tail->element->value = value;
//      pthread_mutex_unlock(&mutex);
      return;
    }
  }

  node_t *cur = createNode(key, value);

  updateBucketNode(linked_hashmap, bucket, cur);
  updateHeader(linked_hashmap, cur);

  if (linked_hashmap->size > linked_hashmap->capacity) { // eviction oldest hash cache
    removeKey(linked_hashmap, linked_hashmap->oldest->element->key);
  }
//  pthread_mutex_unlock(&mutex);

}

// add a node with given key and value for ascend order; if no key exist before, create a new
// bucket index; if duplicate key, overwrite with new value; if reach hashSize, evict oldest key
// bucket. O(1)
void putAseOrder(dLinkedHashmap_t *linked_hashmap, int key, float value) { // insert & update
//  pthread_mutex_lock(&mutex);

  int index = hash(key, linked_hashmap->hashSize);
  dlist_t *bucket = &linked_hashmap->bucket[index];

  if (linked_hashmap->header != NULL) { // &&(bucket->tail!=NULL)
    if (key == linked_hashmap->header->element->key) { // handle collision, overwrite value
      linked_hashmap->header->element->value = value;
//      pthread_mutex_unlock(&mutex);

      return;
    }
  }

  node_t *cur = createNode(key, value);

  updateBucketNodeAsc(linked_hashmap, bucket, cur);
  updateHeader(linked_hashmap, cur);

  if (linked_hashmap->size > linked_hashmap->capacity) { // eviction oldest hash cache
    removeKey(linked_hashmap, linked_hashmap->oldest->element->key);
  }
//  pthread_mutex_unlock(&mutex);

}

// return the value with given key, O(1)
float getValue(dLinkedHashmap_t *dLinkedHashmap, int key) {
  int index = hash(key, dLinkedHashmap->hashSize);
  dlist_t *bucket = &dLinkedHashmap->bucket[index];
  node_t *cur = getNode(bucket, key);

  if (cur == NULL) {
    return -1;
  }
  return cur->element->value;
}

// Returns a boolean value if a key has been put into the hashmap, O(1)
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Returns a '-9999' for invalid hashmaps
int hashmap_hasKey(dLinkedHashmap_t *linked_hashmap, int key) {
  if (linked_hashmap == NULL) {
    return -9999;
  }

  int index = hash(key, linked_hashmap->hashSize);
  dlist_t *bucket = &linked_hashmap->bucket[index];
  node_t *cur = getNode(bucket, key);

  if (cur == NULL) {
    return 0;
  }
  return 1;
}

// Return the first key-value pair in the ordering, O(1)
//  - Returns NULL if there is no pair
element_t *hashmap_getFirst(dLinkedHashmap_t *linked_hashmap) {
  return linked_hashmap->oldest->element;
}

// Return the last key-value pair in the ordering, O(1)
//  - Returns NULL if there is no pair
element_t *hashmap_getLast(dLinkedHashmap_t *linked_hashmap) {
  return linked_hashmap->header->element;
}

// Frees a hashmap, O(n) n is the number of node
void freeHashmap(dLinkedHashmap_t *linked_hashmap) {
  pthread_mutex_lock(&mutex);

  if (linked_hashmap->header == NULL) {
    return;
  }

  node_t *head = linked_hashmap->bucket->head;

  node_t *cur = head;
  node_t *next, *after;

  while (cur != NULL) {
    after = cur->after;
    while (cur) {
      next = cur->next;
      free(cur);
      cur = next;
    }
    if (after == NULL) {
      return;
    }
    if (after->after != NULL) {
      cur = after->after;
    }
    while (after != NULL) {
      next = after->next;
      free(after);
      after = next;
    }
  }
  free(linked_hashmap->bucket);
  free(linked_hashmap->header);
  free(linked_hashmap->oldest);
  linked_hashmap->size = 0;
  free(linked_hashmap);
  pthread_mutex_unlock(&mutex);
}

// Prints all of the keys and corresponding values of hashmap in order, O(n) n is the number of
// nodes
void printHashmap(dLinkedHashmap_t *linked_hashmap) {
  if (linked_hashmap->bucket->head == NULL) {
    return;
  }

  node_t *bucketHead = linked_hashmap->bucket->head;

  node_t *cur = bucketHead;
  node_t *next, *after;
  printf("keys and values in order: \n");
  while (cur != NULL) {
    after = cur->after;
    while (cur) {
      next = cur->next;
      printf("key: %d, value: %f \n", cur->element->key, cur->element->value);
      cur = next;
    }
    if (after == NULL) {
      return;
    }
    if (after->after != NULL) {
      cur = after->after;
    }
    while (after != NULL) {
      next = after->next;
      printf("key: %d, value: %f \n", after->element->key, after->element->value);
      after = next;
    }
  }
}

// Prints all of the keys and corresponding values of hashmap in insert order, O(n) n is the
// number of nodes
void hashmap_printKeys(dLinkedHashmap_t *linked_hashmap) {
  if (linked_hashmap->header == NULL) {
    return;
  }

  node_t *bucketHead = linked_hashmap->bucket->head;

  node_t *cur = bucketHead, *next;
  node_t *after = cur->after;
//  node_t *afterAfter = after->after;
  printf("keys and values in order: \n");
  if (cur->after == NULL) { // only one bucket
    while (cur) {
      next = cur->next;
      printf("key: %d, value: %f \n", cur->element->key, cur->element->value);
      cur = next;
    }
  } else if (cur->after->after == NULL) { // only two linked list within bucket
    while (cur) {
      next = cur->next;
      printf("key: %d, value: %f \n", cur->element->key, cur->element->value);
      cur = next;
    }
    while (after) {
      next = after->next;
      printf("key: %d, value: %f \n", after->element->key, after->element->value);
      after = next;
    }
  } else if (cur->after->after != NULL) { // more than two linked list within buckets
    while (cur != NULL) {
      after = cur->after;
      while (cur) {
        next = cur->next;
        printf("key: %d, value: %f \n", cur->element->key, cur->element->value);
        cur = next;
      }
      cur = after->after;
      while (after->element != NULL) {
        next = after->next;
        printf("key: %d, value: %f \n", after->element->key, after->element->value);
        after = next;
      }
    }
  }
}

#endif //PRACTICUM__LINKED_HASHMAP_H_
