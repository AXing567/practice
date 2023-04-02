#include <iostream>
#define endl '\n'
using namespace std;

int main()
{

	int n;
	while (cin >> n)
	{
		if (n > 3)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}