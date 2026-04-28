#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * URL参数解析器
 * 输入：包含http/https超链接的字符串
 * 输出：解析出所有的key-value键值对，每行显示一个
 */

int parse_url(const char* url) {
    int err = 0;

    char array[100] ;
    memset(array,'\0',100);
    strcpy(array,url);

    char *ptr = strchr(array, '?');
    if (ptr == NULL)
        return err;

    char * rest;
    char * key;
    char * value;

    while (1)
    {
        ptr++;
        rest = ptr;
        ptr = strchr(ptr,'&');
        if (ptr == NULL)
            break;
        *ptr = '\0';

        value = strchr(rest, '=');
        *value = '\0'; 
        printf("key = %s, value = %s\n", rest, value + 1); 
    }
    value = strchr(rest, '=');
    *value = '\0'; 
    printf("key = %s, value = %s\n", rest, value + 1); 

exit:
    return err;
}

int main() {
    const char* test_url = "https://cn.bing.com/search?name=John&age=30&city=New+York";

    printf("Parsing URL: %s\n", test_url);
    printf("Parameters:\n");

    parse_url(test_url);

    return 0;
}