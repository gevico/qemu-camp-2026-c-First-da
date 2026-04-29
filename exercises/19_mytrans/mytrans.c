// mytrans.c
#include "myhash.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char *str) {
    // TODO: 在这里添加你的代码
    int i = 0;
    int idx = 0;
    char temp [1024];
    memset(temp, '\0', 1024);
    while (str[i] != '\0')
    {
        if ((str[i] == '\n') || (str[i] == '\r'))
            {
                i++;
                continue;
            }    
        else 
            temp[idx] = str[i];
            
        idx ++;
        i++;
    }
    strcpy(str, temp);
}

int load_dictionary(const char *filename, HashTable *table,
                    uint64_t *dict_count) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("无法打开词典文件");
    return -1;
  }

  char line[1024];
  char current_word[100] = {0};
  char current_translation[1024] = {0};
  int in_entry = 0;

    // TODO: 在这里添加你的代码
    memset(line, '\0', 1024);
    while (fgets(line, 1024, file) != NULL)
    {
        trim(line);
        if (line[0] == '#')
            {    
                strcpy(current_word, line + 1);
            }
        if (strncmp(line, "Trans:", 6) == 0)
            {
                strcpy(current_translation, line + 6);
                hash_table_insert(table, current_word, current_translation);
                memset(line, '\0', 1024);
                memset(current_word, '\0', 100);
                memset(current_translation, '\0', 1024);
                in_entry ++;
            }        
    }

  *dict_count = in_entry;
  fclose(file);
  return 0;
}
