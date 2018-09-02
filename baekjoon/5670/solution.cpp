#include <cstdio>
#include <algorithm>
#define MAX 100001
using namespace std;

char D[MAX][81];
int T, N;
//어떤노드의 자식이 1개뿐이면, 자동완성으로 타이핑이 된다.
struct Trie {
	bool finish;
	int branch;
	Trie *next[26];

	Trie() : finish(false) , branch(0) {
		fill(next, next + 26, nullptr);
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(const char *key) {
		if (*key == '\0') {
			finish = true;
		}
		else {
			int cur = *key - 'a';
			if (next[cur] == NULL)
				next[cur] = new Trie(); 
			next[cur]->insert(key + 1);
		}
	}

};
int main(void) {
	while (scanf("%d", &N) != EOF) {
		Trie *root = new Trie();
		for (int i = 0; i < N; i++) {
			scanf("%s", &D[i]);
			root->insert(D[i]);
		}
		
	}
}