

""" Instructor code """

def cost(train_days, costs, n, day=0):
    if day >= n:
        return 0
    elif day not in train_days:
        return cost(train_days, costs, n, day+1)
    else:
        return min(costs[0] + cost(train_days, costs, n, day+1),
                   costs[1] + cost(train_days, costs, n, day+7),
                   costs[2] + cost(train_days, costs, n, day+30))
 
 
def cost(train_days, costs, n, day=0, lookup=None):
    lookup = {} if lookup is None else lookup
    if day in lookup:
        return lookup[day]
    if day >= n:
        return 0
    elif day not in train_days:
        lookup[day] = cost(train_days, costs, n, day+1, lookup)
        return lookup[day]
    else:
        lookup[day] = min(costs[0] + cost(train_days, costs, n, day+1, lookup),
                          costs[1] + cost(train_days, costs, n, day+7, lookup),
                          costs[2] + cost(train_days, costs, n, day+30, lookup))
        return lookup[day]
 
 
def cost(travel_days, costs, n):
    dp = [0]*n
    for i in range(len(dp)):
        if i not in travel_days:
            dp[i] = (dp[i-1] if i-1 >= 0 else 0)
        else:
            day_cost = costs[0] + (dp[i-1] if i-1 >= 0 else 0)
            week_cost = costs[1] + (dp[i-7] if i-7 >= 0 else 0)
            month_cost = costs[2] + (dp[i-30] if i-30 >= 0 else 0)
            dp[i] = min(day_cost, week_cost, month_cost)
    return dp[n-1]
 
 
def cost(train_days, costs, n):
    dp = [0]*31
    print(dp)
    for i in range(len(dp)):
        if i not in train_days:
            dp[30] = (dp[29] if i-1 >= 0 else 0)
        else:
            day_cost = costs[0] + (dp[29] if i-1 >= 0 else 0)
            week_cost = costs[1] + (dp[23] if i-7 >= 0 else 0)
            month_cost = costs[2] + (dp[0] if i-30 >= 0 else 0)
            dp[30] = min(day_cost, week_cost, month_cost)
        for j in range(30):
            dp[j] = dp[j+1]
    return dp[30]