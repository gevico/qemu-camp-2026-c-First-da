#include <stdio.h>
#include <stdbool.h>

#define MAX_PEOPLE 50

typedef struct {
    int id;
} People;

typedef struct {
    People data[MAX_PEOPLE];
    int head;
    int tail;
    int count;
} Queue;

int main() {
    Queue q;
    int total_people=50;
    int report_interval=5;

    // TODO: 在这里添加你的代码
    for (int i = 0;i < MAX_PEOPLE;i++)
    {
        q.data[i].id = i + 1;
        q.count = total_people;
    }

    int idx = 0;
    while(q.count != 0)
    {
        idx = (q.count == total_people) ? idx + q.count - 1 : idx + q.count;
        if (idx > MAX_PEOPLE - 1)
            idx -= MAX_PEOPLE ; 
        if (q.data[idx].id) 
            {
                if (q.count == 1)
                {
                    printf("淘汰: %d\n", q.data[idx].id);
                    q.count --;
                    q.data[idx].id = 0;
                }
                else
                {
                    printf("最后剩下的人是: %d\n", q.data[idx].id);
                    q.count --;
                    q.data[idx].id = 0;
                }
                    
            }
    }

    return 0;
}