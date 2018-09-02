#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;
int N, K, M;
vector<int> hypo[MAX];
bool visit[MAX];
struct Node {
	int cur, k;
};
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a;
		for (int j = 1; j < K; j++) {
			cin >> b;
			hypo[a].push_back(b);
			hypo[b].push_back(a);
			a = b;
		}
	}
	queue<Node> q;
	q.push({ 1, 0});
	visit[1] = 1;
	while (!q.empty()) {
		int qSize = q.size();
		
		for (int i = 0; i < qSize; i++) {
			int ccur = q.front().cur; 
			int kk = q.front().k;
			q.pop();
			if (ccur == N) {
				cout << kk << "\n";
				return 0;
			}
			for (int next : hypo[ccur]) {
				if (!visit[next]) {
					visit[next] = 1;
					q.push({ next, kk + 1 });
				}
			}
		}
	}
	cout << "-1" << "\n";
	return 0;
}