#include <iostream>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define MAX 500001
using namespace std;
string N;
int remote[10];
inline int min(int a, int b) {
	return a > b ? b : a;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	fill(remote, remote + 10, true);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int cur;
		cin >> cur;
		remote[cur] = false;
	}
	if (N == "100") {
		cout << "0" << "\n";
		return 0;
	}

	string cur = "";
	queue<string> q;

	q.push(cur);
	while (!q.empty()) {
		
	}
}