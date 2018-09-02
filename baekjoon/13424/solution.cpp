#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
#define INF 987654321
using namespace std;
int N, M;
int D[MAX];
bool visit[MAX];
struct Node {
	int v, w;
};
struct compare {
	inline bool operator() (const Node &n1, const Node &n2) {
		return n1.w > n2.w;
	}
};

priority_queue<Node, vector<Node>, compare> q;
inline int min(int a, int b) {
	return a > b ? b : a;
}
inline void dijkstra(int sp, vector<Node> adj[MAX]) {
	q.push({ sp, 0 });
	fill(D, D + MAX, INF);
	fill(visit, visit + MAX, 0);
	D[sp] = 0;
	while (!q.empty()) {
		int cur = q.top().v;
		int weigh = q.top().w;
		q.pop();
		visit[cur] = 1;
		for (Node p : adj[cur]) {
			int next = p.v;
			int next_weigh = p.w;
			if (visit[next])continue;
			if (D[next] > D[cur] + next_weigh) {
				D[next] = D[cur] + next_weigh;
				q.push({ next, D[next] });
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		vector<Node> adj[MAX];
		for (int i = 0; i < M; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({ v,w });
			adj[v].push_back({ u,w });
		}
		int K; cin >> K;
		vector<int> fri;
		for (int i = 0; i < K; i++) {
			int a; cin >> a;
			fri.push_back(a);
		}
		int minValue = INF;
		int minIdx=0;
		for (int i = 1; i <= N; i++) {
			dijkstra(i, adj);
			int sum = 0;
			for (int j = 0; j < fri.size(); j++) {
				sum += D[fri[j]];
			}
			if (sum < minValue) {
				minValue = sum;
				minIdx = i;
			}
		}

		cout << minIdx << "\n";
		fri.clear();
	}
}