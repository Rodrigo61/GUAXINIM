/*
	Estou calculando com modulo só porque a matriz exemplo é muito grande.

	Lembre-se C(X, Y) = C(X - 1, Y - 1) + C(X - 1, y)
*/

long long ncr[MAXN][MAXN];

void calcncr()
{
    for(int i = 0; i < MAXN; i++)
    {
        ncr[i][0] = 1;
    }
    for(int i = 1; i < MAXN; i++)
    {
        for(int j = 1; j < MAXN; j++)
        {
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%MOD;
        }
    }
}

