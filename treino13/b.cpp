#include<bits/stdc++.h>

using namespace std;

#define pb push_back

main()
{
	int n;
	scanf("%d", &n);
	
	vector<int> fat;
	
	vector<int> verses(n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &verses[i]);
	}
	
	for(int i = 2; i <= n; i++){
		if(n%i == 0)
			fat.pb(i);
	}
	
	for(int i = 0; i < fat.size(); i++){
		int k = fat[i];
		
		vector<int> freq(k, 0);
		
		for(int j = 0; j < n; j++){
			freq[verses[j]%k]++;
		}
		
		int val = 1;
		
		//printf("k = %d\n", k);
		
		for(int j = 0; j < k && val; j++){
			if(freq[j] != n/k){
				val = 0;
			//	printf("%d: %d\n", j, freq[j]);
			}
		}
		
		if(val){
			printf("%d\n", k);
			return 0;
		}
	}
	
	printf("%d\n", -1);
	return 0; 
}
