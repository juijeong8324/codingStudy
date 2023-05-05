## 첫 번째 시도 
```c++
#include <string>
#include <vector>
#include <array>

using namespace std;

vector<int> solution(vector<int> arr) {
    array<int, 10> pow = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    int zero = 0;
    
    for(int i = 0; i < pow.size(); i++){
        if(arr.size() <= pow[i]){
            zero = pow[i] - arr.size();
            break;
        }
    }
    arr.insert(arr.end(), zero, 0);
    return arr;
}
```
1. 문제에서 arr의 길이가 1000까지라 2의 거듭제곱을 담은 배열을 만들어준다.
2. 배열의 크기보다 2의 거듭제곱 값이 크거나 같은 경우를 조건문으로 체크하여 그 간격을 구해준다
3. 해당 간격만큼 0을 추가해준다.

### 문제 발생 
![image](https://user-images.githubusercontent.com/63052097/236430482-55eae9dc-0932-4e6d-a531-23f0ea8d2a5d.png)
아니 대체 어디가 문제인거지?!!? Test case 22 번째가 실패로 뜬다.

<br>

### 문제해결
문제를 잘 읽어보니 길이가 **2의 정수 거듭제곱이 되도록** 만든다고 했다. 즉 2^0 = 1도 2의 정수 거듭제곱이라는 것!!
```c++
#include <string>
#include <vector>
#include <array>

using namespace std;

vector<int> solution(vector<int> arr) {
    array<int, 11> pow = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    int zero = 0;
    
    for(int i = 0; i < pow.size(); i++){
        if(arr.size() <= pow[i]){
            zero = pow[i] - arr.size();
            break;
        }
    }
    arr.insert(arr.end(), zero, 0);
    return arr;
}
```
통과했지롱~~ 
