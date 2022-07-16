#ifndef C_LINKED_LIST_H
#define C_LINKED_LIST_H

#include <iostream>
using namespace std;
  
class node 
{
    public:
        int data;
        node* next;
    
        node(int value)        // A constructor is called here
        {                     
            data = value;     // it automatic assigns the value to  the data
            next = NULL;     // next pointer is pointed to NULL
        }
};

#endif