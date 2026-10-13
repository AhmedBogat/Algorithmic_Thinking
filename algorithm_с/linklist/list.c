#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct s_List {
  int id;
  char *name;
  struct s_List *next;
} t_list;

t_list *create_node(int set_id, char *set_name) {
  t_list *node = (t_list *) malloc(sizeof(node));
  node->id = set_id;
  node->name = set_name;
  node->next = NULL;
  return node;
}

void print_link(t_list *list) {
  while (list != NULL) {
    printf("id = %d ", list->id);
    list = list->next;
  }
}

void front_end(t_list **list, int set_id, char *set_name) {
  t_list *new_element = create_node(set_id, set_name);
  new_element->next = *list;
  *list = new_element;
}

void item_buck(t_list **list, int set_id, char *set_name) {
  t_list *new_element = create_node(set_id, set_name);
  t_list *tmp = list;
  while (tmp->next != NULL) {
    new_element->next = *list;
  }
}

void free_list(t_list *list) {
  t_list *list_ptr;
  while (list != NULL) {
    list_ptr->next;
    free(list);
    list = list_ptr;
  }
}

void deleteNode(t_list **list, int key) {
  t_list *tmp = *list, *prev;

  if (tmp != NULL && tmp->id == key) {
    *list = tmp->next;
    free(tmp);
    return;
  }
  while (tmp != NULL && tmp->id != key) {
    prev = tmp;
    tmp = tmp->next;
  }
  if (tmp == NULL)
    return;
  prev->next = tmp->next;
  free(tmp);
}

void sortLinkedList(t_list **head_ref) {
  t_list *current = *head_ref, *index = NULL;
  while (index != NULL) {
    if (current != NULL) {
      if (current->id > index->id) {
        int tmp = current->id;
        current->id = index->id;
        index->id = tmp;
      }
      current = current->next;
    }
  }
}

int searchNode(struct Node **head_ref, int key) {
  t_list *current = *head_ref;

  while (current != NULL) {
    if (current->id == key)
      return 1;
    current = current->next;
  }
  return 0;
}

int run() {
  t_list *list = create_node(1, "Name1");
  front_end(&list, 2, "prev");
  front_end(&list, 4, "A");

  front_end(&list, 9, "d");
//  print_link();
//  deleteNode(&list, 0);
//  print_link(list);
//  sortLinkedList(&list);
  searchNode(&list, 3);
  int item_to_find = 2;
  if (searchNode(&list, item_to_find)) {
    printf("\n%d is found", item_to_find);
  } else {
    printf("\n%d is not found", item_to_find);
  }
  print_link(list);
  return 0;
}
