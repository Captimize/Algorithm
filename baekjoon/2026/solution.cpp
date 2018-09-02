#include <iostream>
#include <string.h>
#include <vector>
#define MAX 910
using namespace std;
int N, K, F;
int map[MAX][MAX];
bool visit[MAX];
bool flag;
void Dfs(int cur, vector<int> v) {
	if (flag) return;
	visit[cur] = 1;
	v.push_back(cur);
	if (v.size() == K) {
		for (int i = 0; i < K; i++) {
			cout << v[i] << "\n";
		}
		flag = true;
		return;
	}
	else {
		for (int i = cur + 1; i <= N; i++) {
			if (!visit[i]) {
				bool f = false;
				for (int next : v) {
					if (!map[i][next]) {
						f = true;
						break;
					}
				}
				if (!f) {
					Dfs(i, v);
				}
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> K >> N >> F;
	for (int i = 0; i < F; i++) {
		int a, b; cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		vector<int> vv;
		Dfs(i, vv);
		if (flag) break;
	}
	if (!flag) {
		cout << "-1" << "\n";
	}
}