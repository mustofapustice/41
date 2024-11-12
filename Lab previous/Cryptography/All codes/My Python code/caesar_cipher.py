def caesar_encrypt(plaintext, shift):
    encrypted_text = ""
    for char in plaintext:
        if char.isalpha():
            if char.islower():
                encrypted_text += chr((ord(char) + shift - ord('a')) % 26 + ord('a'))
               # print("Plain text:", encrypted_text)
            else:
                encrypted_text += chr((ord(char) + shift - ord('A')) % 26 + ord('A'))
               # print("Plain text:", encrypted_text)
        else:
            encrypted_text += char
            #print("Plain text:", encrypted_text)
    return encrypted_text

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


plaintext = input("Enter any line of text: ");
shift_1 = input("Enter the key: ");
# type cast into integer
shift = int(shift_1);
ciphertext = caesar_encrypt(plaintext, shift)
print(f"Caesar Cipher Encryption: {ciphertext}")
plaintext=caesar_decrypt(ciphertext,3)
print(f"Caesar Cipher Decryption: {plaintext}")