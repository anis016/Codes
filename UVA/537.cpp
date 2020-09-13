#include<stdio.h>
#include<string.h>
#define MAX 10000000

char num[2][MAX];
char chp1, chp2, pref1, pref2, ch;
double C, P, V;

void init()
{
	long i = 0;

	ch = 0;
	chp1 = 0;
	chp2 = 0;
	pref1 = 0;
	pref2 = 0;
	P = 0.00000;
	C = 0.00000;
	V = 0.00000;

	for(i=0; i<1000; i++)
	{
		num[0][i] =  0;
		num[1][i] =  0;
	}
	return ;
}

void read_input()
{
	long i, flag;

	i = flag = 0;
	while(1)
	{
		ch = getchar();

		if(ch == '\n')
			break;
		else if(ch == '=')
		{
			i = 0;
			while(1)
			{
				ch = getchar();
				if(ch >= '0' && ch <= '9' || ch == '.')
					num[0][i++] = ch;
				else
				{
					if(ch == 'm' || ch == 'k' || ch == 'M')
					{
						pref1 = ch;
						ch = getchar();
					}
					chp1 = ch;
					break;
				}
			}

			while(1)
			{
				ch = getchar();
				
				if(ch == '\n')
				{
					flag = 1;
					break;
				}
				else if(ch == '=')
				{
					i = 0;
					while(1)
					{
						ch = getchar();
						if(ch >= '0' && ch <= '9' || ch == '.')
							num[1][i++] = ch;
						else
						{
							if(ch == 'm' || ch == 'k' || ch == 'M')
							{
								pref2 = ch;
								ch = getchar();
							}
							chp2 = ch;
							break;
						}
					}
				}

//				if(chp2)
//					break;
			}
		}
		if(flag == 1)
			break;
//		if(chp1 && chp2)
//		     break;
	}
	return ;
}

double convert(char *s)
{
	double c = 0.000;

	sscanf(s, "%lf", &c);
	
	return c;
}

double multiply(char s, double d)
{
	double a = 0.000;

	if(s == 'm')
		a = d * 0.001;
	else if(s == 'k')
		a = d * 1000;
	else if(s == 'M')
		a = d * 1000000;
	else 
		a = d * 1.000;

	return a;
}

void from_str_to_deci()
{
	if(chp1 == 'A')  // current
	{
		C = convert(num[0]);
		C = multiply(pref1, C);
	}

	else if(chp1 == 'W')  // power
	{
		P = convert(num[0]);
		P = multiply(pref1, P);
	}

	else if(chp1 == 'V')  // voltage
	{
		V = convert(num[0]);
		V = multiply(pref1, V);
	}

	if(chp2 == 'A')  // current
	{
		C = convert(num[1]);
		C = multiply(pref2, C);
	}

	else if(chp2 == 'W')  // power
	{
		P = convert(num[1]);
		P = multiply(pref2, P);
	}

	else if(chp2 == 'V')  // voltage
	{
		V = convert(num[1]);
		V = multiply(pref2, V);
	}

	return ;
}

void process()
{
	if( (chp1 == 'A' && chp2 == 'V') || (chp2 == 'A' && chp1 == 'V') )
	{
		P = C * V;
		printf("P=%.2lfW\n", P);
		return ;
	}
	else if( (chp1 == 'A' && chp2 == 'W') || (chp2 == 'A' && chp1 == 'W') )
	{
		V = P / C;
		printf("U=%.2lfV\n", V);
		return ;
	}
	else if( (chp1 == 'V' && chp2 == 'W') || (chp2 == 'V' && chp1 == 'W') )
	{
		C = P / V;
		printf("I=%.2lfA\n", C);
		return ;
	}
}

int main()
{
//	freopen("in.txt", "r", stdin);

	static char buf[MAX];
	long i;
	long N;

	gets(buf);
	sscanf(buf, "%ld", &N);
	for(i=1; i<=N; i++)
	{
		init();
		read_input();
		from_str_to_deci();

		printf("Problem #%ld\n", i);
		process();
		printf("\n");
	}
	return 0;
}
