

def solve(i, j, matrix, memo = None):
    m = len(matrix[0])
    n = len(matrix)
    memo = {} if memo is None else memo 

    if (i == n-1 and j == m-1 and matrix[i][j] != 1):
        return 1
    
    if (matrix[i][j] == 1):
        return 0

    if ((i, j) in memo):
        return memo[(i, j)]

    if (i == n-1):
        memo[(i, j)] = solve(i, j+1, matrix, memo)
        return memo[(i, j)]

    if (j == m-1):
        memo[(i, j)] = solve(i + 1, j, matrix, memo)
        return memo[(i, j)]
    
    memo[(i, j)] = solve(i, j+1, matrix, memo) + solve(i + 1, j, matrix, memo)
    return memo[(i, j)]


def paths(matrix):
    
    i = len(matrix)
    j = len(matrix[0])
    ans = solve(0, 0, matrix)
    
    return ans


matrix = [
    [0, 0, 1, 0, 1],
    [0, 0, 0, 0, 1],
    [0, 0, 1, 0, 0],
    [1, 0, 0, 0, 0]
]

print(paths(matrix))

matrix = [[0], [1]]

print(paths(matrix))


def paths(matrix, i=0, j=0):
    n, m = len(matrix), len(matrix[0])
    if i == n or j == m or matrix[i][j] == 1:
        return 0
    elif i == n-1 and j == m-1:
        return 1
    else:
        return paths(matrix, i+1, j) + paths(matrix, i, j+1)
 
 
def paths(matrix, i=0, j=0, lookup=None):
    lookup = {} if lookup is None else lookup
    n, m = len(matrix), len(matrix[0])
    if (i, j) in lookup:
        return lookup[(i, j)]
    if i == n or j == m or matrix[i][j] == 1:
        return 0
    elif i == n-1 and j == m-1:
        return 1
    else:
        lookup[(i, j)] = paths(matrix, i+1, j, lookup) + paths(matrix, i, j+1, lookup)
        return lookup[(i, j)]
 
 
def paths(matrix):
    n, m = len(matrix), len(matrix[0])
    dp = [([0]*m) for i in range(n)]
    dp[0][0] = 1 if (matrix[0][0] == 0) else 0
    for j in range(1, m):
        dp[0][j] = dp[0][j-1] if matrix[0][j] == 0 else 0
    for i in range(1, n):
        dp[i][0] = dp[i-1][0] if matrix[i][0] == 0 else 0
    for i in range(1, n):
        for j in range(1, m):
            dp[i][j] = dp[i-1][j] + dp[i][j-1] if matrix[i][j] == 0 else 0
    return dp[n-1][m-1]
 
 
def paths(matrix):
    n, m = len(matrix), len(matrix[0])
    prev_dp = [0]*m
    dp = [0]*m    
    prev_dp[0] = 1 if (matrix[0][0] == 0) else 0
    for j in range(1, m):
        prev_dp[j] = prev_dp[j-1] if matrix[0][j] == 0 else 0
    for i in range(1, n):
        dp[0] = prev_dp[0] if matrix[i][0] == 0 else 0
        for j in range(1, m):
            dp[j] = prev_dp[j] + dp[j-1] if matrix[i][j] == 0 else 0
        prev_dp = dp
        dp = [0]*m
    return prev_dp[m-1]