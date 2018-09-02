#include <iostream>
#include<vector>
#include <queue>
#define MAX 101
using namespace std;
vector<int> adj[MAX];
vector<vector<int>> solution(int n, vector<vector<int> > signs)
{
	vector<vector<int> > answer;
	answer.resize(n);
	for (register int i = 0; i < n; i++) {
		for (register int j = 0; j < n; j++) {
			if (signs[i][j]) {
				adj[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		queue<int> qq;
		qq.push(i);
		int pt = 0;
		bool v[MAX] = {false, };
		while (!qq.empty()) {
			int cur = qq.front(); qq.pop();
			for (int next : adj[cur]) {
				if (v[next]) continue;
				v[next] = 1;
				qq.push(next);
			}
		}
		for (int j = 0; j < n; j++) {
			if (v[j]) {
				answer[i].push_back(1);
			}
			else {
				answer[i].push_back(0);
			}
		}
	}
	return answer;
}
int main(void) {
	vector<vector<int>> d = solution(3, { {0,0,1}, {0,0,1}, {0,1,0} });

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}