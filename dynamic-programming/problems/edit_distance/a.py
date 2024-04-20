# Parameters:
#  word1: str
#  word2: str

# Return type: int

n1 = 0
n2 = 0

def solve(i, j, word1, word2, memo):
    memo = {} if memo is None else memo

    if (i == n1):
        return abs((j) - n2)
    
    if (j == n2):
        return abs((i) - n1)

    if ((i, j) in memo):
        return memo[(i, j)]
    
    if (word1[i] == word2[j]):
        memo[(i, j)] = solve(i+1, j+1, word1, word2, memo)
        return memo[(i, j)] 

    memo[(i, j)]  = min(solve(i+1, j, word1, word2, memo) +1, solve(i+1, j+1, word1, word2, memo) +1, solve(i, j+1, word1, word2, memo) +1)
    return memo[(i, j)] 



def dist(word1, word2):
    global n1, n2
    n1 = len(word1)
    n2 = len(word2)

    return solve(0, 0, word1, word2, None)


w1 = 'inside'
w2 = 'index'

print(dist(w1, w2))


'''
Tutor code
'''

def dist(word1, word2, i=0, j=0):
    if i == len(word1):
        return len(word2)-j
    elif j == len(word2):
        return len(word1)-i
    elif word1[i] == word2[j]:
        return dist(word1, word2, i+1, j+1)
    else:
        return 1 + min(dist(word1, word2, i+1, j), dist(word1, word2, i, j+1), dist(word1, word2, i+1, j+1))
 
 
def dist(word1, word2, i=0, j=0, lookup=None):
    lookup = {} if lookup is None else lookup
    if (i, j) in lookup:
        return lookup[(i, j)]
    if i == len(word1):
        return len(word2)-j
    elif j == len(word2):
        return len(word1)-i
    elif word1[i] == word2[j]:
        lookup[(i, j)] = dist(word1, word2, i+1, j+1)
        return lookup[(i, j)]
    else:
        lookup[(i, j)] = 1 + min(dist(word1, word2, i+1, j), dist(word1, word2, i, j+1), dist(word1, word2, i+1, j+1))
        return lookup[(i, j)]
 
 
def dist(word1, word2):
    n, m = len(word1), len(word2)
    dp = [[0]*(m+1) for i in range(n+1)]
    for j in range(1, m+1):
        dp[0][j] = j
    for i in range(1, n+1):
        dp[i][0] = i
    for i in range(1, n+1):
        for j in range(1, m+1):
            if word1[i-1] == word2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
    return dp[n][m]
 
 
def dist(word1, word2):
    n = len(word1)
    m = len(word2)
    prev_dp = [0]*(m+1)
    dp = [0]*(m+1)
    for j in range(1, m+1):
        prev_dp[j] = j
    for i in range(1, n+1):
        dp[0] = i
        for j in range(1, m+1):
            if word1[i-1] == word2[j-1]:
                dp[j] = prev_dp[j-1]
            else:
                dp[j] = 1 + min(prev_dp[j], dp[j-1], prev_dp[j-1])
        prev_dp = dp
        dp = [0]*(m+1)
    return prev_dp[m]