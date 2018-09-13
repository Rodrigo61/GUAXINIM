#include<bits/stdc++.h>

using namespace std;

bool pal(int x){
	int hr, mn, seg;
	seg = x%60;
	x /= 60;
	
	mn = x%60;
	x /= 60;
	
	hr = x;
	
	return ((hr/10 == seg%10) && (hr%10 == seg/10) && (mn%10 == mn/10));
}

int toInt(char s[9]){
	for(int i = 0; i < 8; i++)
		s[i] -= '0';
	return s[0]*10*3600 + s[1]*3600 +s[3]*600 + s[4]*60 + s[6]*10 + s[7];
}

int ac[24*60*60 + 30];

int main(){
	
	
	
	
	for(int i = 0; i < 24*60*60 + 30; i++){
		if(pal(i))
			ac[i]++;
	} 
	
	for(int i = 1; i < 24*60*60 + 30; i++){
		ac[i] += ac[i-1];
	}
	
	int q;
	
	cin >> q;
	
	char s1[9], s2[9];
	
	for(int i = 0; i < q; i++){
		scanf("%s %s", s1, s2);
		int i1 = toInt(s1);
		int i2 = toInt(s2);
		
		int res = ac[i2] - (i1 == 0 ? 0 : ac[i1 - 1]);
		printf("%d\n", res);
	}
}
