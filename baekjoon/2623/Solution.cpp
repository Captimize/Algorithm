#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;
int N, M;
int DAG[MAX];
bool visit[MAX];
vector<int> adj[MAX];
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int m; cin >> m;
		int start=0;
		for (int j = 0; j < m-1; j++) {
			if (start == 0) {
				int a, b; cin >> a >> b;
				adj[a].push_back(b);
				start = b;
				DAG[b] ++;
			}
			else {
				int b; cin >> b;
				adj[start].push_back(b);
				DAG[b]++;
				start = b;
			}
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (DAG[i] == 0) {
			q.push(i);
			visit[i] = 1;
		}
	}
	
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << "\n";

		//현재 지점과 연결된 노드를 죽인다.
		for (int next : adj[cur]) {
			DAG[next]--;
		}

		for (int j = 1; j <= N; j++) {
			if (visit[j]) continue;
			if (DAG[j] == 0) {
				q.push(j);
			}
		}
	}
}