#输出a,b之间的数字，下三角
a = int(input())
b = int(input())
count = 1 #行
numOfEachLine = 1 #列
for i in range(a,b+1):
    if(count==numOfEachLine):
        print("{:<4}".format(i))
        numOfEachLine += 1
        count = 1
    else:
        count+=1
        print("{:<4}".format(i),end=" ")
