#include <iostream>
using namespace std;
int main() {
	int count = 1;
	int size = 0;
	string problem = "";

	cin >> size >> problem;

	for (int i = 1; i < size; i++) {
		if (problem[i - 1] == problem[i]) continue;
		else {
			count += 1;
		}
	}

	cout << count;

	return 0;
}