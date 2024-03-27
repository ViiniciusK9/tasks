def cost(matrix, i=0, j=0):
    n, m = len(matrix), len(matrix[0])
    if i == n-1 and j == m-1:
        return matrix[i][j]
    elif i == n-1:
        return matrix[i][j] + cost(matrix, i, j+1)
    elif j == m-1:
        return matrix[i][j] + cost(matrix, i+1, j)
    else:
        return matrix[i][j] + min(cost(matrix, i+1, j), cost(matrix, i, j+1))
 
 
def cost(matrix, i=0, j=0, lookup=None):
    lookup = {} if lookup is None else lookup
    n, m = len(matrix), len(matrix[0])
    if (i, j) in lookup:
        return lookup[(i, j)]
    if i == n-1 and j == m-1:
        return matrix[i][j]
    elif i == n-1:
        lookup[(i, j)] = matrix[i][j] + cost(matrix, i, j+1, lookup)
        return lookup[(i, j)]
    elif j == m-1:
        lookup[(i, j)] = matrix[i][j] + cost(matrix, i+1, j, lookup)
        return lookup[(i, j)]
    else:
        lookup[(i, j)] = matrix[i][j] + min(cost(matrix, i+1, j, lookup),
                                            cost(matrix, i, j+1, lookup))
        return lookup[(i, j)]
 
 
def cost(matrix):
    n, m = len(matrix), len(matrix[0])
    dp = [[0]*m for i in range(n)]
    dp[0][0] = matrix[0][0]
    for j in range(1, m):
        dp[0][j] = matrix[0][j] + dp[0][j-1]
    for i in range(1, n):
        dp[i][0] = matrix[i][0] + dp[i-1][0]
    for i in range(1, n):
        for j in range(1, m):
            dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i][j-1])
    return dp[n-1][m-1]
 
 
def cost(matrix):
    n, m = len(matrix), len(matrix[0])
    prev_dp = [0]*m
    dp = [0]*m
    prev_dp[0] = matrix[0][0]
    for j in range(1, m):
        prev_dp[j] = matrix[0][j] + prev_dp[j-1]
    for i in range(1, n):
        dp[0] = prev_dp[0] + matrix[i][0]
        for j in range(1, m):
            dp[j] = matrix[i][j] + min(prev_dp[j], dp[j-1])
        prev_dp = dp
        dp = [0]*m
    return prev_dp[m-1]