#include <iostream>
#include <vector>

using namespace std;
int main() {
	int t = 0;
	int n;
	double mean = 0;
	int count;
	vector<int> score;

	cin >> t;
	for (int i = 0; i < t; i++) {
		count = 0;
		mean = 0;
		cin >> n;

		for (int j = 0; j < n; j++) {
			int temp = 0;
			cin >> temp;
			score.push_back(temp);

			mean += temp;
		}

		mean = mean / n; // ЦђБе

		for (int j = 0; j < n; j++) {
			if (score[j] >= mean) {
				count += 1;
			}
		}

		score.clear();
		cout << count << "/" << n << "\n";
	}

	return 0;
}