#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int D[MAX];
bool solution(vector<int> arr)
{
	//sort(arr.begin(), arr.end());
	D[arr[0]] = 1;
	bool answer = true;
	for (int i = 1; i < arr.size(); i++) {
		if (D[arr[i]]) {
			answer = false;
			break;
		}
		D[arr[i]] = 1;
	}
	for (int i = 1; i <= arr.size(); i++) {
		if (!D[i]) {
			answer = false;
			break;
		}
	}
	return answer;
}
int main() {
	cout << solution({ 4,1,3,2 });
}