#include <string>
#include <vector>

using namespace std;

vector<vector<int>> d;
int s = 0;
int K;
bool vis[8]; // 던전 방문 여부
int answer = 0; // 방문할 수 있는 최대 던전 수 

void dfs(int t, int c){
    // 현재 피로도, 방문 가능 던전 수 
    
    if (c >= answer){ // 최댓값인 경우 
        answer = c;
    }
    
    for(int i=0; i < s; i++){
        if (vis[i] != true && d[i][0] <= t){ // 최소 필요도가 작은 경우
            vis[i] = true;
            dfs(t-d[i][1], c+1); // 던전 방문
            vis[i] = false; // 원상복귀
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    K = k;
    d = dungeons;
    s =  d.size();
    
    dfs(K, 0);
    return answer;
}