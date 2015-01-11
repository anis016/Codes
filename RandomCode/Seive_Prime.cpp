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