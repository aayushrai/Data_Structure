
def count_sq(i,j):
    if i>=len(a) or j>=len(a[0]) or a[i][j] == 0:
        return 0
    if a[i][j] == 1:
        if b[i][j] == -1:
            b[i][j] = 1 + min(count_sq(i+1,j),count_sq(i,j+1),count_sq(i+1,j+1))
        return b[i][j]

if __name__ == "__main__":
    a = [[0,1,1,1],
        [1,1,1,1],
        [0,1,1,1]]
    c = 0
    b = [[-1 for i in range(len(a[0]))] for j in range(len(a))]
    for i in range(len(a)):
        for j in range(len(a[0])):
            c += count_sq(i,j)
    print(c)