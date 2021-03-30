def newPassword(a, b):
    # Write your code here
    c = len(a)
    d = len(b)
    
    solstr = ''
    i=j=flag=0
    while(i<len(a) and j<len(b)):
        if(flag==0):
            solstr = solstr+a[i]
            i+=1
            flag=1
        else:
            solstr = solstr+b[j]
            j+=1
            flag=0
    
    while(i<c):
        solstr+=a[i]
        i+=1
        print(0)
    while(j<d):
        solstr+=b[j]
        j+=1
        print(1)

    return solstr

if __name__ == '__main__':
    prf = newPassword("abc","def")
    print(prf)