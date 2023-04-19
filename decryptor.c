#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char key[100];
    printf("Please provide a password: ");

    fgets(key, 100, stdin);
    key[strcspn(key, "\n")] = '\0';  // remove newline character
    decrypt_file("cipher.txt", key);

}
void decrypt_file(const char *filename, const char *password) {
    FILE *fp_in, *fp_out;
    char ch, key;
    int i = 0;
    int password_length = strlen(password);
    
    fp_in = fopen(filename, "r");
    if (fp_in == NULL) {
        printf("Error opening input file.\n");
        return;
    }

    const char output_filename[100] = "./output_plaintext.txt";
    
    fp_out = fopen(output_filename, "w");
    if (fp_out == NULL) {
        printf("Error opening output file.\n");
        return;
    }
    
    while ((ch = fgetc(fp_in)) != EOF) {
        key = password[i % password_length];
        ch = ch ^ key;
        fputc(ch, fp_out);
        i++;
    }
    
    fclose(fp_in);
    fclose(fp_out);
}
