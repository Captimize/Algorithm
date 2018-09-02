#include <iostream>
#include <string>
#define ll long long
#define MODULER 1000000009
using namespace std;
int N;
ll res;
void Dfs(int number) {
	if (number > N)return;
	if (number == N) {
		res++;
		res %= MODULER;
		return;
	}
	
	Dfs(number + 1);
	Dfs(number + 2);
	Dfs(number + 3);
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		res = 0;
		cin >> N;
		Dfs(0);
		cout << res << "\n";
	}
	
}