#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
int height=45,width=45;
int i,j,k,in;
#define N 9


int isSafe(int input[N][N], int row, int col, int num);
int findEmptyLocation(int input[N][N], int *row, int *col);
int solveSudoku(int input[N][N]);
void draw(int input[N][N]);

int main() {
    int input[N][N] = {
        {4, 0, 0, 0, 0, 6, 8, 0, 0},
        {2, 0, 0, 8, 0, 0, 0, 0, 9},
        {9, 0, 1, 0, 0, 3, 0, 5, 6},
        {0, 0, 9, 6, 8, 0, 0, 0, 2},
        {0, 1, 0, 0, 0, 0, 5, 9, 0},
        {0, 0, 8, 0, 0, 9, 7, 0, 0},
        {0, 2, 4, 0, 9, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 4, 0, 0},
        {0, 0, 7, 3, 0, 0, 0, 0, 0}
    };

    if (solveSudoku(input) == 1)
      draw ( input);
    else
        printf("No solution exists");

    return 0;
}

int isSafe(int input[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++)
        if (input[row][x] == num || input[x][col] == num)
            return 0;
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (i = 0; i < 3; i++)
        for ( j = 0; j < 3; j++)
            if (input[i + startRow][j + startCol] == num)
                return 0;

    return 1;
}

int findEmptyLocation(int input[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (input[*row][*col] == 0)
                return 1;
    return 0;
}

int solveSudoku(int input[N][N]) {
    int row, col;

    if (!findEmptyLocation(input, &row, &col))
        return 1; 

    for (int num = 1; num <= 9; num++) {
        if (isSafe(input, row, col, num)) {
            input[row][col] = num;
            if (solveSudoku(input))
                return 1;
            input[row][col] = 0; 
        }
    }

    return 0;
}

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%d ", grid[row][col]);
        printf("\n");
    }
}

