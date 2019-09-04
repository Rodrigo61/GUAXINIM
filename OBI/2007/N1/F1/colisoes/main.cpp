#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

bool in(pii o, vii &rect)
{
	return o >= rect[0] && o <= rect[1];
}

int main()
{
	vii A(2), B(2);
	scanf("%d%d%d%d", &A[0].fi, &A[0].se, &A[1].fi, &A[1].se);
	scanf("%d%d%d%d", &B[0].fi, &B[0].se, &B[1].fi, &B[1].se);
	sort(all(A));
	sort(all(B));
	
	printf("%d\n", bool(in(A[0], B) + in(A[1], B) + in(B[0], A) + in(B[1], A)));
	
}
