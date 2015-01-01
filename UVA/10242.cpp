#include<stdio.h>

int main()
{
    long double ax, bx, cx, dx, ay, by, cy, dy, final_x, final_y;
    
    while(scanf("%Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy)!=EOF)
    {
		final_x=final_y=0;

		if( (ax==bx) && (ay==by) )
		{
           final_x = cx+dx-ax;
           final_y = cy+dy-ay;
         
           printf("%.3Lf %.3Lf\n", final_x, final_y); 
		}

		else if( (bx==cx) && (by==cy) )
		{
		   final_x = ax+dx-bx;
           final_y = ay+dy-by;
         
           printf("%.3Lf %.3Lf\n", final_x, final_y); 
		}

		else if( (bx==dx) && (by==dy) )
		{
		   final_x = ax+cx-dx;
           final_y = ay+cy-dy;
         
           printf("%.3Lf %.3Lf\n", final_x, final_y); 
		}

		else if( (cx==dx) && (cy==dy) )
		{
		   final_x = ax+bx-cx;
           final_y = ay+by-cy;
         
           printf("%.3Lf %.3Lf\n", final_x, final_y); 
		}

		else if( (ax==dx) && (ay==dy) )
		{
		   final_x = cx+bx-ax;
           final_y = cy+by-ay;
         
           printf("%.3Lf %.3Lf\n", final_x, final_y); 
		}
		
		else if( (ax==cx) && (ay==cy) )
		{
		   final_x = dx+bx-ax;
           final_y = dy+by-ay;
         
           printf("%.3Lf %.3Lf\n", final_x, final_y); 
		}
    }
 return 0;   
}
