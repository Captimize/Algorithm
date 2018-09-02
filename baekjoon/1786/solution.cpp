#include <cstring>
#include <stdio.h>
#include <cstdio>
#include <vector>
#define MAX 1000002
using namespace std;
char W[MAX], S[MAX];
int failure[MAX] = { 0, };
int N, M;
vector<int> v;
int main(void) {
	gets_s(W);
	gets_s(S);
	N = strlen(W);
	M = strlen(S);
	
	for (int i = 0, j = 0; i < N; i++) {
		while (j > 0 && W[i] != S[j]) j = failure[j - 1];

		if (W[i] == S[j]) {
			if (j == M - 1) {
				v.push_back(i - M + 2);
				j = failure[j];
			}
			else {
				j++;
			}
		}
	}

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
}
