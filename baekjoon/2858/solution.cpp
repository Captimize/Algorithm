#include <iostream>
#include <cmath>
using namespace std;
int R, B;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> R >> B;
	int total = R + B;
	int l, w;
	for (int i = 3; i <= sqrt(total); i++) {
		if (total % i == 0) {
			l = (total / i), w = i;
			if (B == (l - 2) * (w - 2)) {
				cout << l << " " << w << "\n";
				return 0;
			}
		}
	}
}