def create(begin,step,n):
    '''
    a = []
    for i in range(n):
        a.append(begin+i*step)
    return a
    '''
    a = []
    count = 0
    while count<n:
        a.append(begin+count * step)
        count+=1
    return a
a = create(3,-4,3)
b = create(4,-3,3)
print(a)
print(b)

def a(n):
    for i in range(1,n+1):
        for j in range(i):
            print('*',end = '')
        print()
    for i in range(n):
        for j in range(n-i):
            print('*',end = '')
        print()
a(5)

for triangle(c,n):
    '''
    for i in range(1,n+1):
        print(i*c)
    '''
    count = 1
    while count<=n:
        print(count*c)
        count+=1
        
triangel('#',3)


for triangle(c,n):
    for i in range(1,n+1):
        print(''*(n-i)+'*'*i)
triangel('#',3)

