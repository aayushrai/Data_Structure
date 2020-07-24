import time
# def CutRod(n):
# 	if n <=0:
# 		return 0
# 	mx = -float("inf")
# 	for i in range(n):
# 		mx = max(mx,price_arr[i]+CutRod(n-i-1))
# 	return mx


# if __name__ == "__main__":
# 	price_arr = [1, 5, 8, 9, 10, 17, 17, 20] 
# 	size = len(price_arr) 
# 	print(CutRod(size))

def CutRod(n):
	if n <=0:
		return 0
	if dp[n] != -1:
		return dp[n]
	mx = -float("inf")
	for i in range(n):
		mx = max(mx,price_arr[i]+CutRod(n-i-1))
	dp[n] = mx
	return mx



if __name__ == "__main__":
	price_arr = [1, 5, 8, 9, 10, 17, 17, 20] 
	size = len(price_arr)
	dp = [-1 for i in range(size+1)] 
	s =time.time()
	print(CutRod(size))
	e =time.time()
	print("time taken",e-s)
po=