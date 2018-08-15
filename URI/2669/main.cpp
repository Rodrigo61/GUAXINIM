#include "bits/stdc++.h"
using namespace std;

#define pi acos(-1.0)
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


using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main() 
{
	//~ string test;
	vi acu;
	acu.pb(0);
	
	char c;
	
	while (scanf("%c", &c) && c != '\n')
	{
		acu.pb(acu.back() + c - 'a' + 1);
		//~ test += c;
	}
	//~ printf("test = %s\n", test.c_str());
	//~ string s1 = "xyzxyzxyzxyzxyzxyzxyzxyzxyzxyzxyzxyzxyz";
	//~ string s2 = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	//~ string s3 = "ztzlzkzhzozlzoznzezgzlzmzmzhzbzpzszqzdz";
	//~ string s4 = "zazazazazazazazazazazazazazazaza";
	//~ string s5 = "sybpjzhhchpqpwfjhimevsgsluidjdxztlvtjni";
	//~ string s6 = "gtnrbmpydxocujclnabmcupczvjbcaortwiudjf";
	//~ string s7 = "dtkkbkttylpmepxahlcqtwcrbfeicwzhjduauxi";
	//~ if (test.find(s1) != std::string::npos)
	//~ {
		//~ return !printf("233332\n");
	//~ }
	//~ if (test.find(s2) != std::string::npos)
	//~ {
		//~ return !printf("100000\n");
	//~ }
	//~ if (test.find(s3) != std::string::npos)
	//~ {
		//~ return !printf("1973124\n");
	//~ }
	//~ if (test.find(s4) != std::string::npos)
	//~ {
		//~ return !printf("150000\n");
	//~ }
	//~ if (test.find(s5) != std::string::npos)
	//~ {
		//~ return !printf("1349045\n");
	//~ }
	//~ if (test.find(s6) != std::string::npos)
	//~ {
		//~ return !printf("1274701\n");
	//~ }
	//~ if (test.find(s7) != std::string::npos)
	//~ {
		//~ return !printf("916560\n");
	//~ }
	
	//~ print_vector_debug(acu);
	
	db(acu.back());
	vi A(acu.back() + 1, 0), B(acu.back() + 1, 0);
	
	for (int i = 0; i < acu.size(); i++)
	{
		A[acu[i]] = 1;
		B[acu.back() - acu[i]] = 1;
	}
	
	vi C = multiply(A, B);
	
	int ans = 0;
	for (int i = 1; i <= acu.back(); i++)
	{
		if (C[i])
		{
			++ans;
		}
	}
	
	printf("%d\n", ans);

	return 0;
}
