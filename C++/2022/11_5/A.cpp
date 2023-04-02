#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
const int N = 1e5 + 10;
char b[N];
int cont;

int main()
{
	string a;
	cin>>a;
	for(int i = 0 ; i < a.length();i++)
	{
		b[i]=a[i];		 
	} 
	for(int i = 0 ; i < a.length();i++)
	{
		if(b[i] == b[i+1] && (b[i] == 'A' || b[i] == 'C'))
		{
			b[i + 1] = '?';
			cont++;	
			i++; 
		}	 
	} 
	cout<<cont<<endl;
	
	return 0;
}