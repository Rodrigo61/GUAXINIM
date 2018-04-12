#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<int> v;

	v.reserve(1000000);
	for(int i = 1; i <= 1000000; ++i){
		v.push_back(i);
	}
		
	int i = 30;
	do{
		cout << v.size() << endl;
		for(auto i : v){
			cout << i << " "			;
		}
		cout << endl;
		next_permutation(v.begin(), v.end());
		next_permutation(v.begin(), v.end());
		next_permutation(v.begin(), v.end());
		--i;		
	}while(i > 0);
	

	return 0;
	
}
