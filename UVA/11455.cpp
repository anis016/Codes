#include<stdio.h>

int main()
{
	long low,  high, i[7], j, t, l, p, e=0, test, z,  mid1,mid2;

    scanf("%lld", &test);
	for(z=0; z<test; z++)
	{
	  for(j=0; j<4; j++)
	  scanf("%ld", &i[j]);
	
	 for(t=0;t<4;t++)
		for(l=0;l<3-t;l++)
			if(i[l]<i[l+1])
			{
				p=i[l];
				i[l]=i[l+1];
				i[l+1]=p;
			}
			
			high  = i[0];
			mid1  = i[1];
			mid2  = i[2];
			low   = i[3];
	     		
			
			if( (high==mid1) && (mid1==mid2) && (mid2==low) )
				printf("square\n");

			else if( (high==mid1) && (mid2==low) )
				printf("rectangle\n");

			else if( e>high )
				printf("quadrangle\n");
			
			else if( e<=high || high==0 || mid1==0 || low==0 || mid2==0)
				printf("banana\n");
			
			
	}
	
	return 0;
}

/* code dat i sumbitted any1 finds mistake in my coded i shall give him a choclate
#include<stdio.h>
int main()
{
    
    long  long int a=4,w,x,y,z,i,j,t,xx[7];
	int m,n;
	scanf("%d",&n);
	for(m=1;m<=n;m++)
	{
		for(i=0;i<a;i++)
			scanf("%lld",&xx[i]);
		
		for(i=1;i<a;i++)
			for(j=1;j<=a-i;j++)
				if(xx[j-1]>xx[j])
				{ 
					t=xx[j-1];
                    xx[j-1]=xx[j];
	                xx[j]=t;
				} 
				w=xx[0];    
				x=xx[1];
                y=xx[2];
				z=xx[3];

				if(w==x && x==y && y==z)
					printf("square\n");
				else if(w==x && y==z)
					printf("rectangle\n");
				else if(w+x+y>z)
					printf("quadrangle\n");
				else if((w+x+y)<=z||w<=0||x<=0||y<=0||z<=0)
					printf("banana\n");
	}
 return 0;
}

*/
