#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 50001
using namespace std;
int N, T;
struct Node {
	int x, y;
};
inline int abs(int a) {
	return a < 0 ? -a : a;
}
inline bool range(Node a1, Node a2) {
	if (abs(a1.x - a2.x) <= 2 && abs(a1.y - a2.y) <= 2) {
		return true;
	}
	return false;
}

inline bool compare(const Node &n1, const Node &n2) {
	if (n1.x < n2.x) return true;
	else if (n1.x == n2.x) {
		if (n1.y < n2.y) return true;
		else return false;
	}
	else return false;
	
}
int visit[MAX];
vector<Node> v;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> T;
	v.push_back({ 0,0 });
	for (int i = 0; i < N; i++) {
		int xx, yy; cin >> xx >> yy;
		v.push_back({ xx,yy });
	}
	//X좌표를 기준으로 정렬을 시킨다. -> 
	sort(v.begin(), v.end(), compare);
	queue<int> q;
	q.push(0);
	visit[0] = 1;
	int res = -1;
	while (!q.empty()) {
		res++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cur = q.front(); q.pop();
			if (v[cur].y == T) {
				cout << res << "\n";
				return 0;
			}
			for (int i = cur; i <= N; i++) {
				if (!visit[i]) {
					if (range(v[cur], v[i])) {
						visit[i] = 1;
						q.push(i);
					}
					else if (!range(v[cur], v[i]))break;
				}
			}
			for (int i = cur; i >= 0; i--) {
				if (!visit[i]) {
					if (range(v[cur], v[i])) {
						visit[i] = 1;
						q.push(i);
					}
					else if (!range(v[cur], v[i]))break;
				}
			}
		}
	}
	cout << "-1" << "\n";
}