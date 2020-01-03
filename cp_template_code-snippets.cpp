{
	// Place your global snippets here. Each snippet is defined under a snippet name and has a scope, prefix, body and 
	// description. Add comma separated ids of the languages where the snippet is applicable in the scope field. If scope 
	// is left empty or omitted, the snippet gets applied to all languages. The prefix is what is 
	// used to trigger the snippet and the body will be expanded and inserted. Possible variables are: 
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. 
	// Placeholders with the same ids are connected.

	"cp template": {
		"prefix": "cp_t",
		"body": [
			"#include <bits/stdc++.h>",
			"",
			"using namespace std;",
			"",
			"#define pb push_back",
			"#define db(x) cerr << #x << \" = \" << x << endl;",
			"#define INF 0x3f3f3f3f3f3f3f3f",
			"#define fi first",
			"#define se second",
			"#define vi vector<int>",
			"#define vll vector<ll>",
			"#define all(x) x.begin(), x.end()",
			"#define pii pair<int, int>",
			"#define pll pair<ll, ll>",
			"#define vii vector<pii>",
			"#define ll long long",
			"#define ull unsigned long long",
			"typedef long double ld;",
			"",
			"",
			"int main()",
			"{",
			"",
			"}",

		],
	},

	"cp_opt": {
		"prefix": "opt",
		"body": [
			"#pragma GCC optimize(\"Ofast\")",
			"#pragma GCC target(\"avx,avx2,fma\")"
		],
	},

	"cp_task": {
		"prefix": "task",
		"body": [
			"\"--std=c++14\",",
			"\"-Wall\",",
			"\"-Wextra\",",
			"\"-Wno-unused-result\",",
			"\"-Wconversion\",",
			"\"-Wfatal-errors\",",
			"\"-fsanitize=undefined,address\",",
		],
	}

}