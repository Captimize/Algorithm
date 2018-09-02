#include <iostream>
#define MAX 1000001
using namespace std;
int D[MAX];
int N, M;
void init() {
	for (int i = 1; i <= N; i++) D[i] = i;
}
inline int find(int a) {
	if (D[a] == a) return a;
	else return D[a] = find(D[a]);
}
void merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	D[pb] = pa;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++) {
		int command, a, b;
		cin >> command >> a >> b;
		if (command == 0) {
			merge(a, b);
		}
		else {
			int pa = find(a);
			int pb = find(b);
			if (pa == pb) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
}