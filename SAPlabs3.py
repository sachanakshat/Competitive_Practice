def hasVowels(strArr, query):
    sol = []
    finalsum = []
    vowels = ['a','e','i','o','u']
    for i in strArr:
        if(i[0] in vowels and i[-1] in vowels):
            sol.append(1)
        else:
            sol.append(0)
    
    for j in query:
        que = j.split("-")
        for k in range(0,len(que)):
            que[k] = int(que[k])-1
        sum=0
        print(que)
        for l in range(que[0],que[1]+1):
            sum = sum+sol[l]
        finalsum.append(sum)
    return finalsum

if __name__ == '__main__':
    prf = hasVowels(['yy','u','oe'], ['1-2', '2-3'])
    print(prf)