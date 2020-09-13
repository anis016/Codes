#include<stdio.h>
#include<math.h>

int main()
{
	long test, i;
    long double ab, ac, bc, r1, r2, r3, angle_a, angle_b, angle_c, hold, area_tri, area_a, area_b, area_c, area_circle, s, area, a, b, c;	

	scanf("%ld", &test);
	for(i=0; i<test; i++)
	{
	   scanf("%Lf %Lf %Lf", &r1, &r2, &r3);
	  
	   ab=r1+r2;
	   ac=r1+r3;
	   bc=r2+r3;

	   s=(ab+ac+bc)/2;

       a=s-ab;
	   b=s-bc;
	   c=s-ac;

	   hold= s*a*b*c;

	   area_tri=sqrt(hold);   /////area of the triangle

	  angle_a = acos(( ((bc)*(bc)) - ((ab)*(ab)) - ((ac)*(ac)) )/(-2*(ab)*(ac)) );
	  angle_b = acos(( ((ac)*(ac)) - ((ab)*(ab)) - ((bc)*(bc)) )/(-2*(ab)*(bc)) );
	  angle_c = acos(( ((ab)*(ab)) - ((ac)*(ac)) - ((bc)*(bc)) )/(-2*(ac)*(bc)) );

	  area_a= 0.5 * r1 * r1 * angle_a;
	  area_b= 0.5 * r2 * r2 * angle_b;
	  area_c= 0.5 * r3 * r3 * angle_c;

	  area_circle = area_a +area_b + area_c; 

 	  area = area_tri-area_circle;
	  printf("%Lf\n", area);
	
	}
	return 0;
}