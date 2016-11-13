#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define nl cout<<"\n";
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
using namespace std;
string replaceString(string original, char a, string txt)
{
	string result= string();
	for (int i = 0; i < original.length(); ++i)
	{
		if(original[i]!=a)
			result+=original[i];
		else
			result+=txt;
	}
	return result;
}
int main()
{
	int n,q1,q2;
	cin>>n>>q1>>q2;
	string original;
	cin>>original;
	char a;
	string substitute;
	int query;
	for (int i = 0; i < q1; ++i)
	{
		cin>>a;
		cin>>substitute;
		original= replaceString(original,a,substitute);
	}
	for (int i = 0; i < q2; ++i)
	{
		cin>>query;
		if(query<= original.length())
			cout<<original[query-1]; nl
		else
			cout<<"none"; nl
	}
	//cout<<original;
	return 0;
}