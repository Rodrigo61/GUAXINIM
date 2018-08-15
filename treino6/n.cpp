#include<bits/stdc++.h>

using namespace std;

int main()
{

	int n, k;
	cin >> n >> k;
	
	int mini = k;
	int maxi = 1;
	
	for (int i = 0; i < n ; i++)
	{
		int floor;
		string cmd;
		
		cin >> floor >> cmd;
		
		if (cmd == "SAFE")
		{
			maxi = max(maxi, floor);
		}
		else
		{
			mini = min(mini, floor);
		}
		
	}
	
	printf("%d %d\n", maxi + 1, mini - 1);
	

	return 0;
}
