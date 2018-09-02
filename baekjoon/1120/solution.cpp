#include <iostream>
#include <string>
#define INF 987654321
using namespace std;
string A, B;
int minValue;
inline int min(int a, int b) {
	return a > b ? b : a;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B;
	minValue = INF;
	for (int i = 0; i <= B.length() - A.length(); i++) {
		//가장 작게 차이나는 부분을 출력하면 끝
		int val = 0;
		for (int j = 0; j < A.length(); j++) {
			if (B[i + j] != A[j]) {
				val++;
			}
		}
		minValue = min(minValue, val);
	}
	cout << minValue << "\n";
}