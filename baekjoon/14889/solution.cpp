#include <iostream>
#define MAX 21
#define INF 987654321
using namespace std;
int N;
int map[MAX][MAX];
int D[MAX];
int minValue;
inline int abs(int a) {
	return a < 0 ? -a : a;
}
inline int check() {
	int sum1 = 0;
	int sum2 = 0;
	// 1 1 1 0 0 0 
	// S11 + S12 + S13 + S21+ S22+S23 + S31+S32+S33
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (D[j] && D[i]) {
				sum1 += map[i][j];
			}
			if (!D[j] && !D[i]) {
				sum2 += map[i][j];
			}
		}
	}
	return abs(sum1 - sum2);
}
inline int min(int a, int b) {
	return a > b ? b : a;
}
void print() {
	cout << "======================" << "\n";
	for (int i = 0; i < N; i++) {
		if (D[i]) {
			cout << "бс";
		}
		else {
			cout << "бр";
		}
	}
	cout << "\n";
}
void Dfs(int cur, int select) {
	if (cur > N -1) return;
	if (select == N / 2) {
		//print();
		int a = check();
		minValue = min(minValue, a);
		return;
	}

	D[cur] = 1;
	Dfs(cur + 1, select + 1);
	D[cur] = 0;
	Dfs(cur + 1, select);
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	minValue = INF;
	Dfs(0, 0);
	cout << minValue;
}