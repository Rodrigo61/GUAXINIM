#include<bits/stdc++.h>

using namespace std;

#define pb push_back

int pot(int e){
	int res = 1;
	int acc = 2;
	for(int i = 1; i <= e; i <<= 1){
		//rintf("%d %d\n", i, acc);
		if(i&e){
			res *= acc;
		}
		acc *= acc;
	}
	
	return res;
}

int descarta;

void hanoi(int n, char A, char B, char C){
	if(n == 1){
		if(descarta)
			descarta = 0;
		else
			printf("%c %c\n", A, C);
	}
	else{
		hanoi(n - 1, A, C, B);
		printf("%c %c\n", A, C);
		hanoi(n - 1, B, A, C);
	}
}

main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	
	int mn = pot(n) - 1;
	
	int enrola = k - mn;
	
	if(k < mn){
		printf("N\n");
	}
	
	else{
		printf("Y\n");
		if(enrola%2 == 0){
			for(int i = 0; i < enrola; i += 2){
				printf("A B\nB A\n");
			}
		}
		
		else if(enrola > 1){
			printf("A B\nB C\nC A\n");
			enrola -= 3;
			for(int i = 0; i < enrola; i += 2){
				printf("A B\nB A\n");
			}
		}
		
		else{
			descarta = 1;
			if(n%2 == 0){
				printf("A C\n");
				printf("C B\n");
			}
			else{
				printf("A B\n");
				printf("B C\n");
			}
		}
		
		hanoi(n, 'A', 'B', 'C');
	}


	return 0; 
}
