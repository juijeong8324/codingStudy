/*
    - Input
        - rows = 행렬의 세로 길이 (2 이상 100 이하)
        - columns = 가로 길이 (2 이상 100 이하)
        - queries = 회전들의 목록 (1 이상 10,000 이하)
            - [x1, y1, x2, y2] = x1 행 y1 열부터 x2행 y2 열까지 영역의 테두리를 시계방향으로 회전
            - 모든 회전은 순서대로 이루어짐 
        - 처음 행렬에는 가로 방향으로 숫자가 1부터 하나씩 증가하면서 적힘 = i행 j열 값 = (i-1) x columns + j)
    - Output
        - 각 회전을 배열에 적용한 뒤, 그 회전에 의해 위치가 바뀐 숫자들 중 가장 작은 숫자들을 순서대로 배열에 return
    - Hint
        - 시계방향으로 할당 
        - temp[다음] = b[현재]  ← 현재 값을 다음 칸에 저장하는 경우, temp라는 추가 공간 필요
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int rotate(int x1, int y1, int x2, int y2, vector<vector<int>>& b){ // return 작은 수
    vector<vector<int>> temp(x2-x1+1, vector<int>(y2-y1+1, 0));
    int min_num = 20000;
    
    int nx = x1;
    int ny = y1;
    // 가로 
    while(ny < y2){
        temp[nx-x1][ny+1-y1] = b[nx][ny]; 
        min_num = min(min_num, b[nx][ny]);
        ny++;
    }
    
    // 세로 
    while(nx < x2){
        temp[nx+1-x1][ny-y1] = b[nx][ny]; 
        min_num = min(min_num, b[nx][ny]);
        nx++;
    }

    // 가로
    while(ny > y1){
        temp[nx-x1][ny-1-y1] = b[nx][ny]; 
        min_num = min(min_num, b[nx][ny]);
        ny--;
    }

    // 세로
    while(nx > x1){
        temp[nx-1-x1][ny-y1] = b[nx][ny]; 
        min_num = min(min_num, b[nx][ny]);
        nx--;
    }
    
    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++){
            if(i > x1 && i < x2 && j > y1 && j < y2) continue;
            b[i][j] = temp[i-x1][j-y1];
        }
    }

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