#include <iostream>
#define MAX 1001
using namespace std;
int stack[MAX], top;
int A[MAX];
int N;
inline int binary_search(int t) {
	int s = 0, e = top, m, ret;
	while (e - s > 1) {
		m = (e + s) / 2;
		if (A[stack[m]] <= t) e = m;
		else s = m;
	}
	ret = e;
	if (A[stack[s]] <= t) ret = s;
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 1; i < N; i++) {
		if (A[stack[top]] > A[i]) {
			stack[++top] = i;
		}
		else {
			//가장 가깝게 큰 idx를 찾는다
			int idx = binary_search(A[i]);
			stack[idx] = i;
		}
	}
	cout << top + 1 << "\n";
}	