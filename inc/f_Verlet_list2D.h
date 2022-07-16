// #include "f_Cell_list2D.h"
#include "C_Matrix_Sparse.h"
#include "C_Matrix_Dense.h"

void Verlet_list2D (int head[], int lscl[], int lcxy, int Lc[], std::vector < std::vector<double> >& center, std::vector<double>& Ld, double rl, C_Matrix_Sparse& nonlcl_ele, int ele_count[], int NEM)
{
    int mc[2], c, mc1[2], c1, i, j;
    double r;
    
    for (int m = 0; m < NEM; m++)
    {
        ele_count[m] = 0;
    }

    for (mc[0] = 0; mc[0] < Lc[0]; (mc[0])++)
    {
        for (mc[1] = 0; mc[1] < Lc[1]; (mc[1])++)
        {
            c = mc[0]*Lc[1] + mc[1];

            for (mc1[0] = mc[0]-1; mc1[0] <= mc[0]+1; (mc1[0])++)
            {
                for (mc1[1] = mc[1]-1; mc1[1] <= mc[1]+1; (mc1[1])++)
                {
                    c1 = ((mc1[0] + Lc[0])%Lc[0])*Lc[1] + (mc1[1] + Lc[1])%Lc[1];

                    i = head[c];
                    
                    while (i != -1)
                    {
                        j = head[c1];
                        while (j != -1)
                        {
                            r = ((center[i][0] - center[j][0])*(center[i][0] - center[j][0])) + ((center[i][1] - center[j][1])*(center[i][1] - center[j][1]));
                            if (r < (rl*rl))
                            {
                                nonlcl_ele (i,j) = j+1;
                                ele_count[i] = ele_count[i] + 1;
                            }
                            j = lscl[j]; 
                        }
                        i = lscl[i]; 
                    }
                }
            }
        }
    }
}