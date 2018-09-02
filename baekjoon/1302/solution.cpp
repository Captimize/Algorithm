#include <iostream>
#include <map>
#include <string>
using namespace std;
int N;
map<string, int> m;
int maxValue;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input; cin >> input;
		if (!m[input]) {
			m[input] = 1;
		}
		else {
			m[input] ++;
		}
		if (m[input] > maxValue) {
			maxValue = m[input];
		}
	}
	
	for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
		if (it->second == maxValue) {
			cout << it->first << "\n";
			return 0;
		}
	}
}