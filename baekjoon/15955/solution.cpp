#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct checkPoint {
	int row, col;
};
vector<checkPoint> v;
map<checkPoint, int> m;
int N, M;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	v.resize(N + 1);
	m.
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		
		v[i].row = a;
		v[i].col = b;
	}

	for (int i = 0; i < M; i++) {
		int start, end, hp;
		cin >> start >> end >> hp;


	}
}