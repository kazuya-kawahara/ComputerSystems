#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *prev;
  struct node *next;
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
    head->prev = NULL;
    head->next = tail;
    tail->val = -1;
    tail->prev = head;
    tail->next = NULL;
    
    int errorcheck = 0;
    while (errorcheck != -1) {
      errorcheck = 0;
      printf("0: finish\n1: put\n2: get\n3: delete\n4: display\n");
      int operation;
      scanf("%d", &operation);
      if (operation == 0) { break; }
      else if (operation == 1) {
        printf("what number will you put?\n");
        int n;
        scanf("%d", &n);
        errorcheck = put(tail, n);
        if (errorcheck == 0) { printf("%d was put.\n", n); }
      }
      else if (operation == 2) {
        errorcheck = get(head);
      }
      else if (operation == 3) {
        printf("what number will you delete?\n");
        int n;
        scanf("%d", &n);
        if (n == delete(head, n)) { printf("%d was deleted.\n", n); }
        else { printf("%d was not found.\n", n); }
      }
      else if (operation == 4) {
        display(head);
      }
      else { errorcheck = -1; }
      printf("\n");
    }

    if (errorcheck == 0) { printf("finish!\n"); }
    else { printf("error!\n"); }

    return errorcheck;
  }
}
