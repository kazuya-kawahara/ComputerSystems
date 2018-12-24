#include <stdio.h>

struct node {
  int val;
  struct node *next;
};

int add(struct node *head, int val) {
  struct node *new;
  new = malloc(sizeof(struct node));
  new->val = val;
  
  new->next = head->next;
  head->next = new;
  return 0;
}

int deleteFirst(struct node *head) {
  struct node *cur;
  int result = -1;
  if (head->next != NULL) {
    cur =head->next;
    head->next = cur->next;
    result = cur->val;
    free(cur);
  }
  return result;
}

int delete(struct node *head, int val) {
  struct node *cur, *prev;
  int result = -1;

  for (prev = head, cur = prev->next; cur !=NULL;
       prev = cur, cur = cur->next) {
    if (cur->val == val) {
      prev->next = cur->next;
      result = cur->val;
      free(cur);
      break;
    }
  }
  return result;
}

void display(struct node *head){
  struct node *cur;
  int line = 1;
  for (cur = head->next; cur != NULL ;cur=cur->next) {
    printf("%d: %d\n",line++, cur->val);
  }
}


int main() {
  struct node head = {-1, NULL};
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
