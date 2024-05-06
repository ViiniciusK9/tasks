# Parameters:
#  amount: int
#  possible_coins: List[int]

# Return type: int

def coins(amount, possible_coins):
    n = amount
    memo = [0] * (n+1)
    inf = 1123456789

    for i in range(1, n+1):
        memo[i] = inf

        for c in possible_coins:
            if (i-c >= 0):
                memo[i] = min(memo[i], memo[i-c]+1)
    
    return  memo[amount] if memo[amount] < inf else -1

amount = 15
possible_coins = [2, 3, 7]

print(coins(amount, possible_coins))


""" Instructor code """

def coins(amount, possible_coins):
    def _coins(amount, possible_coins):
        if amount == 0:
            return 0
        else:
            min_coins = float("inf")
            for coin in possible_coins:
                if (amount-coin) >= 0:
                    min_coins = min(min_coins, 1+_coins(amount-coin, possible_coins))
            return min_coins
    min_coins = _coins(amount, possible_coins)
    return -1 if min_coins == float("inf") else min_coins
 
 
def coins(amount, possible_coins):
    def _coins(amount, possible_coins, lookup=None):
        lookup = {} if lookup is None else lookup
        if amount in lookup:
            return lookup[amount]
        if amount == 0:
            return 0
        else:
            min_coins = float("inf")
            for coin in possible_coins:
                if (amount-coin) >= 0:
                    min_coins = min(min_coins, 1+_coins(amount-coin, possible_coins, lookup))
            lookup[amount] = min_coins
            return lookup[amount]
    min_coins = _coins(amount, possible_coins)
    return -1 if min_coins == float("inf") else min_coins
 
 
def coins(amount, possible_coins):
    dp = [float("inf")]*(amount+1)
    dp[0] = 0
    for i in range(1, amount+1):
        for coin in possible_coins:
            if (i-coin) >= 0:
                dp[i] = min(dp[i], 1+dp[i-coin])
    return -1 if dp[amount] == float("inf") else dp[amount]