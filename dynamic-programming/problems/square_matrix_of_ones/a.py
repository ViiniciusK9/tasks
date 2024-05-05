

""" Instructor code """

def rec(matrix, i, j):
    if i < 0 or j < 0 or matrix[i][j] == 0:
        return 0
    else:
        return 1 + min(rec(matrix, i-1, j), rec(matrix, i, j-1), rec(matrix, i-1, j-1))
 
 
def square(matrix):
    n, m = len(matrix), len(matrix[0])
    max_size = 0
    for i in range(n):
        for j in range(m):
            max_size = max(max_size, rec(matrix, i, j))
    return max_size**2
 
 
def rec(matrix, i, j, lookup):
    if (i, j) in lookup:
        return lookup[(i, j)]
    if i < 0 or j < 0 or matrix[i][j] == 0:
        return 0
    else:
        lookup[(i, j)] = 1 + min(rec(matrix, i-1, j, lookup), rec(matrix, i, j-1, lookup), rec(matrix, i-1, j-1, lookup))
        return lookup[(i, j)]
 
 
def square(matrix):
    n, m = len(matrix), len(matrix[0])
    max_size = 0
    lookup = {}
    for i in range(n):
        for j in range(m):
            max_size = max(max_size, rec(matrix, i, j, lookup))
    return max_size**2
 
 
def square(matrix):
    n, m = len(matrix), len(matrix[0])
    dp = [[0] * m for i in range(n)]
    dp[0][0] = matrix[0][0]
    for j in range(1, m):
        dp[0][j] = matrix[0][j]
    for i in range(1, n):
        dp[i][0] = matrix[i][0]
    for i in range(1, n):
        for j in range(1, m):
            dp[i][j] = 0 if matrix[i][j] == 0 else 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
    return max(map(max,dp))**2
 
 
def square(matrix):
    n, m = len(matrix), len(matrix[0])
    prev_dp = [0]*m
    dp = [0]*m
    prev_dp[0] = matrix[0][0]
    max_size = matrix[0][0]
    for j in range(1, m):
        prev_dp[j] = matrix[0][j]
        max_size = max(max_size, prev_dp[j])
    for i in range(1, n):
        dp[0] = matrix[i][0]
        for j in range(1, m):
            dp[j] = 0 if matrix[i][j] == 0 else 1 + min(prev_dp[j], dp[j-1], prev_dp[j-1])
        max_size = max(max_size, max(dp))
        prev_dp = dp
        dp = [0]*m
    return max_size**2