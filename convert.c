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
    out[strlen(out)] = '\0';
}

void oct_to_hex(const char *oct, char *out) {
    char bin[100];
    oct_to_bin(oct, bin);

    int pos = strlen(bin) % 4;
    int hex = 0;
    for (int i = 0; i < pos; i++) {
        hex += ((bin[i] - '0') << i);
    }

    if (pos > 0) out[0] = hex < 10 ? '0' + hex : 'A' + (hex - 10);

    for (int i = 1; i < (strlen(bin) / 4) + 1; i++){
        hex = 0;

        hex += (bin[pos++] - '0') << 3;
        hex += (bin[pos++] - '0') << 2;
        hex += (bin[pos++] - '0') << 1;
        hex += (bin[pos++] - '0') << 0;
        out[i] = hex < 10 ? '0' + hex : 'A' + (hex - 10);
    }
    out[strlen(out)] = '\0';
}