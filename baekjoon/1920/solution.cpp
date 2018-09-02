#include <iostream>
#include <string>
#include <map>
#define MAX 100001
using namespace std;
map<int, int> m;
int N, M;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	string output;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		m[n] = 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int n; cin >> n;
		if (m[n]) {
			output += "1\n";
		}
		else {
			output += "0\n";
		}
	}
	cout << output;
}