
import time

def LCS(i,j):
    if i >= len(s1) or j >= len(s2):
        return 0
    if s1[i] == s2[j]:
        return 1+LCS(i+1,j+1)
    return max(LCS(i+1,j),LCS(i,j+1))




if __name__ == "__main__":
    s1 = "absfjdskfjdskf"
    s2 = "sejklfjsdklfjsdkl"
    s = time.time()
    print(LCS(0,0))
    e= time.time()
    print(e-s)

    



