void get_LIS(vi &values, vi &res) {

    int sz = values.size();
    res.resize(sz);

    vi ends_list(sz);
    int max_size = 0;
    for (size_t i = 0; i < sz; ++i) {
        int pos = distance(ends_list.begin(), lower_bound(ends_list.begin(), ends_list.begin() + max_size, values[i]));

        ends_list[pos] = values[i];
        
	if (pos == max_size)
            max_size = pos + 1;
        
	res[i] = max_size;
    }

}

