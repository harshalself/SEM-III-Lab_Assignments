# NAME : HARSHAL PATIL
# ROLL NO : 44

my_list = [7,'HARSHAL',0.5,'PATIL',99,'DIV-B']
def display_elements(lst):
    for element in lst:
        if isinstance(element, (int, float)):
            print(element)
            print(element)
            print(element)
        else:
            print(element + '#')

display_elements(my_list)

# OUTPUT
"""
7
7
7
HARSHAL#
0.5
0.5
0.5
PATIL#
99
99
99
DIV-B#
"""