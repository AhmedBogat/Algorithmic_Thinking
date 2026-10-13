#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "../sort/item.h"
#include "tree.h"

tree *parent;

void process_item(item_type x);
tree *predecessor_descendant(tree *PTree);
tree *init_tree(void) {
  return (NULL);
}

bool empty_tre(tree *t) {
  if (t == NULL) {
    return (true);
  }
  return (false);
}

tree *search_tree(tree *l, item_type x) {
  if (l == NULL) {
    return (NULL);
  }
  if (l->item == x) {
    return (l);
  }
  if (x < l->item) {
    return (search_tree(l->left, x));
  } else {
    return (search_tree(l->right, x));
  }
}

void insert_tree(tree **l, item_type x, tree *pointer) {
  tree *p;
  if (*l == NULL) {
    p = malloc(sizeof(tree));
    p->item = x;
    p->left = p->right = NULL;
    p->parent = parent;
    *l = p;
    return;
  }
}

void print_tree(tree *l) {
  if (l != NULL) {
    print_tree(l->left);
    printf("%d", l->item);
    print_tree(l->right);

  }
}

tree *successor_descendant(tree *t) {
  tree *succ;
  if (t->right == NULL) {
    return (NULL);
  }
  succ = t->left;
  while (succ->left != NULL) {
    succ = succ->left;
  }
  return (succ);
}

tree *find_minimum(tree *t) {
  struct tree *min;

  if (t == NULL) {
    return (NULL);
  }
  min = t;
  while (min->left != NULL) {
    min = min->left;
  }
  return (min);
}

tree *predecessor_descendant(tree *t) {
  tree *pred;
  if (t->left == NULL) {
    return (NULL);
  }
  pred = t->left;
  while (pred->right != NULL) {
    pred = pred->right;
  }
  return (pred);
}

tree *delete_tree(tree *t, item_type x) {
  tree *d;             /* node with key to delete */
  tree *p;             /* node to be physically deleted */
  item_type new_key;   /* key to overwrite deleted key */
  tree *child;         /* d's only child, if any */

  d = search_tree(t, x);

  if (d == NULL) {
    printf("Warning: key to be deleted %d is not in tree.\n", x);
    return (t);
  }

  if (d->parent == NULL) {    /* if d is the root */
    if ((d->left == NULL) && (d->right == NULL)) {
      free(d);
      return NULL;    /* root-only tree */
    }

    if (d->left != NULL) {    /* find node to physically delete */
      p = predecessor_descendant(d);
    } else {
      p = successor_descendant(d);
    }
  } else {
    if ((d->left == NULL) || (d->right == NULL)) {
      /* d has <=1 child, so try to find non-null child */
      if (d->left != NULL) {
        child = d->left;
      } else {
        child = d->right;
      }

      if ((d->parent)->left == d) {    /* fill null pointer */
        d->parent->left = child;
      } else {
        d->parent->right = child;
      }
      if (child != NULL) {
        child->parent = d->parent;
      }
      free(d);
      return (t);
    } else {
      p = successor_descendant(d);    /* p has 2 children */
    }
  }

  new_key = p->item;    /* deal with simpler case of deletion */
  delete_tree(t, p->item);
  d->item = new_key;
  return (t);
}
void process_item(item_type x) {
  printf("%d", x);
}
void traverse_tree(tree *l) {
  if (l != NULL) {
    traverse_tree(l->left);
    process_item(l->item);
    traverse_tree(l->right);
  }
}

void Bin_tree(void) {
  char c;
  item_type d;
  tree *l;
  tree *tmp;
  l = init_tree();

  while (scanf("%c", &c) != EOF) {
    if (tolower(c) == 'p') {
      print_tree(l);
      printf("\n");
    }
    if (tolower(c) == 'i') {
      scanf("%d", &d);
      printf("new item: %d\n", d);
      insert_tree(&l, d, NULL);
    }
    if (tolower(c) == 's') {
      scanf("%d", &d);
      tmp = search_tree(l, d);
      if (tmp == NULL) {
        printf("item %d not found\n", d);
      } else {
        printf("item %d found\n", d);
      }
    }
    if (tolower(c) == 'd') {
      scanf("%d", &d);
      printf(" deleting item %d\n", d);
      l = delete_tree(l, d);
      print_tree(l);
      printf("\n");
    }
  }
};