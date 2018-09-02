#include <iostream>
#include <string>
using namespace std;
int N;
bool ans[1001];//012 ~ 987 까지 총 10x9x8-> 720개
struct Result {
	int strike, ball;
};

inline bool compare(int number, int comp, int strike, int ball) {
	//n1이 기존의 수
	int sstrike = 0;
	int bball = 0;
	int n1 = (number / 100);
	int n2 = (number % 100) / 10;
	int n3 = (number % 100) % 10;
	//comp가 for문을 통해 생성된 수
	int m1 = (comp / 100);
	int m2 = (comp % 100) / 10;
	int m3 = (comp % 100) % 10;

	if (m1 == 0 || m2 == 0 || m3 == 0) return true;
	if (m1 == m2 || m2 == m3 || m1 == m3) return true;

	if (n1 == m1) sstrike++;
	if (n2 == m2) sstrike++;
	if (n3 == m3) sstrike++;

	if (n1 == m2 || n1 == m3) bball++;
	if (n2 == m1 || n2 == m3) bball++;
	if (n3 == m1 || n3 == m2) bball++;

	if (sstrike == strike && bball == ball) return false;
	return true;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int number, strike, ball;
		cin >> number >> strike >> ball;
		for (int j = 123; j <= 987; j++) {
			if (ans[j] == 0) {
				ans[j] = compare(number, j, strike, ball);
			}
		}
	}
	int res = 0;
	for (int j = 123; j <= 987; j++) {
		if (ans[j] == 0) {
			res++;
		}
	}
	cout << res << "\n";
}