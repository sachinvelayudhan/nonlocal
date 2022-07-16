#ifndef C_CELL_LIST_H
#define C_CELL_LIST_H

#include <iostream>
#include <cstdlib>

class cell_list
{
    private:
        typedef struct node
        {
            int data;
            node* next;
        }* nodePtr;

        nodePtr head;
        nodePtr curr;
        nodePtr temp;

    public:
        cell_list()
        {
            head = NULL;
            curr = NULL;
            temp = NULL;
        }

        void AddNode (int addData)
        {
            nodePtr n = new node;
            n->next = NULL;
            n->data = addData;

            if (head != NULL)
            {
                curr = head;
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = n;
            }
            else
            {
                head = n;
            }
        }

        void Printlist()
        {
            curr = head;
            while(curr != NULL)
            {
                std::cout << curr->data << "\n";
                curr = curr->next;
            }
        }
}; 



#endif