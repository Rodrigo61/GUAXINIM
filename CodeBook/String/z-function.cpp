/*
	Z-function para criar o Z-array
	[COMPLEX] O(N)
	[USAGE]
		[ARGS] string s que terá o z-array calculado
	[OUT]
		Z-array
	 
	No Z-array o valor de Z[i] nos diz qual o tamanho da substr iniciada em i
	que também é um prefixo de s.	
*/

vi Z_function(const string &s)
{
	int n = (int)s.size();
	vi z(n);
	
	for (int i = 1, l = 0, r = 0; i < n; ++i) 
	{
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
            
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
            
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
            
    }
    return z;
	
}
