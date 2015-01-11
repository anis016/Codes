#include<cstdio>
using namespace std;

int operationP(int x, int y, int &add, int &sub) {
	int mul;

	add = x + y;
	sub = x - y;
	mul = x * y;

	return mul;
}

typedef struct point {
	int add;
	int sub;
	int mul;
}result;

result operationS(int x, int y) {
	result hold;

	hold.add = x+y;
	hold.mul = x*y;
	hold.sub = x-y;

	return hold;
}

int main() {

	int x = 2, y = 3;
	int add, sub, mul;
	result hold;
	
	mul = operationP(2, 3, add, sub);
	printf("Passing Parameters - \nAdd: %d\nSub: %d\nMul: %d\n", add, sub, mul);

	hold = operationS(x, y);
	printf("Structure - \nAdd: %d\nSub: %d\nMul: %d\n", hold.add, hold.sub, hold.mul);

	return 0;
}