def solve(i, qnt, memo, weights):

    if (qnt == 0):
        return 1

    if (i == len(weights)):
        return 0
    
    if (i, qnt) in memo:
        return memo[(i, qnt)]

    if (weights[i] > qnt):
        memo[(i, qnt)] = solve(i+1, qnt, memo, weights)
        return memo[(i, qnt)]

    memo[(i, qnt)] = solve(i+1, qnt, memo, weights) + solve(i+1, qnt - weights[i], memo, weights)
    return memo[(i, qnt)]

def subsets(arr, k):

    return solve(0, k, {}, arr)


arr = [1, 2, 3, 1]
k = 4

arr = [1, 1, 1, 1, 1, 1, 1]
k = 2

print(subsets(arr, k))

""" Instructor code """

def subsets(arr, k, i=0):
    if k == 0:
        return 1
    elif i == len(arr) or k < 0:
        return 0
    else:
        return subsets(arr, k-arr[i], i+1) + subsets(arr, k, i+1)
 
 
def subsets(arr, k, i=0, lookup=None):
    lookup = {} if lookup is None else lookup
    if (i, k) in lookup:
        return lookup[(i, k)]
    if k == 0:
        return 1
    elif i == len(arr) or k < 0:
        return 0
    else:
        lookup[(i, k)] = subsets(arr, k-arr[i], i+1, lookup) + subsets(arr, k, i+1, lookup)
        return lookup[(i, k)]
 
 
def subsets(arr, k):
    n = len(arr)
    if k > sum(arr) or n == 0:
        return 0
    dp = [[0]*(k+1) for i in range(n)]
    dp[0][0] = 1
    if arr[0] <= k:
        dp[0][arr[0]] = 1
    for i in range(1, n):
        for j in range(k + 1):
            dp[i][j] = dp[i-1][j] + (dp[i-1][j-arr[i]] if j-arr[i] >= 0 else 0)
    return dp[n-1][k]
 
 
def subsets(arr, k):
    n = len(arr)
    if k > sum(arr) or n == 0:
        return 0
    prev_dp = [0]*(k+1)
    dp = [0]*(k+1)
    prev_dp[0] = 1
    if arr[0] <= k:
        prev_dp[arr[0]] = 1
    for i in range(1, n):
        for j in range(k+1):
            dp[j] = prev_dp[j] + (prev_dp[j-arr[i]] if j-arr[i] >= 0 else 0)
        prev_dp = dp
        dp = [0]*(k+1)
    return prev_dp[k]