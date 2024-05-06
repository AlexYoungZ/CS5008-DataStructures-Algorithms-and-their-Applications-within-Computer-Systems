typedef struct node {
  int val;
  struct node *next;
  struct node *prev;
} node_t;

typedef struct dlist {
  node_t *head;
  node_t *tail;
  int size;
} dlist_t;

/* insert at front of the list
 * complexity: O(1)
 * */
void push(dlist_t *dlist, int new_val);

/* append at end of the list
 * complexity: O(1)
 * */
void append(dlist_t *dlist, int new_val);

/* insert a new node after the given node
 * complexity: O(n)
 * */
void insertAfter(dlist_t *dlist, node_t *prev, int new_val);

/* add item at position pos in the List,
 * moving the items originally in positions pos through size()-1
 * one place to the right to make room
 * (error if pos is less than 0 or greater than size())
 * */
void add(dlist_t *dlist, int pos, int new_val);

/* delete the first node and return the value, given the head pointer
 * complexity: O(1)
 * */
int deleteFront(dlist_t *dlist);

/* remove a node with given index n and return node val
 * complexity: O(1)
 * */
int removeByIndex(dlist_t *dlist, int n);

/* search the list and return the index of node with given val
 * complexity: O(n)
 * */
int search(dlist_t *dlist, int val);

/* return the item at position pos in the List
 * (error if pos is less than 0 or greater than or equal to size()) */
int get(dlist_t *dlist, int pos);

/* print the val of a linked list from the given list  */
void printList(dlist_t *dlist);

/* return true iff item is in the List
 * (i.e., there is an item x in the List such that x equals(item)) */
bool contains(dlist_t *dlist, int item);

/* return the number of items in the List */
int size(dlist_t *dlist);

/* return true iff the List is empty */
bool isEmpty(dlist_t *dlist);

/* delete the whole linked list  */
void free_list(dlist_t *dlist);



