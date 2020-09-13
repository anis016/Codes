#include<stdio.h>
#include<string.h>
#include<math.h>

void find_s_a_for_u_v_t(double st, double nd, double rd)
{
	double v, u, s, a, t;

	v = u = s = a = t = 0;

	u = st;
	v = nd;
	t = rd;

	a=(v-u) / t;
	s=(u*t) + (0.50 * a * t * t);

	printf("%.3lf %.3lf\n", s, a);

	return ;
}

void find_s_t_for_u_v_a(double st, double nd, double rd)
{
	double v, u, s, a, t;

	v = u = s = a = t = 0;
	
	u = st;
	v = nd;
	a = rd;


	s=( (v * v) - (u * u) )/ (2 * a);
	t=(v - u) / a;

	printf("%.3lf %.3lf\n", s, t);

	return ;
}

void find_v_t_for_u_a_s(double st, double nd, double rd)
{
	double v, u, s, a, t;

	v = u = s = a = t = 0;
	
	u = st;
	a = nd;
	s = rd;


	v= sqrt((u * u) + (2 * a * s));
	t=(v - u) / a;

	printf("%.3lf %.3lf\n", v, t);

	return ;
}

void find_u_t_for_v_a_s(double st, double nd, double rd)
{
	double v, u, s, a, t;

	v = u = s = a = t = 0;
	
	v = st;
	a = nd;
	s = rd;


	u= sqrt((v * v) - (2 * a * s));
	t=(v - u) / a;

	printf("%.3lf %.3lf\n", u, t);

	return ;
}

int main()
{
	double st, nd, rd;
	long n, count;

	count=1;
	while(scanf("%ld", &n), n)
	{
		scanf("%lf %lf %lf", &st, &nd, &rd);
		
		printf("Case %ld: ", count++); 
		if(n==1)
			find_s_a_for_u_v_t(st, nd, rd);
		else if(n==2)
			find_s_t_for_u_v_a(st, nd, rd);
		else if(n==3)
			find_v_t_for_u_a_s(st, nd, rd);
		else if(n==4)
			find_u_t_for_v_a_s(st, nd, rd);
	}

	return 0;
}