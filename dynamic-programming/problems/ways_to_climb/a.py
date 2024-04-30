# Parameters:
#  n: int
#  jumps: List[int]

# Return type: int

def ways(n, jumps):

    dp = [0] * (n+1)
    dp[0] = 1

    for i in range(1, n+1):
        for jump in jumps:
            if (i - jump >= 0):
                dp[i] += dp[i-jump]
    
    return dp[n]

n = 10
jumps = [2, 4, 5, 8]

print(ways(n, jumps))


''' Instructor code '''

def ways(n, jumps):
    if n == 0:
        return 1
    elif n < 0:
        return 0
    else:
        nb = 0
        for jump in jumps:
            nb += ways(n-jump, jumps)
        return nb
 
 
def ways(n, jumps, lookup=None):
    lookup = {} if lookup is None else lookup
    if n in lookup:
        return lookup[n]
    if n == 0:
        return 1
    else:
        nb = 0
        for jump in jumps:
            if (n-jump) >= 0:
                nb += ways(n-jump, jumps)
        lookup[n] = nb
        return lookup[n]
 
 
def ways(n, jumps):
    dp = [0]*(n+1)
    dp[0] = 1
    for i in range(1, n+1):
        for jump in jumps:
            if (i-jump) >= 0:
                dp[i] += dp[i-jump]
    return dp[n]