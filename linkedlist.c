#include "linkedlist.h"

struct LL * createLinkedList() {
  struct LL *x = malloc(sizeof(struct LL));
  x->size = 0;
  x->head = 0;
  return x;
}

struct LLNode * LLCreateNode(int value) {
  struct LLNode *x = malloc(sizeof(struct LLNode));
  x->next = 0;
  x->value = value;
  return x;
}

struct LL * createLL(int A[], int n) {
  struct LL *x = malloc(sizeof(struct LL));
  x->size = n;
  x->head = LLCreateNode(A[0]);

  struct LLNode *node = x->head;
  for(int i=1;i<n; i++) {
    node->next = LLCreateNode(A[i]);
    node = node->next;
  }
  return x;
}

void LLAppend(struct LL *l, int value) {
  l->size++;
  if(!l->head) {
    l->head = LLCreateNode(value);
    return;
  }
  struct LLNode *x = l->head;
  while(x->next) {
    x = x->next;
  }
  x->next = LLCreateNode(value);
}

void LLDisplay(struct LL *l) {
  struct LLNode *x = l->head;
  while(x->next) {
    printf("%d ", x->value);
    x = x->next;
  }
  printf("%d\n", x->value);
}

int LLRemove(struct LL *l, int index) {
  if(index >= l->size) {
    return -1;
  }
  if (index == 0) {
    struct LLNode *n = l->head;
    int i = n->value;
    if(n->next)
      n = n->next;
    else
      n = 0;
    free(l->head);
    l->head = n;
    return i;
  }

  struct LLNode *n = l->head;
  for(int i=0; i<index-1; i++) {
    n = n->next;
  }
  if(!n->next->next) {
    int i = n->next->value;
    free(n->next);
    n->next = 0;
    l->size--;
    return i;
  } else {
    int i = n->next->value;
    struct LLNode *o = n->next->next;
    free(n->next);
    n->next = o;
    l->size--;
    return i;
  }
}
