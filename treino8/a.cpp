#include<bits/stdc++.h>
#define MAXN 10000004
#define MOD 1000000007

using namespace std;

typedef long long ll;

int mem[MAXN][5];

int n;

/*int dp(int msk, int pos){
	//printf("%d %d\n", msk, pos);
	if(pos == 0)
		return(msk == 0);
	if(pos < 0)
		return 0;
	if(mem[pos][msk] == -1){
		if(msk == 0)
			mem[pos][msk] = ((dp(1, pos-1) + dp(2, pos-1))%MOD + dp(0, pos-2))%MOD;
		else if(msk == 1)
			mem[pos][msk] = (dp(0, pos-1) + dp(3, pos-1))%MOD;
		else if(msk == 2)
			mem[pos][msk] = (dp(0, pos-1) + dp(4, pos-1))%MOD;
		else if(msk == 3)
			mem[pos][msk] = dp(1, pos-1);
		else if(msk == 4)
			mem[pos][msk] = dp(2, pos-1);
	}
	
	return mem[pos][msk];
}*/

int main(){
	cin >> n;
	memset(mem, -1, sizeof(mem));
	
	mem[0][0] = 1;
	mem[0][1] = mem[0][2] = mem[0][3] = mem[0][4] = 0;
	
	int pos = 1;
	
	mem[pos][0] = (mem[pos - 1][1] + mem[pos - 1][2])%MOD;
	mem[pos][1] = (mem[pos - 1][0] + mem[pos - 1][3])%MOD;
	mem[pos][2] = (mem[pos - 1][0] + mem[pos - 1][4])%MOD;
	mem[pos][3] = mem[pos - 1][1];
	mem[pos][4] = mem[pos - 1][2];
	
	for(pos = 2; pos <= n; pos++){
		mem[pos][0] = ((mem[pos - 1][1] + mem[pos - 1][2])%MOD + mem[pos-2][0])%MOD;
		mem[pos][1] = (mem[pos - 1][0] + mem[pos - 1][3])%MOD;
		mem[pos][2] = (mem[pos - 1][0] + mem[pos - 1][4])%MOD;
		mem[pos][3] = mem[pos - 1][1];
		mem[pos][4] = mem[pos - 1][2];
	}
	
	
	cout << mem[n][0] << endl;
}

