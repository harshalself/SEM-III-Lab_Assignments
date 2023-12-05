# NAME : HARSHAL PATIL
# ROLL NO : 44

m1=int(input("Enter marks of first subject : "))
m2=int(input("Enter marks of second subject : "))
m3=int(input("Enter marks of third subject : "))

if(m1>100)or(m1<0)or(m2>100)or(m2<0)or(m3>100)or(m3<0):
   print("Entered marks are invalid")
else:
    tot=int(m1+m2+m3)
    avg=int(tot/3)
    print("Average marks are",avg)
if(avg>89)and(avg<101):
    print("O Grade")
elif(avg>79)and(avg<90):
    print("A Grade")
elif(avg>69)and(avg<80):
    print("B Grade")
elif(avg>59)and(avg<70):
    print("C Grade")
elif(avg>39)and(avg<60):
    print("D Grade")
else:
    print("Fail")

# OUTPUT
"""
Enter marks of first subject : 80
Enter marks of second subject : 70
Enter marks of third subject : 60
Average marks are 70
B Grade
"""