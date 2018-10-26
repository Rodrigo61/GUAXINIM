#include<bits/stdc++.h>

using namespace std;

#define MAX 240

bool mapa[MAX][MAX];

enum direction {E, S, W, N};
int vx[4] = {0, 1, 0, -1};
int vy[4] = {1, 0, -1, 0};

struct robo{
	direction dir;
	int x;
	int y;
	
	robo(){
		dir = E;
		x = y = MAX/2;
	}
};

int main(){
	int T;
	cin >> T;
	printf("%d\n",T);
	while(T--){
		string s;
		cin >> s;
		memset(mapa, 0, sizeof(mapa));
		int mnX = MAX/2, mxX = MAX/2;
		int mnY = MAX/2, mxY = MAX/2;
		
		robo r;
		
		mapa[r.x][r.y] = 1;
		
		for(int i = 0; i < (int)s.size(); i++){
			if(s[i] == 'F'){
				r.x += vx[r.dir];
				r.y += vy[r.dir];
			}
			
			else if(s[i] == 'R'){
				r.dir = (direction)(((int)r.dir + 1)%4);
				r.x += vx[r.dir];
				r.y += vy[r.dir];
			}
			
			else if(s[i] == 'B'){
				r.dir = (direction)(((int)r.dir + 2)%4);
				r.x += vx[r.dir];
				r.y += vy[r.dir];
			}
			
			else{
				r.dir = (direction)(((int)r.dir + 3)%4);
				r.x += vx[r.dir];
				r.y += vy[r.dir];
			}
			
			mapa[r.x][r.y] = 1;
			mxX = max(mxX, r.x);
			mnX = min(mnX, r.x);
			mxY = max(mxY, r.y);
			mnY = min(mnY, r.y);
			
		}
		
		printf("%d %d\n", mxX - mnX + 3, mxY - mnY + 2);  
		
		for(int i = mnX - 1; i <= mxX + 1; i++){
			for(int j = mnY; j <= mxY + 1; j++){
				printf("%c", (mapa[i][j]? '.':'#'));
				if(j == mxY + 1)
					printf("\n");
			}
		}
		
	}
	return 0;
}
