a = []
for row in range(3):
	b = []
	for col in range(2):
		b.append(1)
	a.append(b)
print(a)
#[[1,1],[1,1],[1,1]]


a = []
b = []
for row in range(3):
	for col in range(2):
		b.append(1)
	a.append(b)
print(a)
#a[1][0] = 5 均会改


a = []
for row in range(3):
	b = []
	for col in range(2):
		b.append((row+1)*(col+1))
	a.append(b)
c = a#浅复制
print(a)


a = []
for row in range(3):
	b = list(map(int,input("").split()))
print(a)

a = []
for row in range(3):
	b = []
	for col in range(2):
		b.append(list(map,input().split()))
	a.append(b)
print(a)

a = []
while(True):
	b = list(list(map,input().split()))
	if len(b) == 0:
		break
	a.append(b)
print(a)


