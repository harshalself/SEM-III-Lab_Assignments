# NAME : HARSHAL PATIL
# ROLL NO : 44

my_list=[]
n=int(input("Enter number of elements : "))
print("Enter list elements : ")
for i in range (n):
    num=int(input())
    my_list.append(num)
print(my_list)
print("Sum of elements in the list",sum(my_list))
print("Maximum element in the list",max(my_list))
print("Minimum element in the list",min(my_list))
avg=sum(my_list)/n
print("Average of elements in the list",avg)
my_list.sort()
print("List after sort operation")
print(my_list)
my_list.reverse()
print("Reverse of a list")
print(my_list)

# OUTPUT
"""
Enter number of elements : 5
Enter list elements :
60
54
77
23
11
[60, 54, 77, 23, 11]
Sum of elements in the list 225
Maximum element in the list 77
Minimum element in the list 11
Average of elements in the list 45.0
List after sort operation
[11, 23, 54, 60, 77]
Reverse of a list
[77, 60, 54, 23, 11]
"""

