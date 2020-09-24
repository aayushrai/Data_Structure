x = int(input("enter x: "))
y = int(input("enter y: "))
y = 5

print("Before swap")
print("x=",x)
print("y=",y)

if(x!=y):
    x = x^y
    y = x^y
    x = x^y

print("After Swap")
print("x=",x)
print("y=",y)
