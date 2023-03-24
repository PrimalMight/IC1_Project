#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void vulnerable_function(){
    char buffer[16];
    printf("Enter a string: ");
    gets(buffer);
    printf("You entered: %s\n", buffer);


}


int main(){
    vulnerable_function();
    return 0;
}