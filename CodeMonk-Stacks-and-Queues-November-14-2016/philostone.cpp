#include "bits/stdc++.h"

/* useful utility macros */
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
#define printWholeArray(a) for(int(i)=0;(i)<int((sizeof(a)/sizeof(a[0])));i++) { cout<<(a[i])<<' ';}
#define repeat(n) for(int (i)=0;(i)<(int)(n);++(i)) //repeat n times
#define repeatBounds(l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i)) //repeat lower to upperbound
#define until(x,val) for(int(i) = int(x); int(x)!=int(val); (i<val)?x++:x--) //until x becomes val through increment or decrement

/*some constants*/
static const long double PI = 3.142857143;

/*some shorthands*/
typedef long long ll;
#define op cout<< // output to stdout
#define ip cin>> //input from stdin
#define err cerr<< //output to stderr
#define nl cout<<"\n"; //newline

using namespace std;
int main()
{
	stack<int> monkBag;
	queue<int> harryBag;
	int n,coin,q,x, monkBagSum=0;
	string query;
	ip n;
	until(n,0)
	{
		cin>>coin;
		harryBag.push(coin);
	}
	ip q>>x;
	until(q,0)
	{
		cin>>query;
		if(query == "Harry")
		{
			monkBagSum += harryBag.front();
			monkBag.push(harryBag.front());
			if(monkBagSum == x)
			{
				cout<<monkBag.size();
				exit(0);
			}
			harryBag.pop();
		}
		else if(query == "Remove")
		{
			coin=monkBag.top();
			monkBagSum-=coin;
			monkBag.pop();
		}
	}
	cout<<"-1";
	return 0;
}