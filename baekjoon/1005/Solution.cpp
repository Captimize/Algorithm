#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;
int N, K,W;
int structure[MAX];
bool visit[MAX];
int D[MAX];
int topology[MAX];
inline int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fill(visit, visit + MAX, 0);
		fill(topology, topology + MAX, 0);
		fill(D, D + MAX, 0);
		vector<int> adj[MAX];
		cin >> N >> K;
		for (int i = 1; i <= N; i++) cin >> structure[i];

		for (int i = 0; i < K; i++) {
			int u, v; 
			cin >> u >> v;
			adj[u].push_back(v);
			topology[v]++;
		}
		cin >> W;
		queue<int> q;
		//���� ��尡 ���� ���� �־��ش�.
		for (int i = 1; i <= N; i++) {
			if (topology[i] == 0) {
				q.push(i);
			}
		}
		//��ǥ�ϴ� ��尡 0�̸� ���̻� ���ŵ� ������ ����.
		while (topology[W] > 0) {
			int cur = q.front(); q.pop();
			for (int next : adj[cur]) {
				//���� ����� ���� ���� ���� ū������ ���� �Ǿ���Ѵ�.
				D[next] = max(D[next], D[cur] + structure[cur]);
				if (--topology[next] == 0) q.push(next);
			}
		}

		cout << D[W] + structure[W] << "\n";
	}
}