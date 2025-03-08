def swap(a,b):
    return b,a

def selectionSort(arr):
    n = len(arr)
    for i in range(n-1):
        min = i
        for j in range(i+1,n):
            if arr[j] < arr[min]:
                min = j
        if min != i:
            arr[i],arr[min] = swap(arr[i],arr[min])

if __name__ == '__main__':
    arr = [9,3,2,5,6]
    selectionSort(arr)
    print(arr)    