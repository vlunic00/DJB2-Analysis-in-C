#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long djb2(char *input){

    unsigned long hash = 5381;

    int c;
    while (c = *input++ ){
        hash = hash * 33  + c;
    }
    return hash;
}

int main(int argc, char *argv[])
{
    int test_cases = 10000;
    char str1[100], str2[100];
    unsigned long hash1, hash2;

    if(argc != 2){
        printf("Error: One argument is expected. Use test to test djb2's collision resistance, and any other string to find its hash.\n");
        return 0;
    }

    if (strcmp(argv[1], "test")){
        hash1 = djb2(argv[1]);
        printf("Resulting hash value: %d\n", hash1);
        return 0;
    }
    else{
        for (int i = 0; i < test_cases; i++){
            for (int j = i + 1; j < test_cases; j++){
                sprintf(str1, "test%d", i);
                sprintf(str2, "test%d", j);
                hash1 = djb2(str1);
                hash2 = djb2(str2);

                if(hash1 == hash2){
                    printf("Collision found!\n");
                    printf("String 1: %s (Hash: %lu)", str1, hash1);
                    printf("String 2: %s (Hash: %lu)", str2, hash2);
                    return 0;
                }
            }
        }
            printf("No collisions found for %d test strings", test_cases);
            return 0;
    }

}