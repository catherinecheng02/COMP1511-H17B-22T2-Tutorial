// Linked list demo
// Written by Catherine Cheng z5310517
// 21-07-2022
#include <stdio.h>
#include <stdlib.h>
struct node {
  int value;
  struct node *next; // address of the next struct node  in the linked list
};

struct node *create_node(int val, struct node *n);
int main (void) {
    // Why are linked lists useful?
    // - more flexible than arrays. they are dynamic, meaning the size can be 
    //   changed. means we don't need to know what the size is at the beginning
    // - insert nodes and move them around. delete nodes.
    
    
  
    // How can we create a node?
    struct node *head = create_node(5, NULL);
    //printf("%d\n", head->value);
    
    // How do I add a node at the head
    head = create_node(4, head);
    // printf("%d\n", head->value);
    // printf("%d\n", head->next->value);
    
 
    
    // How to go through a linked list?
    struct node *curr = head;
    while(curr != NULL) {
        //printf("%d\n", curr->value);
        curr = curr->next;
    
    }
   
    // Printing the last element
    curr = head;
    while (curr->next != NULL) {
    
        curr = curr->next;
    }
    printf("%d\n", curr->value);

}

struct node *create_node(int val, struct node *n)  {
    struct node *new_node = malloc(sizeof(struct node));
    (*new_node).value = val;
    new_node->next = n;
    return new_node;
}




