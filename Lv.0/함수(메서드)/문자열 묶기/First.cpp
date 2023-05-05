#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> strArr) {
    array <int, 31> count;
    for(int i=0; i < 31; i++){
        count[i] = 0;
    } // strArr 원소의 길이가 30이하이므로 
    int answer = 0;
    
    for(int i=1; i <= 30; i++){ // 각 원소의 길이마다
        for(auto a : strArr){  // strArr에 해당 길이가 몇 개 있는지 count
            if(a.size() == i) count[i] += 1;
        }
        
        if(answer < count[i]){ // count 후 대소 비교 
            answer = count[i];
        }
    }
    
    return answer;
}
