#include "mywc.h"

// 创建哈希表
WordCount **create_hash_table() {
  WordCount **hash_table = calloc(HASH_SIZE, sizeof(WordCount *));
  return hash_table;
}

// 简单的哈希函数
unsigned int hash(const char *word) {
  unsigned long hash = 5381;
  int c;
  while ((c = *word++))
    hash = ((hash << 5) + hash) + c; // hash * 33 + c
  return hash % HASH_SIZE;
}

// 检查字符是否构成单词的一部分
bool is_valid_word_char(char c) { return isalpha(c) || c == '\''; }

// 转换为小写
char to_lower(char c) { return tolower(c); }

// 添加单词到哈希表
void add_word(WordCount **hash_table, const char *word) {
  //如果单词已存在，那么就count + 1
  //如果单词不存在，那么就创建节点

  int index = hash(word);
  int find_flag = 0;
  struct WordCount * ptr = hash_table[index];
  if ((ptr != NULL) && (strcmp(word, hash_table[index]->word) == 0))
      {
          hash_table[index]->count ++;
      }
  else 
      {
          while ((ptr != NULL) && (ptr->next != NULL))
          {
            ptr = ptr->next;
            if (strcmp(word, ptr->word) == 0)
                {
                    ptr->count++;
                    find_flag = 1;
                    break;
                }
          }

          //创建新节点
          if (find_flag == 0)
            {
                WordCount *new_Node = (WordCount *)malloc(sizeof(WordCount));
                strcpy(new_Node->word, word);
                new_Node->count = 1;
                new_Node->next = NULL;
                if (ptr == NULL)
                  hash_table[index] = new_Node;
                else
                  ptr->next = new_Node;
            }
      }


}

// 打印单词统计结果
void print_word_counts(WordCount **hash_table) {
  printf("Word Count Statistics:\n");
  printf("======================\n");

  int index = 0;
  WordCount *ptr;
  while(index < HASH_SIZE)
  {
    if (hash_table[index] != NULL)
        {
            printf("%-21s%d\n", hash_table[index]->word, hash_table[index]->count);
            ptr = hash_table[index];
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
                printf("%-21s%d\n", ptr->word, ptr->count);
            }
        }
      
    index ++;
  }
}

void free_node(WordCount *hash_node)
{
    if (hash_node->next != NULL)
      free_node(hash_node->next);
    free(hash_node);
}

// 释放哈希表内存
void free_hash_table(WordCount **hash_table) {
    int index = 0;
    WordCount *ptr;
    WordCount *ptr_next;
    while(index < HASH_SIZE)
    {
        if (hash_table[index] != NULL)
            free_node(hash_table[index]);
        index ++;
    }
    free(hash_table);
}

// 处理文件并统计单词
void process_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  WordCount **hash_table = create_hash_table();
  char word[MAX_WORD_LEN];
  int word_pos = 0;
  int c;

  while ((c = fgetc(file)) != EOF) {
    if (is_valid_word_char(c)) {
      if (word_pos < MAX_WORD_LEN - 1) {
        word[word_pos++] = to_lower(c);
      }
    } else {
      if (word_pos > 0) {
        word[word_pos] = '\0';
        add_word(hash_table, word);
        word_pos = 0;
      }
    }
  }

  // 处理文件末尾的最后一个单词
  if (word_pos > 0) {
    word[word_pos] = '\0';
    add_word(hash_table, word);
  }

  fclose(file);
  print_word_counts(hash_table);
  free_hash_table(hash_table);
}
