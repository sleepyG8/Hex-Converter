#include <stdio.h>
#include <Windows.h>

//I wrote this for myself and thought I would share

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Usage:\n-s <strings>\n-f <filename>\n", argv[0]);
    }

    if (strcmp(argv[1], "-s") == 0) {
    char data[1024] = "";
    for (int i = 2; i < argc; i++) {
    strcat(data, argv[i]);
    if (i < argc - 1) {
        strcat(data, " ");
        }
    }

    size_t len = strlen(data);
    for (int i=0; i < len; i++) {
    printf("\\x%02X", (BYTE)(data[i]));
    }
}

    else if (strcmp(argv[1], "-f") == 0) {

    FILE* file = fopen(argv[2], "r+");
    if (!file) return 1;
    
    BYTE buffer[2048];
    size_t bytesRead;

    //while bytesRead is greater than 0 print the bytes
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            printf("\\x%02X", buffer[i]);
        }
    }

    }
    return 0;
}
