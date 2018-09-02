#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
vector<string> v;
inline bool asc() {
	for (register int i = 1; i < N; i++) {
		if (v[i - 1] > v[i])return false;
	}
	return true;
}
inline bool desc() {
	for (register int i = 1; i < N; i++) {
		if (v[i - 1] < v[i]) return false;
	}
	return true;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (register int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		v.push_back(tmp);
	}
	if (asc()) {
		cout << "INCREASING" << "\n";
	}
	else if (desc()) {
		cout << "DECREASING" << "\n";
	}
	else {
		cout << "NEITHER" << "\n";
	}
}