void draw(int input[N][N])
{
for (i=0;i<=height;i++)
{
for(j=0;j<=width;j++)
{
  if(i==0||i==height||i%15==0||j==0||j==width||j%15==0)
  { 
     printf("\033[41m-\033[0m");
  }
  else{
  if((i%5==0&&i%15!=0)||(j%5==0&&j%15!=0))
  { 
  printf(".");
  }
  else{
  if(i==3&&j==2)
  {
  printf("%d",input[0][0]);
  }
  else if(i==3&&j==8)
  {
  printf("%d",input[0][1]);
  }
  else if(i==3&&j==13){
  printf("%d",input[0][2]);
  }
  else if(i==3&&j==18){
  printf("%d",input[0][3]);
  }
  else if(i==3&&j==23)
  {
  printf("%d", input [0][4]);
  }
  else if(i==3&&j==28)
  {
   printf("%d",input[0][5]);
  }
  else if(i==3&&j==33)
  {
   printf("%d",input[0][6]);
  }
  else if(i==3&&j==38)
  {
   printf("%d",input[0][7]);
  }
  else if(i==3&&j==43)
  {
   printf("%d",input[0][8]);
  }
  else if(i==8&&j==3)
  {
   printf("%d",input[1][0]);
  }else if(i==8&&j==8)
  {
   printf("%d",input[1][1]);
  }else if(i==8&&j==13)
  {
   printf("%d",input[1][2]);
  }else if(i==8&&j==18)
  {
   printf("%d",input[1][3]);
  }else if(i==8&&j==23)
  {
   printf("%d",input[1][4]);
  }else if(i==8&&j==28)
  {
   printf("%d",input[1][5]);
  }else if(i==8&&j==33)
  {
   printf("%d",input[1][6]);
  }else if(i==8&&j==38)
  {
   printf("%d",input[1][7]);
  }else if(i==8&&j==43)
  {
   printf("%d",input[1][8]);
  }
  else if(i==13&&j==3)
  {
   printf("%d",input[2][0]);
  }else if(i==13&&j==8)
  {
   printf("%d",input[2][1]);
  }else if(i==13&&j==13)
  {
   printf("%d",input[2][2]);
  }else if(i==13&&j==18)
  {
   printf("%d",input[2][3]);
  }else if(i==13&&j==23)
  {
   printf("%d",input[2][4]);
  }else if(i==13&&j==28)
  {
   printf("%d",input[2][5]);
  }else if(i==13&&j==33)
  {
   printf("%d",input[2][6]);
  }else if(i==13&&j==38)
  {
   printf("%d",input[2][7]);
  }else if(i==13&&j==43)
  {
   printf("%d",input[2][8]);
  }else if(i==18&&j==3)
  {
   printf("%d",input[3][0]);
  }else if(i==18&&j==8)
  {
   printf("%d",input[3][1]);
  }else if(i==18&&j==13)
  {
   printf("%d",input[3][2]);
  }else if(i==18&&j==18)
  {
   printf("%d",input[3][3]);
  }else if(i==18&&j==23)
  {
   printf("%d",input[3][4]);
  }else if(i==18&&j==28)
  {
   printf("%d",input[3][5]);
  }else if(i==18&&j==33)
  {
   printf("%d",input[3][6]);
  }else if(i==18&&j==38)
  {
   printf("%d",input[3][7]);
  }else if(i==18&&j==43)
  {
   printf("%d",input[3][8]);
  }else if(i==23&&j==3)
  {
   printf("%d",input[4][0]);
  }else if(i==23&&j==8)
  {
   printf("%d",input[4][1]);
  }else if(i==23&&j==13)
  {
   printf("%d",input[4][2]);
  }else if(i==23&&j==18)
  {
   printf("%d",input[4][3]);
  }else if(i==23&&j==23)
  {
   printf("%d",input[4][4]);
  }else if(i==23&&j==28)
  {
   printf("%d",input[4][5]);
  }else if(i==23&&j==33)
  {
   printf("%d",input[4][6]);
  }else if(i==23&&j==38)
  {
   printf("%d",input[4][7]);
  }else if(i==23&&j==43)
  {
   printf("%d",input[4][8]);
  }
  else if(i==28&&j==3)
  {
   printf("%d",input[5][0]);
  }else if(i==28&&j==8)
  {
   printf("%d",input[5][1]);
  }else if(i==28&&j==13)
  {
   printf("%d",input[5][2]);
  }else if(i==28&&j==18)
  {
   printf("%d",input[5][3]);
  }else if(i==28&&j==23)
  {
   printf("%d",input[5][4]);
  }else if(i==28&&j==28)
  {
   printf("%d",input[5][5]);
  }else if(i==28&&j==33)
  {
   printf("%d",input[5][6]);
  }else if(i==28&&j==38)
  {
   printf("%d",input[5][7]);
  }else if(i==28&&j==43)
  {
   printf("%d",input[5][8]);
  }
  else if(i==33&&j==3)
  {
   printf("%d",input[6][0]);
  }else if(i==33&&j==8)
  {
   printf("%d",input[6][1]);
  }
  else if(i==33&&j==13)
  {
   printf("%d",input[6][2]);
  }else if(i==33&&j==18)
  {
   printf("%d",input[6][3]);
  }else if(i==33&&j==23)
  {
   printf("%d",input[6][4]);
  }else if(i==33&&j==28)
  {
   printf("%d",input[6][5]);
  }else if(i==33&&j==33)
  {
   printf("%d",input[6][6]);
  }else if(i==33&&j==38)
  {
   printf("%d",input[6][7]);
  }else if(i==33&&j==43)
  {
   printf("%d",input[6][8]);
  }
  else if(i==38&&j==3)
  {
   printf("%d",input[7][0]);
  }else if(i==38&&j==8)
  {
   printf("%d",input[7][1]);
  }else if(i==38&&j==13)
  {
   printf("%d",input[7][2]);
  }else if(i==38&&j==18)
  {
   printf("%d",input[7][3]);
  }else if(i==38&&j==23)
  {
   printf("%d",input[7][4]);
  }else if(i==38&&j==28)
  {
   printf("%d",input[7][5]);
  }else if(i==38&&j==33)
  {
   printf("%d",input[7][6]);
  }else if(i==38&&j==38)
  {
   printf("%d",input[7][7]);
  }else if(i==38&&j==43)
  {
   printf("%d",input[7][8]);
  }else if(i==43&&j==3)
  {
   printf("%d",input[8][0]);
  }else if(i==43&&j==8)
  {
   printf("%d",input[8][1]);
  }else if(i==43&&j==13)
  {
   printf("%d",input[8][2]);
  }else if(i==43&&j==18)
  {
   printf("%d",input[8][3]);
  }else if(i==43&&j==23)
  {
   printf("%d",input[8][4]);
  }else if(i==43&&j==28)
  {
   printf("%d",input[8][5]);
  }else if(i==43&&j==33)
  {
   printf("%d",input[8][6]);
  }else if(i==43&&j==38)
  {
   printf("%d",input[8][7]);
  }else if(i==43&&j==43)
  {
   printf("%d",input[8][8]);
  }
  else{
  printf(" ");
  }
  }
  }
  }
  printf("\n");
  }
  }
  
  