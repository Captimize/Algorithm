#include <iostream>
#include <queue>
#include <map>
#define INF 100001
#define MAX 200002
using namespace std;
int s, e;
int D[MAX];
int M[MAX];
struct Node {
	int cnt, x;
};
inline int min(int a, int b) {
	return a > b ? b : a;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> e;
	queue<Node> q;
	q.push({0, s});
	//D[s] = 1;
	int ret = 987654321;
	if (s == e) {
		cout << 0 << "\n" << 1;
		return 0;
	}
	while (!q.empty()) {	
		int qSize = q.size();
		//if (minValue < res) break;
		for (register int i = 0; i < qSize; i++) {
			int cnt = q.front().cnt;
			int x = q.front().x;
			q.pop();
			
			D[x] = 1;
			if (x == e) {
				M[cnt] ++;
				ret = min(ret, cnt);
			}
			
			if (x - 1 >= 0 && D[x - 1] == 0) {
				q.push({ cnt + 1, x - 1 });
			}
			if (x + 1 <= 100001 && D[x + 1] == 0) {
				q.push({ cnt + 1, x + 1 });
			}
			if (x * 2 <= 100001 && D[x * 2] == 0) {
				q.push({ cnt + 1, x * 2 });
			}
		}
	}
	cout << ret << "\n" << M[ret] << "\n";
}
