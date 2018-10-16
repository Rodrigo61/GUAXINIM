#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, x;
		cin >> x >> n;
		if(n == 1){
			printf("%lld\n", x);
			continue;
		}
		long long res[1000];
		long long m = 2*n - 2;
		for(int i = 1; i < n - 1; i++){
			res[i] = 2*(x/m);
		}
		res[n-1] = res[0] = (x/m);
		
		long long cnt = x%m;
		
		int pos = 0;
		
		int crec = 1;
		
		while(cnt--){
			res[pos]++;
			if(pos == n - 1)
				crec = -1;
			pos += crec;
		}
		
		for(int i = 0; i < n; i++)
			printf("%lld%c", res[i], " \n"[i == n - 1]);
	}
}
