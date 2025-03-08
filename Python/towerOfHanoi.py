def towerOfHanoi(n,source,destination,auxiliart):
    if(n == 1):
        print("Move disk 1 from source {} to destination {}".format(source,destination))
        return
    towerOfHanoi(n-1,source,auxiliart,destination)
    print("Move disk {} from source {} to destination {}".format(n,source,destination))
    towerOfHanoi(n-1,auxiliart,destination,source)

if __name__ == "__main__":
    towerOfHanoi(3,'A','B','C')