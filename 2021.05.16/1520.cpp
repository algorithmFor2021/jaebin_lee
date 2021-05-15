#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int d[500][500]; //(i,j)에서 갈 수 있는 경로의 수
int visited[500][500];
vector<vector<int>>a(500); //지점의 높이
int n, m;
int recur(int i, int j,int direction) { //방향은 0,1,2,3순으로 상 하 좌 우에서 온 것
	//기저 케이스
	if (i >= m || j >= n || i < 0 || j < 0) return 0;
	if (i == m - 1 && j==n-1) return 1;
	if (d[i][j] == -1) {
		d[i][j] = 0;
		//오른쪽
		if (j+1 < n && direction!=2 && a[i][j] > a[i][j + 1]) {
			d[i][j] += recur(i, j + 1,3);
		}
		//아래
		if (i+1 < m && direction != 0 && a[i][j] > a[i + 1][j]) {
			d[i][j] += recur(i + 1, j,1);
		}
		//왼쪽
		if (j-1 >= 0 && direction != 3 && a[i][j - 1] < a[i][j]) {
			d[i][j] += recur(i, j - 1,2);
		}
		//위
		if (i-1 >= 0 && direction != 1 && a[i - 1][j] < a[i][j]) {
			d[i][j] += recur(i - 1, j,0);
		}
		
	}
	return d[i][j];
}
int main() {
	cin >> m >> n; //세로 m 가로 n
	//각 줄별로 개수 만들기
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = -1;
			int aa;
			cin >> aa;
			a[i].push_back(aa);
		}
	}
	
	cout << recur(0, 0, 5);
	return 0;
}