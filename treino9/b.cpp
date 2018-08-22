#include<bits/stdc++.h>

using namespace std;


int main()
{
	char s[1000006], out[1000006];
	
	scanf("%s", s);
	
	int i = 0, j = 0;
	
	int n = strlen(s);
	
	for(i = 0; i < n; i++){
		if(s[i] == 'R'){
			out[j++] = 'S';
			if(i > 1 && ((s[i-2] == 'B' && s[i-1] == 'L')
				||(s[i-1] == 'B' && s[i-2] == 'L'))){
				j = j - 3;
				out[j++] = 'C';
				out[j] = '\0';
				s[i] = '.';
				s[i-1] = '.';
			}
		}
		
		if(s[i] == 'B'){
			out[j++] = 'K';
			if(i > 1 && ((s[i-2] == 'R' && s[i-1] == 'L')
				||(s[i-1] == 'R' && s[i-2] == 'L'))){
				j = j - 3;
				out[j++] = 'C';
				out[j] = '\0';
				s[i] = '.';
				s[i-1] = '.';
			}
		}

		if(s[i] == 'L'){
			out[j++] = 'H';
			if(i > 1 && ((s[i-2] == 'B' && s[i-1] == 'R')
				||(s[i-1] == 'B' && s[i-2] == 'R'))){
				j = j - 3;
				out[j++] = 'C';
				out[j] = '\0';
				s[i] = '.';
				s[i-1] = '.';
			}
		}
		
	}
	out[j] = '\0';
	
	printf("%s\n", out);
	
	return 0;
}
