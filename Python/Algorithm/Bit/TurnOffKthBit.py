n = int(input("Enter the number: "))
k = int(input("Enter value of k: "))

print(bin(n))
l = 1 << (k-1)
l = ~l

n = n & l

print(bin(n))
