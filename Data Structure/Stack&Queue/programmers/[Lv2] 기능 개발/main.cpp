/*
    - Input
        - progresses = 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열
            - 길이 = 100개 이하 
            - 진도 = 100 미만의 자연수 
        - speeds = 각 작업의 개발 속도가 적힌 정수 배열 (100개 이하)\
            - 길이 = 100개 이하 
            - 속도 = 100 이하의 자연수 
    - Output
        - 각 배포다마 몇 개의 기능이 배포되는지 (배포는 하루의 끝에 이루어짐)
        - 진도가 100%일 때 서비스에 반영 가능 
        - 각 기능의 개발속도는 모두 다르기 떄문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있음!
            - 단 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됨 
    - Hint
        - Queue 
            - 앞선 작업의 완료일이 기준이 되어, 이후 작업들이 그보다 빠르면 함께 count
        - 올림 나눗셈 공식
            - (a + b - 1) / b
            - C++에서 int/int 나눗셈은 버림(내림) 처리
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    
    for(int i=0; i < progresses.size(); i++){
        days.push((100 - progresses[i] + speeds[i] - 1) / speeds[i]); // 올림 나눗셈
    }
    
    while(!days.empty()){
        int curr = days.front();
        int mount = 1;
        days.pop();
        
        while(!days.empty() && curr >= days.front()){ // curr가 기준이 되는 경우
            days.pop();
            mount++;
        }
        
        answer.push_back(mount);
    }
    
    return answer;
}