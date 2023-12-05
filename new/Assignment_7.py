# NAME : HARSHAL PATIL
# ROLL NO : 44

input_string = input("Enter a string: ")
words = input_string.split()
word_length_count = {}

for word in words:
    word_length = len(word)
    if word_length in word_length_count:
        word_length_count[word_length] += 1
    else:
        word_length_count[word_length] = 1

print("Word Length Count:")
print(word_length_count)

# OUTPUT
"""
Enter a string: I scream you scream we all scream for ice cream
Word Length Count:
{1: 1, 6: 3, 3: 4, 2: 1, 5: 1}
"""