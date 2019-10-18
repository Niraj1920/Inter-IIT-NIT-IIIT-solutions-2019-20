#include<iostream>
using namespace std;
int traverse(int a[100][100], int n, int m, int i, int j, int h){
	int ans;

	if (i <= 0 || j <= 0 || i > n || j > m)
		return -1;

	if (a[i][j] == 1 || a[i][j] == 3){
		a[i][j] *= -1;

		ans = traverse(a, n, m, i, j - 1, h);
		if (ans >= 1)
			return ans;

		ans = traverse(a, n, m, i, j + 1, h);
		if (ans >= 1)
			return ans;

		for (int k = 1; k <= h; k++){
			ans = traverse(a, n, m, i - k, j, k);
			if (ans >= 1)
				return ans;
		}

		for (int k = 1; k <= h; k++){
			ans = traverse(a, n, m, i + k, j, k);
			if (ans >= 1)
				return ans;
		}
	}
	else if (a[i][j] <= 0)
		return -1;

	else if (a[i][j] == 2)
		return h;

	else
		return -1;
}

int main(){

	int n, m, T, h, di, dj, ans = -1;
	int a[100][100];
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n >> m;
		h = n - 1;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> a[i][j];
				if (a[i][j] == 3){
					di = i;
					dj = j;
				}
			}
		}

		for (int i = 1; i <= h; i++){
			ans = traverse(a, n, m, di, dj, h);
			if (ans >= 1)
				break;
		}
		cout << ans << endl;
	}
	getchar();
	return 0;
}
