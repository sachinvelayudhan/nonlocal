#include "./inc/C_Loadtxt.h"
#include "./inc/f_Linked_list3D.h"
#include "./inc/f_Element_list3D.h"

int main()
{
    int NEM = 132, NPE = 4;
    double rl = 1;

    std::ofstream out1("neigh_elem3D.txt");
    std::ofstream out2("neigh_count3D.txt");

    std::vector < int > nonlclele[NEM];

    std::vector < double > rc;
    std::vector < double > Ld;

    rc = {1,1,1};
    Ld = {3,3,3};

    int elCon[4], Lc[3], ele_count[NEM];

    Lc[0] = Ld[0] / rc[0];
    Lc[1] = Ld[1] / rc[1];
    Lc[2] = Ld[2] / rc[2];

    int lcxy = Lc[0]*Lc[1], lcxyz = Lc[0]*Lc[1]*Lc[2];

    int head[lcxyz], lscl[NEM];

    std::vector < std::vector<double> > center; 
    std::vector < double > cen_ele;

    auto nodes = loadtxt <double> ( "nodes3D.txt" );
    auto elements = loadtxt <int> ( "elements3D.txt" );

    for (int i = 0; i < NEM; i++)
    {
        for (int j = 0; j < NPE; j++)
        {
            elCon[j] = elements[i][j] - 1;
        }
        
        cen_ele = {(nodes[elCon[0]][0]+nodes[elCon[1]][0]+nodes[elCon[2]][0]+nodes[elCon[3]][0])/4.0, (nodes[elCon[0]][1]+nodes[elCon[1]][1]+nodes[elCon[2]][1]+nodes[elCon[3]][1])/4.0, (nodes[elCon[0]][2]+nodes[elCon[1]][2]+nodes[elCon[2]][2]+nodes[elCon[3]][2])/4.0};
        center.push_back(cen_ele);
    }

    Linked_list3D (NEM, center, rc, lcxy, lcxyz, head, lscl, Lc);
    Element_list3D (head, lscl, lcxy, Lc, center, Ld, rl, nonlclele, ele_count, NEM);

    for (int j = 0; j < NEM; j++)
    {
        out2 << ele_count[j] << endl;
        for (int i = 0; i < ele_count[j]; i++)
        {
            out1 << nonlclele[j][i] << "    ";
        }
        out1 << "\n";
    }
}