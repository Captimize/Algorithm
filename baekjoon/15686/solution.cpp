#include <iostream>
#include <vector>
#define INF 987654321
#define MAX 51
using namespace std;
struct Node {
	int row, col;
};
int N, M;
int vSize;
int A[14];
int ans;
vector<Node> house;
vector<Node> chiken;
inline int abs(int a) {
	return a < 0 ? -a : a;
}
inline int dist(int a1, int b1, int a2, int b2) {
	return abs(a1 - a2) + abs(b1 - b2);
}
inline int min(int a, int b) {
	return a > b ? b : a;
}
inline int check() {
	
	int hSize = house.size();
	int res = 0;
	for (register int i = 0; i < hSize; i++) {
		int minValue = INF;
		
		for (register int j = 0; j < vSize; j++) {
			if (A[j] == 1) {
				int tmp = dist(house[i].row, house[i].col, chiken[j].row, chiken[j].col);
				minValue = min(minValue, tmp);
			}
		}
		res += minValue;
	}
	return res;
}
void Dfs(int idx, int select) {
	if (idx > vSize) return;
	if (select == M) {
		int tmp = check();
		ans = min(ans, tmp);
		return;
	}

	A[idx] = 1;
	Dfs(idx + 1, select + 1);
	A[idx] = 0;
	Dfs(idx + 1, select);

}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	ans = INF;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			int numb; cin >> numb;
			if (numb == 1) {
				house.push_back({ i,j });
			}
			else if (numb == 2){
				chiken.push_back({ i,j });
			}
		}
	}
	vSize = chiken.size();
	Dfs(0, 0);
	cout << ans << "\n";
}