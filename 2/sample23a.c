#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} Node;

int add(Node *head, int val) {
  Node *new;
  new = malloc(sizeof(Node));
  new->val = val;
  
  new->next = head->next;
  head->next = new;
  return 0;
}

int deleteFirst(Node *head) {
  Node *cur;
  int result = -1;
  if (head->next != NULL) {
    cur =head->next;
    head->next = cur->next;
    result = cur->val;
    free(cur);
  }
  return result;
}

int delete(Node *head, int val) {
  Node *cur, *prev;
  int result = -1;

  for (cur = head->next, prev = head; cur !=NULL;
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

void display(Node *head){
  Node *cur;
  int line = 1;
  for (cur = head->next; cur != NULL ;cur=cur->next) {
    printf("%d: %d\n",line++, cur->val);
  }
}


int main() {
  Node head = {-1, NULL};
  int nums[] = {9,8,7,6,5,4,3,2,1,0};
  int i;
  for (i = 0; i < 10; i++){
    int res = add(&head, nums[i]);
    if (res != 0) return 1;
  }
  deleteFirst(&head);
  delete(&head, 9);
  delete(&head, 5);
  delete(&head, 10);
  display(&head);
  return 0;
}
