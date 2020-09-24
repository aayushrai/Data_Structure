
def findLongestPath(i,j,n):
	if i<0 or j<0 or i>=len(mat) or j>=len(mat[0]):
		return 0

	if mat[i][j] == n+1:
		return 1+ max(findLongestPath(i,j+1,mat[i][j]),findLongestPath(i+1,j,mat[i][j]),findLongestPath(i,j-1,mat[i][j]),findLongestPath(i-1,j,mat[i][j]))
	return 0




if __name__ == "__main__":
	mat = [[11, 10, 9],  
	[12, 10, 8], 
	[13, 6, 7]]
	mx = 0
	for i in range(len(mat)):
		for j in range(len(mat[0])):
			mx = max(mx,findLongestPath(i,j,mat[i][j]-1))
	print(mx)
