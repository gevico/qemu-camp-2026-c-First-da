#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

#if DEBUG_LEVEL==1

#define DEBUG_PRINT(fmt, ...)                               \
    do                                                      \
    {                                                       \
        printf("DEBUG: func=%s, line=%d\n",__func__,__LINE__);  \

    }while(0)       

#elif DEBUG_LEVEL==2

#define DEBUG_PRINT(fmt, ...)                               \
    do                                                      \
    {                                                       \
        printf("DEBUG: func=%s, line=%d, ",__func__,__LINE__);\
        printf(fmt, __VA_ARGS__);\
        printf("\n");\
    }while(0)      

#elif DEBUG_LEVEL==3
#define DEBUG_PRINT(fmt, ...)                           \
    do                                                  \
    {                                                   \
        void *buffer[100];                              \
        int n;                                          \
        printf("DEBUG: func=%s, line=%d, ",__func__,__LINE__);\
        printf(fmt, __VA_ARGS__);                       \
        printf("\n");                                   \
        n = backtrace(buffer,100);                      \
        char **symbols;                            \
        symbols = backtrace_symbols(buffer, n);         \
        for(int i = 0; i < n; i++)                      \
        {                                               \
            printf("%s\n",symbols[i]);                  \
        }                                               \  
        free(symbols);                                  \
    }while(0)
#else
#define DEBUG_PRINT(fmt, ...) do {} while (0)

#endif
void test() {
    int x = 42;
    DEBUG_PRINT("x=%d", x);
}

int main() {
    test();
    return 0;
}