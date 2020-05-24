
if __name__ == "__main__":
    a = [[1,0, 1, 0, 0],
         [1,0, 1, 1, 1],
         [1, 1, 1, 1,1],
         [1,0,0,1,0]]
    dp = [[0 for i in range(len(a[0]) + 1)] for j in range(len(a)+ 1)]
    larg = 0
    for i in range(1,len(a)+1):
        for j in range(1,len(a[0])+1):
            if a[i-1][j-1] == 1:
                dp[i][j] =  (1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]))
            if larg < dp[i][j]:
                larg = dp[i][j]

    print(larg*larg)