

def goldMine(i,j):
	if i<0 or j<0 or i>=n or j>=m:
		return 0

	if dp[i][j] == -1:
		dp[i][j] = gold[i][j]+max(goldMine(i+1,j+1),goldMine(i-1,j+1),goldMine(i,j+1))

	return dp[i][j]


if __name__ == "__main__":
	gold = [[1, 3, 1, 5], 
			[2, 2, 4, 1], 
			[5, 0, 2, 3], 
			[0, 6, 1, 2]] 
  
m = 4
n = 4

dp = [[-1 for i in range(m)]for j in range(n)]
mx = gold[0][0]
for i in range(n):
	mx = max(mx,goldMine(i,0))
print(dp)
print(mx)
