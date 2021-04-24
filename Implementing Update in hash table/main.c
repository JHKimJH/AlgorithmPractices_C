#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 11
#define NAME_SIZE 390
#define EMPTY 0
#define FALSE 0
#define TRUE 1

struct hash{
    char name[15];
    unsigned short collision;
    int index;
};

struct hash hash_table[TABLE_SIZE];


int random[9];

int hash(char str[]){
    int i, h=0;

    for(i=0; i< strlen(str); i++){
        h += (str[i]*random[i]);
    }
    return h%TABLE_SIZE;
}



int hash_insert(char name[]){
    int num =0;
    int key = hash(name);
    int original = 0;
    original = key;
    printf("key: %d\n", key);
    if (strcmp(hash_table[key].name, "")!=0){
        while((strcmp(hash_table[key].name, "")!=0) && (strcmp(hash_table[key].name, name) != 0)){
            hash_table[key].collision++;
            num++;
            key = ((num*num)+key)%TABLE_SIZE;
            printf("%d\n",key);
        }
        if(strcmp(hash_table[key].name, name) == 0){
            printf("%s is already located in hash table.\n", name);
            }
        if(hash_table[original].index != 100){
            while(hash_table[original].index != 100){
                original = hash_table[original].index;
            }
        }
        hash_table[original].index = key;
        strcpy(hash_table[key].name, name);
        hash_table[key].index = 100;
        }
    else if(strcmp(hash_table[key].name, name) == 0){
        printf("%s is already located in hash table.\n", name);
    }
    else{
        strcpy(hash_table[key].name, name);
        hash_table[key].index = 100;
    }

    return key;
}


void hash_delete(int key, char data[]){
    int prev;
    if(strcmp(hash_table[key].name, data)!=0){
        while(strcmp(hash_table[key].name, data)!=0){
        prev = key;
        key = hash_table[key].index;
        }
        strcpy(hash_table[key].name, "");
        hash_table[prev].index = 100;
        hash_table[key].collision = 0;
    }
    else{
        strcpy(hash_table[key].name, "");
        hash_table[key].collision = 0;

    }
}


void update(char data[], char replace[]){
    int key = hash(data);

    hash_delete(key,data);
    hash_insert(replace);

}

void initialize_table(){
    int i;
    for(i=0;i<TABLE_SIZE;i++){
        strcpy(hash_table[i].name, "");
        hash_table[i].collision = 0;
        hash_table[i].index = 00;
    }
}

int main()
{
    unsigned short collision;
    srand(time(NULL));

    for (int j=0;j<=9;j++){
        random[j] = rand()%TABLE_SIZE;
    }

    initialize_table();


    int exist = 0;
    char data[10];
    char replace[10];
    int choice = 0;
    int key = 0;



    while(1){
        printf("Press the number you want to do: \n");
        printf("1.Insert Data\n2.Update Data\n3.Delete Data\n4.Show Table\n5.Terminate programme\n\n");
        scanf("%d", &choice);
        printf("\n");

        if(choice == 1){
            printf("Type the data to insert: \n");
            scanf(" %s", &data);
            hash_insert(data);
            printf("\n");
        }
        else if(choice == 2){
            printf("Type the data you want to replace: ");
            scanf("%s %s", &data, &replace);
            update(data, replace);
            printf("\n");
        }
        else if(choice == 3){
            printf("Type the data to delete: \n");
            scanf(" %s", &data);
            key = hash(data);
            hash_delete(key, data);
            printf("\n");
        }
        else if(choice == 4){
            printf("Data in Hash table\n");
            for (int i=0;i<TABLE_SIZE;i++){
                if (strcmp(hash_table[i].name, "")== EMPTY){
                    printf("table[%d]: EMPTY%3d\n",i, hash_table[i].collision);
                }
                else{
                    if(hash_table[i].index == 100){
                        printf("table[%d]: %s%4d     \n", i,hash_table[i].name, hash_table[i].collision);
                    }
                    else{
                        printf("table[%d]: %s%4d     %d\n", i,hash_table[i].name, hash_table[i].collision, hash_table[i].index);
                    }
                }
            }
            printf("\n");
        }
        else if(choice == 5){
            printf("Terminate.");
            break;
        }
    }
}
