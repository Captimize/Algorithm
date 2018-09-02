#include <iostream>
#define INF 987654321
#define MAX 101
using namespace std;
int N, M;
int minValue;
int day[MAX];
int D[MAX][MAX];
inline int min(int a, int b) {
	return a > b ? b : a;
}
inline int Dfs(int cur, int coupon) {
	if (coupon < 0) return INF;
	if (cur > N) {
		return 0;
	}
	if (D[cur][coupon] != -1) return D[cur][coupon];
	if (day[cur]) {
		D[cur][coupon] = Dfs(cur + 1, coupon);
	}
	else {
		D[cur][coupon] = min(Dfs(cur+1,coupon-3), min(Dfs(cur+1, coupon) + 10000,min(Dfs(cur+3,coupon+1)+25000, Dfs(cur+5,coupon+2)+37000)));
	}
	return D[cur][coupon];
}
int main(void) {
		ios_base::sync_with_stdio(0); cin.tie(0);
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
		int a; cin >> a;
		day[a] = 1;
	}
	fill(D[0], D[MAX], -1);
	cout << Dfs(1, 0);;
}


