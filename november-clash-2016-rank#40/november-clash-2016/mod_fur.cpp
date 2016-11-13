#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define nl cout<<"\n";
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
using namespace std;

map<int,vector<int> > connections;
int maxDepth= INT_MIN;
set<int> visited;

void explore(int source , int depth=0)
{

	visited.insert(source);
	for (vector<int>::iterator it = connections[source].begin(); it!= connections[source].end(); ++it)
	{	
		if(visited.count( *it )==0)
				explore( *it ,depth+1);
		if(depth>maxDepth)
				maxDepth=depth;
	}
	return;
}

int main()
{
	int n=5,q=0;
	cin>>n>>q;
	int type, arg1,arg2, count=0, nv=0;
	for (int i = 0; i < q; ++i)
	{
		cin>>type;
		if(type==1)
		{
			cin>>arg1>>arg2;
			connections[arg1].push_back(arg2);
			connections[arg2].push_back(arg1);
			//printConns();

		}
		else if(type ==2)
		{
			cin>>arg1;
			explore(arg1,0);
			(maxDepth<0)?cout<<'0':cout<<maxDepth; nl
			maxDepth=INT_MIN;
			
		}
		arg1=0;
		arg2=0;
		type=0;
		visited.clear();
	}
	//printGraph(graph,n);
	return 0;
}