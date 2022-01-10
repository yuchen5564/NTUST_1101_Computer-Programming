#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

#define N 12

typedef enum { RIGHT, UP, LEFT, DOWN }face;


/*
* 輸入
* 找到右邊起點
* 以左邊為基準，移動
* 輸出
*/

int Left_test(face p, int x, int y,char* pos) {   //回傳1表示有牆，0表示沒牆
    switch (p) {
    case RIGHT:
        if (pos[1] == '#') return 1;
        else return 0;
    case UP:
        if (pos[2] == '#') return 1;
        else return 0;
    case LEFT:
        if (pos[3] == '#') return 1;
        else return 0;
    case DOWN:
        if (pos[0] == '#') return 1;
        else return 0;
    }
}

int Front_test(face p, int x, int y, char* pos) {
    switch (p) {
    case RIGHT:
        if (pos[0] == '#') return 1;
        else return 0;
    case UP:
        if (pos[1] == '#') return 1;
        else return 0;
    case LEFT:
        if (pos[2] == '#') return 1;
        else return 0;
    case DOWN:
        if (pos[3] == '#') return 1;
        else return 0;
    }
    
}

void move(face p, int* x, int* y,char* pos) {
    switch (p) {
    case RIGHT:
        if (pos[0] != '#') (*x)++;
        break;
    case UP:
        if (pos[1] != '#') (*y)--;
        break;        
    case LEFT:
        if (pos[2] != '#') (*x)--;
        break;
    case DOWN:
        if (pos[3] != '#') (*y)++;
        break;
    }
    
}

int main()
{
    char maze[N][N+1] = { '\0' };
    int x = 0, y = 0;
    //======================================
    //輸入
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N+1; j++) {
            scanf("%c", &maze[i][j]);
            if ((j == 0) && (maze[i][j]) == 'X') {
                x = j;
                y = i;
                maze[y][x] = 'R';
            }
        }
    }

    //======================================
    //執行
    face p = RIGHT;
    char position[4] = { '\0' };
    
    do {
        position[1] = maze[y - 1][x];//up
        position[3] = maze[y + 1][x];//down
        position[0] = maze[y][x + 1];//right
        position[2] = maze[y][x - 1];//left
        if (Left_test(p, x, y, &position) == 1) {
            if (Front_test(p, x, y, &position) == 1) {
                //右轉
                if (p == 0) p = 3;
                else p--;                
            }
            else if (Front_test(p, x, y, &position) == 0) {
                //前進
                move(p, &x, &y, &position);
                maze[y][x] = 'R';
            }
        }
        else if (Left_test(p, x, y, &position) == 0) {
            //左轉
            if (p == 3) p = 0;
            else p++;
            move(p, &x, &y, &position);
            maze[y][x] = 'R';
        }
        //printf("%.2d (%.2d, %.2d, %d)\n",t, x, y, p);
    } while (x != N - 1 && x != 0);

    //======================================
    //輸出
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    if (x == 0) {
        printf("This maze has no solution\n");
    }
    return 0;
}