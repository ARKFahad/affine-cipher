#include <stdio.h>
#include <string.h>

// Extended Euclidean Algorithm function
int extended_euclidean(int a, int b) {
    if (a == 0)
        return b;
    else
        return extended_euclidean(b % a, a);
}

int main() {
    int a = 27, b = 5, m = 26;
    int a_inv;

    // Calculate multiplicative inverse of 'a' mod m using Extended Euclidean Algorithm
    a_inv = extended_euclidean(a % m, m);

    printf("Multiplicative Inverse: %d\n", a_inv);

    char message[] = "Mjqqt Uwjymjgn";
    int length = strlen(message);
    int encryptedMessage[length];
    
    for (int i = 0; i < length; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            // If the character is a lowercase letter
            encryptedMessage[i] = ((27 * (message[i] - 'a')) + 5) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            // If the character is an uppercase letter
            encryptedMessage[i] = ((27 * (message[i] - 'A')) + 5) % 26;
        } else {
            encryptedMessage[i] = message[i];
        }
    }

    int decryptedMessage[length];

    for (int i = 0; i < length; ++i) {
        if (encryptedMessage[i] >= 'a' && encryptedMessage[i] <= 'z') {
            // If the character is a lowercase letter
            decryptedMessage[i] = ((-1 * a_inv * (encryptedMessage[i] - 'a')) + 5) % m;
            if (decryptedMessage[i] < 0)
                decryptedMessage[i] += m;
        } else if (encryptedMessage[i] >= 'A' && encryptedMessage[i] <= 'Z') {
            // If the character is an uppercase letter
            decryptedMessage[i] = ((-1 * a_inv * (encryptedMessage[i] - 'A')) + 5) % m;
            if (decryptedMessage[i] < 0)
                decryptedMessage[i] += m;
        } else {
            decryptedMessage[i] = encryptedMessage[i];
        }
    }

    printf("DM: ");

    for (int i = 0; i < length; ++i) {
        if (decryptedMessage[i] >= 'a' && decryptedMessage[i] <= 'z') {
            printf("%c", decryptedMessage[i] + 'a');
        } else if (decryptedMessage[i] >= 'A' && decryptedMessage[i] <= 'Z') {
            printf("%c", decryptedMessage[i] + 'A');
        } else {
            printf("%c", decryptedMessage[i]);
        }
    }

    return 0;
}
