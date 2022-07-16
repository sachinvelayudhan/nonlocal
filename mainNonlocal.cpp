#include "./inc/C_Loadtxt.h"
#include "./inc/f_Cell_list2D.h"
#include "./inc/f_Verlet_list2D.h"
#include "./inc/C_Matrix_Sparse.h"
#include "./inc/C_Matrix_Dense.h"

int main()
{
    int NEM = 18, NPE = 3;
    double rl = 1;

    C_Matrix_Sparse nonlcl_ele(18,18);

    std::vector < double > rc;
    std::vector < double > Ld;

    rc = {1,1};
    Ld = {3,3};

    int elCon[3], Lc[2], ele_count[NEM];

    Lc[0] = Ld[0] / rc[0];
    Lc[1] = Ld[1] / rc[1];

    int lcxy = Lc[0]*Lc[1];

    int head[lcxy], lscl[NEM];

    std::vector < std::vector<double> > center; 
    std::vector < double > cen_ele;

    auto nodes = loadtxt <double> ( "nodes.txt" );
    auto elements = loadtxt <int> ( "elements.txt" );

    for (int i = 0; i < NEM; i++)
    {
        for (int j = 0; j < NPE; j++)
        {
            elCon[j] = elements[i][j] - 1;
        }
        
        cen_ele = {(nodes[elCon[0]][0]+nodes[elCon[1]][0]+nodes[elCon[2]][0])/3.0, (nodes[elCon[0]][1]+nodes[elCon[1]][1]+nodes[elCon[2]][1])/3.0};
        center.push_back(cen_ele);
    }

    Cell_list2D (NEM, center, rc, lcxy, head, lscl, Lc);
    Verlet_list2D (head, lscl, lcxy, Lc, center, Ld, rl, nonlcl_ele, ele_count, NEM);

    cout << nonlcl_ele;

    for (int j = 0; j < NEM; j++)
    {
        cout << ele_count[j] << endl;
    }
}