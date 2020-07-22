
def knapsack(c,i):
	if i >= len(w):
		return 0
	if w[i] <= c:
		return max(knapsack(c-w[i],i+1)+p[i],knapsack(c,i+1))
	else:
		return knapsack(c,i+1)


if __name__ == "__main__":
	w = [1,2,5,6,7]
	p =[1,6,18,22,28] 
	capacity = 11
	print(knapsack(capacity,0))

	# Bottom up


	dp = [[0 for j in range(capacity+1)] for i in range(len(p)+1) ]

	for i in range(len(p)+1):
		for j in range(capacity+1):
			if w[i-1] <= j:
				dp[i][j] = max(dp[i-1][j-w[i-1]]+p[i-1],dp[i-1][j])
			else:
				dp[i][j] =  dp[i-1][j]
	print(dp[-1][-1])
