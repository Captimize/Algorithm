#include <iostream>
#include <algorithm>
#define INF 987654321
#define MAX 10001
using namespace std;
int D[MAX];
int N;
inline bool comp(int a, int b) {
	return a > b;
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> D[i];
	sort(D, D + N, comp);
	//2장 고르는 경우
	int a1 = D[0] * D[1];
	int a2 = D[N - 1] * D[N - 2];
	int a3 = D[0] * D[N - 1];

	int maxValue1 = max(a1, max(a2, a3));
	//3장 고르는 경우
	int b1 = D[0] * D[1] * D[2];
	int b2 = D[0] * D[N - 1] * D[N - 2];
	int b3 = D[0] * D[1] * D[N - 1];
	int b4 = D[N - 1] * D[N - 2] * D[N - 3];
	int maxValue2 = max(b1, max(b2, max(b3, b4)));

	cout << max(maxValue1, maxValue2);
	
}