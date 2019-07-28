// Fake anti-virus.c written by kaz

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

char *md5(char *filename) {
    unsigned char c[MD5_DIGEST_LENGTH];
    MD5_CTX mdContext;
    int i, bytes;
    char data[1024];
    char *filemd5 = (char*) malloc(33 * sizeof(char));

    FILE *inFile = fopen(filename, "rb");

    MD5_Init(&mdContext);
    while ((bytes = fread(data,1, 1924, inFile)) != 0) MD5_Update(&mdContext, data, bytes);

    MD5_Final(c, &mdContext);

    for (i = 0; i < MD5_DIGEST_LENGTH; i++) sprintf(&filemd5[i*2], "%02x", (unsigned int)c[i]);

    fclose(inFile);
    return filemd5;
}

void definitions(char *in, char *out[]) {
    char buf[256];
    // char *output[100];
    FILE *f = fopen(in, "r");
    int i;
    int line = 0;
    /*
    while (read = getline()) {
        fscanf(f, "%[^\n]", buf);
        out[line] = buf;
        line++;
    }
    */

    while
    fclose(f);
}

int heuristic(char *definitions[], char *filename) {
    return 1;
}

int main (int argc, char **argv[]) {
    // Function to take a folder in argv[]

    // Hash Check

    // Heuristic Scan

    // Delete

    char *new_md5 = md5("helloworld.txt");
    printf("%s", new_md5);
    printf("\n");
    return 0;
}
