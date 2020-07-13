import time



def LCS(i,j):
	if i >= len(s1) or j >= len(s2):
		return 0
	if dp[i][j] != -1:
		return dp[i][j]
	if s1[i] == s2[j]:
		dp[i][j] = 1+LCS(i+1,j+1)
		return dp[i][j]
	dp[i][j] = max(LCS(i+1,j),LCS(i,j+1))
	return dp[i][j]





if __name__ == "__main__":
	s1 = "absefkfjdlfkjkdfjdskfjdskf"
	s2 = "seklfjskajklfjsdklfjsdkl"
	dp = [[-1 for i in range(len(s2))] for j in range(len(s1))]
	s = time.time()
	print(LCS(0,0))
	e = time.time()
	print(e-s)

