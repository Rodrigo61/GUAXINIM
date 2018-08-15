#include "bits/stdc++.h"
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
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

#define l10 (double)3.321928094887362

/*
 * Ideia: Queremos satisfazer P = floor(2^E/10^T)  <==> P <= 2^E/10^10 < P + 1
 *  <==> Tlg10 + lgP <= E < Tlg10 + lg(P + 1).  Queremos encontrar um T onde
 * os lados esquerdos e direitos estejam na fronteira de um unico numero
 * (ex: 4.8 e 5.3, tendo 5 como resposta final). O problema tbm se apoia no fato
 * de que sempre existe uma solucao, pois a busca no valor de T é exaustiva.
 * */


int main() 
{

	int P;
	
	while (scanf("%d", &P) != EOF)
	{
		
		string strP = to_string(P);
		int T = strP.size() + 1;
		double lP = log(P)/log(2);
		double lP1 = log(P + 1)/log(2);
		
		for (; ceil((double)T * l10 + lP) != floor((double)T * l10 + lP1); ++T);

		printf("%d\n", (int)ceil((double)T * l10 + lP));
		
	}

	return 0;
}
