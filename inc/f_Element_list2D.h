#include <fstream>
#include <sstream>

void Element_list2D (int NEM, std::vector < std::vector<double> >& center, std::vector< double >& rc, int Lc[], std::vector < std::vector<int> >& cell_list, int head[], int lscl[], int ele_count[], double rl, std::vector < std::vector<int> >& nonlclele)
{
    int mc[2], mc1[2], c, c1, i, j;
    double r;

    std::ofstream out1("neigh_elem.txt");
    std::ofstream out2("neigh_count.txt");

    for (int m = 0; m < NEM; m++)
    {
        ele_count[m] = 0;
    }

    for (mc[1] = 0; mc[1] < Lc[1]; (mc[1])++)
    {
        for (mc[0] = 0; mc[0] < Lc[0]; (mc[0])++)
        {
            c = mc[1]*Lc[0] + mc[0];

            std::vector<int> tmp;

            if (mc[1] == 0)
            {
                if (mc[0] == 0)
                {
                    tmp = {c, c+1, c+Lc[0], c+Lc[0]+1};
                }
                else if (mc[0] == (Lc[0]-1))
                {
                    tmp = {c-1, c, c+Lc[0]-1, c+Lc[0]};
                }
                else
                {
                    tmp = {c-1, c+1, c, c+Lc[0]-1, c+Lc[0], c+Lc[0]+1};
                }
            }

            else if ((mc[0] == 0) && (mc[1] != 0))
            {
                if (mc[1] == (Lc[1]-1))
                {
                    tmp = {c-Lc[0], c-Lc[0]+1, c, c+1};
                }
                else
                {
                    tmp = {c-Lc[0], c-Lc[0]+1, c, c+1, c+Lc[0], c+Lc[0]+1};
                }
            }

            else if ((mc[1] == (Lc[1]-1)) && (mc[0] != 0))
            {
                if (mc[0] == (Lc[0]-1))
                {
                    tmp = {c-Lc[0]-1, c-Lc[0], c-1, c};
                }
                else
                {
                    tmp = {c-Lc[0]-1, c-Lc[0], c-Lc[0]+1, c-1, c, c+1};
                }
            }

            else if ((mc[0] == (Lc[0]-1)) && (mc[1] != 0) && (mc[1] != (Lc[1]-1)))
            {
                tmp = {c-Lc[0]-1, c-Lc[0], c-1, c, c+Lc[0]-1, c+Lc[0]};
            }

            else
            {
                for (mc1[1] = mc[1]-1; mc1[1] <= mc[1]+1; (mc1[1])++)
                {
                    for (mc1[0] = mc[0]-1; mc1[0] <= mc[0]+1; (mc1[0])++)
                    {
                        c1 = ((mc1[1] + Lc[1])%Lc[1])*Lc[0] + (mc1[0] + Lc[0])%Lc[0];

                        if (c1 >= 0 )
                        {
                            tmp.push_back(c1);
                        }
                    }
                }
            }
            cell_list.push_back(tmp);

            int s = tmp.size();

            i = head[c];

            while (i != -1)
            {
                std::vector<int> tmp1;
                std::vector<int> tmp2;
                tmp1.push_back(i+1);
                tmp2.push_back(i+1);

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

                tmp2.push_back(count);

                // Writing Neighbour elements to text file
                for(int it = 0; it < tmp1.size(); it++)
                {
                    out1 << tmp1[it] <<" ";
                }
                out1 << "\n";

                for(int ix = 0; ix < tmp2.size(); ix++)
                {
                    out2 << tmp2[ix] << " ";
                }
                out2 << "\n";
            } 
        }
    }
}