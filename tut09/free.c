// Demo of free
// Written by Catherine Cheng (z5310517) on 28-07-2022

#include <stdio.h>
#include <stdlib.h>
struct node *create_node(int data, struct node *n);

struct node {
    int data;
    struct node *next;
};

int main(void) {
    
    struct node *new = create_node(4, NULL);
    printf("%d\n", new->data);
    free(new); // free takes in address as input
    
    //printf("%d\n", new->data); // use after free error
    
    // how to free a linked list?
    struct node *head = create_node(7, NULL);
    head = create_node(6, head);
    head = create_node(5, head);
    head = create_node(4, head);
    head = create_node(3, head);
    head = create_node(2, head);
    head = create_node(1, head);
    
    // free(head);
    struct node *curr = head;
    while (curr != NULL) {
        struct node *temp = curr;
        curr = curr->next;
        free(temp);
       
    }
   
    return 0;
    
}

struct node *create_node(int data, struct node *n) {
    
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = n;
 
    
    return new_node;

}
