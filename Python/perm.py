def swap(a,b):
    return b,a

def perm(list,i,n):
    if i == n:
        for i in range(0,n+1):
            print(list[i],end ='')
        print()
        return
    j = i
    for j in range(n+1):
        list[i],list[j] = swap(list[i],list[j])
        perm(list,i + 1,n)
        list[i],list[j] = swap(list[i],list[j])

if __name__ == '__main__':
    list = ['a','b','c']
    perm(list,0,2)