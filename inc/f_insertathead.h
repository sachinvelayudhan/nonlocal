#include "C_Linked_list.h"
#include <iostream>

// function to insert a element at head position
void insertathead(node*& head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}