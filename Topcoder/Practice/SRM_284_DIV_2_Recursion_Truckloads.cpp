#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;

#define eps 1e-8
#define pinf (1<<30)
#define ninf -1*pinf
#define pi (2*acos(0.0))
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))

#define MAX 500

struct Truckloads{
int numTrucks(int numCrates, int loadSize)
{
	int ret = 0;
	int left, right;

	if(numCrates > loadSize) {
		if(numCrates%2 == 0) {
			right = numCrates/2;
			left = numCrates/2;

			ret += numTrucks(left, loadSize);
			ret += numTrucks(right, loadSize);
		} else {
			right = (numCrates+1)/2;
			left = (numCrates)/2;

			ret += numTrucks(left, loadSize);
			ret += numTrucks(right, loadSize);
		}
	} else {
		return 1;
	}

	return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 14; int Arg1 = 3; int Arg2 = 6; verify_case(0, Arg2, numTrucks(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 15; int Arg1 = 1; int Arg2 = 15; verify_case(1, Arg2, numTrucks(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1024; int Arg1 = 5; int Arg2 = 256; verify_case(2, Arg2, numTrucks(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
Truckloads ___test;
___test.run_test(-1);
return 0;
}
// END CUT HERE