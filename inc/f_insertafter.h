#include "C_Linked_list.h"
#include <iostream>

// function to insert a element at a specified position
void insertafter(node* head, int key, int val)
{
    node* n = new node(val);
    if (key == head->data) 
    {
        n->next = head->next;
        head->next = n;
        return;
    }

    node* temp = head;
    while (temp->data != key) 
    {
        temp = temp->next;
        if (temp == NULL) 
        {
            return;
        }
    }
    n->next = temp->next;
    temp->next = n;
}  
