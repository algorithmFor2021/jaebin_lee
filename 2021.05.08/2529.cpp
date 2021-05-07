#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int k;
int arr[10];
long long minval = 1e11;
long long maxval = -1e11;
int visited[10];
char cmp[10];
bool LisBig(char x){
	if (x == '>') return true;
	return false;
}
int makeTen(int x){
	int sum = 1;
	for (int i = 0; i < x; i++){
		sum *= 10;
	}
	return sum;
}
void permutation(int x){
	if (x == k + 1){
		string ans;
		int i;
		for (i = 0; i < k; i++){
			//부등호가 >인데 부등호 방향이 틀렸으면 return
			if (LisBig(cmp[i]))
			{
				if (arr[i] > arr[i + 1]) {
					char aa[2];
					sprintf(aa, "%d", arr[i]);
					ans = ans + aa;
				}
				else return;
			}

			else
			{
				if (arr[i] < arr[i + 1]) {
					//int aa = arr[i] + 48;
					//int bb = arr[i + 1] + 48;
					//ans += aa + bb;
					char aa[2];
					sprintf(aa, "%d", arr[i]);
					ans = ans + aa;
				}
				else return;
			}


		}
		if (i == k) {
			char aa[2];
			sprintf(aa, "%d", arr[k]);
			ans = ans + aa;
		}

		minval = min(minval, atoll(ans.c_str()));
		maxval = max(maxval, atoll(ans.c_str()));
		return;
	}

	for (int i = 0; i <= 9; i++){
		if (visited[i] == -1){
			visited[i] = 1;
			arr[x] = i;
			permutation(x + 1);
			visited[i] = -1;
		}
	}
}

int main(){
	memset(visited, -1, sizeof(visited));
	memset(arr, -1, sizeof(arr));

	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> cmp[i];
	}


	permutation(0);
	if (maxval < makeTen(k)){
		cout << "0" << maxval << "\n";
	}
	else cout << maxval << "\n";

	if (minval < makeTen(k)){
		cout << "0" << minval << "\n";
	}
	else cout << minval << "\n";


	return 0;
}