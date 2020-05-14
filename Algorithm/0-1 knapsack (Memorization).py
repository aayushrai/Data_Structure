
def knapsack(cap,n):
    if n == 0 or cap == 0:
        return 0
    if (cap,n) in dis.keys():
        return dis[(cap,n)]
    if weight[n-1] > cap:
        dis[(cap,n)] = knapsack(cap, n - 1)
        return dis[(cap,n)]
    else:
        dis[(cap,n)] = max(knapsack(cap - weight[n - 1], n - 1) + price[n - 1], knapsack(cap, n - 1))
        return dis[(cap,n)]

if __name__ == "__main__":
    price = [2,4,5,6,1,5,2,2,23,51,3,5,1,45,6,14,2,2,41,44]
    weight = [2,4,3,2,4,3,3,4,5,3,23,43,3,3,33,41,34,3,4,5]
    capacity =  100
    n = len(price)
    dis = {}
    print(knapsack(capacity,n))
