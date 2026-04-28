#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int parse_replace_command(const char* cmd, char** old_str, char** new_str) {
    if (cmd[0] != 's' || cmd[1] != '/') {
        return -1;
    }

    char copy[MAX_LINE_LENGTH];
    memset(copy, '\0', MAX_LINE_LENGTH);
    strcpy(copy, cmd);

    *old_str = (char *)malloc(strlen("unix") + 1);
    *new_str = (char *)malloc(strlen("linux") + 1);

    char * ptr = strtok(copy, "/");
    while(ptr != NULL)
    {
        if (strcmp(ptr,"unix") == 0)
            strcpy(*old_str,"unix");
        else if (strcmp(ptr,"linux") == 0)
            strcpy(*new_str,"linux");
        
        ptr = strtok(NULL, "/");
    }

    return 0;
}

void replace_first_occurrence(char* str, const char* old, const char* new) {

    char *find;

    char *ptr = (char *)malloc(MAX_LINE_LENGTH);
    memset(ptr, '\0', MAX_LINE_LENGTH);

    find = strstr(str, old);
    if (find == NULL)
        return;
    
    if (find - str == 0)
    {
        strcat(ptr, new);
        strcat(ptr, find + strlen(old));
    }
    else if (str + strlen(str) == find + strlen(old))
    {
        strncpy(ptr, str, find - str);
        strcat(ptr, new);
    }
    else 
    {
        strncpy(ptr, str, find - str );
        strcat(ptr, new);

        strcat(ptr, find + strlen(old));
    }

    strcpy(str, ptr);
    free(ptr);
}

int main(int argc, char* argv[]) {
    const char* replcae_rules = "s/unix/linux/";

    char line[MAX_LINE_LENGTH] = {"unix is opensource. unix is free os."};

    char* old_str = NULL;
    char* new_str = NULL;
    
    if (parse_replace_command(replcae_rules, &old_str, &new_str) != 0) {
        fprintf(stderr, "Invalid replace command format. Use 's/old/new/'\n");
        return 1;
    }

    
    replace_first_occurrence(line, old_str, new_str);
    fputs(line, stdout);

    free(old_str);
    free(new_str);
    return 0;
}
