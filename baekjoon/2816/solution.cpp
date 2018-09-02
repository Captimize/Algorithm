#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
vector<string> v;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		v.push_back(input);
	}
	//먼저 KBS1의 위치를 찾은뒤, ans.append("1");
	//KBS1이 0일떄까지 ans.append("4");

	//
	int vsize = v.size();
	string ans = "";
	int cursor=0;
	for (; v[cursor] != "KBS1"; cursor++) {
		ans.append("1");
	}



	while (v[0] != "KBS1") {
		ans.append("4");
		swap(v[cursor], v[cursor - 1]);
		cursor = cursor -1;
	}
	for (; v[cursor] != "KBS2"; cursor++) {
		ans.append("1");
	}
	while (v[1] != "KBS2") {
		ans.append("4");
		swap(v[cursor], v[cursor - 1]);
		cursor = cursor - 1;
	}
	cout << ans << "\n";
}
