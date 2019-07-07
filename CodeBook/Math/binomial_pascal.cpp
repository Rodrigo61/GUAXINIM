/*
	Estou calculando com modulo só porque a matriz exemplo é muito grande.

	Lembre-se C(X, Y) = C(X - 1, Y - 1) + C(X - 1, y)
*/

long long ncr[1004][1004];

void calcncr()
{
    for(int i = 0; i <= 1000; i++)
    {
        ncr[i][0] = 1;
    }
    for(int i = 1; i <= 1000; i++)
    {
        for(int j = 1; j <= 1000; j++)
        {
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%MOD;
        }
    }
}

