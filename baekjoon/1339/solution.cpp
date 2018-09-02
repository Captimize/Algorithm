#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int N;
vector<string> v;
int alpha[26];
int iidx;
int vSize;
int maxValue;
map<char, int > m;
inline int max(int a, int b) {
	return a > b ? a : b;
}
void Dfs(int cur, int select) {
	if (select < -1) return;
	if (cur == iidx) {
		int sum = 0;
		for (register int i = 0; i < vSize; i++) {
			int p = 1;
			string tmp;
			for (register int j = 0; j < v[i].length(); j++) {
				tmp += to_string(m[v[i][j]]);
			}
			//cout << tmp << "\n";
			sum += stoi(tmp);
		}
		maxValue = max(maxValue, sum);
		//cout << maxValue << "\n";
		return;
	}
	for (register int i = 0; i < 26; i++) {
		if (alpha[i] == 1) {
			alpha[i] = 0;
			m[i + 'A'] = select;
			Dfs(cur + 1, select - 1);
			alpha[i] = 1;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (register int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		v.push_back(tmp);
		for (register int j = 0; j < tmp.length(); j++) {
			alpha[tmp[j]-'A'] = 1;
		}
	}
	vSize = v.size();
	for (register int i = 0; i < 26; i++) {
		if (alpha[i]) iidx++;
	}
	Dfs(0, 9);
	cout << maxValue << "\n";
}