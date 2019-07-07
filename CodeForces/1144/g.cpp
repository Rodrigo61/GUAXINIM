#include <bits/stdc++.h>

using namespace std;
#define MAXN 212345
#define pb push_back
#define db(x) //cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
int N;

vector<int> LIS(vector<int> vals) {

    int sz = N;
    vector<int> ends_list(sz);
    vector<int> lis_vet(N);
    int max_size = 0;
    
    for (int i = 0; i < sz; ++i) {
        
        int pos = distance(ends_list.begin(), lower_bound(ends_list.begin(), ends_list.begin() + max_size, vals[i]));

        ends_list[pos] = vals[i];
        
		if (pos == max_size)
		{
            max_size = pos + 1;
		}
        
		lis_vet[i] = pos + 1;
    }
    
    return lis_vet;
}

vector<int> get_lis_left(vector<int> vals, int pos)
{
	vector<int> lis_vet = LIS(vals);

	vector<int> indices;
	indices.pb(pos);
	int last_val = vals[pos];
	int last_length = lis_vet[pos];
	
	for (int i = pos - 1; i >=0; --i)
	{
		if (vals[i] < last_val && lis_vet[i] == last_length - 1)
		{
			indices.pb(i);
			last_val = vals[i];
			last_length--;
		}
	}
	
	return indices;
}

vector<int> get_lis_right(vector<int> vals, int pos)
{
	reverse(vals.begin(), vals.end());
	vector<int> lis_vet = LIS(vals);
	
	
	vector<int> indices;
	indices.pb(pos);
	pos = (N - pos) - 1;
	int last_val = vals[pos];
	int last_length = lis_vet[pos];
	
	for (int i = pos - 1; i >= 0; --i)
	{
		if (vals[i] < last_val && lis_vet[i] == last_length - 1)
		{
			indices.pb((N - i) - 1);
			last_val = vals[i];
			last_length--;
		}
	}
	
	return indices;
}

void print_vector(vector<int> vet)
{
	for (int v : vet)
		printf("%d ", v);
	printf("\n");
}

bool check_freq(vector<int> vals)
{
	vector<int> freq(MAXN);
	for (int i : vals)
	{
		freq[i]++;
		if (freq[i] > 2)
		{
			return false;
		}
	}
	
	return true;
}

bool possible(int pos, vector<int> vals)
{
	//left
	auto indices = get_lis_left(vals, pos);
	reverse(indices.begin(), indices.end());
	//~ print_vector(indices);
	int it = 0;
	int last = INF;
	bool possible = true;
	for (int i = 0; i < N; i++)
	{
		if (i == indices[it])
		{
			++it;
			continue;
		}
		db(vals[i]);
		if (vals[i] >= last)
		{
			possible = false;
			break;
		}
		last = vals[i];
	}
	
	if (possible)
	{
		printf("YES\n");
		int it = 0;
		for (int i = 0; i < N; i++)
		{
			if (i == indices[it])
			{
				++it;
				printf("0 ");
				continue;
			}
			printf("1 ");
		}
		return true;
	}
	
	//right
	indices = get_lis_right(vals, pos);
	//~ print_vector(indices);
	it = 0;
	last = -1;
	possible = true;
	for (int i = 0; i < N; i++)
	{
		if (i == indices[it])
		{
			++it;
			continue;
		}
		if (vals[i] <= last)
		{
			possible = false;
			break;
		}
		last = vals[i];
	}
	
	if (possible)
	{
		printf("YES\n");
		int it = 0;
		for (int i = 0; i < N; i++)
		{
			if (i == indices[it])
			{
				++it;
				printf("1 ");
				continue;
			}
			printf("0 ");
		}
		return true;
	}
	
	return false;
}


int main()
{
	scanf("%d", &N);
	vector<int> vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	if (!check_freq(vals))
		return !printf("NO\n");
		
	int maxi = *max_element(vals.begin(), vals.end());
	for (int i = 0; i < N; ++i)
	{
		if (vals[i] == maxi && possible(i, vals))
		{
			return 0;
		}
	}
	
	printf("NO\n");
		
	
}
