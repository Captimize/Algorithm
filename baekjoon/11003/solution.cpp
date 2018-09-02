#include <iostream>
#include <string>
#define INF 1e9
#define MAX 5000001
using namespace std;

int N, L;
int D[MAX];
string out;
inline int min(int a, int b) {
	return a > b ? b : a;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> L;
	for (int i = 1; i <= N; i++) cin >> D[i];
	int minValue = INF;
	int s = 1, e = 1;
	for (; e <= N; ) {
		if (e <= L) {
			if (D[e] < minValue) {
				minValue = D[e];
			}
			else {

			}
			e++;
		}
	}
	cout << out << "\n";
}