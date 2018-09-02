#include <iostream>
#define MAX 1000001
#define ll long long
using namespace std;
int N, M, K;
ll tree[MAX * 4];
inline int getIdx(int t) {
	int ret = 1;
	for (; ret < t; ret *= 2);
	return ret;
}
void update(int idx) {
	while (idx > 0) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx--;
	}
}
inline ll sum(int s, int e) {
	
	ll ret = 0;
	while (s <= e) {
		if (s % 2 == 1) ret += tree[s];
		if (e % 2 == 0) ret += tree[e];
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	int tree_idx = getIdx(N);
	for (int i = 0; i < N; i++) cin >> tree[tree_idx + i];
	tree_idx--;
	update(tree_idx);
	
	for (int i = 0; i < M + K; i++) {
		int command;
		cin >> command;

		if (command == 1) {
			//b번쨰 수부터 c번쨰 수에 d로 더한다.

		}
		else {
			int a, int b;
			cin >> a >> b;
			cout << sum(a + tree_idx, b + tree_idx) << "\n";
		}
	}
}