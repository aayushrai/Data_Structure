n = int(input("Enter the Number: "))
k = int(input("Enter value of k: "))

print(bin(n))

l = 1 << (k-1)
n = n ^ l
print(bin(n))
