#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;
struct Node {
	int num, gold, silver, bronze;
};
inline bool comp (const Node &n1, const Node &n2) {
	if (n1.gold > n2.gold) return true;
	else if (n1.gold == n2.gold) {
		if (n1.silver > n2.silver) return true;
		else if (n1.silver == n2.silver) return n1.bronze > n2.bronze;
		else return false;
	}
	else return false;
}
int score[MAX];
int N, K;
vector<Node> v;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	//input을 받는다 -> 정렬한다.
	//순위를 메긴다

	for (int i = 0; i < N; i++) {
		int num, g, s, b;
		cin >> num >> g >> s >> b;
		v.push_back({ num,g,s,b });
	}
	sort(v.begin(), v.end(), comp);
	int vSize = v.size();
	int g = 0, s = 0, b = 0;
	int ii = 0;
	int token = 0;
	for (int i = 0; i < vSize; i++) {
		if (v[i].gold != g || v[i].silver != s || v[i].bronze != b) {
			g = v[i].gold; s = v[i].silver; b = v[i].bronze;
			ii++;
			ii += token;
			score[v[i].num] = ii;
			token = 0;
		}
		else {
			//동점자의 수
			token++;
			score[v[i].num] = ii;
		}
		
		if (score[K] != 0) {
			cout << score[K] << "\n";
			return 0;
		}
	}
	
}