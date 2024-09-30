import sys
input = sys.stdin.readline

n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]

# 첫 번째 칸 기준
blocks = [[(0,0), (1,0), (1,1)], [(0,1), (1,0), (1,1)], [(0,0), (1,0), (0,1)], [(0,0), (0,1), (1,1)], [(0,0), (0,1), (0,2)], [(0,0),(1,0),(2,0)]]


result = []
for i in range(n):
    for j in range(m):
        for block in blocks:
            summ = 0
            done = True
            for k in range(3):
                if i + block[k][0] < 0 or i + block[k][0] >= n or j + block[k][1] < 0 or j + block[k][1] >= m:
                    done = False
                else:
                    summ += A[i + block[k][0]][j + block[k][1]]
                if done:
                    result.append(summ)

print(max(result))