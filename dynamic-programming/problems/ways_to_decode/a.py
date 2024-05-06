
def ways(s):

    if (s[0] == '0'):
        return 0
    
    if (len(s) == 1):
        return 1
    n = len(s)

    before = 1
    prev = int(s[1] != '0') + int(s[0] == '1' or (s[0] == '2' and s[1] <= '6'))

    for i in range(2, n):
        dp = 0
        if (s[i] != '0'):
            dp += prev
        if (s[i-1] == '1' or (s[i-1] == '2' and s[i] <= '6')):
            dp += before
        
        before = prev
        prev = dp

    return prev


s = "19"

print(ways(s))

""" Instructor code """

def ways(s, i=0):
    if i == len(s):
        return 1
    elif s[i] == "0":
        return 0
    elif i+1 < len(s) and "10" <= s[i]+s[i+1] <= "26":
        return ways(s, i+1) + ways(s, i+2)
    else:
        return ways(s, i+1)
 
 
def ways(s, i=0, lookup=None):
    lookup = {} if lookup is None else lookup
    if i in lookup:
        return lookup[i]
    if i == len(s):
        return 1
    elif s[i] == "0":
        return 0
    elif i+1 < len(s) and "10" <= s[i]+s[i+1] <= "26":
        lookup[i] = ways(s, i+1, lookup) + ways(s, i+2, lookup)
        return lookup[i]
    else:
        lookup[i] = ways(s, i+1, lookup)
        return lookup[i]
 
 
def ways(s):
    n = len(s)
    dp = [0]*n
    if s[0] == "0":
        return 0
    elif len(s) == 1:
        return 1
    dp[0] = 1
    dp[1] = int(s[1] != "0") + int("10" <= s[0]+s[1] <= "26")
    for i in range(2, n):
        if s[i] != "0":
            dp[i] += dp[i-1]
        if "10" <= s[i-1]+s[i] <= "26":
            dp[i] += dp[i-2]
    return dp[n-1]
 
 
def ways(s):
    n = len(s)
    if s[0] == "0":
        return 0
    elif len(s) == 1:
        return 1
    before_prev_dp = 1
    prev_dp = int(s[1] != "0") + int("10" <= (s[0]+s[1]) <= "26")
    for i in range(2, n):
        dp = 0
        if s[i] != "0":
            dp += prev_dp
        if "10" <= (s[i-1]+s[i]) <= "26":
            dp += before_prev_dp
        before_prev_dp = prev_dp
        prev_dp = dp
    return prev_dp