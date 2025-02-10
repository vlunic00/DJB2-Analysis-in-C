#include <stdio.h>
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

    if(argc != 2)
        printf("Error: Only one argument is expected.\n");

    printf("Calculating djb2 hash...\n");


    unsigned long resulting_hash = djb2(argv[1]);

    printf("Resulting hash value: %lu", resulting_hash);

}