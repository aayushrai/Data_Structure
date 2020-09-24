n = int(input("Enter the  number: "))
print(bin(n))

if n & (n-1):
    print("Not power of 2")
else:
    print("power of 2")
