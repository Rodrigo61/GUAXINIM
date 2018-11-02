#include<bits/stdc++.h>

using namespace std;

char s[2010], c[2010];

int main()
{
	int n, m;
	scanf("%s %s", s, c);
	n = strlen(s);
	m = strlen(c);
	
	int cnt = 0;
	
	for(int i = 0; i < n - m + 1; i++){
		int match = 1;
		char cr0 = 0, cr1 = 0;
		
		for(int j = 0; j < m; j++){
			if(c[j] == '0'){
				if(cr0 == 0)
					cr0 = s[i + j];
				else if(cr0 != s[i + j]){
					match = 0;
					break;
				}
			}
			
			else if(c[j] == '1'){
				if(cr1 == 0)
					cr1 = s[i + j];
				else if(cr1 != s[i + j]){
					match = 0;
					break;
				}
			}
		}
		
		if(match == 0){
			match = 1;
			cr0 = 0;
			cr1 = 0;
			for(int j = 0; j < m; j++){
				if(c[m - j - 1] == '0'){
					if(cr0 == 0)
						cr0 = s[i + j];
					else if(cr0 != s[i + j]){
						match = 0;
						break;
					}
				}
				
				else if(c[m - j - 1] == '1'){
					if(cr1 == 0)
						cr1 = s[i + j];
					else if(cr1 != s[i + j]){
						match = 0;
						break;
					}
				}
			}
		}
		
		cnt += match;
			
	}
	
	printf("%d\n", cnt);
	
	return 0;
}
