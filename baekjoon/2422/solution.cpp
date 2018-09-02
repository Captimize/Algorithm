#include <iostream>
#include <vector>
#define MAX 205
using namespace std;
struct Node {
	int a, b;
};
int N, M;
int res;
int A[MAX];
vector<int> v[MAX];

void Dfs(int cur, int select) {
	if (cur > N+1) return;
	if (select == 3) {
		
		res++;
		return;
	}
	
	A[cur] = 1;
	for (int next : v[cur]) {
		if (A[next] == 1) {//같이 먹으면 안되는 조합이 있다면
			A[cur] = 0;
			Dfs(cur + 1, select);
			return;
		}
	}
	Dfs(cur + 1, select + 1);
	
	A[cur] = 0;
	Dfs(cur + 1, select);
	
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	Dfs(1, 0);
	cout << res << "\n";
}
