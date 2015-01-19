#include<cstdio>
using namespace std;

int arrayList[100];

void init() {
	int i;
	for(i=0;i<=100;i++)
		arrayList[i] =1;
}

int main() {

	int i, length = 100;

	init();

	for(i = 2; (i*i) < length; i++) {
		if(arrayList[i] == 1)
		for(int j = i*i; j < length; j+=i){
			arrayList[j] = 0;
		}
	}

	for(i = 2; i < length; i++) {
		if(arrayList[i] == 1)
			printf("%d ", i);
	}
	printf("\n");

	return 0;
}

/* More faster way

#define MAXP 31623

long a[MAXP], isPrime[MAXP];

long generatePrime() {
	long i, j, t, k;
	long M = (long)sqrt((double)MAXP);
	
	for(i=3; i<=M; i+=2) {
		if(a[i]==0)
			for(j=i*i;j<=MAXP;j=j+i+i) {
				a[j]=1;
			}
	}

	isPrime[0]=2;
	for(k=3, t=1; k <= MAXP; k=k+2) {
		if(a[k]==0) {
			isPrime[t]=k;
			t++;
		}
	}

	return t;
}

*/