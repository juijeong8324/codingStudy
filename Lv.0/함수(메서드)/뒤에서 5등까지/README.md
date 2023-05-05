## [sort()](https://modoocode.com/272) 이용
- **< algorithm >** 에 정의 
- first 부터 last 전까지의 원소들을 오름차순 정렬 
- 이때 first와 last는 **임의 접근 반복자(RandomIterator)**
- list는 sort 함수 사용 할 수 없음.(순차 접근 반복자이기 때문)

```c++
// 1. default - 오름차순
void sort(RandomIt first, RandomIt last);

// 2. comp 함수를 이용한 비교 - 내림차순을 위해서 이 방법을 사용하기도 함 
bool cmp(const Type1 &a, const Type2 &b); 
void sort(RandomIt first, RandomIt last, Comp cmp); // cmp가 True가 되도록 렬렬
```

### 예시
```c++
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool cmp(int a, int b){
  return a > b; // 내림차순이 True
}

int main() {
  vector<int> v = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

  // 기본
  sort(v.begin(), v.end());
  for (auto a : v) {
    cout << v << " ";
  }
  
  // cmp를 이용한 내림차순 정렬
  sort(v.begin(), v.end(), cmp);
  for (auto a : v) {
    cout << a << " ";
  }

  // 람다 함수를 이용한 내림차순 정렬
  sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
  for (auto a : v) {
    cout << a << " ";
  }
  
  // 표준 라이브러리 비교 함수 객체 greater 를 통한 정렬
  sort(v.begin(), v.end(), greater<int>());
  for (auto a : v) {
    cout << a << " ";
  }
}
```
```
0 1 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 1 0
9 8 7 6 5 4 3 2 1 0
9 8 7 6 5 4 3 2 1 0
```

<br>

---

## vetor의 insert와 초기화
- [insert()](https://modoocode.com/186)
```c++
iterator insert(iterator position, const T& x); // 해당 position에 x를 추가
void insert(iterator position, size_type n, const T& x); // 해당 position에 n개의 같은 값 x들을 추가

template <class InputIterator>
void insert(iterator position, InputIterator first, InputIterator last); // 해당 position에 first부터 last 전까지의 원소들을 추가!
```
