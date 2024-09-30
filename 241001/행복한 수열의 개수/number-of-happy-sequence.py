import sys
input = sys.stdin.readline

n, m = map(int, input().split())
A = [[] for _ in range(n)]
for i in range(n):
    A[i] = list(map(int, input().split()))
count = 0
for i in range(n):
    num_seq = 1
    past_elem = A[i][0]
    for j in range(1, n):
        if past_elem == A[i][j]:
            num_seq += 1
        else:
            num_seq = 1
            past_elem = A[i][j]
    if num_seq >= m:
        count += 1

for i in range(n):
    num_seq = 1
    past_elem = A[0][i]
    for j in range(1, n):
        if past_elem == A[j][i]:
            num_seq += 1
        else:
            num_seq = 1
            past_elem = A[j][i]
    if num_seq >= m:
        count += 1

print(count)