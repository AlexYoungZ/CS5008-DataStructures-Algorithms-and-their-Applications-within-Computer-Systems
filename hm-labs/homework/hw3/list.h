
typedef struct node {
  int val;
  struct node *next;
} node_t;

typedef struct slist {
  node_t *head;
  node_t *tail;
  int size;
} slist_t;

void push(slist_t *slist, int new_val);

/* add item to the end of the List */
void append(slist_t *slist, int new_val);

/* add item at position pos in the List,
 * moving the items originally in positions pos through size()-1
 * one place to the right to make room
 * (error if pos is less than 0 or greater than size())
 * */
void add(slist_t *slist, int pos, int new_val);

/* delete the first node and return the value, given the head pointer
 * complexity: O(1)
 * */
int deleteFront(slist_t *slist);

/* delete a node with given value
 * complexity: O(n)
 * */
int delete_by_value(slist_t *slist, int val);

/* search the list and return the index of node with given data
 * complexity: O(n)
 * */
int search(slist_t *slist, int val);

/* return the item at position pos in the List
 * (error if pos is less than 0 or greater than or equal to size()) */
int get(slist_t *slist, int pos);

/* return true iff item is in the List
 * (i.e., there is an item x in the List such that x equals(item)) */
bool contains(slist_t *slist, int item);

/* return the number of items in the List */
int size(slist_t *slist);

/* return true iff the List is empty */
bool isEmpty(slist_t *slist);

/* remove and return the item at position pos in the List,
 * moving the items originally in positions pos+1 through size()-1
 * one place to the left to fill in the gap
 * (error if pos is less than 0 or greater than or equal to size()) */
int removeByIndex(slist_t *slist, int pos);

/* print the val of a linked list from the given node  */
void print_list(slist_t *slist);

/* delete the whole linked list  */
void free_list(slist_t *slist);
