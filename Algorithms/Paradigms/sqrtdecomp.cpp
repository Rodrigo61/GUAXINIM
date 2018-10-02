/*
   Template para sqrt decomposition.
   [OBS]
	Em geral guardamos informacoes em até O(N *sqrt(N)) (e.g. vetor de freq dos blocos)
	Tome cuidado como é calculado o sqr, use exatamente a formula abaixo
	
 * */


int sqr = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks

int sum = 0;
int c_l = l / len,   c_r = r / len;
if (c_l == c_r)
    for (int i=l; i<=r; ++i)
        sum += a[i];
else {
    for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
        sum += a[i];
    for (int i=c_l+1; i<=c_r-1; ++i)
        sum += b[i];
    for (int i=c_r*len; i<=r; ++i)
        sum += a[i];
}
