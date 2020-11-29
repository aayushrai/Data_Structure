heap = [11,9,4,7,8,3,1,2,5,6]

def minHeapify(ele,n):
    smallest = ele
    left  = (2*ele) + 1
    right = (2*ele) + 2
    if left < n and (heap[smallest] > heap[left]):
        smallest = left 
    if right < n and (heap[smallest] > heap[right]):
        smallest = right 
    if(smallest != ele):
        temp = heap[smallest]
        heap[smallest] = heap[ele]
        heap[ele] = temp
        minHeapify(smallest,n)
        
print("building minHeap")
for i in range((len(heap)//2)-1,-1,-1):
    minHeapify(i,len(heap))       
print(heap)

print("Printing minHeap")
for i in range((len(heap)//2)):
    print("root:",heap[i],"left child:",(2*i)+1 < len(heap) and heap[(2*i)+1],"right child:",(2*i)+2 < len(heap) and heap[(2*i)+2])

# print("heap sort")
# for i in range(len(heap)-1,0,-1):
#     heap[0],heap[i] = heap[i],heap[0]
#     minHeapify(0,i)   
# print(heap)
    
# kth min element
n =len(heap)
def extractMin(n):
    heap[0],heap[n-1] = heap[n-1],heap[0]
    n -= 1
    minHeapify(0,n)
    return n

k = 1
 
for i in range(k-1):
    n = extractMin(n)
print(heap[0])
