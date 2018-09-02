#include <iostream>
#include <queue>
#define MAX 26
using namespace std;
int R, C;
char map[MAX][MAX];
bool connect[MAX][MAX][4];
bool visit[MAX][MAX];
struct Node {
	int row, col;
};
Node node[2];
queue<Node> q;
const int dRow[] = {-1, 0, 1, 0};
const int dCol[] = {0, -1, 0, 1};
inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r > R - 1 || c > C - 1) return true;
	return false;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		char tmp[MAX];
		cin >> tmp;
		for (int j = 1; j <= C; j++) {
			map[i][j] = tmp[j - 1];
			//���� ��ġ (i,j)�� ���ؼ� ���� ���� �ִ��� ���θ� check�մϴ�. ���࿡, (i-1, j)���� ���� �ö���� (i,j)�� �Ǵµ� �̶� (i-1,j)�� ��������
			//���� �����̴��� ���θ� �Ǵ��մϴ�
			if (map[i][j] == 'M') {
				node[0].row = i;
				node[0].col = j;
			}
			else if (map[i][j] == 'Z') {
				node[1].row = i;
				node[1].col = j;
			}
			else if (map[i][j] == '|') {
				connect[i][j][0] = 1;
				connect[i][j][2] = 1;
			}
			else if (map[i][j] == '+') {
				connect[i][j][0] = 1;
				connect[i][j][1] = 1;
				connect[i][j][2] = 1;
				connect[i][j][3] = 1;
			}
			else if (map[i][j] == '-') {
				connect[i][j][1] = 1;
				connect[i][j][3] = 1;
			}
			else if (map[i][j] == '1') {
				connect[i][j][0] = 1;
				connect[i][j][1] = 1;
			}
			else if (map[i][j] == '2') {
				connect[i][j][2] = 1;
				connect[i][j][1] = 1;
			}
			else if (map[i][j] == '3') {
				connect[i][j][3] = 1;
				connect[i][j][2] = 1;
			}
			else if (map[i][j] == '4') {
				connect[i][j][3] = 1;
				connect[i][j][0] = 1;
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == '.' && map[i][j] != 'Z' && map[i][j] != 'M') {
				//���� ��ġ�� .�ε� (��, ���ϳ��� ��ó���� ���ɼ��� �ִ� ��ġ) �װ��� ���ؼ� ����ĭ�� ���� �����ִٸ�? 
				// �������� �ٷ� ���ϳ��� ��ó�� �װ���
				if (connect[i + 1][j][2] && connect[i - 1][j][0]) { 
					if (connect[i][j + 1][3]) {
						cout << i << " " << j << " +" << "\n";
					}
					else {
						cout << i << " " << j << " |" << "\n";
					}
				}
				else if (connect[i - 1][j][0] && connect[i][j + 1][3]) {
					if (connect[i][j - 1][1]) {
						cout << i << " " << j << " +" << "\n";
					}
					else {
						cout << i << " " << j << " 2" << "\n";
					}
				}
				else if (connect[i - 1][j][0] && connect[i][j - 1][1]) {
					if (connect[i][j + 1][3]) {
						cout << i << " " << j << " +" << "\n";
					}
					else {
						cout << i << " " << j << " 3" << "\n";
					}
				}
				else if (connect[i][j - 1][1] && connect[i][j + 1][3]) {
					if (connect[i - 1][j][0]) {
						cout << i << " " << j << " +" << "\n";
					}
					else {
						cout << i << " " << j << " -" << "\n";
					}
				}
				else if (connect[i][j - 1][1] && connect[i + 1][j][2]) {
					if (connect[i - 1][j][0]) {
						cout << i << " " << j << " +" << "\n";
					}
					else{
						cout << i << " " << j << " 4" << "\n";
					}
				}
				else if (connect[i][j + 1][3] && connect[i + 1][j][2]) {
					if (connect[i - 1][j][0]) {
						cout << i << " " << j << " +" << "\n";
					}
					else {
						cout << i << " " << j << " 1" << "\n";
					}
				}
			}
		}
	}
	
	//print();
}