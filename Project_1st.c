#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
void input(int size,int arr[][size])
{
    int n = size*size-1;
    int num[n];
    int i,j,index,lastIndex =n-1;
    for(i=0;i<n;i++)
    {
        num[i]=i+1;
    }
    srand(time(NULL));
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(lastIndex>=0)
            {
              index = rand() % (lastIndex+1);
              arr[i][j] = num[index];
              num[index] = num[lastIndex--];
            }
        }
    }
    arr[i-1][j-1] = 0;

}
void showMatrix(int size,int arr[][size])
{
    int i,j;
    printf("-------------\n");
    for(i=0;i<size;i++)
    {
        printf("|");
        for(j=0;j<size;j++)
        {
           if(arr[i][j]!=0)
            printf("%2d | ",arr[i][j]);
           else
            printf("   | ");
        }
         printf("\n");
    }
    printf("-------------\n");
}
int readEnteredKey()
{
    char x;
    x=getch();
    if(x==-32)
      x=getch();
    return x;
}
int Winner(int size,int arr[][size])
{
   int i,j,k=1;
   for(i=0;i<size;i++)
   {
      for(j=0;j<size;j++,k++)
      {
         if(arr[i][j] !=k && k !=(size*size))
          break;
      }
      if(j<size)
       break;
   }
   if(j<size)
    return 0;
   return 1;

}

void gameRule(int size,int arr[][size])
{

    system("cls");

    int i, j, k = 1;

    printf("\t\t  MATRIX PUZZLE\n");
    printf("\n");
    printf(ANSI_COLOR_RED "                 RULE OF THIS GAME                 \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "\n1.You can move only 1 step at a time by arrow key " ANSI_COLOR_RESET);
    printf("\n\tMove Up   : by Up arrow key ");
    printf("\n\tMove Down : by Down arrow key");
    printf("\n\tMove Left : by Left arrow key");
    printf("\n\tMove Right: by Right arrow key");

    printf(ANSI_COLOR_RED "\n2.You can move number at empty position only " ANSI_COLOR_RESET);
    printf("\n");
    printf(ANSI_COLOR_RED "\n3. For each valid move : your total number of move will decreased by 1 \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "4. Wining situation : " ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED " Number in a 4*4 matrix should be in order from 1 to 15 " ANSI_COLOR_RESET);
    printf("\n\n            winning situation:         \n");

    printf(ANSI_COLOR_YELLOW "----------------\n" ANSI_COLOR_RESET);

    for (i = 0; i < size; i++)
    {
        printf(ANSI_COLOR_YELLOW "| " ANSI_COLOR_RESET);
        for (j = 0; j < size; j++)
        {
            if (arr[i][j] != 0)
                printf(ANSI_COLOR_YELLOW "%2d | " ANSI_COLOR_RESET, size * i + j + 1);
            else
                printf(ANSI_COLOR_YELLOW "   |" ANSI_COLOR_RESET);
        }
        printf("\n");
    }

    printf(ANSI_COLOR_YELLOW "----------------\n" ANSI_COLOR_RESET);
    printf("\n5.You can exit the game at any time by pressing 'E' or 'e' ");

    printf("\nSo Try to win in minimum no of move \n");

    printf("\nEnter any key to start.....   ");

    int x = readEnteredKey();
}

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    printf("");
}

int shiftUp(int size,int arr[][size])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            if (arr[i][j] == 0)
                break;
        if (j < size)
            break;
    }
    if (i == size-1) // shifting not possible
        return 0;

    // Successfully swapped two numbers !
    swap(&arr[i][j], &arr[i + 1][j]);
    return 1; // Success
}

int shiftDown(int size,int arr[][size])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            if (arr[i][j] == 0)
                break;
        if (j < size)
            break;
    }
    if (i == 0) // shifting not possible
        return 0;
    swap(&arr[i][j], &arr[i - 1][j]); // swap numbers

    return 1; // shift up success
}

int shiftRight(int size,int arr[][size])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            if (arr[i][j] == 0)
                break;
        if (j < size)
            break;
    }
    if (j == 0) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j - 1]);

    return 1; // shift up success
}

int shiftLeft(int size,int arr[][size])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            if (arr[i][j] == 0)
                break;
        if (j < size)
            break;
    }

    if (j == size-1) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j + 1]);
    return 1; // shift up success
}

int main()
{
    int size = 2,maxTry = 100;
    int arr[size][size];
    char name[50];
    int k;
    for ( k = 0; k < 3; k++)
        printf("\n");
    printf("Player Name: ");
    scanf("%s",name);
    system("cls");
    while(1)
    {
       input(size,arr);
       gameRule(size,arr);
       while(!Winner(size,arr))
       {
          system("cls");
          if(!maxTry)
             break;

          printf("\n\n  Player Name:  %s ,  Move remaining : %d\n\n",name, maxTry);
          showMatrix(size,arr);
          int key = readEnteredKey();
          switch (key)
          {
          case 101:
          case 69:
                printf("\a\a\a\a\a\a\n     Thanks for Playing ! \n\a");
                printf("\nHit 'Enter' to exit the game \n");
                key = readEnteredKey();
                return 0;
          case 72:
                if (shiftUp(size,arr))
                    maxTry--;
                    break;
          case 80: // arrow down
                if (shiftDown(size,arr))
                    maxTry--;
                    break;
          case 77: // arrow  right
                if (shiftRight(size,arr))
                    maxTry--;
                    break;
          case 75: // arrow left
                if (shiftLeft(size,arr))
                    maxTry--;
                    break;
          default:
                printf("\n\n      \a\a Not Allowed \a");
          }
       }
        if (!maxTry)
            printf(ANSI_COLOR_RED "\n\a          YOU LOSE !          \a\a\n" ANSI_COLOR_RESET);
        else
        {
           showMatrix(size,arr);
           printf(ANSI_COLOR_GREEN "\n\a!!!!!!!!!!!!!Congratulations  %s for winning this game !!!!!!!!!!!!!\n\a" ANSI_COLOR_RESET, name);

        }
            

        fflush(stdin); // Will clear the buffer
        char check;
        printf(ANSI_COLOR_GREEN "\nWant to play again ? \n" ANSI_COLOR_RESET);
        printf("enter 'y' to play again:  ");
        scanf("%c", &check);
        // Leave the game here itself !
        if ((check != 'y') && (check != 'Y'))
            break;

        maxTry = 100;
    }
    return 0;

}