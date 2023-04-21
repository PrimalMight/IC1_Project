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
            // check_password = 1; // nah you have to overflow this
        }
    }

    printf("\n Flag1 captured -- now, second flag needs firstly encrypt cipher.txt in order to continue, co please continue");
    return true;
}

bool isFilepresent(const char *filename2){
        FILE *fp = fopen(filename2, "r");
        bool is_exists = false;
        if (fp != NULL){
		is_exists = true;
        }else {
		fp = fopen(filename2, "w");
		char someText[] = "What is long, hard and has *cum* in the middle?\n";
		fprintf(fp, "%s", someText);
		//system("touch riddle_me_this_batman.txt && echo 'What is long, hard and has *cum* in the middle?' >> riddle_me_this_batman.txt");
	}
	fclose(fp);
	return is_exists;
}


char* generate_password() {
    static char password[9];  // create static buffer to hold password
    int i;
    int x = 65; 

    for (i = 0; i < 8; i++) {
        password[i] = (char) x;
        x++;
        if (x == 127) {  // wrap around to start of printable ASCII characters
            x = 33;
        }
    }
    password[8] = '\0';  // add null terminator to end of string

    return password;
}

void encrypt_file(const char *filename, const char *password) {
    FILE *fp;
    char ch, key;
    int i = 0;
    int password_length = strlen(password);
    
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    while ((ch = fgetc(fp)) != EOF) {
        key = password[i % password_length];
        ch = ch ^ key;
        fseek(fp, -1, SEEK_CUR);
        fputc(ch, fp);
        i++;
    }
    
    fclose(fp);
}


int main(){
    printf("Welcome to our text-based capture the flag game!\nIn this game, your goal is to capture all the flags and gain root access to the computer system.\nThe flags are hidden within the program itself and can be captured using various exploits and methods.\nAs you progress through the game, you will encounter challenges and obstacles that you will need to overcome using your technical skills and knowledge.\nEach flag you capture will bring you closer to gaining root access and ultimately stealing all the confidential files on the system.\nBut beware, gaining root access is only half the battle. Your final task will be to leave the system with a bang -- deleting system binaries and files to cover your tracks and be able to blackmail the user.\nAre you up for the challenge? Get ready to test your skills and see if you have what it takes to become the ultimate hacker!\n");

    bool auth = authenticate();
    if(auth){
        // only authenticated should be able to do this (if sudo and is sudoer)
        setuid(0);
        setgid(0);
        char choice;
        printf("\nDo you want to check for running http localhost service? (y/n): ");
        scanf(" %c", &choice);        
        if(choice == 'y' || choice == 'Y') {
            system("curl -I localhost");
        }else {
            printf("\nSkipping localhost service check.\n");
        }
    }
	
	printf("\n Now for the next flag, program needs to make and encrypt .txt file, Now you object is exploit this program for root privilages and decrypting this secret file");
        char *filename2 = "riddle_me_this_batman.txt";
        if(isFilepresent(filename2)){
                printf("\nFile exists, no encryption is needed \n");
        }else {
                printf("\nFile dont exists, encryption is needed \n");
                char *password = generate_password();
                encrypt_file("riddle_me_this_batman.txt", password);
        }

/* 
    char filename[100];
    char choice_encrypt;
    char choice_decrypt;
    printf("\nDo you want to encrypt file? (y/n): ");
    scanf(" %c", &choice_encrypt);
    getchar();
 
    if(choice_encrypt == 'y' || choice_encrypt == 'Y') {
        printf("\nEnter filename to encrypt: ");
        fgets(filename, 100, stdin);
        filename[strcspn(filename, "\n")] = '\0';  // remove newline character
        char *password = generate_password();
        encrypt_file(filename, password);
    }
*/

   

}
