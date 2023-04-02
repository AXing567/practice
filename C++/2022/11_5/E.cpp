#include <iostream>
#include <cmath>

using namespace std;
double y;

double check(double x)
{
	return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
}

double lower(double l, double r, double x)
{
	int a =( l + 0.00005) * 10000,b = ( r + 0.00005) * 10000;
	while (a / 10000.0 != b / 10000.0)
	{
		double mid = ((l - r) / 2.0) + r;
		if (check(mid) > y)
			r = mid;
		else
			l = mid;
		a =( l + 0.00005) * 10000,b = ( r + 0.00005) * 10000;
	}
	return a/10000.0;
}

int main()
{
	cin >> y;
	double x = lower(-0.000000000000001, 100.000000000000001, y);
	if(y < 6) 
	{
		cout << "No solution!" << endl;
		return 0;
	}

	if (y > 807020306)
	{
		cout << "No solution!" << endl;
		return 0;
	}

	if (x >= 0 && x <= 100)
		printf("%.4f",x );
	else
		cout << "No solution!" << endl;
	return 0;
}
/*

6		0

<6		No solution!  


10000000000   100
*/
