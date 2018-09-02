#include <iostream>
#include <string.h>
#define MAX 10001
using namespace std;
struct Trie {
	bool finish; //끝나는 지점인지를 표시
	Trie *next[10]; //26가지 알파벳에 대한 트라이
	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(const char *key) {
		if (*key == '\0') {
			finish = true; //문자열이 끝나는 지점일 경우
		}
		else {
			int curr = *key - '0';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}
	bool find(const char *key) {
		if (*key == '\0') return 0;
		if (finish) {
			return 1;
		}
		int curr = *key - '0';
		return next[curr]->find(key + 1);
	}
};
int n, r;
char a[MAX][11];

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Trie *root = new Trie;
		r = 0;
		for (int i = 0; i < n; i++) {
			root->insert(a[i]);
		}
		for (int i = 0; i < n; i++) {
			if (root->find(a[i])) {
				r = 1;
			}
		}
		cout << (r == 1 ? "NO" : "YES") << "\n";
	}
}