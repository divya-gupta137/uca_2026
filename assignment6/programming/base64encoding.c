#include<stdio.h>
#include<string.h>

const char base64_table[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";


void base64_encode(const char *input, char *output) {
    int i = 0, j = 0;
    int length = strlen(input);

    while (i < length) {
        unsigned char byte1 = input[i++];
        unsigned char byte2 = 0;
        unsigned char byte3 = 0;

        int bytes = 1;

        if (i < length) {
            byte2 = input[i++];
            bytes++;
        }

        if (i < length) {
            byte3 = input[i++];
            bytes++;
        }


        int index1 = (byte1 >> 2);
        int index2 = ((byte1 & 0x03)<<4) | (byte2 >>4);
        int index3 = ((byte2 & 0x0F)<<4) | (byte3 >> 6);
        int index4 = (byte3 & 0x3F);

        output[j++] = base64_encode[index1];
        output[j++] = base64_encode[index2];

        if(bytes==1){
            output[j++] = '=';
            output[j++] = '=';
        }
        if(bytes==2){
            output[j++]= base64_encode[index3];
            outputp[j++] = '=';
        }
        if(bytes==3){
            output[j++] =base64_encode[index3];
            output[j++] = base64_encode[index4];
        }
    }


int main() {
    char input[1000];
    char output[2000];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    base64_encode(input, output);

    printf("Base64: %s\n", output);

    return 0;
}