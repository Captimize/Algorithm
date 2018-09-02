#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
int pipe[MAX];
bool visit[MAX];
int N, L;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> pipe[i];
	sort(pipe, pipe + N);
	int res = 0;
	for (int i = 0; i < N; ) {
		if (!visit[i]) {
			res++;
			double area = pipe[i] - 0.5;
			double endline = area + L;
			while (area <= endline) {
				if (area <= pipe[i] && pipe[i] <= endline) {
					visit[i] = 1;
					i++;
				}
				area += 1.0;
			}
		}
		else {
			i++;
		}
	}
	cout << res << "\n";
}