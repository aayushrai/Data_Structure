
# def editDistance(i,j):
# 	if i ==0:
# 		return j
# 	if j ==0:
# 		return i
# 	if str1[i] == str2[j]:
# 		return editDistance(i-1,j-1)
# 	return 1 + min(editDistance(i-1,j),editDistance(i-1,j-1),editDistance(i,j-1))

def editDistance(i,j):
	if i ==0:
		return j
	if j ==0:
		return i

	if dp[i][j]!= -1:
		return dp[i][j]

	if str1[i] == str2[j]:
		dp[i][j] = editDistance(i-1,j-1)
		return dp[i][j]
	dp[i][j] =  1 + min(editDistance(i-1,j),editDistance(i-1,j-1),editDistance(i,j-1))
	return dp[i][j]



if __name__ == "__main__":
	str1 = "geekm"
	str2 = "gesssssekdd"
	dp = [[-1 for i in range(len(str2))]for j in range(len(str1))]


	print(editDistance(len(str1)-1,len(str2)-1))


