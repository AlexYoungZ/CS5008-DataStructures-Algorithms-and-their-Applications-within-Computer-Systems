typedef struct vector {
  int *data;
  int size;
  int capacity;
} vector_t;

vector_t *createVector(int initCapacity);

void freeVector(vector_t *vector);

/* search the vector and return the index
 * complexity: O(n)
 * */
int search(vector_t *vector, int val);

/* return the item at position pos in the List
 * (error if pos is less than 0 or greater than or equal to size()) */
int get(vector_t *vector, int pos);

/* resize the vector into double capacity
 * complexity: O(n)
 * */
int resize(vector_t *vector);

/* append at end of the vector
 * worse complexity: O(n) have to resize and copy
 * average complexity: O(1)
 * */
int append(vector_t *vector, int element);

void print(vector_t *vector);

/* insert(add) an element with given position
 * complexity: O(n)
 * */
int insert(vector_t *vector, int pos, int element);

/* remove and return the item at position pos in the List,
 * moving the items originally in positions pos+1 through size()-1
 * one place to the left to fill in the gap
 * (error if pos is less than 0 or greater than or equal to size()) */
int removeByPos(vector_t *vector, int pos);

/* return true iff the List is empty */
bool isEmpty(vector_t *vector);

/* insert at front of the vector
 * complexity: O(n)
 * */
int push(vector_t *vector, int element);

/* return true iff item is in the List
 * (i.e., there is an item x in the List such that x equals(item)) */
bool contains(vector_t *vector, int val);