# NAME : HARSHAL PATIL
# ROLL NO : 44

x=int(input("Enter Time in Seconds : "))

h=int(x/3600)
m=int((x-h*3600)/60)
s=int(x-(h*3600+m*60))

print(h,"Hrs",m,"Mins",s,"Secs")

# OUTPUT
"""
Enter Time in Seconds : 12200
3 Hrs 23 Mins 20 Secs
"""

