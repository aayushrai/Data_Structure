def lcs(i,j):
    if i >= len(s1) and j>=len(s2):
        return 0
    if i >= len(s1):
        return lcs(i,j+1)
    if j >= len(s2):
        return  lcs(i+1,j)
    if s1[i] == s2[j]:
        return 1 + lcs(i+1,j+1)
    else:
        return max(lcs(i,j+1),lcs(i+1,j))

if __name__ == "__main__":
    s1 = "aabcdggdfsafjf"
    s2 = 'aadsffsdsj'
    print(lcs(0,0))