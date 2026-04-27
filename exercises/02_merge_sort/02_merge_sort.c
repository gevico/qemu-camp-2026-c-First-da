#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int score;
} Student;

Student students[MAX_STUDENTS];
Student temp[MAX_STUDENTS];

void merge(int left, int mid , int right)
{
    int len = right - left + 1;
    int ptr_left = left;
    int ptr_right = mid + 1;
    Student *copy = (Student *) malloc(sizeof(Student) * len);
    for (int i = 0; i < len; i++)
    {
        if (ptr_left > mid)
        {
            copy[i] = students[ptr_right];
            ptr_right ++;
        }
        else if (ptr_right > right)
        {
            copy[i] = students[ptr_left];
            ptr_left ++;
        }
        else 
        {
            if (students[ptr_left].score > students[ptr_right].score)
            {
                copy[i] = students[ptr_left];
                ptr_left ++;
            }
            else 
            {
                copy[i] = students[ptr_right];
                ptr_right ++;
            }
        }
    }

    int begin_left = left;
    for (int i = 0; i < len; i++)
    {
        students[begin_left++] = copy[i];
    }

    free(copy);
}


void merge_sort(int left, int right) {
    // TODO: 在这里添加你的代码
    int mid = (left + right ) / 2;
    Student temp;
    if (left == right )
        return ;
    else if (left == right - 1)
    {
        if (students[left].score < students[right].score)
            {
                temp = students[left];
                students[left] = students[right];
                students[right] = temp;
            }
        return ;
    }


    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, mid, right);

}

int main(void) {
    FILE *file = fopen("02_students.txt", "r");
    if (!file) {
        printf("错误：无法打开文件 02_students.txt\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    if (n <= 0 || n > MAX_STUDENTS) {
        printf("学生人数无效：%d\n", n);
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%s %d", students[i].name, &students[i].score);
    }
    fclose(file);

    merge_sort(0, n - 1);

    printf("\n归并排序后按成绩从高到低排序的学生名单：\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].name, students[i].score);
    }

    return 0;
}