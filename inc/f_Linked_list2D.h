#include <vector>

void Linked_list2D (int NEM, std::vector < std::vector<double> >& center, std::vector< double >& rc, int lcxy, int head[], int lscl[], int Lc[], std::vector< double >& xlim, std::vector< double >& ylim)
{
    int mc[2], c, mcx[2], mcy[2];

    for (int k = 0; k < 2; k++)
    {
        mcx[k] = 0.0;
        mcy[k] = 0.0;
    }
    
    if (xlim[0] < 0.0)
    {
        mcx[0] = (0.0 - xlim[0]) / rc[0];
    }

    if (ylim[0] < 0.0)
    {
        mcx[1] = (0.0 - ylim[0]) / rc[1];
    }

    if (xlim[1] < 0.0)
    {
        mcy[0] = (0.0 - xlim[1]) / rc[0];
    }

    if (ylim[1] < 0.0)
    {
        mcy[1] = (0.0 - ylim[1]) / rc[1];
    }

    for (c = 0; c < lcxy; c++)
    {
        head[c] = -1;
    }

    for (int i = NEM-1; i >= 0; i--)
    {
        for (int a = 0; a < 2; a++)
        {
            mc[a] = (center[i][a] / rc[a]) + mcx[a] + mcy[a];
        }

        c = mc[1]*Lc[0] + mc[0];

        lscl[i] = head[c];
        head[c] = i;
    }
}