# NAME : HARSHAL PATIL
# ROLL NO : 44

n=int(input("Enter number of rows : "))
num=1
print("FLOYD's TRIANGLE")

num=1
for i in range(0, n):
    for j in range(0, i+1):
        print(num, end=" ")
        num += 1
    print()

print("REVERSE FLOYD's TRIANGLE")
num-=1
for i in range(n,0,-1):
    for j in range(i,0,-1):
        print(num,end=' ')
        num-=1
    print()

# OUTPUT
"""
Enter number of rows : 5
FLOYD's TRIANGLE
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
REVERSE FLOYD's TRIANGLE
15 14 13 12 11
10 9 8 7
6 5 4
3 2
1
"""