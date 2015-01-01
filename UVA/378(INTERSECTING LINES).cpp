#include<stdio.h>

int main()
{
	long x1, x2, x3, x4, y1, y2, y3, y4;
	long up1, down, up2, count;
	float x, y;


	scanf("%ld", &count);

	printf("INTERSECTING LINES OUTPUT\n");
	while(count--)
	{
		scanf("%ld %ld %ld %ld %ld %ld %ld %ld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		
		up1=(x4-x3)*(y1-y3) - (y4-y3)*(x1-x3);
		up2=(x2-x1)*(y1-y3) - (y2-y1)*(x1-x3);
		
		
		down=(y4-y3)*(x2-x1) - (x4-x3)*(y2-y1);
		if( (up1==0) && (up2==0) && (down==0) )
		{
			printf("LINE\n");
			continue;
		}
		else if(down==0)
		{
			printf("NONE\n");
			continue;
		}
				
		x=float(x1) + ( float(up1)/float(down) )*float((x2 - x1));
		y=float(y1) + ( float(up1)/float(down) )*float((y2 - y1));
		
		printf("POINT %.2f %.2f\n", x, y);
	}
	printf("END OF OUTPUT\n");

	return 0;
}