#include <stdio.h>

int main() {
    int people[50];
    for (int i = 0; i < 50; i++) people[i] = i + 1;
    
    int current = 0;
    int remaining = 50;
    
    while (remaining > 1) {
        current = (current + 4) % remaining;
        printf("淘汰: %d\n", people[current]);
        
        for (int i = current; i < remaining - 1; i++) {
            people[i] = people[i + 1];
        }
        remaining--;
    }
    
    printf("最后剩下的人是: %d\n", people[0]);
    return 0;
}