#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;
int N, M;
int color[MAX];
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fill(color, color + MAX, 0);
		cin >> N >> M;
		vector<int> adj[MAX];
		int a, b;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		queue<int> q;
		q.push(a);
		color[a] = 1;
		bool flag = false;
		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int next : adj[cur]) {
				if (color[next] == 0) {
					if (color[cur] == 1) {
						color[next] = 2;
					}
					else {
						color[next] = 1;
					}
					q.push(next);
				}
				else {
					if (color[cur] == 1 && color[next] == 1) {
						flag = true;
						while (!q.empty()) q.pop();
						break;
					}
					else if (color[cur] == 2 && color[next] == 2) {
						flag = true;
						while (!q.empty()) q.pop();
						break;
					}
				}
			}
		}
		adj->clear();
		
		cout << (flag  ? "impossible" : "possible") << "\n";
	}
}