#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#include <queue>
#define MAX 10001
#define INF 987654321
using namespace std;
int N, K;
int vSize;
bool visit[1002];
struct p {
	int idx, kk;
};
vector<pair<int,int>> v;
inline int distance(int a1, int b1, int a2, int b2) {
	int x = a2 - a1;
	int y = b2 - b1;
	return (int)ceil(sqrt(x*x + y*y) / 10);
}
inline bool paramertic(int t) {
	queue<p> q;
	q.push({ 0,0});
	memset(visit, false, sizeof(visit));
	visit[0] = 1;
	while (!q.empty()) {
		int idx = q.front().idx;
		int kk = q.front().kk;
		q.pop();
		if (idx == vSize - 1) {
			if(kk <= K+1)return true;
			else return false;
		}
		int row = v[idx].first;
		int col = v[idx].second;
		for (int i = 1; i < vSize; i++) {
			if (visit[i]) continue;
			
			int nextRow = v[i].first;
			int nextCol = v[i].second;
			if (distance(row, col, nextRow, nextCol) <= t) {
				visit[i] = true;
				q.push({ i, kk +1 });
			}
		}
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	v.push_back({ 0,0 });
	for (int i = 0; i < N; i++) {
		int r, c; cin >> r >> c;
		v.push_back({ r,c });
	}
	v.push_back({ 10000, 10000 });
	
	vSize = v.size();
	int s = 1, e = distance(0,0,10000,10000), m;
	while (s <= e) {
		m = (s + e) / 2;
		if (paramertic(m)) {
			e = m-1;
		}
		else {
			s = m+1;
		}
	}
	cout << s << "\n";
}