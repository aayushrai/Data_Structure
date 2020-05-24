if __name__ == "__main__":
    price = [2, 4, 5, 6, 1, 5, 2, 2, 23, 51, 3, 5, 1, 45, 6, 14, 2, 2, 41, 44]
    weight = [2, 4, 3, 2, 4, 3, 3, 4, 5, 3, 23, 43, 3, 3, 33, 41, 34, 3, 4, 5]
    capacity = 100
    n = len(price)
    dp = [[0 for i in range(capacity+1)]for j in range(n+1)]
    for i in range(1,n+1):
      for j in range(1,capacity+1):
          if j >= weight[i-1]:
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i-1]]+price[i-1])
          else:
            dp[i][j] = dp[i - 1][j]
    print(dp[-1][-1])