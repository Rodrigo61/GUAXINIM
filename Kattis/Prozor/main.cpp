#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;

template<typename T>
void print_vector_debug(const T& t) {
	cout << "[DEBUG] VECTOR:";
	for (auto i = t.cbegin(); i != t.cend(); ++i) {
		if ((i + 1) != t.cend()) {
			cout << *i << " ";
		} else {
			cout << *i << endl;
		}
	}
}

#define MAXN 105
char grid[MAXN][MAXN];

int main() 
{

	int R, S, K;
	
	scanf("%d%d%d\n", &R, &S, &K);
	
	vector<vi> acu_mat(R, vi(S));

	int num;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < S; ++j) {
			scanf("%c", &grid[i][j]);
			
			num = grid[i][j] == '*' ? 1:0;
			
			if(i == 0 && j == 0){
				acu_mat[i][j] = num;
			}else if(i == 0){
				acu_mat[i][j] = num + acu_mat[i][j-1];
			}else if(j == 0){
				acu_mat[i][j] = num + acu_mat[i-1][j];
			}else{
				acu_mat[i][j] = num + acu_mat[i][j-1] + acu_mat[i-1][j] - acu_mat[i-1][j-1];
			}
		}
		scanf("\n");
	}
	
	db("d1");

	int maxi = 0;
	
	pii maxi_pos;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < S; ++j) {
			
			int i_0 = i + 1;
			int j_0 = j + 1;
			int i_f = i + K - 2;
			int j_f = j + K - 2;
			
			if (i_f + 1 >= R || j_f + 1 >= S)
			{
				continue;
			}
			
			db(i_0);
			db(j_0);
			db(i_f);
			db(j_f);
			
			int curr_val = acu_mat[i_f][j_f];

			if(j_0 > 0) curr_val -= acu_mat[i_f][j_0-1];
			if(i_0 > 0) curr_val -= acu_mat[i_0-1][j_f];
			if(j_0 > 0 && i_0 > 0) curr_val += acu_mat[i_0-1][j_0-1];

			if (curr_val > maxi)
			{
				maxi = curr_val;
				maxi_pos = {i, j};
			}
		}
	}

	printf("%d\n", maxi);
	grid[maxi_pos.first][maxi_pos.second] = '+';
	grid[maxi_pos.first][maxi_pos.second + K - 1] = '+';
	grid[maxi_pos.first + K - 1][maxi_pos.second] = '+';
	grid[maxi_pos.first + K - 1][maxi_pos.second + K - 1] = '+';
	
	for (int i = maxi_pos.second + 1; i < maxi_pos.second + K - 1; i++)
	{
		grid[maxi_pos.first][i] = '-';
	}
	for (int i = maxi_pos.second + 1; i < maxi_pos.second + K - 1; i++)
	{
		grid[maxi_pos.first + K - 1][i] = '-';
	}
	
	for (int i = maxi_pos.first + 1; i < maxi_pos.first + K - 1; i++)
	{
		grid[i][maxi_pos.second] = '|';
	}
		for (int i = maxi_pos.first + 1; i < maxi_pos.first + K - 1; i++)
	{
		grid[i][maxi_pos.second + K - 1] = '|';
	}
	
	
	

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < S; ++j) {
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
