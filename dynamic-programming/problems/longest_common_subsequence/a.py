

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


s1 = "abdacbab"
s2 = "acebfca"
print(lcs(s1, s2))