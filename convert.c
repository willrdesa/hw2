#include <stdint.h>
#include <string.h>
#include <stdio.h>

void oct_to_bin(const char *oct, char *out) {
    int pos = 0;
    for (int i = 0; i < strlen(oct); i++){
        //Extract 3 bits from octal
        int octal_digit = oct[i] - '0';

        //Build binary from octal
        out[pos++] = (octal_digit >> 2) & 1 ? '1' : '0';
        out[pos++] = (octal_digit >> 1) & 1 ? '1' : '0';
        out[pos++] = (octal_digit >> 0) & 1 ? '1' : '0';
    }

    //Terminator
    out[pos] = '\0';
}

void oct_to_hex(const char *oct, char *out) {

    //Convert from octal to binary
    char bin[100];
    oct_to_bin(oct, bin);

    int start = strlen(bin) % 4;
    int pos= 0;
    int i = 0;

    //Handle first bits
    if (start > 0) {
        int hex = 0;
        for (int j = 0; j < start; j++) hex = (hex << 1) | (bin[j] - '0');
        out[pos++] = hex < 10 ? '0' + hex : 'A' + (hex - 10);
        i = start;
    }
    

    //Handle rest in nibbles
    for (int i = start; i < strlen(bin); i += 4) {
        int hex = 0;
        for (int j = 0; j < 4; j++) hex = (hex << 1) | (bin[i + j] - '0');
        out[pos++] = hex < 10 ? '0' + hex : 'A' + (hex - 10);
    }

    //Terminator
    out[pos] = '\0';
}

void hex_to_bin(const char *hex, char *out) {
    int pos = 0;
    for (int i = 0; i < strlen(hex); i++) {
        char c = hex[i];
        int c_num;

        //Validating hex digit
        if (c >= '0' && c <= '9') c_num = c - '0';
        else if (c >= 'A' && c <= 'F') c_num = 10 + (c - 'A');
        else if (c >= 'a' && c <= 'f') c_num = 10 + (c - 'a');

        //Convert hex to bin
        out[pos++] = (c_num >> 3) & 1 ? '1' : '0';
        out[pos++] = (c_num >> 2) & 1 ? '1' : '0';
        out[pos++] = (c_num >> 1) & 1 ? '1' : '0';
        out[pos++] = (c_num >> 0) & 1 ? '1' : '0';
    }

    //Terminator
    out[pos] = '\0';
}

void to_sign_magnitude(int n, char *out) {
    int pos = 0;
    u_int32_t pow = 1 << 30;

    //Handle first bit and negative n
    if(n < 0) {
        n = n * -1;
        out[pos++] = '1';
    } else out[pos++] = '0';

    //Converts dec to bin
    while (pow > 0) {
        int remainder = n / pow;
        n = n % pow;
        out[pos++] = '0' + remainder;

        pow /= 2;
    }

    //Terminator
    out[pos] = '\0';
}

void to_ones_complement(int n, char *out) {
    to_sign_magnitude(n, out);

    //Invert all bits if negative
    if (out[0] == '1') {
        for(int i = 1; i < strlen(out); i++) {
            out[i] = out[i] == '0' ? '1' : '0';
        }
    }
}

void to_twos_complement(int n, char *out) {
    to_sign_magnitude(n, out);

    //Invert all bits but last one if negative
    if (out[0] == '1') {
        for(int i = 1; i < strlen(out) - 1; i++) {
            out[i] = out[i] == '0' ? '1' : '0';
        }
    }
}