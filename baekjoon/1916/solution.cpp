#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;
int N, M;
int sp, ep;
int D[MAX];
bool visit[MAX];
const int INF = 987654321;
struct Node {
	int v, w;
};
struct compare {
	inline bool operator() (const Node &n1, const Node &n2) {
		return n1.w > n2.w;
	}
};
vector<Node> adj[MAX];
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i ++ ) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		//adj[v].push_back({ u,w });
	}
	cin >> sp >> ep;
	fill(D, D + MAX, INF);
	priority_queue<Node, vector<Node> , compare> q;
	q.push({sp, 0});
	D[sp] = 0;
	while (!q.empty()) {
		int cur = q.top().v;;
		int weigh = q.top().w;
		q.pop();
		visit[cur] = 1;
		for (Node p : adj[cur]) {
			int next = p.v;
			int next_weigh = p.w;

			if (visit[next]) continue;
			if (D[next] > D[cur] + next_weigh) {
				D[next] = D[cur] + next_weigh;
				q.push({ next, D[next] });
 			}
		}
	}
	cout << D[ep];
}