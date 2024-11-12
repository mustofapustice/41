def brute_force_decrypt(ciphertext):
    for shift in range(26):
        decrypted_text = caesar_decrypt(ciphertext, shift)
        print(f"Shift {shift}: {decrypted_text}")

def caesar_decrypt(ciphertext, shift):
    decrypted_text = ""
    for char in ciphertext:
        if char.isalpha():
            if char.islower():

                decrypted_text += chr((ord(char) - shift - ord('a')) % 26 + ord('a'))
            else:
                decrypted_text += chr((ord(char) - shift - ord('A')) % 26 + ord('A'))
        else:
            decrypted_text += char
    return decrypted_text

#ciphertext = "khoor"
ciphertext = input("Enter ciphertext: ");
print("Brute Force Decryption for Caesar Cipher:")
brute_force_decrypt(ciphertext)
