#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define nl cout<<"\n";
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
using namespace std;
int main()
{
	int t=0,x=0,l=0,n=0, mana=0;
	cin>>t;
	while(t--)
	{
		cin>>x>>l>>n;
		/*while(x<l || n==0)
		{
			mana++;
			x=x*2;
			n--;
		}
		if(n==0)
		{
			cout<<mana; nl
		}
		else
			cout<<'0'; nl*/
		int i=x-1;
		if(n!=0)
			while(!(pow(i,n)<l))
			{
				i--;
			}
		else
		{
			cout<<'0'; nl
			continue;
		}
		cout<<i; nl

	}
	return 0;
}