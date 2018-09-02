#include <iostream>
#define MAX 1026
using namespace std;
int N;
int D[MAX];
int A[MAX];
int idx;
inline int pow(int k) {
	int ret = 1;
	for (int i = 1; i <= k; i++) ret *= 2;
	return ret ;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int k = pow(N);
	for (int i = 0; i < k; i++) {

	}
}