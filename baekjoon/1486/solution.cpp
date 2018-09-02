#include <iostream>
#include <vector>
#define INF 987654321
#define MAX 26
using namespace std;
int N, M, T, D;
int map[MAX][MAX];
int DP[MAX][MAX];
struct Node {
	int v, w;
};
vector<Node> dd[MAX];
inline int min(int a, int b) {
	return a > b ? b : a;
}
void Dfs(int row, int col, int time) {

}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> T >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == j)continue;
			DP[i][j] = INF;
		}
	}
	for (register int i = 0; i < N; i++) {
		char tmp[MAX];
		cin >> tmp;
		for (register int j = 0; j < M; j++) {
			if (tmp[j] >= 'A' && tmp[j] <= 'Z') {
				DP[i][j] = min(DP[i][j], tmp[j] - 'A');
			}
			else if (tmp[j] >= 'a' && tmp[j] <= 'z') {
				DP[i][j] = min(DP[i][j], tmp[j] - 'a' + 26);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

		}
	}
}