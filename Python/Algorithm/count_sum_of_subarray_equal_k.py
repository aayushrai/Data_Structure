if __name__ == "__main__":
    lst = lst(map(int,input().split()))
    k = int(input())
    count = 0
    dis = {}
    prefixsm = 0
    for i in range(len(lst)):
        prefixsm += lst[i]
        if prefixsm == k:
            count += 1
        if prefixsm - k in dis:
            count += dis[prefixsm - k]
            
        if prefixsm not in dis:
            dis[prefixsm] = 1
        else:
            dis[prefixsm] += 1
    print(count)
                    

