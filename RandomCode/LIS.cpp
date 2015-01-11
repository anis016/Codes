/* LIS (Longest Increasing Subsequence)
	   ------------------------------------
	   LIS(i) = 1 + MAX{LIS(j)}; i > j (j=i-1), A[i] > A[j]
	          = 1, if there is no such j
*/

#include<stdio.h>

int DP[10], LIS[10], Path[10];

int _max(int index) {
	int max = -1;
	for(int i = 0; i < index; i++) {
		if(LIS[i] > max)
			max = LIS[i];
	}
	return max;
}

void init(int length) {
	for(int i = 0; i < length; i++) {
		Path[i] = -1;
	}
}

int main() {

	int A[] = {10,22,9,33,21,50,41,60,80};
	int length = 9; // length of the array;
	int i, j, counter = 1;
	int index;

	init(length);
	DP[0] = 1;
	Path[0] = A[0];
	
	for(i = 1; i < length; i++) {
		index = 0;
		for(j = 0; j <= i-1; j++) {
			if(A[i] > A[j]) {
				LIS[index++] = DP[j];
			}
		}
		
		if(index) { // If any j exists
			int k = _max(index);
			DP[i] = 1 + k; // add the maximum of LIS(j)
			if(Path[k] == -1)
				Path[k] = A[i];
		}
		else {
			DP[i] = 1;
		}
	}

	printf("Longest Increasing Length: %d\n", DP[length-1]);

	return 0;
}