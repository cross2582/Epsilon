#include <iostream>
#include <string.h>
using namespace std;
double pow(double x, int p) {
	double up = 1;
	for (int m = p; m > 0; m--) {
		up = up * x;
	}
	return up;
}
double g(double x, int i) 
{
	if(i==1) 
	{
	return 1;
	}
	
	double a = (x - 1)/(x + 1);
	int b = 2 * i + 1;
	double c = pow(a, b);
	return (g(x, i - 1) / b) * c;
	
}
void out(double first, double second,int i) {
	cout << i-1 << ") " << first << "	" << i << ") " << second << "	" << first - second<<endl;
}
double sum(double x, double epsilon)
{   
	double first, second;
	double sum = 1;
	int i = 2;
	while ((g(x, i-1) - g(x, i)) > epsilon) {
		first = g(x, i - 1);
		second = g(x, i);
		sum = second+ sum;
		out(first, second, i);
		i++;
		
	}
	return sum;
}