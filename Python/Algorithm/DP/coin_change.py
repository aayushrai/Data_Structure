def cc(arr,n,index):
	if n == 0:
		return 1
	if n<0:
		return 0 

	if index<=0:
		return 0

	return cc(arr,n-arr[index-1],index) + cc(arr,n,index-1)


if __name__ == "__main__":
	arr = [2, 3,5,6] 
	n = 10
    dp = [-1 for]
	print(cc(arr,n,len(arr)))
	