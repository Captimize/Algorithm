#include <stdio.h>
#include <cstring>
#include <cstdio>
#define MAX 2501
using namespace std;
int ret;
char W[MAX], S[MAX];
int main(void) {
	gets_s(W);
	gets_s(S);
	int N = strlen(W);
	int M = strlen(S);
	
	for (int i = 0; i <= N-M; i++) {
		bool found = true;
		int j;
		for (j = 0; j < M; j++) {
			if (W[i + j] != S[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			i += j;
			i--;
			ret++;
		}

	}
	printf("%d", ret);
}