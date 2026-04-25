/*
    - Input
        - maps = 게임 맴의 상태 
            - n x m (1 이상 100 이하의 자연수)
            - 0과 1로만 이루어짐, 0은 벽이 있는 자리 1은 벽이 없는 자리
            - 캐릭터는 (1,1)에 상대팀은 (n,m)에 위치 
    - Output
        - 상대 팀 진영에 도착하기 위해서 지나가야 하는 칸의 개수의 최솟값
    - Hint
        - BFS는 1칸씩 주변을 탐색함. 
        - 즉 같은 레벨의 노드를 탐색하기 때문에 (트리라면 같은 높이, 그래프 혹은 행렬이라면 같은 거리) 최단거리를 탐색할 수 있다
        - BFS는 큐를 사용한다는 것에 집중하자!!!
*/
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int answer = 0;
    queue<pair<int,int>> q;
    vector<vector<int>> vis(n+1, vector<int>(m+1, -1));
    
    q.push({1, 1});
    vis[1][1] = 1;
    
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        
        for(int i=0; i <4; i++){
            int x = curr.first + dx[i];
            int y = curr.second + dy[i];
            
            if (x <= 0 || x > n || y <= 0 || y > m) continue;
            if (vis[x][y] != -1 || maps[x-1][y-1] == 0) continue;
            
            q.push({x, y});
            vis[x][y] = vis[curr.first][curr.second] + 1;
        }
        
    }
    
    return vis[n][m];
}