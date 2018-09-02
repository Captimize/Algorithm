#include <iostream>
using namespace std;
int N, M,K;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	cout << K / M << " " << K % M << "\n";
}