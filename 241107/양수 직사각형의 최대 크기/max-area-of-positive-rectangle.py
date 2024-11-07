n, m = map(int, input().split())
 
matrix = [list(map(int, input().split())) for _ in range(n)]
res = -1
 
def canCal(x, y, r, c):
    if 0 <= x and x + c < m and 0 <= y and y + r < n:
        return True
    else:
        return False
 
def cal(x, y, r, c):
    for i in range(c + 1):
        for j in range(r + 1):
            if matrix[y + j][x + i] <= 0:
                return False
    return True
 
 
def simul(x, y):
    global res
    for i in range(n):
        for j in range(m):
            if canCal(x, y, i, j):
                if cal(x, y, i, j):
                    res = max(res, (j+1) * (i+1))
 
for i in range(n):
    for j in range(m):
        simul(j, i)
 
print(res)