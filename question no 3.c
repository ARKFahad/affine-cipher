#include <stdio.h>
#include <string.h>

int main() {
    int a = 27, b = 5, m = 26;

    char message[] = "Hello Prethebi";
    int length = strlen(message);
    char encryptedMessage[length];

    printf("OM: %s\n", message);//OM is Original Message

    
    for (int i = 0; i < length; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {// If the character is a lowercase letter
            encryptedMessage[i] = ((a * (message[i] - 'a')) + b) % m;
            if (encryptedMessage[i] < 0)
                encryptedMessage[i] += m;
            encryptedMessage[i] += 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {//for uppercase letter
            encryptedMessage[i] = ((a * (message[i] - 'A')) + b) % m;
            if (encryptedMessage[i] < 0)
                encryptedMessage[i] += m;
            encryptedMessage[i] += 'A';
        } else {
            encryptedMessage[i] = message[i];
        }
    }

    
    printf("EM: ");// EM is Encrypted Message

    
    for (int i = 0; i < length; ++i) {
        printf("%c", encryptedMessage[i]);
    }

    printf("\n");

    return 0;
}

