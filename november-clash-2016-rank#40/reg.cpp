#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
#define nl cout<<"\n";
using namespace std;
struct trieNode
{
	bool isLeaf;
	std::map<char, trieNode*> children;
	trieNode()
	{
		isLeaf=false;
	}
}*root;
bool searchTrie(string);
trieNode* insertToTrie( string word)
{
	
	if(root== NULL)
	{
		root= new trieNode;
	}
	trieNode *temp;
	temp=root;
	for(int i=0;i< word.length();i++)
	{
		if(temp->children.count(word[i])==0) // no such key exists
		{
			temp->children[word[i]] = new trieNode; //create it
		}
		temp = temp-> children[word[i]]; // set new root as it's child
	}
	temp->isLeaf = true; // mark new word entry
	return temp;
}
bool searchTrie(string word)
{
	if(root==NULL)
		return false;
	trieNode* temp= root;
	for(int i=0;i< word.length();i++)
	{
		if(temp->children.count(word[i])==0) // no such key exists
		{
			return false;
		}
		temp = temp-> children[word[i]]; // set new root as it's child
	}
	//finished traversal through word[]
	if(temp->isLeaf)
		return true;
}
//*root= NULL;
int main()
{
	
	int n=0;
	cin>>n;
	string str;
	while(n--)
	{
		cin>>str;
		int i=0;
		if(searchTrie(str)) //username taken
		{
			while(searchTrie(str+to_string(i)))
			{
				i++;
			}
			str=str+to_string(i);
			insertToTrie(str);
			cout<<str; nl
		}
		else
		{
			insertToTrie(str);
			cout<<str; nl
		}	

	}
	return 0;
}