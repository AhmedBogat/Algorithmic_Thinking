#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum {
  _INIT_ELEM,
  _DECIMAL_ELEM,
  _REAL_ELEM,
  _STRING_ELEM,
} vtype_list_t;

typedef union {
  int64_t decimal;
  double real;
  uint8_t *string;
} value_list_t;

typedef struct List {
  vtype_list_t type;
  value_list_t value;
  struct List *next;
} List;

extern List *new_list(uint8_t *format, ...);

extern void free_list(List *list);

extern List *push_list(List *list, uint8_t *format, ...);

extern List *pop_list(List *list);

extern void print_list(List *list);

int list_demo() {
  List *list = new_list("dir", 55, 1.23, "hello_word");
  List *temp = push_list(list, "d", 571);

  temp = push_list(temp, "d", 1);
  temp = push_list(temp, "d", 2);
  temp = push_list(temp, "d", 3);

  print_list(list);
  free_list(list);
  return 123;
}

extern List *new_list(uint8_t *format, ...) {
  List *list = (List *) malloc(sizeof(List));
  List *list_ptr = list;
  list->type = _INIT_ELEM;
  list->next = NULL;
  value_list_t value;
  va_list factor;
  va_start(factor, format);
  while (*format) {
    switch (*format) {
    case 'd':
    case 'i': // decimal
      value.decimal = va_arg(factor, int64_t);
      list_ptr = push_list(list_ptr, "d", value.decimal);
      break;
    case 'r':
    case 'f': // real
      value.real = va_arg(factor,
                          double);
      list_ptr = push_list(list_ptr, "r", value.real);
      break;
    case 's': // string
      value.string = va_arg(factor, uint8_t *);
      list_ptr = push_list(list_ptr, "s", value.string);
      break;
    }
    ++format;
  }
  va_end(factor);
  return list;
}

extern void free_list(List *list) {
  List *list_ptr;
  while (list != NULL) {
    list_ptr = list->next;
    free(list);
    list = list_ptr;
  }
}

extern List *push_list(List *list, uint8_t *format, ...) {
  if (list == NULL) {
    fprintf(stderr, "%s\n", "list is null");
  }
  List *push = new_list(list->next);
}