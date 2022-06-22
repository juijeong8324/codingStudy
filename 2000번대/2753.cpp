#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int year;
	cin >> year;
	
	if (year % 4 == 0 && year % 100 != 0) {
		cout << 1;
	}
	else if (year % 400 == 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}

/* 다른 분의 풀이 
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int year;
  cin >> year;

  if(year % 4 == 0){
	// 4의 배수이면서 400의 배수
	if(year % 400 == 0)  cout << 1;
	// 4의 배수이면서 100의 배수
	else if(year % 100 == 0)  cout << 0;
	// 4의 배수이면서 100, 400의 배수가 아닌 수
	else  cout << 1;
  }
  // 4의 배수가 아닌 수
  else  cout << 0;
}
*/