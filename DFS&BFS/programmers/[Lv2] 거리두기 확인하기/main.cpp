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
        - 맨해튼 거리 == BFS 최단거리 구할 때랑 거리가 2인지 확인
        - - 각 P에서 BFS 탐색, 거리 2 이내에 다른 P 있으면 위반 (map 크기 자체가 5 x 5이기 때문에 가능)
        - 파티션이 있으면 어차피 못 감..!! 
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 0, 1, 0}; 
int dy[4] = { 0, -1, 0, 1};

int manhattan(vector<string>& place){
    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            if(place[i][j] != 'P') continue;
            
            queue<tuple<int,int,int>> q;
            vector<vector<int>> vis(5, vector<int>(5, -1)); 
            q.push({i, j, 0});
            vis[i][j] = 1;
            
            while(!q.empty()){
                auto [cx, cy, d] = q.front();
                q.pop();
                
                if(d >= 2) continue; // 이미 확인한 좌표들 (거리가 2)
                
                for(int i=0; i < 4; i++){
                    int x = cx + dx[i];
                    int y = cy + dy[i];
                    
                    if(x < 0 || x >= 5 || y < 0 || y >= 5) continue;
                    if(vis[x][y] != -1) continue;
                    if(place[x][y] == 'X') continue; // 파티션이 막아둠..
                    
                    if(place[x][y] == 'P'){
                        return 0; 
                    }
                    
                    vis[x][y] = 1;
                    q.push({x, y, d+1});
                }
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