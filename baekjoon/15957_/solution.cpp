#include <iostream>
#define MAX 100001
using namespace std;
int N, K, J;//���� ��, ��� �������� ��, ��ǥ����
int parent[MAX];
int singer[MAX];
int score[MAX];
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> J;
	for (int i = 2; i <= N - 1; i++) {
		int a; cin >> a;
		parent[i] = a;	//i�� ����� �θ�� a
	}
	//�� ��忡�� ���� ����� ���� �־����
}