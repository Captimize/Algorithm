#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#define MAX 500001
using namespace std;
struct ListNode {
	int prev, cur, next;
};
int N, M;
int A[MAX];
int stack[MAX], top;
ListNode node[MAX];
vector<string> v;
inline int binary_search(int t) {
	int s = 0, e = top, m, ret;
	while (e - s > 1) {
		m = (e + s) / 2;
		if (A[stack[m]] >= t) e = m;
		else s = m;
	}
	ret = e;
	if (A[stack[s]] >= t) ret = s;
	return ret;
}
inline int binary_search2(int t) {
	int s = 0, e = top, m, ret;
	while (e - s > 1) {
		m = (e + s) / 2;
		if (A[stack[m]] <= t) e = m;
		else s = m;
	}
	ret = e;
	if (A[stack[s]] <= t) ret = s;
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
		node[0].next = 1;
		for (int i = 1; i <= N; i++) {
			node[i].prev = i - 1;
			node[i].cur = i;
			node[i].next = i + 1;
		}
		int idx = 1;
		for (int i = 0; i < M; i++) {
			char command;
			int a, b;
			cin >> command >> a >> b;
			ListNode tmpNode = node[a];
			node[node[a].next].prev = node[node[a].cur].prev;
			node[node[a].prev].next = node[node[a].cur].next;
			if (command == 'A') {
				node[node[b].prev].next = node[a].cur;
				node[a].prev = node[b].prev;
				node[b].prev = node[a].cur;
				node[a].next = node[b].cur;
			}
			else {
				node[node[b].next].prev = node[a].cur;
				node[a].next = node[b].next;
				node[b].next = node[a].cur;
				node[a].prev = node[b].cur;
			}

		}
		//for (int i = 1; i <= N; i++) {
		//	cout << node[i].prev << " " << node[i].cur << " " << node[i].next << "\n";
		//}
		for (int i = 1; i <= N; i++) {
			if (node[i].prev == 0) {
				idx = i;
				break;
			}
		}
		
		int token = 0;
		while (idx <= N) {
			A[token++] = node[idx].cur;
			idx = node[idx].next;
		}

		for (int i = 1; i < N; i++) {
			if (A[stack[top]] < A[i]) {
				stack[++top] = i;
			}
			else {
				int idx = binary_search(A[i]);
				string input = "A " + to_string(A[i]) + " " + to_string(A[stack[idx]]);
				v.push_back(input);
				stack[idx] = i;
			}
		}
		int vSize = v.size();
		cout << vSize << "\n";
		for (int i = 0; i < vSize; i++) {
			cout << v[i] << "\n";
		}
}