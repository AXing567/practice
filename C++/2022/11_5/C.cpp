#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#define endl '\n'
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;

int main()
{
    ll n, base = 1000, ans = 0;
    cin >> n;
    while (n >= base)
    {
        ans += n - (base - 1);
        base *= 1000;
    }
    cout << ans << endl;
    return 0;
}


/*
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#define endl '\n'
using namespace std;

int main()
{
	long long n;
	cin>>n;

	if(n <= 999)//999
		cout<<0<<endl;	
	else 
		if (n<=999999)//999 999 
			cout<< n - 999  <<endl;
		else 
			if(n <= 999999999ll)// 999 999 999
				cout<<n-999 + (n-999999) << endl;
			else 
				if(n <= 999999999999ll)// 999 999 999 999
					cout<<n-999 + (n-999999) +(n-999999999ll) << endl;
				else 
					if(n <= 999999999999999ll)//999 999 999 999 999
						cout<<n-999 + (n-999999) +(n-999999999ll) + (n-999999999999ll)<< endl;
                    else
                        cout<<n-999 + (n-999999) +(n-999999999ll) + (n-999999999999ll) + (n - 999999999999999ll)<< endl;
                    


 
	return 0;
}

*/

