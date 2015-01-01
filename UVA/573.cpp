#include<stdio.h>

int main()
{
	float H, D, F, U;
	long  flag=0, count=0;
	float fatig, hf, dis_climbed, height_slid, height_climb, init_height, sum;

		while(scanf("%f %f %f %f",&H, &U, &D, &F)!=EOF)
		{
		  if(H==0)
			  break;

		fatig=hf=dis_climbed=height_climb=init_height=height_slid=sum=0;
		flag=0;
		count=0;

		dis_climbed=U;
		fatig=(F*U)/100;

		while(1)
		{
			++count;

			height_climb=init_height+dis_climbed;			
			if(height_climb>H)
			{
				flag=1;
				break;
			}

			height_slid=height_climb-D;
			init_height=height_slid;
			
			if(init_height<0)
			{
				flag=2;
				break;
			}

			dis_climbed=dis_climbed-fatig;	
			if(dis_climbed<0.0)
				dis_climbed=0.0;
		}

		if(flag==1)
			printf("success on day %ld\n", count);
		else if(flag==2)
			printf("failure on day %ld\n", count);
	}
	return 0;
}
