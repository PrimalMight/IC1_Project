#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

bool authenticate(){
    char password[16];
    int check_password = 0; // oh my god this is so wrong

    while(check_password == 0){
        printf("\nEnter a password: ");
        gets(password);
        
        if(strcmp(password, "hardcodedpasswordlule")){
            printf("Wrong password, try again.");
        }
        else{
            printf("Very well");
            check_password = 1;
        }
    }

    printf("Flag1 captured -- now it gets harder.");
    return true;
}


int main(){
    printf("Welcome to our text-based capture the flag game!\nIn this game, your goal is to capture all the flags and gain root access to the computer system.\nThe flags are hidden within the program itself and can be captured using various exploits and methods.\nAs you progress through the game, you will encounter challenges and obstacles that you will need to overcome using your technical skills and knowledge.\nEach flag you capture will bring you closer to gaining root access and ultimately stealing all the confidential files on the system.\nBut beware, gaining root access is only half the battle. Your final task will be to leave the system with a bang -- deleting system binaries and files to cover your tracks and be able to blackmail the user.\nAre you up for the challenge? Get ready to test your skills and see if you have what it takes to become the ultimate hacker!\n");

    bool auth = authenticate();
    if(auth){
        // only authenticated should be able to do this (if sudo and is sudoer)
        setuid(0);
        setgid(0);
        printf("hello it gets here xd");
        system("curl -I localhost");

    }

    return 0;
}