#include<bits/stdc++.h>

using namespace std;

int freq[26], freq2[26];
char str[100001], str2[100001];


main()
{
	int N;
	scanf("%d", &N);
	while(N--)
	{
		for(int i = 0; i < 26; i++)
		{
			freq[i] = 0;
			freq2[i] = 0;
		}
		scanf("%s %s", str, str2);
		for(int i = 0; str2[i]; i++)
			freq[str2[i]-'a']++;
		int ans = 0;
		for(int i = 0; str[i]; i++)
		{
			if(freq[str[i]-'a'])
			{
				ans++;
				freq[str[i]-'a']--;
			}
			else
				break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
