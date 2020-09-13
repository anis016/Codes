#include<cstdio>
using namespace std;

int arrayList[] = {1,3,4,6,7,9,10,12};

bool bSearch(int leftRange, int rightRange, int value) {
	int midPoint = (leftRange + rightRange)/2;
	if(leftRange >= rightRange) {
		return false;
	} else if(arrayList[midPoint] == value) {
		return true;
	}
	
	if(arrayList[midPoint] > value) {
		rightRange = midPoint;
		bSearch(leftRange, rightRange, value);
	} else if (arrayList[midPoint] < value) {
		leftRange = midPoint + 1;
		bSearch(leftRange, rightRange, value);
	}
}

int main() {
	int key = 12;
	int length = 8;
	bool flag = false;

	flag = bSearch(0, length, key);

/*  Iterative Method
	int midPoint, leftRange, rightRange;
	leftRange = 0;
	rightRange = length;
	while(!flag) {
		midPoint = (rightRange+leftRange)/2;

		if(rightRange >= leftRange)
			break;

		if(arrayList[midPoint] > key) {
			rightRange = midPoint;
		} else if(arrayList[midPoint] < key) {
			leftRange = midPoint + 1;
		} else if(arrayList[midPoint] == key) {
			flag = true;
			break;
		}
	}
*/
	if(flag) {
		printf("found key\n");
	} else 
		printf("not found key\n");
}