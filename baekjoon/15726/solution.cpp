#include <iostream>
#define ll long long
using namespace std;
ll A, B, C;
inline ll max(ll a, ll b) {
	return a > b ? a : b;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B >> C;

	ll a = (double)A * B / C;
	ll b = (double)A / B * C;
	cout << max(a,b);
	return 0;
}