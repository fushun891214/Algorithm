def exponentiate(x,n):
    m = n
    power = 1
    z = x
    while(m > 0):
        while(m % 2 == 0):
            m //= 2
            z *= z
        m -= 1
        power *= z
    return power

if __name__ == '__main__':
    print(exponentiate(2,5))