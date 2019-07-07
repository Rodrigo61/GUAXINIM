#include <bits/stdc++.h>

using namespace std;

#define MAXN 512345
#define INF 0x3f3f3f3f
#define db(x) //cerr << #x << " = " << x << endl;

vector<string> words;
int endof[MAXN];

int bs(int beg, int target)
{
	int up = words.size();
	int lo = beg;
	int best = up;
	while (lo <= up)
	{
		int mid = lo + (up - lo)/2;
		if (endof[mid] <= target)
		{
			best = mid;
			lo = mid + 1;
		}
		else
		{
			up = mid - 1;
		}
	}
	
	return best;
}

int solve(int len)
{
	int word_it = -1;
	int target = len;
	int total = -1;
	
	do 
	{
		db("----");
		total += (int)words[word_it + 1].size() + 1;
		int last = word_it;
		word_it = bs(word_it + 1, target);
		assert(last != word_it);
		db(word_it);
		target = endof[word_it] + 1 + len;
		db(target);
		
		db(total);
	} while (word_it < (int)words.size() - 1);
	
	return total;
}

int main()
{
	char c;
	int pos = 0;
	int it = 0;
	while (c = getchar(), c != '\n')
	{
		ungetc(c, stdin);
		string word;
		cin >> word;
		words.push_back(word);
		pos += word.size();
		endof[it] = pos;
		db(endof[it]);
		pos++;
		++it;
	}
	endof[words.size()] = INF;
	
	int a, b;
	scanf("%d%d", &a, &b);
	cin >> a >> b;
	
	for (int i = a; i <= b; i++)
	{
		printf("%d\n", solve(i));
	}
	
}
