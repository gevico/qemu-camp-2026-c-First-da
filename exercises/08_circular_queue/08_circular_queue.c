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
    int step = 4;


    while(q.count != 0)
    {
        if (q.data[idx].id == 0) 
            {
                idx ++;
                continue;
            }
        idx ++;    
        if (idx >= MAX_PEOPLE)
            idx -=MAX_PEOPLE;
        step --;
        
        if (step == 0)
        {
            if (q.count != 1)
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
            
            step = report_interval;
        }
    }


    return 0;
}