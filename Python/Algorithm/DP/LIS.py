

if __name__ == "__main__":

	arr =[10,22,42,9, 33, 21, 50, 41] 
	dp = [1 for i in range(len(arr))]
	for i in range(len(arr)):
		for j in range(0,i):
			if arr[j]<arr[i] and dp[i]< dp[j] + 1 :
				dp[i] += 1
	print(dp)
	print(max(max(dp),0))