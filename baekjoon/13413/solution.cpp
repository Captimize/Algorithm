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
	//B�� ������ W�� ������ ���� ���ٸ�, SWAP�ϴ°� �� ������.
	//������ B�� ������ W�� ������ ���� �ٸ��ٸ�, ���� ������ ��������Ѵ�.
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
			//�ٸ��� �ִٸ� �ϴ� ������ �� ���� ��ŭ�� �ٱ������
			cout << abs(aW - bW) + (res / 2) << "\n";
		}
	}
}