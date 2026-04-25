import heapq

def solution(n, s, a, b, fares):
    graph = [ [] for _ in range(n+1)]
    
    for c, d, f in fares:
        graph[c].append((d, f))
        graph[d].append((c, f))
        
    def dijksta(start, n, g):
        pq = []
        dist = [1e9 for _ in range(n+1)]
        
        dist[start] = 0
        heapq.heappush(pq, (0, start))
        while pq:
            currd, currn = heapq.heappop(pq)
            
            if currd > dist[currn]:
                continue # 이미 방문 
                
            for next_n, fee in g[currn]: 
                if dist[next_n] > currd + fee:
                    dist[next_n] = currd + fee
                    heapq.heappush(pq, (dist[next_n], next_n))
                    
        return dist
    
    answer = 1e9 * 200 * 3
    dist_s = dijksta(s, n, graph)
    dist_a = dijksta(a, n, graph)
    dist_b = dijksta(b, n, graph)
    
    for k in range(1, n+1):
        answer = min(answer, dist_s[k] + dist_a[k] + dist_b[k])
        
        
    return answer