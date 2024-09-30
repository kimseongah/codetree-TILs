import sys
input = sys.stdin.readline

n = int(input())
A = [[]for _ in range(n)]
for i in range(n):
    A[i] = list(map(int, input().split()))

max_val = 0
for i in range(n-2):
    for j in range(n-2):
        curr_val = A[i][j] + A[i][j+1] + A[i][j+2] + A[i+1][j] + A[i+1][j+1] + A[i+1][j+2] + A[i+2][j] + A[i+2][j+1] + A[i+2][j+2]
        if curr_val > max_val:
            max_val = curr_val

print(max_val)