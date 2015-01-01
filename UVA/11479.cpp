#include<stdio.h>

int main()
{
	long low, mid, high, i[4], j, count=1, t, l, p, s,e=0, test, z;

	for(s=0; s<4; s++)
		i[s]=0;

	scanf("%ld", &test);
	for(z=0; z<test; z++)
	{
	  for(j=0; j<3; j++)
	   scanf("%ld", &i[j]);
	
	 for(t=0;t<3;t++)
		for(l=0;l<2-t;l++)
			if(i[l]<i[l+1])
			{
				p=i[l];
				i[l]=i[l+1];
				i[l+1]=p;
			}
			
			high = i[0];
			mid  = i[1];
			low  = i[2];
			
			
			e=low+mid;

	  	
		        if( e<=high)
				printf("Case %ld: Invalid\n", count++);

			else if( (high==mid) && (mid==low) && (low==high) )
				printf("Case %ld: Equilateral\n", count++);

			else if( ( (high!=mid)&&(high==low) ) || ( (high!=low)&&(low==mid) ) || ( (mid!=low)&&(mid==high) ) )
				printf("Case %ld: Isosceles\n", count++);

			else if( e>high )
				printf("Case %ld: Scalene\n", count++);
			
	
	}
	
	return 0;
}

