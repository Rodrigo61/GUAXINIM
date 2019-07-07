value[0] = 0;
for (int x = 1; x <= n; x++) {
	value[x] = INF;
	for (auto c : coins) {
		if (x-c >= 0 && value[x-c]+1 < value[x]) {
			value[x] = value[x-c]+1;
			first[x] = c;
		}
	}
}

