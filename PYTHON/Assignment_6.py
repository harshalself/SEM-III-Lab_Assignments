# NAME : HARSHAL PATIL
# ROLL NO : 44

sample_data = [('item1', '13.10'), ('item2', '17.10'), ('item3', '25.3')]

# Convert the second element of each tuple to float for sorting
sorted_data = sorted(sample_data, key=lambda x: float(x[1]), reverse=True)

print("Expected Output:", sorted_data)

# OUTPUT
"""
Expected Output: [('item3', '25.3'), ('item2', '17.10'), ('item1', '13.10')]
"""