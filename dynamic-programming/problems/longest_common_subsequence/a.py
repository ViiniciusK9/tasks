# top down
def solve(i1, i2, s1, s2, memo = None):

    memo = {} if memo is None else memo

    if (i1 >= len(s1) or i2 >= len(s2)):
        return 0
    
    if (s1[i1] == s2[i2]):
        memo[(i1, i2)] = 1 + solve(i1+1, i2+1, s1, s2, memo)
        return memo[(i1, i2)]
    
    memo[(i1, i2)] = max(solve(i1+1, i2, s1, s2, memo), solve(i1, i2+1, s1, s2, memo))
    return memo[(i1, i2)]



def lcs(s1, s2):
    return solve(0, 0, s1, s2)

# bottom up
def lcs(s1, s2):
    n = len(s1)
    m = len(s2)

    # matriz de n+1 linhas e m+1 colunas inicializadas com zero
    tabulation = [[0]*(m+1) for i in range(n+1)]
    
    for i in range(1, n+1):
        for j in range(1, m+1):
            if (s1[i-1] == s2[j-1]):
                tabulation[i][j] = 1 + tabulation[i-1][j-1]
            else:
                tabulation[i][j] = max(tabulation[i-1][j], tabulation[i][j-1])
    
    return tabulation[n][m]


s1 = "abdacbab"
s2 = "acebfca"
print(lcs(s1, s2))


# Code 

def lcs(s1, s2, i=0, j=0):
    if i == len(s1) or j == len(s2):
        return 0
    elif s1[i] == s2[j]:
        return 1 + lcs(s1, s2, i+1, j+1)
    else:
        return max(lcs(s1, s2, i+1, j), lcs(s1, s2, i, j+1))
 
 
def lcs(s1, s2, i=0, j=0, lookup=None):
    lookup = {} if lookup is None else lookup
    if (i, j) in lookup:
        return lookup[(i, j)]
    if i == len(s1) or j == len(s2):
        return 0
    elif s1[i] == s2[j]:
        lookup[(i, j)] = 1 + lcs(s1, s2, i+1, j+1, lookup)
        return lookup[(i, j)]
    else:
        lookup[(i, j)] = max(lcs(s1, s2, i+1, j, lookup), lcs(s1, s2, i, j+1, lookup))
        return lookup[(i, j)]
 
 
def lcs(s1, s2):
    n = len(s1)
    m = len(s2)
    dp = [[0]*(m+1) for i in range(n+1)]
    for i in range(1, n+1):
        for j in range(1, m+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[n][m]
 
 
def lcs(s1, s2):
    n = len(s1)
    m = len(s2)
    prev_dp = [0]*(m+1)
    dp = [0]*(m+1)
    for i in range(1, n+1):
        for j in range(1, m+1):
            if s1[i-1] == s2[j-1]:
                dp[j] = 1 + prev_dp[j-1]
            else:
                dp[j] = max(prev_dp[j], dp[j-1])
        prev_dp = dp.copy()
        dp = [0]*(m+1)
    return prev_dp[m]