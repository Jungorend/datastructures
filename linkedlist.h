#include <stdio.h>
#include <stdlib.h>

struct LLNode {
  int value;
  struct LLNode *next;
};

struct LL {
  int size;
  struct LLNode *head;
};

struct LL* createLinkedList();
struct LL* createLL(int A[], int n);
struct LLNode *LLCreateNode(int value);
void LLAppend(struct LL *l, int value);
void LLDisplay(struct LL *l);
int LLRemove(struct LL *l, int index);
