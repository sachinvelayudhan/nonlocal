#include <vector>

// #include "C_Cell_list.h"
// #include "C_Linked_list.h"
// #include "f_insertafter.h"
// #include "f_insertathead.h"
// #include "f_insertattail.h"
// #include "f_printlist.h"

void Cell_list2D (int NEM, std::vector < std::vector<double> >& center, std::vector< double >& rc, int lcxy, int head[], int lscl[], int Lc[])
{
    int mc[2], c;

    // node* head = NULL;

    // cell_list lscl;
    // cell_list head;

    // node* head1 = NULL;

    for (c = 0; c < lcxy; c++)
    {
        head[c] = -1;
    }

    for (int i = 0; i < NEM; i++)
    {
        for (int a = 0; a < 2; a++)
        {
            mc[a] = center[i][a] / rc[a];
        }

        c = mc[0]*Lc[1] + mc[1];

        lscl[i] = head[c];
        head[c] = i;
    }
  
    // insertathead(head, 1);
    // insertathead(head, 2);
    // cout << "After insertion at head: ";
    // print(head);
    // cout << endl;
  
    // insertattail(head, 4);
    // insertattail(head, 5);
    // cout << "After insertion at tail: ";
    // print(head);
    // cout << endl;
  
    // insertafter(head, 1, 2);
    // insertafter(head, 5, 6);
    // cout << "After insertion at a given position: ";
    // print(head);
    // cout << endl;

    // lscl.AddNode(3);
    // lscl.AddNode(4);

    // lscl.Printlist();

}