#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { //cout<<(a[i])<<' ';}
#define nl cout<<"\n";
using namespace std;
int** a; //dynamic 2d array for the board
#define MARKED -2
#define OBSTACLE -1
#define ROOK -3
bool isOutOfBounds(int x,int y, int n,int m)
{
	if(x<0 || x >= n || y <0 || y >= m)
		return true;
	return false;
}
int findAvailablePosition(int** &a, int n, int m, int row=0) //find vacant pos on passed row after and including the given column.
{
	int min=INT_MAX, m_index;
	for (int i = 0; i < m; ++i)
	{
		if(a[row][i]>=0 && a[row][i] < min)
		{
			min= a[row][i];
			m_index=i;
		}
	}
	if(min==INT_MAX)
		return -1;
	else
		return m_index;
}
bool markPath(int** &a,int n, int m, int row,int col) // mark all the x's on the passed (row,col) co-ordinates on the board. return bool indicates success or failure
{

	if(a[row][col] == MARKED || a[row][col] == ROOK)
	{
		return false; //trying to mark a non-vacant position
	}
	a[row][col]=ROOK; //mark it with rook.
	int lp=col-1, rp=col+1;
	while(!isOutOfBounds(row,lp,n,m) && a[row][lp]!=OBSTACLE)
		a[row][lp--]=MARKED;
	while(!isOutOfBounds(row,rp,n,m) && a[row][rp]!=OBSTACLE)
		a[row][rp++]=MARKED;
	int up=row-1, dp=row+1;
	while(!isOutOfBounds(up,col,n,m) && a[up][col]!=OBSTACLE)
		a[up--][col]=MARKED;
	while(!isOutOfBounds(dp,col,n,m) && a[dp][col]!=OBSTACLE)
		a[dp++][col]=MARKED;
	return true;
}
int countThreats(int** &a,int n, int m, int row,int col) // mark all the x's on the passed (row,col) co-ordinates on the board. return bool indicates success or failure
{
	int count=0;
	int lp=col-1, rp=col+1;
	while(!isOutOfBounds(row,lp,n,m) && a[row][lp]!=OBSTACLE)
	{
		count++;
		lp--;
	}
	while(!isOutOfBounds(row,rp,n,m) && a[row][rp]!=OBSTACLE)
	{
		count++;
		rp++;
	}
	int up=row-1, dp=row+1;
	while(!isOutOfBounds(up,col,n,m) && a[up][col]!=OBSTACLE)
	{
		count++;
		up--;
	}
	while(!isOutOfBounds(dp,col,n,m) && a[dp][col]!=OBSTACLE)
	{
		count++;
		dp--;
	}
	return count;
}
bool defineScores(int** a, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(a[i][j]!= OBSTACLE)
				a[i][j]= countThreats(a,n,m,i,j);
		}
	}
}
int defineObstacles(int n, int m)
{
	int r,c;
	cin>>r>>c;
	if(!isOutOfBounds(r-1,c-1,n,m))
		a[r-1][c-1]=OBSTACLE;
}
int countRooks(int** a,int n, int m)
{
	int currentRow=0,rookCount=0, pos;
	while(currentRow != n)
	{
		pos=findAvailablePosition(a,n,m,currentRow);
		while(pos!=-1)
		{
			markPath(a,n,m,currentRow,pos);
			rookCount++;
			pos=findAvailablePosition(a,n,m,currentRow);
		}
		currentRow++;
	}
	return rookCount;

}
int main()
{
	int t=0,m,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		a = new int*[n];
		for (int i = 0; i < n; ++i)
			a[i]= new int[m];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				a[i][j]=0; //initially set all positions to be vacant
		while(k--)
			defineObstacles(n,m);
		//printMatrix(a,n,m); nl
		//markPath(a,n,m,2,2);
		defineScores(a,n,m);
		cout<<countRooks(a,n,m); nl
	}
	return 0;
}
