#include <iostream>
#define MAX 10001
using namespace std;
int N;
int total;
int mmax;
int ans;
int city[MAX];
inline int max(int a, int b) {
	return a > b ? a : b;
}
inline int check(int t) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (city[i] <= t) {
			res += city[i];
		}
		else {
			res += t;
		}

		if (res > total) return 0;
	}
	if (mmax < res && res <= total) {
		mmax = res;
		return 1;
	}
	else {
		return 0;
	}
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int amax = 0;
	for (int i = 0; i < N; i++) {
		cin >> city[i];
		amax = max(amax, city[i]);
	}
	cin >> total;

	int s = 0, e = amax, m;
	while (s <= e) {
		m = (s + e) / 2;
		if (check(m)) {
			ans = m;
			s = m + 1;
		}
		else {
			e = m - 1;	
		}
	}
	cout << ans << "\n";
}