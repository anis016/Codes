#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int a1, a2, b1, b2, c1, c2, ho1, ho2, lod, cal1, cal2;
	float x, y;

	while(1)
	{
		a1=a2=b1=b2=c1=c2=ho1=ho2=lod=cal1=cal2=0;
		x=y=0.00;

		scanf("%d %d %d", &a1, &b1, &c1);
		scanf("%d %d %d", &a2, &b2, &c2);

		if( (a1+a2+b1+b2+c1+c2)==0)
			break;
		else
		{
			ho1=a1*b2;
			ho2=a2*b1; 

			if(ho1==ho2)
				printf("No fixed point exists.\n");
			else
			{
				lod=ho1-ho2;
				cal1=(-b1*c2+b2*c1);
				cal2=(-c1*a2+c2*a1);

				x=float(cal1)/float(lod);
				y=float(cal2)/float(lod);

				printf("The fixed point is at %.2f %.2f.\n", x, y);
			}
		}
	}
	return 0;
}
//0.26190476190476
//0.19047619047619
