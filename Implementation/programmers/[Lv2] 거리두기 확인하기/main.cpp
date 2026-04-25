/*
    - Input
        - places = 자리에 앉아 있는 응시자들의 정보와 대기실 구조를 대기실별로 담은 2차원 문자열 배열 
        - 길이 = 5 x 5(대기실 개수 x 대기실 세로 길이)
        - 원소는 POX로 이루어진 문자열 (길이 = 5, 대기실 가로 길이)
            - P = 응시자가 않자있는 자리 
            - O = 빈 테이블 
            - X = 파티션 
        
    - Output
        places에 담겨 있는 5개 대기실의 순서대로, 거리두기 준수 여부를 차례대로 배열에 담기
        각 대기실별로 거리두기를 지키고 있으면 1을, 한 명이라도 지키지 않고 있으면 0을 return 
        - 거리두기 
            - 대기실은 5개이고 각 대기실은 5 x 5 크기 
            - 맨해튼 거리( |r1 - r2| + |c1 - c2|)가 2 이하로 앉지 말기 
            - 응시자 간 자리에 파티션으로 막혀 있을 때는 가능! 
            
    - Hint 
        - 걍 구현 ->  O(5 × 5 × 5 × const) 수준
        - 각 좌표를 순회하면서 1. 상하좌우 1 -> 2. 상하좌우 2 -> 3. 대각선 에 따라 확인
        - 확인해야 할 조건들은 1,2,3에 따라 모두 다르다. 
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = { -1, 0, 1, 0}; 
int dy[4] = { 0, -1, 0, 1};
int dx2[4] = { -2, 0, 2, 0}; 
int dy2[4] = { 0, -2, 0, 2};
int dx3[4] = { -1, 1, -1, 1}; 
int dy3[4] = { -1, 1, 1, -1};
int sx[2] = {0, 1};
int sy[2] = {1, 0};

int manhattan(vector<string>& place){
    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            if(place[i][j] != 'P') continue;
            
            // 거리가 1
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if(place[nx][ny] == 'X' || place[nx][ny] == 'O') continue;
            
                return 0;
            }
            // 거리가 2 
            for(int k = 0; k < 4; k++){
                int nx = i + dx2[k];
                int ny = j + dy2[k];
                
                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if(place[nx][ny] == 'X' || place[nx][ny] == 'O') continue;
               
                int mx = i + dx[k], my = j + dy[k]; // 해당 방향의 거리가 1인 곳에 파티션이 있는지 확인 
                if(place[mx][my] != 'X') return 0;
            }
            // 대각선 
            for(int k = 0; k < 4; k++){
                int nx = i + dx3[k];
                int ny = j + dy3[k];
                
                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if(place[nx][ny] == 'X' || place[nx][ny] == 'O') continue;
                
                if(place[nx][j] != 'X' || place[i][ny] != 'X') // 좌표와 대각선 모두 거리가 1인 곳에 파티션이 있는지 확인 
                    return 0;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5, 0);
    
    for(int i=0; i < 5; i++){
        int ans = manhattan(places[i]);
        answer[i] = ans;
    }
    

    return answer;
}