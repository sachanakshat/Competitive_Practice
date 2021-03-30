str = "HelLo World"

str = list(str)
dcn = {}
finalword = []

for i in str:
    if i in dcn:
        dcn[i] = dcn[i]+1
    else:
        dcn[i] = 1

alphabets = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")

for i in alphabets:
    if i in str or i.lower() in str:
        if i in str:
            finalword.append(i*dcn[i])
        else:
            finalword.append(i.lower()*dcn[i.lower()])

str = ''.join(finalword)
print(str)
j = len(str)
for i in range(len(str)/2):
    print(str[i] + str[len(str)-i-1])