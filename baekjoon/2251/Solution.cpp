#include <iostream>
#include <queue>
using namespace std;
int A, B, C;
bool visit[201][201][201];
bool ans[201];
struct Node {
	int a, b, c;
};
void Dfs(int a, int b, int c) {
	if (visit[a][b][c]) return;

	visit[a][b][c] = 1;
	if (a == 0) {
		ans[c] = 1;
	}
	//a ->b;
	if (a + b > B) {
		Dfs((a + b) - B, B, c);
	}
	else {
		Dfs(0, a + b, c);
	}

	//a->c
	if (a + c > C) {
		Dfs((a + c) - C, b, C);
	}
	else {
		Dfs(0, b, a + c);
	}

	//b->a
	if (a + b > A) {
		Dfs(A, (a+b)-A,c);
	}
	else {
		Dfs(a + b, 0, c);
	}

	//b ->c
	if (b + c > C) {
		Dfs(a, (b + c) - C, C);
	}
	else {
		Dfs(a, 0, b + c);
	}

	//c->a
	if (a + c > A) {
		Dfs(A, b, (c + a) - A);
	}
	else {
		Dfs(a + c, b, 0);
	}
	//c->b
	if (b + c > B) {
		Dfs(a, B, (b + c) - B);
	}
	else {
		Dfs(a, b + c, 0);
	}
	
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B >> C;
	Dfs(0, 0, C);

	for (int i = 0; i <= 200; i++) {
		if (ans[i]) {
			cout << i << " ";
		}
	}
}