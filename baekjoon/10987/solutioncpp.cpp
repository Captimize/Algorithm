#include <iostream>
#define MAX 101
using namespace std;
char input[MAX];
int idx = 0;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> input;
	int res = 0;
	while (input[idx] != '\0') {
		if (input[idx] == 'a' || input[idx] == 'e' || input[idx] == 'i' || input[idx] == 'o' || input[idx] == 'u') res++;
		idx++;
	}
	cout << res << '\n';
}