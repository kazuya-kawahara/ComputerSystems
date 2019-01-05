#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
  struct node *prev;
} Queue;

int put(Queue *tail, int val) {
  Queue *new;
  new = (Queue*)malloc(sizeof(Queue));
  if (new == NULL) { return -1; }
  else {
    Queue *prev;
    prev = tail->prev;
    new->val = val;
    new->next = tail;
    new->prev = prev;
    prev->next = new;
    tail->prev = new;
    return 0;
  }
}

int get(Queue *head) {
  Queue *cur;
  cur = head->next;
  int result = cur->val;

  if (result != -1) {
    Queue *next;
    next = cur->next;
    next->prev = head;
    head->next = next;
    free(cur);
  }
  
  return result;
}

int delete(Queue *head, int val) {
  Queue *next, *cur, *prev;
  int result = -1;

  for (prev = head, cur = head->next, next = (head->next)->next;
       next != NULL;
       prev = prev->next, cur = cur->next, next = next->next) {
    if (cur->val == val) {
      result = cur->val;
      next->prev = prev;
      prev->next = next;
      free(cur);
      break;
    }
  }
  
  return result;
}

void display(Queue *head) {
  Queue *cur;
  int line = 1;

  for (cur = head->next; cur->val != -1; cur = cur->next) {
    printf("%d: %d\n", line++, cur->val);
  }
}


int main() {
  Queue *head;
  Queue *tail;
  head = (Queue*)malloc(sizeof(Queue));
  tail = (Queue*)malloc(sizeof(Queue));
  
  if (head == NULL) { return -1; }
  else if (tail == NULL) { return -1; }
  else {
    head->val = -1;
    tail->val = -1;
    head->next = tail;
    tail->next = NULL;
    head->prev = NULL;
    tail->prev = head;
    
    int i = 0;
    int k, n;
    while (i == 0) {
      printf("0: finish\n1: put\n2: get\n3: delete\n4: display\n");
      scanf("%d", &k);
      if (k == 0) { i = 1; }
      else if (k == 1) {
        printf("what number will you put?\n");
        scanf("%d", &n);
        i = put(tail, n);
      }
      else if (k == 2) {
        n = get(head);
        if (n == -1) { i = -1; }
      }
      else if (k == 3) {
        printf("what number will you delete?\n");
        scanf("%d", &n);
        if (n != delete(head, n)) { i = -1; }
      }
      else if (k == 4) {
        display(head);
      }
      else { i = -1; }
    }

    if (i == 1) { printf("finish!\n"); }
    else { printf("error!\n"); }

    return 0;
  }
}
