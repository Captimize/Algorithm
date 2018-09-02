#include <iostream>
#include <queue>
#define INF 987654321
#define MAX 200002
using namespace std;
int s, e;
int ret;
bool visit[MAX];
struct Node {
	int cnt, x;
};
struct compare {
	inline bool operator() (const Node &n1, const Node &n2) {
		return n1.cnt > n2.cnt;
	}
};
inline int min(int a, int b) {
	return a > b ? b : a;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> e;
	if (s == e) {
		cout << "0" << "\n" << "0" << "\n";
		return 0;
	}
	ret = INF;
	queue<Node> q;
	q.push({ 0,s });
	while (!q.empty()) {
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		visit[x] = 1;
		if (x == e) {
			ret = min(ret, cnt);
		}

		if (x - 1 >= 0 && visit[x - 1]==0) {
			q.push({ cnt + 1, x - 1 });
		}
		if (x + 1 <= 100000 && visit[x + 1]==0) {
			q.push({ cnt + 1, x + 1 });
		}
		if (x * 2 <= 100000 && visit[x * 2]==0) {
			q.push({ cnt , x * 2 });
		}
	}
	cout << ret << "\n";
}