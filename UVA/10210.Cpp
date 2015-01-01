#include <stdio.h>
#include <math.h>

main()
{
     double x1,x2,y1,y2,D,d1,d2,d_,cmd,enf,s1,s2;
     while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&cmd,&enf)!=EOF)
	{
     if(x1>=x2)
		d1=pow(x1-x2,2);
     else
     d1=pow(x2-x1,2);

     if(y1>=y2)
     d2=pow(y1-y2,2);
     else
     d2=pow(y2-y1,2);

     d_=sqrt(d1+d2);
     s1=d_/tan((cmd*2*acos(0))/180);
     s2=d_/tan((enf*2*acos(0))/180);

     printf("%.3lf\n",s1+s2);
    }
}

