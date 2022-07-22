#include <fstream>
#include <sstream>

void Element_list3D (int head[], int lscl[], int lcxy, int Lc[], std::vector < std::vector<double> >& center, std::vector<double>& Ld, double rl, std::vector < int > nonlclele[], int ele_count[], int NEM)
{
    int mc[3], c, mc1[3], c1, i, j;
    double r;

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
                    int count = 0;

                    for (int k = 0; k < s; k++)
                    {
                        j = head[tmp[k]];
                        while (j != -1)
                        {
                            r = ((center[i][0] - center[j][0])*(center[i][0] - center[j][0])) + ((center[i][1] - center[j][1])*(center[i][1] - center[j][1])) + ((center[i][2] - center[j][2])*(center[i][2] - center[j][2]));
                            if (r <= (rl*rl))
                            {
                                nonlclele[i].push_back(j+1);
                                count = count + 1;
                            }
                            j = lscl[j]; 
                        }
                    }
                    
                    ele_count[i] = count;
                    i = lscl[i]; 
                } 
            } 
        }
    }
}