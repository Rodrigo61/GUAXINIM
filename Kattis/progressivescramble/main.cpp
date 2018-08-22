#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;

template<typename T>
void print_vector_debug(const T& t) {
	cout << "[DEBUG] VECTOR:";
	for (auto i = t.cbegin(); i != t.cend(); ++i) {
		if ((i + 1) != t.cend()) {
			cout << *i << " ";
		} else {
			cout << *i << endl;
		}
	}
}

int vet[1001];
int acu[1001];

void print_char(int num)
{
	db(num);
	if (num == 0)
	{
		printf(" ");
	}
	else
	{
		printf("%c", (num % 27) + 'a' - 1);
	}
}

int main() 
{
	int N;
	cin >> N; 
	cin.ignore();

	
	string str;
	char c;
	
	for (int i = 0; i < N; i++)
	{
		getline(cin, str);
		db(str);
		
		c = str[0];
		if (c == 'e')
		{
			int sz = 0;
			for (int i = 2; i < str.size(); ++i)
			{
				c = str[i];
				if (c == ' ')
				{
					vet[sz] = 0;
				}
				else
				{
					vet[sz] = c - 'a' + 1;
				}
				++sz;
			}
			
			acu[0] = vet[0];
			for (int i = 1; i < sz; i++)
			{
				acu[i] = (vet[i] + acu[i - 1]) % 27;
			}
			
			for (int i = 0; i < sz; i++)
			{
				
				print_char(acu[i]);

			}
			
			printf("\n");
			
		}
		else
		{
			
			c = str[2];
			int last_u = c == ' ' ? 0 : c - 'a' + 1;
			int curr_u;
			
			//~ printf("last_u = %d\n", last_u);
			print_char(last_u);
			db(last_u);
			
			for (int i = 3; i < str.size(); ++i)
			{
				c = str[i];
				if (c == ' ')
				{
					curr_u = 0;
				}
				else
				{
					curr_u = c == ' ' ? 0 : c - 'a' + 1;
				}
				
				db(curr_u);
				db(last_u);
				
				int x;
				if (curr_u >= last_u)
				{
					x = curr_u - last_u;
				}
				else
				{
					x = curr_u + 27 - last_u;
				}

				while (x < 0)
				{
					x += 27;
				}
				print_char(x);
				
				db(x);
				
				last_u = last_u + x;
			}
			
			printf("\n");
		}
	}
	

	return 0;
}
