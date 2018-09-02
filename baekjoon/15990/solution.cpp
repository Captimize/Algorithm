#include <iostream>
#define MODULER 1000000009
#define MAX 100001
#define ll unsigned long long
using namespace std;
ll D[MAX];
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	//d[1] = 1
	//d[2] = 1
	//d[3] = 2
	//d[4] = 3
	//d[5] = 4
	//d[6] 
	//1 2 1 2


	for (int tc = 1; tc <= T; tc++) {
		int N; cin >> N;
		cout << D[N] << "\n";
	}
}