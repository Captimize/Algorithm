#include <iostream>
#include <string>
#include <map>
#define ll long long
using namespace std;
ll N;
map<ll, int> m;
bool flag;
inline void f(ll t) {
	if (m[t] == 1) {
		return;
	}
	m[t] = 1;
	string input = to_string(t);
	int sum = 0;
	for (int i = 0; i < input.length(); i++) {
		sum += ((input[i] - '0') * (input[i] - '0'));
	}
	if (sum == 1) {
		flag = true;
		return;
	}
	else {
		f(sum);
	}
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	f(N);

	cout << (flag == 1 ? "HAPPY" : "UNHAPPY") << "\n";
}