// #include <stdio.h>

// #define MAX_ROW 5
// #define MAX_COL 5

// struct point { int row, col; } stack[512];
// int top = 0;

// void push(struct point p)
// {
// 	stack[top++] = p;
// }

// struct point pop(void)
// {
// 	return stack[--top];
// }

// int is_empty(void)
// {
// 	return top == 0;
// }

// int maze[MAX_ROW][MAX_COL] = {
// 	0, 1, 0, 0, 0,
// 	0, 1, 0, 1, 0,
// 	0, 0, 0, 0, 0,
// 	0, 1, 1, 1, 0,
// 	0, 0, 0, 1, 0,
// };

// struct point predecessor[MAX_ROW][MAX_COL] = {
// 	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
// 	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
// 	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
// 	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
// 	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
// };

// void visit(int row, int col, struct point pre)
// {
// 	struct point visit_point = { row, col };
// 	maze[row][col] = 2;
// 	predecessor[row][col] = pre;
// 	push(visit_point);
// }

// int main(void)
// {
// 	struct point p = { 0, 0 };

// 	maze[p.row][p.col] = 2;
// 	push(p);	
	
// 	while (!is_empty()) {
// 		p = pop();
// 		if (p.row == MAX_ROW - 1  /* goal */
// 		    && p.col == MAX_COL - 1)
// 			break;
// 		if (p.col+1 < MAX_COL     /* right */
// 		    && maze[p.row][p.col+1] == 0)
// 			visit(p.row, p.col+1, p);
// 		if (p.row+1 < MAX_ROW     /* down */
// 		    && maze[p.row+1][p.col] == 0)
// 			visit(p.row+1, p.col, p);
// 		if (p.col-1 >= 0          /* left */
// 		    && maze[p.row][p.col-1] == 0)
// 			visit(p.row, p.col-1, p);
// 		if (p.row-1 >= 0          /* up */
// 		    && maze[p.row-1][p.col] == 0)
// 			visit(p.row-1, p.col, p);
// 	}
// 	if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
// 		printf("(%d, %d)\n", p.row, p.col);
// 		while (predecessor[p.row][p.col].row != -1) {
// 			p = predecessor[p.row][p.col];
// 			printf("(%d, %d)\n", p.row, p.col);
// 		}
// 	} else
// 		printf("No path!\n");

// 	return 0;
// }
#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

typedef struct {
	int pre[2];
} pos;

pos path[MAX_ROW * MAX_COL];
int ptr;

int is_empty()
{
	return ptr;
}

pos top()
{
	return path[ptr];
}

pos pop()
{
	return path[--ptr];
}

pos push(pos element)
{
	return path[ptr++] = element;
}

int main(void)
{
	pos current_pos;
	current_pos.pre[0] = 0;
	current_pos.pre[1] = 0;
	while ((current_pos.pre[0] != 4) && (current_pos.pre[1] != 4))
	{
		//down 
		while ((current_pos.pre[1] <= 4) && (!maze[current_pos.pre[0]][current_pos.pre[1]+1]))
		{
			push(current_pos);
			current_pos.pre[1]++;
		}

		//right
		// if ((current_pos.pre[0] + 1 <= 4) && (!maze[current_pos.pre[0] + 1 ][current_pos.pre[1]]))
		// {
		// 	push(current_pos);
		// 	current_pos.pre[0]++;
		// }
		// else if (maze[current_pos.pre[0] + 1 ][current_pos.pre[1]])
		// {

		// }
		// else if((current_pos.pre[0] + 1 > 4)||)
		// else if 

	}

	return 0;
}