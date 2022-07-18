#include <fstream>
#include <sstream>

void Verlet_list2D (int head[], int lscl[], int Lc[], std::vector < std::vector<double> >& center, std::vector<double>& Ld, double rl, std::vector < std::vector<int> >& nonlclele, int ele_count[], int NEM)
{
    int mc[2], c, mc1[2], c1, i, j;
    double r;

    std::ofstream out1("neigh_elem2D.txt");
    std::ofstream out2("neigh_count2D.txt");
    
    for (int m = 0; m < NEM; m++)
    {
        ele_count[m] = 0;
    }

    for (mc[1] = 0; mc[1] < Lc[1]; (mc[1])++)
    { 
        for (mc[0] = 0; mc[0] < Lc[0]; (mc[0])++)
        {
            c = mc[1]*Lc[0] + mc[0];
            std::vector < int > tmp;

            for (mc1[1] = mc[1]-1; mc1[1] <= mc[1]+1; (mc1[1])++)
            {
                for (mc1[0] = mc[0]-1; mc1[0] <= mc[0]+1; (mc1[0])++)
                {
                    c1 = ((mc1[1] + Lc[1])%Lc[1])*Lc[0] + (mc1[0] + Lc[0])%Lc[0];
                    tmp.push_back(c1);
                }
            }

            i = head[c];
            int s = tmp.size();

            while (i != -1)
            {
                std::vector<int> tmp1;
                int count = 0;

                for (int k = 0; k < s; k++)
                {
                    j = head[tmp[k]];
                    while (j != -1)
                    {
                        r = ((center[i][0] - center[j][0])*(center[i][0] - center[j][0])) + ((center[i][1] - center[j][1])*(center[i][1] - center[j][1]));
                        if (r <= (rl*rl))
                        {
                            tmp1.push_back(j+1);
                            ele_count[i] = ele_count[i] + 1;
                            count = count + 1;
                        }
                        j = lscl[j]; 
                    }
                }
                nonlclele.push_back(tmp1);
                i = lscl[i];

                // Writing Neighbour elements to text file
                for(int it = 0; it < tmp1.size(); it++)
                {
                    out1 << tmp1[it] <<" ";
                }
                out1 << "\n";

                out2 << count << "\n";
            } 
        } 
    }
}