#include <iostream>
#include <queue>
using namespace std;
struct compare {
	inline bool operator() (const int &n1, const int &n2) {
		return n1 < n2;
	}
};
int N;
priority_queue<int, vector<int>, compare> q;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n; cin >> n; q.push(n);
	}
	int res = 0;
	while (1) {
		int a = q.top(); q.pop();
		int b = q.top(); q.pop();
		res += (a*b);

		if (q.empty()) break;
		q.push(a + b);
	}
	cout << res << "\n";
}