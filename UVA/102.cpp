#include<stdio.h>
#include<math.h>
#include<limits.h>

int main()
{
	int b[10];
	int temp,min,ans;

	while(scanf("%d%d%d%d%d%d%d%d%d",&b[1],&b[2],&b[3],&b[4],&b[5],&b[6],&b[7],&b[8],&b[9])==9)
	{
		min=INT_MAX;
		temp=b[4]+b[7]+b[3]+b[9]+b[2]+b[5]; 

		if(temp<min) 
		{
			min=temp;	
			ans=1;
		}

		temp=b[4]+b[7]+b[2]+b[8]+b[3]+b[6]; 
		if(temp < min) 
		{
			min=temp;	
			ans=2;
		}

		temp=b[6]+b[9]+b[1]+b[7]+b[2]+b[5]; 
		if(temp<min)
		{
			min=temp;	
			ans=5;
		}

		temp=b[6]+b[9]+b[2]+b[8]+b[1]+b[4]; 
		if(temp<min)
		{
			min=temp;	
			ans=6;
		}

		temp=b[5]+b[8]+b[1]+b[7]+b[3]+b[6]; 
		if(temp<min) 
		{
			min=temp;	
			ans=4;
		}
		
		temp=b[5]+b[8]+b[3]+b[9]+b[1]+b[4]; 
		if(temp<min) 	
		{
			min=temp;	
			ans=3;
		}
		
		switch(ans)
		{
			case 1:
				printf("BCG %d\n", min);
				break;
			case 2:
				printf("BGC %d\n", min);
				break;
			case 3:
				printf("GCB %d\n", min);
				break;
			case 4:
				printf("GBC %d\n", min);
				break;
			case 5:
				printf("CBG %d\n", min);
				break;
			case 6:
				printf("CGB %d\n", min);
				break;
			default:
				break;
		}
	}
	return 0;
}
