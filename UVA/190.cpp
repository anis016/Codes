#include<stdio.h>
#include<math.h>

int main()
{
	double x,y,x1,y1,x2,y2,x3,y3,equ1[3][2],equ2[3][2],equ3[3][2],e,q,u,alpha,beta,r,c,com;
	long i,j;

	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
	{
		equ1[0][0]=-2*x1;
		equ1[1][0]=-2*y1;
		equ1[2][0]=(x1*x1)+(y1*y1);
		equ2[0][0]=-2*x2;
		equ2[1][0]=-2*y2;
		equ2[2][0]=(x2*x2)+(y2*y2);
		equ3[0][0]=-2*x3;
		equ3[1][0]=-2*y3;
		equ3[2][0]=(x3*x3)+(y3*y3);

		e=equ1[0][0];
		q=equ1[1][0];
		u=equ1[2][0];

		equ1[0][0]=e-equ2[0][0];
		equ1[1][0]=q-equ2[1][0];
		equ1[2][0]=-(u-equ2[2][0]);
		equ2[0][0]=e-equ3[0][0];
		equ2[1][0]=q-equ3[1][0];
		equ2[2][0]=-(u-equ3[2][0]);

		com=(equ1[0][0]*equ2[1][0])-(equ1[1][0]*equ2[0][0]);
		alpha=((equ1[1][0]*equ2[2][0])-(equ1[2][0]*equ2[1][0]))/com;
		beta=-((equ1[0][0]*equ2[2][0])-(equ1[2][0]*equ2[0][0]))/com;

		r=sqrt((x1+alpha)*(x1+alpha)+(y1+beta)*(y1+beta));

		printf("(x ");
		if(alpha<0)
			printf("- %.3lf)^2 + (y ",-alpha);
		else
			printf("+ %.3lf)^2 + (y ",alpha);
		if(beta<0)
			printf("- %.3lf)^2 = ",-beta);
		else
			printf("+ %.3lf)^2 = ",beta);
		printf("%.3lf^2\n",r);

		c=(alpha*alpha)+(beta*beta)-(r*r);

		printf("x^2 + y^2 ");
		if(alpha<0)
			printf("- %.3lfx ",-(2*alpha));
		else
			printf("+ %.3lfx ",2*alpha);
		if(beta<0)
			printf("- %.3lfy ",-(2*beta));
		else
			printf("+ %.3lfy ",2*beta);
		if(c<0)
			printf("- %.3lf = 0\n\n",-c);
		else
			printf("+ %.3lf = 0\n\n",c);

	}

	return 0;
}