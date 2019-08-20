// Ivan Carvalho
// Taxa - Fase 3 Programação Nível 2 - OBI 2017
// O(N^3)
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 401;
const int INF = 1e9;
double fator;
int dp[MAXN][MAXN],acumulada[MAXN],vetor[MAXN],total,resp,n;
int calcula(int i,int j){
	return acumulada[j] - acumulada[i-1];
}
int solve(int ini,int fim){
	if(dp[ini][fim] != -1) return dp[ini][fim];
	if(ini == fim) return dp[ini][fim] = 0;
	int best = INF;
	for(int quebra = ini;quebra + 1 <= fim;quebra++){
		int custo = max(calcula(ini,quebra),calcula(quebra+1,fim));
		best = min(best, custo + solve(ini,quebra) + solve(quebra+1,fim));
	}
	return dp[ini][fim] = best;
}
int main(){
	scanf("%d %lf",&n,&fator);
	for(int i = 1;i<=n;i++){
		scanf("%d",&vetor[i]);
		vetor[i+n] = vetor[i];
		total += vetor[i];
	}
	for(int i = 1;i<=2*n;i++){
		acumulada[i] = acumulada[i-1] + vetor[i];
	}
	memset(dp,-1,sizeof(dp));
	resp = INF;
	for(int i = 1;i<=n;i++){
		for(int j = i;j <= n;j++){
			int c1 = calcula(i,j);
			int c2 = total - c1;
			int tam = n - (j - i + 1);
			int c3 = solve(i,j) + solve(j+1,j+tam);
			resp = min(resp,max(c1,c2)+c3);
		}
	}
	printf("%.2lf\n", resp*fator);
	return 0;
}
