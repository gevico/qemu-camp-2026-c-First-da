#include <stdio.h>

int main() {
    char str[]="Don't ask what your country can do for you, but ask what you can do for your country.";
    int wordCount = 0;

    int i = 0;
    while(str[i++] != '\0')
    {
        if ((str[i] == ' ') && (str[i - 1] != ' ' ))
            wordCount ++;
    }

    printf("单词数量: %d\n", wordCount);
    
    return 0;
}