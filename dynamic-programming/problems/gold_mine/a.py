







def gold(mine):
    n = len(mine)
    m = len(mine[0])

    if (n == 1):
        ans = 0
        for i in range(m):
            ans = max(ans, mine[0][i])
        return ans
    
    if (m == 1):
        ans = 0
        for i in range(n):
            ans += mine[i][0]
        return ans

    prev_dp = [0] * m
    dp = [0] * m

    for i in range(m):
        prev_dp[i] = mine[n-1][i]

    for i in range(n-2, -1, -1):

        for j in range(m):
            if (j == 0):
                dp[j] = max(prev_dp[j], prev_dp[j+1])
            elif (j == m-1):
                dp[j] = max(prev_dp[j], prev_dp[j-1])
            else:
                dp[j] = max({prev_dp[j], prev_dp[j-1], prev_dp[j+1]})
            dp[j] += mine[i][j]

        prev_dp = dp.copy()
    
    ans = 0
    for i in range(m):
        ans = max(ans, prev_dp[i])

    return ans


def gold(mine):
    n, m = len(mine), len(mine[0])
    dp = [[0]*m for i in range(n)]
    for j in range(m):
        dp[0][j] = mine[0][j]
    for i in range(1, n):
        for j in range(m):
            top_left = dp[i-1][j-1] if (j-1) >= 0 else 0
            top = dp[i-1][j]
            top_right = dp[i-1][j+1] if (j+1) < m else 0
            dp[i][j] = mine[i][j] + max(top_left, top, top_right)

    for i in range(len(dp)):
        for j in range(len(dp[0])):
            print(dp[i][j], end=" ")
        print()
    
    return max(dp[n-1])


mine = [
   [3],
   [6],
   [8],
   [3]
]

mine = [
   [3, 2, 12, 15, 10]
]

mine = [
   [3, 2, 12, 15, 10],
   [6, 19, 7, 11, 17],
   [8, 5, 12, 32, 21],
   [3, 20, 2, 9, 7]
]

print(gold(mine))





def rec(mine, i, j):
    n, m = len(mine), len(mine[0])
    if i == n or j < 0 or j == m:
        return 0
    else:
        return mine[i][j] + max(rec(mine, i+1, j-1), rec(mine, i+1, j), rec(mine, i+1, j+1))
 
 
def gold(mine):
    max_gold = 0
    for i in range(len(mine[0])):
        max_gold = max(max_gold, rec(mine, 0, i))
    return max_gold
 
 
def rec(mine, i, j, lookup):
    n, m = len(mine), len(mine[0])
    if (i, j) in lookup:
        return lookup[(i, j)]
    if i == n or j < 0 or j == m:
        return 0
    else:
        lookup[(i, j)] = mine[i][j] + max(rec(mine, i+1, j-1, lookup), rec(mine, i+1, j, lookup), rec(mine, i+1, j+1, lookup))
        return lookup[(i, j)]
 
 
def gold(mine):
    max_gold = 0
    lookup = {}
    for i in range(len(mine[0])):
        max_gold = max(max_gold, rec(mine, 0, i, lookup))
        return max_gold
 
 
def gold(mine):
    n, m = len(mine), len(mine[0])
    dp = [[0]*m for i in range(n)]
    for j in range(m):
        dp[0][j] = mine[0][j]
    for i in range(1, n):
        for j in range(m):
            top_left = dp[i-1][j-1] if (j-1) >= 0 else 0
            top = dp[i-1][j]
            top_right = dp[i-1][j+1] if (j+1) < m else 0
            dp[i][j] = mine[i][j] + max(top_left, top, top_right)

    for i in range(len(dp)):
        for j in range(len(dp[0])):
            print(dp[i][j], end=" ")
        print()
    
    return max(dp[n-1])
 
 
def gold(mine):
    n, m = len(mine), len(mine[0])
    prev_dp = [0]*m
    dp = [0]*m
    for j in range(m):
        prev_dp[j] = mine[0][j]
    for i in range(1, n):
        for j in range(m):
            top_left = prev_dp[j-1] if (j-1) >= 0 else 0
            top = prev_dp[j]
            top_right = prev_dp[j+1] if (j+1) < m else 0
            dp[j] = mine[i][j] + max(top_left, top, top_right)
        prev_dp = dp
        dp = [0]*m
    return max(prev_dp)