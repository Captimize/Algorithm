#include <iostream>
#define MAX 101
using namespace std;

int N, M;
int ball[MAX];
inline void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
inline void init() {
	for (int i = 1; i <= N; i++) ball[i] = i;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		swap(ball[a], ball[b]);
	}
	for (int i = 1; i <= N; i++) cout << ball[i] << " ";
}