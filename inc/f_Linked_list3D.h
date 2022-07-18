#include <vector>

void Linked_list3D (int NEM, std::vector < std::vector<double> >& center, std::vector< double >& rc, int lcxy, int lcxyz, int head[], int lscl[], int Lc[])
{
    int mc[3], c;

    for (c = 0; c < lcxyz; c++)
    {
        head[c] = -1;
    }

    for (int i = NEM-1; i >= 0; i--)
    {
        for (int a = 0; a < 3; a++)
        {
            mc[a] = center[i][a] / rc[a];
        }

        c = mc[2]*lcxy + mc[1]*Lc[0] + mc[0];

        lscl[i] = head[c];
        head[c] = i;
    }
}