import sys
input = sys.stdin.readline

n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]

answer = 0
# 가능한 가장 큰 마름모의 K == N-1
for k in range(n-1):
    cost = k*k + (k+1)*(k+1)
    for i in range(n):
        for j in range(n):
            count = A[i][j]
            for s in range(k):
                for r in range(k-s):
                    if i+s >=0 and i+s < n and j+r>=0 and j+r <n :
                        count += A[i+s][j+r]
                    if i-s >=0 and i-s < n and j-r>=0 and j-r <n :
                        count += A[i-s][j-r]
            if cost < count*m and answer < count:
                answer = count

print(answer)