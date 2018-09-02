#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define MAX 500001
using namespace std;
int N;
vector<int> v[MAX];
int depth[MAX];
int child[MAX];
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b; 
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	ll ans = 0;
	int res = 0;
	fill(depth, depth + N+1, -1);
	depth[1] = 0;
	while (!q.empty()) {
		res++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cur = q.front(); q.pop();
			for (int next : v[cur]) {
				if (depth[next] == -1) {
					child[cur] = next;
					depth[next] = res;
					q.push(next);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (child[i] == 0) {
			ans += 
				depth[i];
		}
	}
	if (ans & 1) {
		//홀수 이면 성공
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}
	return 0;
}