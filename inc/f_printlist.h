#include "C_Linked_list.h"
#include <iostream>

// function to print the singly linked list
void print(node*& head)
{
    node* temp = head;

    while (temp != NULL) 
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}