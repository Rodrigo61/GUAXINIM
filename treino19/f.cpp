#include<bits/stdc++.h>

using namespace std;

int vet[2001];

main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		set<int> s;
		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
			s.insert(v[i]);
		}
		
		sort(v.begin(), v.end());
		
		vector<int> val(s.size()), dim(s.size(), 0);
		
		val.assign(s.begin(), s.end());
		
		for(int i = 0; i < val.size(); i++){
		//	cout << "i = " << i << endl;
			//cout << val[i] << endl;
			if(dim[i] == 0){
				dim[i] = val[i];
				for(int j = 2*val[i]; j <= val[val.size() - 1]; j += val[i]){
					int pos = lower_bound(val.begin(), val.end(), j) - val.begin();
					if(pos < val.size() && val[pos] == j && dim[pos] == 0)
						dim[pos] = val[i];
				}
			}
		}
		
		//cout << "ok" << endl;
		
		int j = 0;
		long long res = 0;
		for(int i = 0; i < n; i++){
			while(v[i] > val[j]){
				//printf("%d %d j = %d\n", v[i], val[j], j);
				j++;
				//if(j > 10)
				//	return 0;
			}
			res += dim[j];
		}
		
		cout << res << endl;
		
	}
	return 0;
}
