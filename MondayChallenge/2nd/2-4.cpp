#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n = 0;
	int count = 0;
	int ans = 0;

	vector<vector<int>> v;
	vector<int> v2;

	cin >> n >> count;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v2.push_back(0);
		}
		v.push_back(v2);
	}

	for (int i = 0; i < count; i++) {
		int row, col;
		cin >> row >> col;

		v[row - 1][col - 1] += 1;
		if (row - 2 > -1) {
			v[row - 2][col - 1] += 1;
		}
		if (row < n) {
			v[row][col - 1] += 1;
		}
		if (col - 2 > -1) {
			v[row - 1][col - 2] += 1;
		}
		if (col < n) {
			v[row - 1][col] += 1;
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += v[i][j];
		}

	}

	cout << ans;

	return 0;
}