#include<stdio.h>
#include<string.h>
#define MAX 2000

char alpha[150];
long num[150];

char buf[MAX], out[MAX];
char temp[MAX];

void init()
{
	num[65] = -1, num[66] = -1, num[67] = -1;
	num[69] = -1, num[70] = -1, num[71] = -1;
	num[72] = -1, num[73] = -1, num[74] = -1;
	num[75] = -1, num[76] = -1, num[77] = -1;
	num[78] = -1, num[79] = -1, num[80] = -1;
	num[81] = -1, num[82] = -1, num[83] = -1;
	num[84] = -1, num[85] = -1, num[86] = -1;
	num[87] = -1, num[88] = -1, num[89] = -1;
	num[90] = -1, num[68] = -1;

	num[97] = -1, num[98] = -1, num[99] = -1;
	num[101] = -1, num[102] = -1, num[103] = -1;
	num[104] = -1, num[105] = -1, num[106] = -1;
	num[107] = -1, num[108] = -1, num[109] = -1;
	num[110] = -1, num[111] = -1, num[112] = -1;
	num[113] = -1, num[114] = -1, num[115] = -1;
	num[116] = -1, num[117] = -1, num[118] = -1;
	num[119] = -1, num[120] = -1, num[121] = -1;
	num[122] = -1, num[100] = -1;

	num[32] = -1, num[33] = -1, num[44] = -1;
    num[46] = -1, num[58] = -1, num[59] = -1;
    num[63] = -1;

	alpha['A'] = 65, alpha['B'] = 66, alpha['C'] = 67;
	alpha['D'] = 68, alpha['E'] = 69, alpha['F'] = 70;
	alpha['G'] = 71, alpha['H'] = 72, alpha['I'] = 73;
	alpha['J'] = 74, alpha['K'] = 75, alpha['L'] = 76;
	alpha['M'] = 77, alpha['N'] = 78, alpha['O'] = 79;
	alpha['P'] = 80, alpha['Q'] = 81, alpha['R'] = 82;
	alpha['S'] = 83, alpha['T'] = 84, alpha['U'] = 85;
	alpha['V'] = 86, alpha['W'] = 87, alpha['X'] = 88;
	alpha['Y'] = 89, alpha['Z'] = 90;

	alpha['a'] = 97, alpha['b'] = 98, alpha['c'] = 99;
	alpha['d'] = 100, alpha['e'] = 101, alpha['f'] = 102;
	alpha['g'] = 103, alpha['h'] = 104, alpha['i'] = 105;
	alpha['j'] = 106, alpha['k'] = 107, alpha['l'] = 108;
	alpha['m'] = 109, alpha['n'] = 110, alpha['o'] = 111;
	alpha['p'] = 112, alpha['q'] = 113, alpha['r'] = 114;
	alpha['s'] = 115, alpha['t'] = 116, alpha['u'] = 117;
	alpha['v'] = 118, alpha['w'] = 119, alpha['x'] = 120;
	alpha['y'] = 121, alpha['z'] = 122;

	alpha[' '] = 32, alpha['!'] = 33, alpha[','] = 44;
    alpha['.'] = 46, alpha[':'] = 58, alpha[';'] = 59;
    alpha['?'] = 63;
}

int Strrev(char *Str)
{
	char Temp[10000]={'\0'};
	int l=strlen(Str),i;
	for(i=0;i<l;i++)
	{
		Temp[i]=Str[l-i-1];
	}
	Temp[i]='\0';
	strcpy(Str,Temp);
	return 0;
}

bool is_digit(char ch)
{
	if(ch >= '0' && ch <= '9')
		return true;
	return false;
}

void init_temp()
{
	long i;

	for(i=0; i<5; i++)
		temp[i] = 0;
}

int main()
{
//	freopen("in.txt", "r", stdin);
	long i, j, len, n, m, a;
	
	init();
	
	while(gets(buf))
	{
		Strrev(buf);
		len = strlen(buf);
		for(i=0, j=0; i<len; )
		{
			if( is_digit(buf[i]) == true)
			{
				temp[0] = buf[i++];
				temp[1] = buf[i];
				sscanf(temp, "%ld", &n);

				if(num[n] != -1)
				{
					i++;
					temp[2] = buf[i];
					sscanf(temp, "%ld", &n);
				}			
				out[j++] = char(n);
				i++;
				init_temp();
			}
			else 
			{
				m = long(alpha[buf[i]]);
				while(m!=0)
				{
					a = m % 10;
					out[j++] = (char) a + 48;
					m = m / 10;
				}
				i++;
			}
		}
		out[j] = '\0';
		puts(out);
	}
	return 0;
}