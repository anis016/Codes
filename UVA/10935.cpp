#include<iostream>
#include<queue>             /// First In First Out
//#include<stack>           /// Last In First Out
using namespace std;

#define MAX 1000

int main()
{
	int n, j, hold=0, a, t=0, i;
	int array[MAX];

	while(cin>>n)
	{
	  if(n==0)
		break;

	 queue<int>input;                    /// for queue alwayz initialize inside the loop

	 memset(array, '0', sizeof(array));
	 hold=t=a=0;

	 for(i=1; i<=n; i++)
		 input.push(i);
	
	 j=0;
  	 while(input.size()!=1)
	 {
		array[j++]=input.front();        /// first deck is holding
		input.pop();                     /// popping out
	    a=input.front();                 /// a contains the next deck
		input.pop();                     /// popped out
		input.push(a);                   /// inserted to back side
	 }
	
	 hold=input.front();

	 if(n==1)
		 printf("Discarded cards:");    //// critical , i hate PE
	 else
	     printf("Discarded cards: ");
	 
	 for(i=0, t=j; i<j; i++)
	 {
	   printf("%d", array[i]);
	   
	   if( (t-1)!=0)                    /// important for output....
	   {
		  printf(", ");
		  t--;
	   }
	 }
	 printf("\n");	
	 printf("Remaining card: ");
	 printf("%d\n", hold);

	}
	
	return 0;
}