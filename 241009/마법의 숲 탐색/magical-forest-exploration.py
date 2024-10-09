import sys
from collections import deque

input = sys.stdin.readline
R,C,K = map(int, input().split())
forest = [[0]*C for _ in range(R)]

magicians = [list(map(int, input().split())) for _ in range(K)]
golrem = [[-1, 0], [0, 1], [1, 0], [0, -1], [0, 0]]
directions = [[+1, 0, 0, [[+1, -1], [+2, 0], [+1, +1]]], [+1, -1, -1, [[0, -2], [-1, -1], [+1, -1], [+2, -1], [+1, -2]]], [+1, +1, +1, [[0, +1], [-1, +1], [+1, +1], [+2, +1], [+1, +2]]]] # delta_exit = [0, -1, +1] # %4 해줘야함

answer = 0
for i, (c, d) in enumerate(magicians, 1):
    y, x = [-2, c-1] # 누적할 때 +1 해야 함
    endpoint = 0
    while(endpoint == 0):
        for dy, dx, e, margins in directions:
            ny = y + dy
            nx = x + dx
            if ny < R and nx > -1 and nx < C:
                valid = 0
                for dmy, dmx in margins:
                    nmy = y + dmy
                    nmx = x + dmx
                    if nmy < 0:
                        continue
                    if nmy < R and nmx > -1 and nmx < C:
                        if forest[nmy][nmx] != 0:
                            valid = 1
                            break
                    else:
                        valid = 1
                        break
                if valid == 0:
                    y = ny
                    x = nx
                    d = (d + e) % 4

                    break
            if e == 1 and valid == 1:
                endpoint = 1
    for gy, gx in golrem:
        forest[y+gy][x+gx] = i
    gy, gx = golrem[d]
    forest[y+gy][x+gx] = -i # exit
    if y < 1 :
        forest = [[0]*C for _ in range(R)]
        continue

    # # 가장 남쪽으로 정령 이동시키기
    # 현재 y, x
    queue = deque([[y, x]])
    visited = set()
    while(queue):
        cy, cx = queue.popleft()
        if forest[cy][cx] not in visited:
            for dy, dx in golrem[:4]:
                ny = cy + dy
                nx = cx + dx
                if ny > -1 and ny < R and nx > -1 and nx < C:
                    if abs(forest[ny][nx]) == abs(forest[cy][cx]): # 이동 가능
                        visited.add(forest[ny][nx])
                        if ny > y:
                            y = ny
                        if forest[ny][nx]*(-1) == forest[cy][cx]: # 출구
                            for ndy, ndx in golrem[:4]:
                                y_neigh = ny + ndy
                                x_neigh = nx + ndx
                                if y_neigh > -1 and y_neigh < R and x_neigh > -1 and x_neigh < C:
                                    if abs(forest[y_neigh][x_neigh]) > 0 and abs(forest[ny][nx]) != abs(forest[y_neigh][x_neigh]): # 다른 golrem
                                        for t_y, t_x in golrem[:4]:
                                            nty = y_neigh + t_y
                                            ntx = x_neigh + t_x
                                            if nty > -1 and nty < R and ntx > -1 and ntx < C:
                                                if abs(forest[nty][ntx]) == abs(forest[y_neigh][x_neigh]):
                                                    queue.append([nty, ntx]) # 이웃 golrem 중심
                                        
    print(y+1)                           
    answer += (y + 1)

print(answer)