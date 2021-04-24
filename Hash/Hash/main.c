#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define TABLE_SIZE 541
#define NAME_SIZE 390
#define EMPTY 0
#define FALSE 0
#define TRUE 1

struct hash{
    char names[NAME_SIZE];
    unsigned short collision;
};

struct hash hash_table[TABLE_SIZE];

int hash1(char str[]){
    int i, h;

    for(i=0,h=0; i<strlen(str); i++){
        h = ((int)str[i]+h)%TABLE_SIZE;
    }
    return h;
}

int hash2(char str[]){
    int i,h;

    for(i=0,h=0; i< strlen(str); i++){
        h = ((int)str[i] + h*h)%TABLE_SIZE;
    }
    return h;
}

int hash_insert1(char name[]){
    int num =0;
    int key = hash1(name);

    while(strcmp(hash_table[key].names, "")!=0){
        hash_table[key].collision++;
        num++;
        key = (num+key)%TABLE_SIZE;
    }

    strcpy(hash_table[key].names, name);
    return key;
}

int hash_insert2(char name[]){
    int num =0;
    int key = hash2(name);

    while(strcmp(hash_table[key].names, "")!=0){
        hash_table[key].collision += 1;
        num++;
        key = (num+key)%TABLE_SIZE;
    }

    strcpy(hash_table[key].names, name);
    return key;
}

void initialize_table(){
    int i;
    for(i=0;i<TABLE_SIZE;i++){
        strcpy(hash_table[i].names, "");
        hash_table[i].collision = 0;
    }
}

int main()
{
    unsigned short collision1, collision2;

    initialize_table();

    FILE* fp1 = fopen("names.txt","r");
    FILE* fp2 = fopen("names.txt","r");

    char name[NAME_SIZE];

    while(fscanf(fp1, "%s", name)!= EOF){
        hash_insert1(name);
    }

    printf("Using Hash1\n");
    for (int i=0;i<TABLE_SIZE;i++){
        if (strcmp(hash_table[i].names, "")== EMPTY){
            printf("table[%d]: EMPTY    %d\n",i, hash_table[i].collision);
        }
        else{
            printf("table[%d]: %s    %d\n", i,hash_table[i].names, hash_table[i].collision);
        }
    }

    for(int e=0; e<TABLE_SIZE; e++){
        collision1 += hash_table[e].collision;
    }

    initialize_table();

    while(fscanf(fp2, "%s", name) != EOF){
        hash_insert2(name);
    }


    printf("\nUsing Hash2\n");
    for(int j = 0; j<TABLE_SIZE; j++){
        if (strcmp(hash_table[j].names, "")== EMPTY){
            printf("table[%d]: EMPTY    %d\n", j, hash_table[j].collision);
        }
        else{
            printf("table[%d]: %s   %d\n", j,hash_table[j].names,hash_table[j].collision);
        }
    }

    for(int w=0; w<TABLE_SIZE; w++){
        collision2 += hash_table[w].collision;
    }


    printf("\nNumber of Collisions:\n");
    printf("Hash 1 collisions: %d\n", collision1);
    printf("Hash 2 collisions: %d\n", collision2);
}
