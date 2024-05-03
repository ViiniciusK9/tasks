# Parameters:
#  arr: List[int]

# Return type: int

def lis(arr):
    n = len(arr)
    dp = [0] * (n)
    dp[0] = 1
    for i in range(1, n):
        maxn = 0
        for j in range(i):
            if (arr[j] < arr[i] and dp[j] > maxn):
                maxn = dp[j]
            
        dp[i] = 1 + maxn
    
    return max(dp)


arr =  [8, 5, 5, 3]
arr = [7, 5, 2, 4, 7, 2, 3, 6, 4, 5, 12, 1, 7]

print(lis(arr))


""" Instructor code """

def lis(arr, i=0, prev=float("-inf")):
    if i == len(arr):
        return 0
    elif arr[i] <= prev:
        return lis(arr, i+1, prev)
    else:
        return max(1+lis(arr, i+1, arr[i]), lis(arr, i+1, prev))
 
 
def lis(arr):
    def rec(arr, i):
        maxlen = 0
        for j in range(i+1, len(arr)):
            if arr[j] > arr[i]:
                maxlen = max(maxlen, rec(arr, j))
        return 1+maxlen
    return max([rec(arr, i) for i in range(len(arr))])
 
 
def lis(arr):
    def rec(arr, i, lookup=None):
        if i in lookup:
            return lookup[i]
        max_len = 0
        for j in range(i+1, len(arr)):
            if arr[j] > arr[i]:
                max_len = max(max_len, rec(arr, j, lookup))
        lookup[i] = 1+max_len
        return lookup[i]
    lookup = {}
    return max([rec(arr, i, lookup) for i in range(len(arr))])
 
 
def lis(arr):
    n = len(arr)
    dp = [0]*n
    dp[0] = 1
    for i in range(1, n):
        maxlen = 0
        for j in range(i):
            if arr[j] < arr[i] and dp[j] > maxlen:
                maxlen = dp[j]
        dp[i] = 1+maxlen
    return max(dp)