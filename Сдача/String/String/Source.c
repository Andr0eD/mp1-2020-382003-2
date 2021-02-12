#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void foo(const char*, const char*, char*, char);

int main() {
    char s[] = "A few characters c inside";
    char s0[] = "###";
    char c = 'c';
    char result[100];

    foo(s, s0, result, c);
    printf("%s", result);

    return 0;
}

void foo(const char* s, const char* s0, char* result, char c) {
    int index = 0;
    for (int i = 0; i < s[i] != '\0'; i++) 
    {
        if (s[i] == c) 
        {
            for (int j = 0; j < s0[j] != '\0'; j++) 
            {
                result[index++] = s0[j];
            }
        }
        result[index++] = s[i];
    }
    result[index] = '\0';
}