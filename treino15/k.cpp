#include<bits/stdc++.h>

using namespace std;

struct employ{
	int salary;
	char name[10] ;
	
	bool operator < (employ o) const{
		return salary < o.salary;
	}
};

vector<employ> e;

int main(){
	int n, d, k;
	
	cin >> n >> d >> k;
	
	e.resize(n);
	
	for(int i = 0; i < n; i++)
		scanf("%s %d", e[i].name, &e[i].salary); 
	
	sort(e.begin(), e.end());
	
	int f = 0;
	
	int sum = 0;
	
	while(f < k && sum < d){
		sum += e[n - f++ - 1].salary;
	}
	
	if(f <= k && sum >= d){
		printf("%d\n", f);
		
		for(int i = 0; i < f; i++)
			printf("%s, YOU ARE FIRED!\n", e[n - 1 - i].name);
	}
	
	else 
		printf("impossible\n");
	return 0;
}
