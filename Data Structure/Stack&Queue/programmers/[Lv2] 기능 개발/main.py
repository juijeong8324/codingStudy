from collections import deque

def solution(progresses, speeds):
    answer = []
    q = deque()
    
    for p, s in zip(progresses, speeds):
        day = ((100 - p) + s - 1) // s
        q.append(day)
    
    while q: # q.empty() 확인 
        # 초기화 
        curr = q.popleft()
        count = 1
        # 배포 가능한 기능 
        while q and curr >= q[0]: # q.empty() 확인 및 현재 원소 비교
            q.popleft()
            count += 1
            
        answer.append(count)
            
    
    return answer