
myset = set()

def lis(a): # assumes a != []
    n = len(a)
    dp = [1 for _ in range(n)] 
    # dp[k] = length of LIS with first element a[k]
    max_length = 1
    for k in range(n - 1, -1, -1):
        result = 1
        for i in range(k + 1, n):
            if a[i] > a[k]:
                result = max(result, 1 + dp[i])
        dp[k] = result
        max_length = max(max_length, result)
    
    # printing all LISs
    st = [None for _ in range(max_length)]
    st_index = 0
    def rec(index): # credit: Ivaylo Strandjev
        nonlocal st_index, dp, a
        if dp[index] == 1:
            #print("Another sequence:")
            for i in range(st_index):
                #print(st[i])
                myset.add(st[i])
        for j in range(index + 1, n):
            if dp[j] == dp[index] - 1 and a[j] >= a[index]:
                st[st_index] = a[j]
                st_index += 1
                rec(j)
                st_index -= 1
    # beginning the recursion at each valid index
    for index in range(n):
        if dp[index] == max_length:
            st_index = 1
            st[0] = a[index]
            rec(index)
    return max_length



t = int(input())

while (t):
    myset.clear()
    t-=1
    vet = []
    n = int(input())
    vet = list(map(int, input().split()))

    lis(vet)
    print(len(myset))
    fir = 1
    for i, j in enumerate(vet):
        if (j in myset):
            if (fir == 1):
                fir = 0
                print(i+1, end="")
            else:
                print(" ", end="")
                print(i+1, end="")
    print()