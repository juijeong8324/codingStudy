
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <iostream>
#include <bits/stdc++.h>
const int MAX_FARE = INT_MAX;

using namespace std;

vector<int> dijkstra(int start, int n, vector<vector<pair<int,int>>>& g){
    priority_queue<pair<int, int>> pq; // 가장 거리가 짧은 = 이때 주의할 것은 <-거리, 간선>
    vector<int> dist(n+1, MAX_FARE); // 최대 거리 
    
    dist[start] = 0;
    pq.push({0, start});
    
    
    // 2. 다익스트라 
    while(!pq.empty()){
        auto curr = pq.top();
        int curr_dist = - curr.first;
        int curr_node = curr.second;
    
        pq.pop();
        
        if(curr_dist > dist[curr_node]){
            // 이미 방문 
            continue;
        }
        
        for(auto next: g[curr_node]){
            int new_dist = curr_dist + next.second; // 새로운 거리 
            if(new_dist < dist[next.first]){
                pq.push({-new_dist, next.first});
                dist[next.first] = new_dist;
            }
        }
    
    }
    
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = (long long) MAX_FARE*200*3;
    vector<vector<pair<int,int>>> graph(n+1); // graph 정보 저장  
    
    // 1. 그래프 정보 저장 
    for(int i=0; i < fares.size(); i++){
        int c = fares[i][0];
        int d = fares[i][1];
        int f = fares[i][2];

        graph[c].push_back(pair<int, int>(d, f));
        graph[d].push_back(pair<int, int>(c, f));
    }
    
    vector<int> dist_s = dijkstra(s, n, graph);
    vector<int> dist_a = dijkstra(a, n, graph);
    vector<int> dist_b = dijkstra(b, n, graph);
    
    for(int k=1; k < n+1; k++){
        answer = min(answer, (long long) dist_s[k]+ (long long)dist_a[k] + (long long)dist_b[k]); // s -> k -> a + b
    }

    
    return answer;
}