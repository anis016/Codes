#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	long G, L, Case;

	cin>>Case;
	while(Case--)
	{
		cin>>G>>L;
		if( (L%G)==0)
		{
			cout<<G<<" "<<L<<endl;
		}
		else
		{
			cout<<"-1"<<endl;
		}
	}
	
	return 0;
}