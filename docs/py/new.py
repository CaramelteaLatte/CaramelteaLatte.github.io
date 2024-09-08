b=[1,2,3]
b[2]=b
s = 0
print(b)
for row in b:
    print(row)
    if type(row)==list:
        print(row)
        for elem in row:
            print(elem)
            s += elem
    else:
        s+=row
print(s)