#include <iostream>
#include <string.h>
#define MAX_N 10001
#define MAX 501
using namespace std;
char D[MAX_N][MAX];
char A[MAX_N][MAX];
int N, M;
struct Trie {
	bool finish;
	Trie *next[26];
	Trie() : finish(false) {
		fill(next, next + 26, nullptr);
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i]) {
				delete next[i];
			}
		}
	}
	void insert(const char *key) {
		if (*key == '\0') {
			finish = true;
		}
		else {
			int cur = *key - 'a';
			if (next[cur] == NULL) {
				next[cur] = new Trie();
			}
			next[cur]->insert(key + 1);
		}
	}
	inline int find(const char *key) {
		if (finish) {
			return 1;
		}
		if (*key == '\0') {//비교하고자 하는 키가 끝까지 왔다면 찾은거
			return 0;
		}
		int cur = *key - 'a';
		if (next[cur] == NULL) return 0;//만약에 찾고자 하는 값이 없다면?
		return next[cur]-> find(key + 1);
	}

};
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	Trie *root = new Trie();
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		root->insert(A[i]);
	}
	int ret = 0;
	for (int i = 0; i < M; i++) {
		cin >> D[i];
		ret += root->find(D[i]);
	}
	cout << ret;
}