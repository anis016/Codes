#include<cstdio>
#include<iostream>
using namespace std;
#define MAX 100000

void Sort(long numbers[], long array_size)
{
  long i, j, index;

  for (i=1; i < array_size; i++)
  {
    index = numbers[i];
    j = i;
    while ((j > 0) && (numbers[j-1] > index))
    {
      numbers[j] = numbers[j-1];
      j = j - 1;
    }
    numbers[j] = index;
  }
}

long a[MAX];

int main()
{
    long in, odd, ho_1, ho_2, out, n;

	n=odd=ho_1=ho_2=out=0;
	while(scanf("%ld", &in)!=EOF)
	{
		a[n]=in;
		n++;
		
		Sort(a, n);
		if(n%2==1)
		{
			odd=(n+1)/2;
			cout<<a[odd-1]<<endl;
		}
		else if(n%2==0)
		{
			ho_1=a[(n/2)-1];
			ho_2=a[(n/2)];
			out=(ho_1+ho_2)/2;
			cout<<out<<endl;
		}
	}
 	return 0;
}
