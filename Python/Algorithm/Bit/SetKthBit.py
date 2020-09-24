n = int(input("Enter the number: "))
k = int(input("Enter the value of k: "))
print(bin(n))
l = 1 << (k-1)

if l & n:
    print("Kth bit is set")
else:
    print("Kth bit is not set")
