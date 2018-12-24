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
  if(new==NULL){ return -1; }
  else{
  new->val = val;
  new->next = tail;
  new->prev = tail->prev;
  tail->prev = new;
  return 0;
  }
}

int get(Queue *head) {
  Queue *cur;
  cur = head->next;
  int result = cur->val;

  if (result != -1) {
    head->next = cur->next;
  }
  
  return result;
}

int delete(Queue *head, int val) {
  Queue *cur, *prev;
  int result = -1;

  for (cur = head->next, prev = head; cur->val != -1;
       cur = cur->next, prev = prev->next) {
    if (cur->val == val) {
      prev->next = cur->next;
      result = cur->val;
      free(cur);
      break;
    }
  }
  
  return result;
}

void display(Queue *head){
  Queue *cur;
  int line = 1;

  for (cur = head->next; cur->val != -1 ;cur=cur->next, line++) {
    printf("%d: %d\n", line, cur->val);
  }
}


int main() {
  Queue *head;
  Queue *tail;
  head = (Queue*)malloc(sizeof(Queue));
  tail = (Queue*)malloc(sizeof(Queue));
  
  head->val = -1;
  tail->val = -1;
  head->next = tail;
  tail->next = NULL;
  head->prev = NULL;
  tail->prev = head;

  int nums[] = {9,8,7,6,5,4,3,2,1,0};
  int res;
  for (int i = 0; i < 10; i++){
    res = put(tail, nums[i]);
  }
  get(head);
  delete(head, 9);
  delete(head, 5);
  delete(head, 10);
  display(head);
  return res;
}
