#include "bits/stdc++.h"

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl;

int main()
{
	double p1, p2, p3, p4, p5, p6;
	
	scanf("%lf%lf%lf%lf%lf%lf", &p1,&p2,&p3,&p4,&p5,&p6);
	
	double exp = p1*1 + p2*2 + p3*3 + p4*4 + p5*5 + p6*6;
	
	db(exp);
	double aux_exp = exp - p1*1;
	db(aux_exp);
	double x = (3.5-aux_exp)/p1;
	db(x);
	double mini = abs(x - 1);
	
	aux_exp = exp - p2*2;
	x = (3.5-aux_exp)/p2;
	mini = min(mini, abs(x - 2));
	
	aux_exp = exp - p3*3;
	x = (3.5-aux_exp)/p3;
	mini = min(mini, abs(x - 3));
	
	aux_exp = exp - p4*4;
	x = (3.5-aux_exp)/p4;
	mini = min(mini, abs(x - 4));
	
	aux_exp = exp - p5*5;
	x = (3.5-aux_exp)/p5;
	mini = min(mini, abs(x - 5));
	
	aux_exp = exp - p6*6;
	x = (3.5-aux_exp)/p6;
	mini = min(mini, abs(x - 6));
	
	printf("%.3lf\n", mini);
	
	return 0;
}
