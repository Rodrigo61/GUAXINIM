/*
	LIS nlgn DP + Binary Search
	[COMPLEX] O(NlgN)
	[USAGE]
		[ARGS] vetor values que queremos obter o LIS
	[OUT]
		Vetor res que nos diz o maior LIS que termina na posição i
*/

vi LIS(vi &values) {

    int sz = values.size();
    vi res(sz);
    vi ends_list(sz);
    int max_size = 0;
    
    for (int i = 0; i < sz; ++i) {
        
        int pos = distance(ends_list.begin(), lower_bound(ends_list.begin(), ends_list.begin() + max_size, values[i]));

        ends_list[pos] = values[i];
        
		if (pos == max_size)
		{
            max_size = pos + 1;
		}
        
		res[i] = pos + 1;
    }
    
    return res;

}

