#include <iostream>
#define MAX 100001
using namespace std;
int N;
int Tree[MAX * 4];
inline int getIdx(int N) {
	int idx = 1;
	for (; idx <= N; idx *= 2);

	return idx;
}
void init(int t) {
	while (t >= 1) {
		Tree[t] = Tree[2 * t] + Tree[2 * t + 1];
		t--;
	}
}
inline int query(int a, int b) {
	int s = a, e = b, ret=0;
	while (s <= e) {
		if (s % 2 == 1) ret += Tree[s];
		if (e % 2 == 0) ret += Tree[e];

		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int idx = getIdx(N);
	for (int i = 0; i < N; i++) cin >> Tree[idx + i];
	idx--;
	init(idx);
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		cout << query(a+idx, b+idx) << "\n";
	}
}