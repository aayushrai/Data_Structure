n = int(input("Enter the number: "))
print(bin(n))

if n & 1:
    print("position of right most set bit is 1")
else:
    n = n ^ (n & (n-1))
    position = 0
    while n:
        n >>= 1
        position += 1# add 1 to position
    
    print("position of right most set bit is",position)




