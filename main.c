#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void vulnerable_function(){
    char password[16];
    int check_password = 0; // oh my god this is so wrong

    printf("Enter a password: ");
    gets(password);
    printf("(delete this afterwards) You entered: %s\n", password);

    if(strcmp(password, "hardcodedpasswordlule")){
        printf("Try ageeein");
    }
    else{
        printf("u are in");
        check_password = 1;
    }

    if(check_password){
        // only authenticated should be able to do this (if sudo and is sudoer)
        setuid(0);
        setgid(0);
        system("curl -I localhost");

    }

}

int main(){
    vulnerable_function();
    return 0;
}