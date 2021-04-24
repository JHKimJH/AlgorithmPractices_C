#include <stdio.h>
#include <stdlib.h>

#define MESSAGE_LENGTH 55

unsigned int do_XOR(unsigned int c, unsigned int key){
    return c^key;
}

char message[] = {"Welcome to Algorithm Practices. this is WoongSup Kim!"};

unsigned int encryption[MESSAGE_LENGTH];
char decryption[MESSAGE_LENGTH];

int main()
{
    int count = 0;
    for(int i=0;i < MESSAGE_LENGTH; i++){
        unsigned int c = (unsigned int)message[i];
        encryption[i] = do_XOR(c, 0x5);
    }
   for(int j=0; j < MESSAGE_LENGTH; j++){
        printf("%u",encryption[j]);
        count++;
    }

    printf("\n");

    for(int i=0;i < MESSAGE_LENGTH; i++){
        unsigned int ch = (unsigned int)encryption[i];
        decryption[i] = (char)do_XOR(ch, 0x5);
    }
    for(int j=0; j < MESSAGE_LENGTH; j++){
        printf("%c",decryption[j]);
        count++;
    }
    //print(decryption[]);


}
