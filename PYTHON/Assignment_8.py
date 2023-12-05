# NAME : HARSHAL PATIL
# ROLL NO : 44

set1 = {1, 2, 3, 4, 5}
set2 = {4, 5, 6, 7, 8}

print("Set 1:", set1)
print("Set 2:", set2)

union_set = set1.union(set2)
print("Union of Set 1 and Set 2:", union_set)

intersection_set = set1.intersection(set2)
print("Intersection of Set 1 and Set 2:", intersection_set)

difference_set = set1.difference(set2)
print("Difference between Set 1 and Set 2:", difference_set)

symmetric_difference_set = set1.symmetric_difference(set2)
print("Symmetric Difference between Set 1 and Set 2:", symmetric_difference_set)

set1.add(6)
print("Set 1 after adding element 6:", set1)

set2.remove(8)
print("Set 2 after removing element 8:", set2)

is_subset = set1.issubset(set2)
print("Is Set 1 a subset of Set 2:", is_subset)

is_superset = set1.issuperset(set2)
print("Is Set 1 a superset of Set 2:", is_superset)

# OUTPUT
"""
Set 1: {1, 2, 3, 4, 5}
Set 2: {4, 5, 6, 7, 8}
Union of Set 1 and Set 2: {1, 2, 3, 4, 5, 6, 7, 8}
Intersection of Set 1 and Set 2: {4, 5}
Difference between Set 1 and Set 2: {1, 2, 3}
Symmetric Difference between Set 1 and Set 2: {1, 2, 3, 6, 7, 8}
Set 1 after adding element 6: {1, 2, 3, 4, 5, 6}
Set 2 after removing element 8: {4, 5, 6, 7}
Is Set 1 a subset of Set 2: False
Is Set 1 a superset of Set 2: False
"""