n = int(input("enter the number: "))
k = int(input("enter the k value: "))
print(bin(n))

l = 1 << (k-1)
n = n | l
print(bin(n))
