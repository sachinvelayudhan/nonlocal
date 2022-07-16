#include <vector>

void Cell_list_2D (int NEM, std::vector < std::vector<double> >& center, std::vector< double >& rc, int Lc[], std::vector < std::vector<int> >& cell_list)
{
    int mc[2], mc1[2], c, c1;

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
                    tmp = {c+1, c+Lc[0], c+Lc[0]+1};
                }
                else if (mc[0] == (Lc[0]-1))
                {
                    tmp = {c-1, c+Lc[0]-1, c+Lc[0]};
                }
                else
                {
                    tmp = {c-1, c+1, c+Lc[0]-1, c+Lc[0], c+Lc[0]+1};
                }
            }

            else if ((mc[0] == 0) && (mc[1] != 0))
            {
                if (mc[1] == (Lc[1]-1))
                {
                    tmp = {c-Lc[0], c-Lc[0]+1, c+1};
                }
                else
                {
                    tmp = {c-Lc[0], c-Lc[0]+1, c+1, c+Lc[0], c+Lc[0]+1};
                }
            }

            else if ((mc[1] == (Lc[1]-1)) && (mc[0] != 0))
            {
                if (mc[0] == (Lc[0]-1))
                {
                    tmp = {c-Lc[0]-1, c-Lc[0], c-1};
                }
                else
                {
                    tmp = {c-Lc[0]-1, c-Lc[0], c-Lc[0]+1, c-1, c+1};
                }
            }

            else if ((mc[0] == (Lc[0]-1)) && (mc[1] != 0) && (mc[1] != (Lc[1]-1)))
            {
                tmp = {c-Lc[0]-1, c-Lc[0], c-1, c+Lc[0]-1, c+Lc[0]};
            }

            else
            {
                for (mc1[1] = mc[1]-1; mc1[1] <= mc[1]+1; (mc1[1])++)
                {
                    for (mc1[0] = mc[0]-1; mc1[0] <= mc[0]+1; (mc1[0])++)
                    {
                        c1 = ((mc1[1] + Lc[1])%Lc[1])*Lc[0] + (mc1[0] + Lc[0])%Lc[0];

                        if ((c1 >= 0 ) && (c1 != c ))
                        {
                            tmp.push_back(c1);
                        }
                    }
                }
            }
            cell_list.push_back(tmp);
        }
    }

    for (int i = 0; i < NEM; i++)
    {
        for (int a = 0; a < 2; a++)
        {
            mc[a] = center[i][a] / rc[a];
        }

        c = mc[1]*Lc[0] + mc[0];
    }
}