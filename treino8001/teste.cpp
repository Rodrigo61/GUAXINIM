#include<bits/stdc++.h>
#include<time.h>
using namespace std;

int main(){
	int T = 10;
	cout << T << endl;
	srand(time(NULL));
	while(T--){
		int n = rand()%10 + 3;
		cout << n << endl;
		
		for(int i = 0; i < n; i++){
			printf("%d %d\n", -10 + rand()%21, -10 + rand()%21);
		}
	}
	return 0;
}
