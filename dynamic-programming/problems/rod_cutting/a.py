# Parameters:
#  prices: List[int]
#  n: int

# Return type: int

def rod(prices, n, dp = None):

    dp = {} if dp is None else dp

    if n == 0:
        return 0

    if n in dp:
        return dp[n]
    
    ans = 0
    for i in range(1, len(prices)):
        if (i <= n):
            ans = max(ans, rod(prices, n-i, dp) + prices[i])
    
    dp[n] = ans
    return ans

n = 8
prices = [0, 1, 3, 5, 6, 7, 9, 10, 11]

n = 1

prices = [0, 8]

print(rod(prices, n))


""" Instructor code """

def rod(prices, n):
    max_price = 0
    for length in range(1, n+1):
        max_price = max(max_price, prices[length]+rod(prices, n-length))
    return max_price
 
 
def rod(prices, n, lookup=None):
    lookup = {} if lookup is None else lookup
    if n in lookup:
        return lookup[n]
    max_price = 0
    for length in range(1, n+1):
        max_price = max(max_price, prices[length]+rod(prices, n-length, lookup))
    lookup[n] = max_price
    return lookup[n]
 
 
def rod(prices, n):
    dp = [0]*(n+1)
    for i in range(1, n+1):
        for length in range(1, i+1):
            dp[i] = max(dp[i], prices[length]+dp[i-length])
    return dp[n]