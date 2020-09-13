#include<cstdio>
using namespace std;

int main() {
	int arrayList[] = {5,2,4,6,1,3};
	int i, j, length = 6;
/*
	// increasing order
	for(i = 1; i < length; i++) {					// loop till length n
		int key = arrayList[i];							// get the key (the number needs to be inserted)
		for(j = i; j >= 0; j--) {						// loop from the ith index down to 0 
			if(key < arrayList[j-1]) {						// find the number if it is greater then the keyelement
				arrayList[j] = arrayList[j-1];					// replace the current element with previous element -|
				arrayList[j-1] = key;							// replace the previous element with the key element -| -> does the shifting
			}												//
		}												//
	}												//
*/
	// decreasing order
	for(i = 1; i < length; i++) {
		int key = arrayList[i];
		for(j = i-1; j >= 0; j--) {
			if(key > arrayList[j]) {
				arrayList[j+1] = arrayList[j];
				arrayList[j] = key;
			}
		}
	}

	for(i = 0; i < length; i++)
		printf("%d ", arrayList[i]);
	printf("\n");

	return 0;
}