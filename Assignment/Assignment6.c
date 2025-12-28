#include <stdio.h>

int main() {
    char text[100], pattern[50];
    int found = 0;

    scanf("%s", text);
    scanf("%s", pattern);

    for (int i = 0; text[i] != '\0'; i++) {
        int j = 0;
        while (text[i + j] == pattern[j] && pattern[j] != '\0')
            j++;

        if (pattern[j] == '\0') {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Pattern found");
    else
        printf("Pattern not found");

    return 0;
}
