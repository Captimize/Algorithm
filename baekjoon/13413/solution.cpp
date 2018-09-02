#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
int N;
string A, B;
inline int abs(int a) {
	return a < 0 ? -a : a;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//B의 개수와 W의 개수가 서로 같다면, SWAP하는게 더 빠르다.
	//하지만 B의 개수와 W의 개수가 서로 다르다면, 같을 때까지 뒤집어야한다.
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		cin >> A;
		cin >> B;
		int aSize = A.size();
		int bSize = B.size();
		int res = 0;
		int aW = 0;
		int bW = 0;
		for (int i = 0; i < aSize; i++) {
			if (A[i] != B[i]) {
				res++;
			}
			if (A[i] == 'W') {
				aW++;
			}
			if (B[i] == 'W') {
				bW++;
			}
		}
		if (aW == bW) {
			cout << res / 2 << "\n";
		}
		else {
			//다른게 있다면 일단 무조건 그 차이 만큼은 바까줘야함
			cout << abs(aW - bW) + (res / 2) << "\n";
		}
	}
}