

def count(n):
    return (n+4)*(n+3)*(n+2)*(n+1)//24


""" Instructor code """    

def count(n, last=''):
    if n == 0:
        return 1
    else:
        nb = 0
        for vowel in ['a', 'e', 'i', 'o', 'u']:
            if last <= vowel:
                nb += count(n - 1, vowel)
        return nb
 
 
def count(n, last='', lookup=None):
    lookup = {} if lookup is None else lookup
    if (n, last) in lookup:
        return lookup[(n, last)]
    if n == 0:
        return 1
    else:
        nb = 0
        for vowel in ['a', 'e', 'i', 'o', 'u']:
            if last <= vowel:
                nb += count(n-1, vowel, lookup)
        lookup[(n, last)] = nb
        return lookup[(n, last)]
 
 
def count(n):
    NB_VOWELS = 5
    dp = [[0] * NB_VOWELS for i in range(n)]
    dp[0] = [1]*NB_VOWELS
    for i in range(1, len(dp)):
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4]
        dp[i][1] = dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4]
        dp[i][2] = dp[i-1][2] + dp[i-1][3] + dp[i-1][4]
        dp[i][3] = dp[i-1][3] + dp[i-1][4]
        dp[i][4] = dp[i-1][4]
    return sum(dp[n-1])
 
 
def count(n):
    NB_VOWELS = 5
    prev = [1] * NB_VOWELS
    curr = [0] * NB_VOWELS
    for i in range(1, n):
        curr[0] = prev[0] + prev[1] + prev[2] + prev[3] + prev[4]
        curr[1] = prev[1] + prev[2] + prev[3] + prev[4]
        curr[2] = prev[2] + prev[3] + prev[4]
        curr[3] = prev[3] + prev[4]
        curr[4] = prev[4]
        for j in range(NB_VOWELS):
            prev[j] = curr[j]
    return sum(prev)
 
 
def count(n):
    return (n+4)*(n+3)*(n+2)*(n+1)//24