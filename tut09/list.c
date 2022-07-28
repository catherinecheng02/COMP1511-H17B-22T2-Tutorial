// Program to do various linked list exercises
// Written by Catherine Cheng on 28-07-2022

#include <stdio.h>
#include <stdlib.h>
#define NOT_IDENTICAL 0
#define IDENTICAL 1

#include "list.h"

int main(void) { 


    struct node *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    print_list(head);
    
    struct node *head2 = create_node(4);
    head2->next = create_node(5);
    head2->next->next = create_node(6);
    print_list(head2);
    
    struct node *copy_head = copy(head);
    print_list(copy_head);
    print_list(list_append(head, head2));
  return 0; }

/** PRESCRIBED FUNCTIONS **/

struct node *add_last(struct node *head, int data) {
  struct node *new = malloc(sizeof(struct node));
  new->data = data;
  new->next = NULL;

  // Return new if linked list is initially empty
  if (head == NULL) {
    return new;
  }

  // Otherwise, loop to end of list and add node.
  struct node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new;

  // We are inserting at the end --> head will not change
  return head;
}

void print_list(struct node *head) {
  struct node *curr = head;
  while (curr != NULL) {
    printf("%d -> ", curr->data);
    curr = curr->next;
  }
  printf("X\n");
}

struct node *copy(struct node *list) {
  // struct node *thing = list; ?
  struct node *old_curr = list;
  struct node *new_head = create_node(old_curr->data);
  struct node *new_prev = new_head;
  old_curr = old_curr->next;
  while (old_curr != NULL) {
    struct node *new_curr = create_node(old_curr->data);
    new_prev->next = new_curr;
    new_prev = new_prev->next;
    old_curr = old_curr->next;
  }
  return new_head;
}

struct node *list_append(struct node *first_list, struct node *second_list) {
  //ok cool
  struct node *curr = first_list;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = second_list;
  return first_list;
}

int identical(struct node *first_list, struct node *second_list) {
  
  
 // no need to malloc cos not making new node 
    
    struct node *curr1 = first_list;
    struct node *curr2 = second_list;
    // check we are not at the end of either list
    while(curr1 != NULL && curr2 != NULL) {
        // if data values at position dont match, we return early
        if (curr1->data != curr2->data) {
            return NOT_IDENTICAL;
        }
        
        // iterate at the same time
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    // check that lists are same length
    if (curr1 != NULL || curr2 != NULL) {
        return NOT_IDENTICAL;
    }
    
    
    
    return IDENTICAL;
}

struct node *set_intersection(struct node *first_list,
                              struct node *second_list) {
  struct node *head = NULL;

    // Loop through both lists at the same time.
    // We're not going to be at exactly the same place
    // in both lists, we might move asymetrically
    // based on which numbers are higher in which list.
    struct node *first_curr = first_list;
    struct node *second_curr = second_list;
    // We don't need to check if either is NULL because that means there are extra
    // hanging elements which aren't a part of either.
    while (first_curr != NULL && second_curr != NULL) {
        if (first_curr->data < second_curr->data) {
            // Since the data from the first list is less than the data from
            // the second list, we need to move it along
            first_curr = first_curr->next;
        } else if (second_curr->data < first_curr->data) {
            // Since the data from the second list is less than the data from
            // the first list, we need to move it along
            second_curr = second_curr->next;
        } else {
            // The last case is if both first_curr and second_curr hold the same
            // data which is when we add it and then increment them both
            head = add_last(head, first_curr->data);
            first_curr = first_curr->next;
            second_curr = second_curr->next;
        }
    }

    return head;
}

struct node *create_node(int data) {

  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}
