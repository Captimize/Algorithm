#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define MAX 10001
#define INF 987654321234567
using namespace std;
struct Node {
	int v, w;
};
struct wrap {
	int v, k;
	ll w;
};
int N, M, K;
ll dist[MAX][21];
vector<Node> adj[MAX];
inline int min(int a, int b) {
	return a > b ? b : a;
}
struct comp {
	inline bool operator() (const wrap &n1, const wrap &n2) {
		return n1.w > n2.w;
	}
};
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	for (register int i = 1; i <= N; i++) {
		for (register int j = 0; j <= K; j++) {
			dist[i][j] = INF;
		}
	}
	
	for (register int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	priority_queue<wrap, vector<wrap>, comp> pq;
	pq.push({ 1,K, 0 });
	for (register int i = 0; i <= K; i++) dist[1][i] = 0;

	while (!pq.empty()) {
		int cur = pq.top().v;
		ll weigh = pq.top().w;
		int kk = pq.top().k;

		pq.pop();
		//if (weigh != dist[cur][kk]) continue;
		
		for (Node p : adj[cur]) {
			int next = p.v;
			int nextW = p.w;

			if (dist[next][kk] > weigh + nextW) {
				dist[next][kk] = weigh + nextW;
				pq.push({ next, kk, dist[next][kk] });
			}
			if (kk > 0) {
				if (dist[next][kk - 1] > weigh) {
					dist[next][kk - 1] = weigh;
					pq.push({ next, kk - 1, weigh });
				}
			}
		}
	}

	ll minValue = 987654321234567;
	for (register int i = 0; i <= K; i++) {
		minValue = min(dist[N][i], minValue);
	}
	cout << minValue << "\n";
}