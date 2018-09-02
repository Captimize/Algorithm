#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;
int DAG[MAX];
int time[MAX];
int D[MAX];
int N;
vector<int> adj[MAX];
inline int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int t, m; cin >> t >> m;
		time[i] = t;
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			DAG[i] ++; //방향 노드
			adj[a].push_back(i);
		}
	}
	queue<int> q;
	for (int j = 1; j <= N; j++) {
		if (DAG[j] == 0) {
			D[j] = time[j];
			q.push(j);
		}
	}
	
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int next : adj[cur]) {
			D[next] = max(D[next], D[cur] + time[next]);
			DAG[next] --;
			if (DAG[next] == 0) {
				q.push(next);
			}
		}
	}
	int ans = D[1];
	for (int i = 2; i <= N; i++) {
		ans = max(ans, D[i]);
	}
	cout << ans << "\n";

}