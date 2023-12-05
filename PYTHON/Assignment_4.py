# NAME : HARSHAL PATIL
# ROLL NO : 44

password = input("Enter Password : ")
c=0
upper=False
lower=False
numeric=False

for i in password :
	c=c+1
	x=ord(i)
	if(x>64 and x<91):
		upper=True
	if(x>96 and x<123):
		lower=True
	if(x>47 and x<58):
		numeric=True				

if c>=8:
	if(upper and lower and numeric):
		print("Password '"+password+"' is Valid")
	else:
		print("Password '"+password+"' is Invalid")
else:
	print("Warning : Must include atleast 8 characters")		

if (upper==False):
	print("Warning : Must include atleast one Uppercase")
if (lower==False):
	print("Warning : Must include atleast one Lowercase")
if (numeric==False):
	print("Warning : Must include atleast one Numeric")

# OUTPUT
"""
Enter Password : HarshalPatil1
Password 'HarshalPatil1' is Valid
"""