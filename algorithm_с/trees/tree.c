#include <stdio.h>
#include <stdlib.h>

typedef struct binaryTree_s {
  int data;
  struct binaryTree_s *left;
  struct binaryTree_s *right;
} binary_tree_s;

binary_tree_s *Creat_Tree_s(int data) {
  binary_tree_s *createbin = (binary_tree_s *) malloc(sizeof(binary_tree_s));
  if (createbin == NULL) {
    printf("Malloc returned NULL\n");
    exit(1);
  }
  createbin->data = data;
  createbin->left = NULL;
  createbin->right = NULL;
  return createbin;
}

void push(binary_tree_s **tree, int data) {
  binary_tree_s *newNode = Creat_Tree_s(data);
  binary_tree_s *tmp = *tree;
  if (tmp == NULL) {
    *tree = newNode;
  } else if (data < tmp->data) {
    if (tmp->left == NULL) {
      tmp->left = newNode;
    } else {
      push(&(tmp->left), data);
    }
  } else if (data > tmp->data) {
    if (tmp->right == NULL) {
      tmp->right = newNode;
    } else {
      push(&(tmp->right), data);
    }
  }
}

void printInDepthRecursively(binary_tree_s *tree) {
  if (tree == NULL) {
    return;
  } else {
    printf("%d", tree->data);
    if (tree->left != NULL) {
      printInDepthRecursively(tree->left);
    }
    if (tree->left != NULL) {
      printInDepthRecursively(tree->left);
    }
  }
}

void printSorted(binary_tree_s *root) {
  if (root != NULL) {
    printSorted(root->left);
    printf("%d/\n", root->data);
    printSorted(root->right);

  }
}



int binRun() {
  binary_tree_s *tree = NULL;
  push(&tree, 5);
  push(&tree, 7);
  push(&tree, 3);
  push(&tree, 4);
  push(&tree, 6);
  push(&tree, 2);
  push(&tree, 1);
  printSorted(tree);
  return 0;
}

//tree *init_tree(void) {
//    return (NULL);
//}
//
//bool empty_tree(tree *t) {
//    if (t == NULL) {
//        return (tree);
//    }
//    return (false);
//}
//
//tree *search_tree(tree *l, item_type x) {
//    if (l == NULL) {
//        return (NULL);
//    }
//    if (l->item == x) {
//        return (l);
//    }
//    if (x < l->item) {
//        return (search_tree(l->left, x);
//    } else {
//        return (search_tree(l->right, x));
//    }
//}
//
//void insert_tree(tree **l, item_type x, tree *parent) {
//    tree *p;
//
//    if (*l == NULL) {
//        p = malloc(sizeof(tree));
//        p->item = x;
//        p->left = p->right = NULL;
//        p->parent = parent;
//        *l = p;
//        return;
//    }
//    if (x < (*l)->item) {
//        insert_tree(&((*l)->left), x, l);
//    } else {
//        insert_tree(&((*l)->right), x, *l);
//    }
//}
//
//void print_tree(tree *l) {
//    if (l != NULL) {
//        print_tree(l->left);
//        printf("%d", l->item);
//        print_tree(l->right);
//    }
//}
//
//tree *successor_descendant(tree *t) {
//    tree *succ;
//    if (t->right == NULL) {
//        return NULL;
//    }
//    succ = t->right;
//    while (succ->left != NULL) {
//        succ = succ->left;
//    }
//    return (succ);
//}
//
//
//tree *find_minimum(tree *t) {
//    tree *min;
//    if(t == NULL) {
//        return (NULL);
//    }
//
//    min = t;
//    while (min->left != NULL) {
//        min = min ->left;
//    }
//    return (min);
//}
//
//tree *predecessor_descendant(tree *t) {
//    tree *pred;
//
//    if(t->left == NULL) {
//        return (NULL);
//    }
//}
