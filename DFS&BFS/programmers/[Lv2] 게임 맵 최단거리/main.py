def solution(maps):
    m = len(maps[0])
    n = len(maps)
    
    visit = [[0 for _ in range(m)] for _ in range(n)] # 방문 여부 
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    
    queue = [(0, 0)] # (x, y)
    visit[0][0] = 1 # 방문 표시
    
    while queue:
        curX, curY = queue.pop(0)
        for idx in range(4):
            x = curX + dx[idx]
            y = curY + dy[idx]
            
            if x < 0 or x >= n or y < 0 or y >= m:
                continue
            if maps[x][y] == 0: # 벽이면
                continue
            if visit[x][y] != 0: # 방문했으면
                continue
            
            queue.append((x, y))
            visit[x][y] = visit[curX][curY] + 1
    
    return visit[n-1][m-1] if visit[n-1][m-1] != 0 else -1