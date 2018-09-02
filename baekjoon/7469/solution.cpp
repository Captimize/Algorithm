#include <iostream>
#define MAX 100001
using namespace std;
int N, K;
int D[MAX];
int dT[MAX];

void mergeSort(int s, int m, int e) {
	int i = s;
	int j = m + 1;
	int k = s;//임시 배열의 시작점
	int tmp_v[MAX];
	while (i <= m && j <= e) {
		tmp_v[k++] = (dT[i] > dT[j] ? dT[j++] : dT[i++]);
	}
	int mm = (i > m) ? j : i;
	int nn = (i > m) ? e : m;

	for (; mm <= nn; mm++) {
		tmp_v[k++] = dT[mm];
	}
	for (mm = s; mm <= e; mm++) dT[mm] = tmp_v[mm];
}

void merge(int start, int end) {
	int mid = (start + end) / 2;
	if (start < end) {
		merge(start, mid);
		merge(mid + 1, end);
		mergeSort(start, mid, end);
	}
}
inline int Q(int i, int j, int q) {
	int idx = 0;
	for (; i <= j; i++) dT[idx++] = D[i];
	merge(0, idx-1);

	return dT[q];
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> D[i];
	for (int i = 0; i < K; i++) {
		int a, b, q; cin >> a >> b >> q;
		cout << Q(a - 1, b - 1, q - 1) << "\n";
	}
	
}