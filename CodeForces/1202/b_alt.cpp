#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000 * 2000 + 10;
char s[N];
int change[10][10][10][10];
 
int main() {
	scanf("%s",s+1);
	int len = strlen(s + 1);
 
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					change[x][y][i][j] = 100;
					for (int c1 = 0; c1 <= 10; c1++) {
						for (int c2 = 0; c2 <= 10; c2++) {
							if (c1+c2==0)continue;
							if ((i + x * c1 + y * c2) % 10 == j)
								change[x][y][i][j] = min(change[x][y][i][j], c1 + c2);
						}
					}
					if (change[x][y][i][j] == 100)change[x][y][i][j] = -1;
				}
			}
		}
	}
 
	for (int x = 0; x < 10; x++) { 
		for (int y = 0; y < 10; y++) {
			int ans = 0;
			bool f = true;
			for (int i = 2; i <= len; i++) {
				if (change[x][y][s[i - 1] - '0'][s[i] - '0'] == -1) {
					f = false;
					break;
				}
				ans += change[x][y][s[i - 1] - '0'][s[i] - '0'];
			}
			if (f)printf("%d ",ans-len+1);
			else printf("-1 ");
		}
		puts("");
	}
	return 0;
}