
import math




if __name__ == "__main__":
	number_of_row = 5
	number_of_col = 5
	number_of_circles= 1
	radius = 1
	coordinates_of_circles = [(2,1),(2,2)]

	grid = [[0 for i in range(number_of_col)]for j in range(number_of_row)]

	for k in range(len(coordinates_of_circles)):
		for x in range(number_of_col):
			for y in range(number_of_row):
				dist  = math.sqrt(pow(x-coordinates_of_circles[k][0],2) + pow(y-coordinates_of_circles[k][1],2) )  #Pythagorean theorem
				if dist <= radius:
					grid[x][y] = 1
	print(grid)
	
	Q = [(0,0)]
	grid[0][0] = 1

	while Q:
		coor = Q.pop(0)
		ele1,ele2 = coor

		#top left
		if (ele1-1 >=0 and ele2-1>=0) and grid[ele1-1][ele2-1] == 0:
			Q.append((ele1-1,ele2-1))
			grid[ele1-1][ele2-1] = 1
		#top right
		if (ele1+1<number_of_col  and ele2-1>=0) and grid[ele1+1][ele2-1] == 0:
			Q.append((ele1+1,ele2-1))
			grid[ele1+1][ele1-1] = 1

		if (ele1+1 <number_of_col and ele2+1<number_of_row) and grid[ele1+1][ele2+1] == 0:
			Q.append((ele1+1,ele2+1))
			grid[ele1+1][ele2+1] = 1

		if (ele1+1 <number_of_col) and grid[ele1+1][ele2] == 0:
			Q.append((ele1+1,ele2))
			grid[ele1+1][ele2] = 1

		if (ele2+1<number_of_row) and grid[ele1][ele2+1] == 0:
			Q.append((ele1,ele2+1))
			grid[ele1][ele2+1] = 1

		if (ele1-1 >=0) and grid[ele1-1][ele2] == 0:
			Q.append((ele1-1,ele2))
			grid[ele1-1][ele2] = 1

		if (ele2-1>=0) and grid[ele1][ele2-1] == 0:
			Q.append((ele1,ele2-1))
			grid[ele1][ele2-1] = 1

		if (ele1-1 >=0 and ele2+1<number_of_row) and grid[ele1-1][ele2+1] == 0:
			Q.append((ele1-1,ele2+1))
			grid[ele1-1][ele1+1] = 1


	print(grid[number_of_col-1][number_of_row-1]==1)










	
				
	





	
	

