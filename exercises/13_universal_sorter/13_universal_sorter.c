#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*CompareFunc)(const void *, const void *);

int compareInt(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compareFloat(const void *a, const void *b) {
    float diff = (*(float*)a - *(float*)b);
    return (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
}

int compareString(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}

void sort(void *array, size_t n, size_t size, CompareFunc compare) {
    qsort(array, n, size, compare);
}

void processFile(const char *filename) {
    FILE *fin = fopen(filename, "r");
    if (!fin) {
        printf("错误: 无法打开文件 %s\n", filename);
        return;
    }

    int choice, n;
    if (fscanf(fin, "%d", &choice) != 1 || fscanf(fin, "%d", &n) != 1) {
        printf("错误: 文件 %s 格式不正确\n", filename);
        fclose(fin);
        return;
    }

    if (n > 20) n = 20;  // 最多支持20个元素

    printf("=== 处理数据来自: %s ===\n", filename);

    switch (choice) {
        // TODO: 在这里添加你的代码
        case 1:
        {
            int array[20];
            int i = 0;
            while ((fscanf(fin,"%d",&array[i]) == 1)&& i < n)
            {
                i++;
            }
            sort(array,i,sizeof(int),compareInt);
            for(int j = 0; j < n; j++)
            {
                printf("%d",array[j]);
                if (j != n - 1)
                    printf(" ");
            }
            break;
        }
        case 2:
            {            
                float array[20];
                int i = 0;
                while ((fscanf(fin,"%f",&array[i]) == 1) && i < n)
                {
                    i++;
                }
                sort(array,i,sizeof(float),compareFloat);
                for(int j = 0; j < n; j++)
                {
                    printf("%f",array[j]);
                    if (j != n - 1)
                        printf(" ");
                }
                break;
            }
        case 3:
        {
            char array[20][100];
            int i = 0;
            while(fscanf(fin,"%s",&array[i]) == 1)
            {
                i++;
            }
            sort(array, i, sizeof(array[0]),compareString);
            break;
        }
    }

    fclose(fin);
}

int main() {
    processFile("int_sort.txt");
    processFile("float_sort.txt");

    return 0;
}