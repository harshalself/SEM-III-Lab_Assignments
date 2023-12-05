# NAME : HARSHAL PATIL
# ROLL NO : 44 

def hamming_encode(data):
    # Calculate the number of parity bits required
    m = len(data)
    r = 1
    while 2 ** r < m + r + 1:
        r += 1

    # Initialize the encoded data with parity bits
    encoded_data = [0] * (m + r)
    j = 0

    # Fill in the data bits
    for i in range(1, m + r + 1):
        if i & (i - 1) != 0:  # Skip positions that are powers of 2
            encoded_data[i - 1] = int(data[j])
            j += 1

    # Fill in the parity bits
    for i in range(r):
        mask = 2 ** i
        parity_bit = 0
        for j in range(1, m + r + 1):
            if j & mask != 0:
                parity_bit ^= encoded_data[j - 1]
        encoded_data[mask - 1] = parity_bit

    return encoded_data

def hamming_decode(encoded_data):
    r = 1
    while 2 ** r < len(encoded_data) + 1:
        r += 1

    error_position = 0
    for i in range(r):
        mask = 2 ** i
        parity_bit = 0
        for j in range(1, len(encoded_data) + 1):
            if j & mask != 0:
                parity_bit ^= encoded_data[j - 1]
        error_position += parity_bit * mask

    if error_position != 0:
        print(f"Error detected at position {error_position}")
        encoded_data[error_position - 1] ^= 1

    # Extract the original data bits
    decoded_data = [encoded_data[i - 1] for i in range(1, len(encoded_data) + 1) if i & (i - 1) != 0]

    return decoded_data

def ascii_to_binary(ascii_string):
    binary_string = ''.join(format(ord(char), '08b') for char in ascii_string)
    return binary_string

def binary_to_ascii(binary_string):
    ascii_string = ''.join([chr(int(binary_string[i:i + 8], 2)) for i in range(0, len(binary_string), 8)])
    return ascii_string

def main():
    # Example ASCII string
    original_ascii = "Hello"

    # Convert ASCII to binary
    original_binary = ascii_to_binary(original_ascii)

    # Add error simulation
    # Uncomment the next line to simulate an error
    # original_binary = original_binary[:5] + '1' + original_binary[6:]

    # Encode using Hamming Code
    encoded_data = hamming_encode(original_binary)

    # Decode using Hamming Code
    decoded_data = hamming_decode(encoded_data)

    # Convert binary to ASCII
    decoded_ascii = binary_to_ascii(''.join(map(str, decoded_data)))

    print("Original ASCII:", original_ascii)
    print("Encoded Data:", ''.join(map(str, encoded_data)))
    print("Decoded ASCII:", decoded_ascii)

if __name__ == "__main__":
    main()
12th.py