#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int wins;
  int year;
  struct node *next;
} node_t;

void create_list(node_t *head, int wins, int year) {
  node_t *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = (node_t *) malloc(sizeof(node_t));
  current->next->wins = wins;
  current->next->year = year;
//  return current;
}

void print_list(node_t *head) {
  node_t *current = head;
  //  2018, 108 wins
  while (current != NULL) {
    printf("%d, %d wins\n", current->year, current->wins);
    current = current->next;
  }
}

void free_list(node_t *head) {
  node_t *current = head, *next = head;

  while (current) {
    next = current->next;
    free(current);
    current = next;
  }
}

//2018, 108 wins
//2017, 93 wins
//2016, 93 wins
//2015, 78 wins
//2014, 71 wins
int main() {

  node_t *red_sox = (node_t *) malloc(sizeof(node_t));
  create_list(red_sox, 108, 2018);
  create_list(red_sox->next, 93, 2017);
  create_list(red_sox->next->next, 93, 2016);
  create_list(red_sox->next->next->next, 78, 2015);
  create_list(red_sox->next->next->next->next, 71, 2014);

  print_list(red_sox->next);

  free_list(red_sox);

}
