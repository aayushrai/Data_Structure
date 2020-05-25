if __name__ == "__main__":
    lst = list(map(int,input().split()))
    k = int(input())
    dis = {}
    total = 0
    bl = False
    for i in range(len(lst)):
        total += lst[i]
        if total == k:
            bl = True
            break
        if (total - k) in dis.keys():
            bl = True
            break
        dis[total] = 1
    print(bl)
    


