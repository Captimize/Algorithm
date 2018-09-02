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
			//현재 위치 (i,j)에 대해서 길이 열려 있는지 여부를 check합니다. 만약에, (i-1, j)에서 위로 올라오면 (i,j)가 되는데 이때 (i-1,j)의 시점에서
			//길이 열려이는지 여부를 판단합니다
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
				//현재 위치가 .인데 (즉, 도둑놈이 훔처갔을 가능성이 있는 위치) 그곳에 대해서 다음칸이 길이 열려있다면? 
				// ㅇㅋㅇㅋ 바로 도둑놈이 훔처간 그곳임
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