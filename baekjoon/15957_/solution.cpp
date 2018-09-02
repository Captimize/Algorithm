#include <iostream>
#define MAX 100001
using namespace std;
int N, K, J;//곡의 수, 결과 데이터의 수, 목표점수
int parent[MAX];
int singer[MAX];
int score[MAX];
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> J;
	for (int i = 2; i <= N - 1; i++) {
		int a; cin >> a;
		parent[i] = a;	//i번 노드의 부모는 a
	}
	//각 노드에는 하위 노드의 수가 있어야함
}