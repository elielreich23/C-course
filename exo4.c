#include <stdio.h>
#include <string.h>

int contarOcorrencias(const char *str1, const char *str2) {
    int ocorrencias = 0;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len2 > len1) {
        return 0; // A segunda string não pode ocorrer na primeira se for maior.
    }

    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str1[i + j] != str2[j]) {
                break;
            }
        }
        if (j == len2) {
            ocorrencias++;
        }
    }

    return ocorrencias;
}

int main() {
    char string1[] = "abracadabra";
    char string2[] = "abra";

    int ocorrencias = contarOcorrencias(string1, string2);

    printf("A segunda string ocorre %d vezes na primeira.\n", ocorrencias);

    return 0;
}
