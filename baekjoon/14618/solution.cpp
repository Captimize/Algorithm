#include <iostream>
#include <vector>
#include <queue>
#define MAX 5005
#define INF 2100000000
#define endl '\n'
using namespace std;
struct Node {
	int v, w;
};
int type[MAX]; //1이 A, 2가 B, 3이 진서집
int dist[MAX];
bool visit[MAX];
int jinseo;
int N, M, K;
vector<Node> vv[MAX];
inline int min(int a, int b) {
	return a > b ? b : a;
}
struct compare {
	inline bool operator() (const Node &n1, const Node &n2) {
		return n1.w > n2.w;
	}
};
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> jinseo;
	cin >> K;
	
	for (int i = 0; i < K; i++) {
		int n; cin >> n;
		type[n] = 1;
	}
	for (int i = 0; i < K; i++) {
		int n; cin >> n;
		type[n] = 2;
	}
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vv[u].push_back({ v,w });
		vv[v].push_back({ u,w });
	}
	fill(dist, dist + MAX, INF);
	priority_queue<Node, vector<Node>, compare> q;
	q.push({ jinseo ,0});//진서의 집에서 출발해서 가까운 거리로 갱신
	dist[jinseo] = 0;
	
	while (!q.empty()) {
		int cur;
		do {
			cur = q.top().v; q.pop();
		} while (!q.empty() && visit[cur]);
		if (visit[cur]) break;
		visit[cur] = 1;
		for (Node p : vv[cur]) {
			int next = p.v;
			int weigh = p.w;
			if (dist[next] > dist[cur] + weigh) {
				dist[next] = dist[cur] + weigh;
				q.push({ next ,dist[next]});
			}
		}
	}
	
	int min_a = INF;
	int min_b = INF;
	for (int i = 1; i <= N; i++) {
		if (type[i] == 1) {
			min_a = min(min_a, dist[i]);
		}
		else if (type[i] == 2) {
			min_b = min(min_b, dist[i]);
		}
	}
	if (min_a != INF || min_b != INF) {
		cout << (min_a > min_b ? 'B' : 'A') << endl;
		cout << min(min_a, min_b) << "\n";
	}
	else {
		cout << "-1" << "\n";
	}
	
}