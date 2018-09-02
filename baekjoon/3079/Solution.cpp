#include <iostream>
#define MAX 100001
#define ll unsigned long long
using namespace std;
int N, M;
ll human[MAX];
inline ll min(int a, int b) {
	return a > b ? b : a;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//총 시간을 안다면, 반대로 나간 사람의 수을 알 수 있따.
	cin >> N >> M;
	ll max = 0;
	for (int i = 0; i < N; i++) {
		cin >> human[i];
		if (max < human[i]) {
			max = human[i];
		}
	}

	ll s = 0, e = M * max, m;
	ll res = e;
	while (s <= e) {
		m = (s + e) / 2;
		ll total = 0;
		for (int i = 0; i < N; i++) {
			total += (m / human[i]);
			if (total > M) break;
		}
		if (total < M) {
			s = m + 1;
		}	
		else {
			res = min(res, m);
			e = m - 1;
		}
	}
	cout << res << "\n";
}