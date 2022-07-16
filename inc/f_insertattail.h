#include "C_Linked_list.h"
#include <iostream>

// function to insert a element at the end
void insertattail(node*& head, int val)
{
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
  
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}