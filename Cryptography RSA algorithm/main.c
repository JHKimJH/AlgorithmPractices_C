#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MESSAGE_LENGTH 30

char message[] = {'H','e','l','l','o',',',' ','P','l','e','a','s','e',
    ' ','l','o','v','e',' ','W','o','o','n','g','s','u','p','!','!',
    '!','\0'};
char message2[] = {'M','y', ' ','n','a','m','e',' ','i','s',' ','W','o','o','n','g',' ','s','u','p',' ','K','i','m','.'};

unsigned int encryption[MESSAGE_LENGTH];
char decryption[MESSAGE_LENGTH];

unsigned int do_exp(int c, int key, int N){
    if (key==0){
        return 1;
    }
    unsigned int z = do_exp(c,key/2,N);
    if ((key%2)==0){
        return (z*z)%N;
    }
    else{
        return (c*z*z)%N;
    }
}

struct _node{
    int first;
    int second;
    int third;
};

struct _node *extended_Euclid(int a, int b)
{
    struct _node *n1, *n2;

    n1 = (struct _node *)malloc(sizeof(struct _node));
    n2 = (struct _node *)malloc(sizeof(struct _node));

    if(b == 0) {
        n1->first = 1;
        n1->second = 0;
        n1->third = a;
        return n1;
    }

    else {
        n1 = extended_Euclid(b, a % b);
        n2->first = n1->second;
        n2->second = (n1->first) - (a/b)*(n1->second);
        n2->third = n1->third;
        return n2;
    }
}

void print_encryption(unsigned int e[]){
    printf("Encoding\n");
    for (int i = 0; i< MESSAGE_LENGTH; i++){
        printf("%d ", e[i]);
    }
    printf("\n\n");
}

void print_decryption(char e[]){
    printf("Decoding\n");
    for (int k = 0; k< MESSAGE_LENGTH; k++){
        printf("%c", e[k]);
    }
    printf("\n\n");
}

int main()
{
     int p = 11;
     int q = 17;
     int e = 3;
     unsigned int c;
     int N = p*q;

     int d = extended_Euclid(e,(p-1)*(q-1))->first + (p-1)*(q-1);



     for(int i=0;i<MESSAGE_LENGTH;i++){
        char ch = message[i];
        c = (int)ch;
        encryption[i] = do_exp(c,e,N);
     }
     print_encryption(encryption);

     for(int j=0; j<MESSAGE_LENGTH;j++){
        unsigned int a = encryption[j];
        decryption[j] = (char)(do_exp(a, d, N));
     }

     print_decryption(decryption);




     for(int i=0;i<sizeof(message2);i++){
        char ch = message2[i];
        c = (int)ch;
        encryption[i] = do_exp(c,e,N);
     }
     print_encryption(encryption);

     for(int j=0; j<sizeof(message2);j++){
        unsigned int a = encryption[j];
        decryption[j] = (char)(do_exp(a, d, N));
     }

     print_decryption(decryption);



}
