#include <iostream>
#include <algorithm>
using namespace std;

struct check {
	string name;
	float height;
};

bool s(check first, check second);

int main() {
	int n = 0;
	int find = 0;

	check* problem = new check[n];

	cin >> n >> find;
	for (int i = 0; i < n; i++) {
		cin >> problem[i].name >> problem[i].height;
	}

	sort(problem, problem + n, s);

	cout << problem[find - 1].name << " " << problem[find - 1].height;

	delete[] problem;
	return 0;
}

bool s(check first, check second) {
	if (first.name == second.name) {
		return first.height < second.height;
	}
	else return first.name < second.name;
}