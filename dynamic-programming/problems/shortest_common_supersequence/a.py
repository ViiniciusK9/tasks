# Parameters:
#  s1: str
#  s2: str

# Return type: int

def scs(s1, s2):

    n = len(s1)
    m = len(s2)
    
    dp_at = [0] * (m + 1)
    dp_prev = [0] * (m + 1)

    for i in range(0, m+1):
        dp_prev[i] = i

    for i in range(1, n+1):
        dp_at[0] = i
        for j in range(1, m+1):
            if (s1[i-1] == s2[j-1]):
                dp_at[j] = dp_prev[j-1] + 1
            else:
                dp_at[j] = 1 + min(dp_at[j-1], dp_prev[j])
        
        dp_prev = dp_at.copy()

    return dp_prev[len(s2)]


s1 = "abdacebfcab"
s2 = "acebfca"

print(scs(s1, s2))


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
 
 
def scs(s1, s2):
    return len(s1) + len(s2) - lcs(s1, s2)
 
 
def scs(s1, s2, i=0, j=0):
    if i == len(s1):
        return len(s2)-j
    elif j == len(s2):
        return len(s1)-i
    elif s1[i] == s2[j]:
        return 1 + scs(s1, s2, i+1, j+1)
    else:
        return 1 + min(scs(s1, s2, i+1, j), scs(s1, s2, i, j+1))
 
 
def scs(s1, s2, i=0, j=0, lookup=None):
    lookup = {} if lookup is None else lookup
    if (i, j) in lookup:
        return lookup[(i, j)]
    if i == len(s1):
        return len(s2)-j
    elif j == len(s2):
        return len(s1)-i
    elif s1[i] == s2[j]:
        lookup[(i, j)] = 1 + scs(s1, s2, i+1, j+1, lookup)
        return lookup[(i, j)]
    else:
        lookup[(i, j)] = 1 + min(scs(s1, s2, i+1, j, lookup), scs(s1, s2, i, j+1, lookup))
        return lookup[(i, j)]
 
 
def scs(s1, s2):
    n, m = len(s1), len(s2)
    dp = [[0]*(m+1) for i in range(n+1)]
    for j in range(1, m+1):
        dp[0][j] = j
    for i in range(1, n+1):
        dp[i][0] = i
    for i in range(1, n+1):
        for j in range(1, m+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1])
    return dp[n][m]
 
 
def scs(s1, s2):
    n, m = len(s1), len(s2)
    prev_dp = [0]*(m+1)
    dp = [0]*(m+1)
    for j in range(1, m+1):
        prev_dp[j] = j
    for i in range(1, n+1):
        dp[0] = i
        for j in range(1, m+1):
            if s1[i-1] == s2[j-1]:
                dp[j] = 1 + prev_dp[j-1]
            else:
                dp[j] = 1 + min(prev_dp[j], dp[j-1])
        prev_dp = dp
        dp = [0]*(m+1)
    return prev_dp[m]