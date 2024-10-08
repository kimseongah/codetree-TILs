import sys
input = sys.stdin.readline

n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]

answer = 0
# 가능한 가장 큰 마름모의 K == N-1
for k in range(2*n-1):
    cost = k*k + (k+1)*(k+1)
    for i in range(n):
        for j in range(n):
            count = 0
            for s in range(k+1):
                for r in range(k-s+1):
                    if s == 0 and r == 0:
                        count += A[i+s][j+r]
                        continue
                    if i+s >=0 and i+s < n and j+r>=0 and j+r <n :
                        count += A[i+s][j+r]
                    if i-s >=0 and i-s < n and j-r>=0 and j-r <n :
                        count += A[i-s][j-r]
                    if s == 0 or r == 0:
                        continue
                    if i+s >=0 and i+s < n and j-r>=0 and j-r <n :
                        count += A[i+s][j-r]
                    if i-s >=0 and i-s < n and j+r>=0 and j+r <n :
                        count += A[i-s][j+r]
            if cost <= count*m and answer < count:
                answer = count

print(answer)