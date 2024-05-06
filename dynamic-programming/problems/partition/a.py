

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


def solve(i, sum, meio, n, v, dp):

    if (i, sum) in dp:
        return dp[(i, sum)]

    if (sum == meio):
        return 1
    
    if (i == n):
        return 0
    
    if (sum > meio):
        return 0
    
    dp[(i, sum)] = max(solve(i+1, sum+v[i], meio, n, v, dp), solve(i+1, sum, meio, n, v, dp))

    return dp[(i, sum)]

  

def partition(arr):

    soma = sum(arr)

    if (soma % 2 == 1):
        return False

    meio = soma/ 2

    if (solve(0, 0, meio, len(arr), arr, {}) == 1):
        return True
    
    return False
    
arr = [5, 6, 2, 3, 8, 1]

print(partition(arr))


def partition(arr):

    s = sum(arr)
    if (s%2 == 1):
        return False
    else:
        return subsets(arr, s//2) > 0
    
arr = [5, 6, 2, 3, 8, 1]

print(partition(arr))


""" Instructor code """

def partition(arr, i=0, sum1=0, sum2=0):
    if i == len(arr):
        return sum1 == sum2
    else:
        return partition(arr, i+1, sum1+arr[i], sum2) or partition(arr, i+1, sum1, sum2+arr[i])
 
 
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
 
 
def partition(arr):
    s = sum(arr)
    if s%2 == 1:
        return False
    else:
        return subsets(arr, s//2) > 0