
import math


def dfs(i,j,m,n):
	if i >= m or j >= n or i <0 or j<0:
		return False

	if i == m-1 and j == n-1:
		return True

	if grid[i][j] == 1:
		return False
	grid[i][j] = 1

	if grid[i+1][j]==0 and dfs(i+1,j,m,n):
		print(i,j)
		grid[i][j+1]=1 
		return True

	if grid[i][j+1]==0 and dfs(i,j+1,m,n):
		print(i,j)
		grid[i][j]=1 
		return True

	if grid[i][j-1]==0 and dfs(i,j-1,m,n):
		print(i,j)
		grid[i][j-1]=1 
		return True

	if grid[i-1][j]==0 and dfs(i-1,j,m,n):
		print(i,j)
		grid[i-1][j]=1 
		return True

	if grid[i+1][j+1]==0 and dfs(i+1,j+1,m,n):
		print(i,j)
		grid[i+1][j+1]=1 
		return True

	if grid[i+1][j-1]==0 and dfs(i+1,j-1,m,n):
		print(i,j)
		grid[i+1][j-1]=1 
		return True

	if grid[i-1][j+1]==0 and dfs(i-1,j+1,m,n):
		print(i,j)
		grid[i-1][j+1]=1 
		return True

	if grid[i-1][j-1]==0 and dfs(i-1,j-1,m,n):
		print(i,j)
		grid[i-1][j-1]=1 
		return True
	return False




if __name__ == "__main__":
	number_of_row = 5
	number_of_col = 5
	number_of_circles= 1
	radius = 1
	coordinates_of_circles = [(1,1)]

	grid = [[0 for i in range(number_of_col)]for j in range(number_of_row)]

	for k in range(len(coordinates_of_circles)):
		for x in range(number_of_col):
			for y in range(number_of_row):
				dist  = math.sqrt(pow(x-coordinates_of_circles[k][0],2) + pow(y-coordinates_of_circles[k][1],2) )  #Pythagorean theorem
				if dist <= radius:
					grid[x][y] = 1
	print(grid)
	




	
				
	





	
	

