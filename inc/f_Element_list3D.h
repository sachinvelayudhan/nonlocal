#include <fstream>
#include <sstream>

void Element_list3D (int head[], int lscl[], int lcxy, int Lc[], std::vector < std::vector<double> >& center, std::vector<double>& Ld, double rl, std::vector < std::vector<int> >& nonlclele, int ele_count[], int NEM)
{
    int mc[3], c, mc1[3], c1, i, j;
    double r;

    std::ofstream out1("neigh_elem3D.txt");
    std::ofstream out2("neigh_count3D.txt");
    
    for (int m = 0; m < NEM; m++)
    {
        ele_count[m] = 0;
    }

    for (mc[2] = 0; mc[2] < Lc[2]; (mc[2])++)
    {
        for (mc[1] = 0; mc[1] < Lc[1]; (mc[1])++)
        { 
            for (mc[0] = 0; mc[0] < Lc[0]; (mc[0])++)
            {
                c = mc[2]*lcxy + mc[1]*Lc[0] + mc[0];
                std::vector < int > tmp;

                for (mc1[2] = mc[2]-1; mc1[2] <= mc[2]+1; (mc1[2])++)
                {
                    for (mc1[1] = mc[1]-1; mc1[1] <= mc[1]+1; (mc1[1])++)
                    {
                        for (mc1[0] = mc[0]-1; mc1[0] <= mc[0]+1; (mc1[0])++)
                        {
                            c1 = ((mc1[2] + Lc[2])%Lc[2])*lcxy + ((mc1[1] + Lc[1])%Lc[1])*Lc[0] + (mc1[0] + Lc[0])%Lc[0];
                            tmp.push_back(c1);
                        }
                    }
                }

                i = head[c];
                int s = tmp.size();

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
                            r = ((center[i][0] - center[j][0])*(center[i][0] - center[j][0])) + ((center[i][1] - center[j][1])*(center[i][1] - center[j][1])) + ((center[i][2] - center[j][2])*(center[i][2] - center[j][2]));
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
}