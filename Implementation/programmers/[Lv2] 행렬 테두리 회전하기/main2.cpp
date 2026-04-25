/*
    - KeyPoint
        temp 배열 안 두고 바로 in-place!
        - 반시계 방향으로 읽어서 할당
        - b[현재] = b[이전] ← 첫 값만 saved로 저장해두면 in-place 가능
        - 상상해보자! 시작점을 빼서 남은 왼쪽 열은 위로, 아래쪽 행은 왼쪽으로, 오른쪽 열은 아래로, 위쪽 행은 오른쪽으 이동시킨 후 시작점을 남은 공간에 끼운다..
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;


int rotate(int x1, int y1, int x2, int y2, vector<vector<int>>& b){
    int min_num = 20000;
    int saved = b[x1][y1];
    min_num = min(min_num, saved);
    
    // 반시계 방향으로 
    // 왼쪽 열
    for(int i=x1; i < x2; i++){
        min_num = min(min_num, b[i+1][y1]);
        b[i][y1] = b[i+1][y1];
    }
    
    // 아래 행 
    for(int j=y1; j < y2; j++){
        min_num = min(min_num, b[x2][j+1]);
        b[x2][j] = b[x2][j+1];
    }
    
    // 오른쪽 열 
    for(int i=x2; i > x1; i--){
        min_num = min(min_num, b[i-1][y2]);
        b[i][y2] = b[i-1][y2];
    }
    
    // 위쪽 행
    for(int j=y2; j > y1; j--){
        min_num = min(min_num, b[x1][j-1]);
        b[x1][j] = b[x1][j-1];
    }
    
    b[x1][y1+1] = saved;

    return min_num;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows+1, vector<int>(columns+1, 0));
    
    // 배열 채우기 
    for(int i=1; i <= rows; i++){
        for(int j=1; j <= columns; j++){
            board[i][j] = (i-1)*columns + j;
        }
    }
    
    for(auto& q: queries){
        answer.push_back(rotate(q[0], q[1], q[2], q[3], board));
    }
    
    return answer;
}