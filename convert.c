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
    out[strlen(out)] = '\0';
}

void oct_to_hex(const char *oct, char *out) {

    //Convert from octal to binary
    char bin[100];
    oct_to_bin(oct, bin);

    int pos = strlen(bin) % 4;
    int hex = 0;

    //Handle first bits
    for (int i = 0; i < pos; i++) {
        hex += ((bin[i] - '0') << i);
    }
    if (pos > 0) out[0] = hex < 10 ? '0' + hex : 'A' + (hex - 10);

    //Handle rest in nibbles
    for (int i = 1; i < (strlen(bin) / 4) + 1; i++){
        hex = 0;

        //Convert bits to hex
        hex += (bin[pos++] - '0') << 3;
        hex += (bin[pos++] - '0') << 2;
        hex += (bin[pos++] - '0') << 1;
        hex += (bin[pos++] - '0') << 0;
        out[i] = hex < 10 ? '0' + hex : 'A' + (hex - 10);
    }

    //Terminator
    out[strlen(out)] = '\0';
}

void hex_to_bin(const char *hex, char *out) {
    int pos = 0;
    for (int i = 0; i < strlen(hex); i++) {
        char c = hex[i];

        //Validating hex digit
        int c_num = (c - '0');
        if (c_num > 10) {
            if (c >= 'A' && c <= 'F') c_num = c - '7';
            else if (c >= 'a' && c <= 'f') c_num = c - 'W';
            else break;
        }

        //Convert hex to bin
        out[pos++] = (c_num >> 3) & 1 ? '1' : '0';
        out[pos++] = (c_num >> 2) & 1 ? '1' : '0';
        out[pos++] = (c_num >> 1) & 1 ? '1' : '0';
        out[pos++] = (c_num >> 0) & 1 ? '1' : '0';
    }

    //Terminator
    out[strlen(out)] = '\0';
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