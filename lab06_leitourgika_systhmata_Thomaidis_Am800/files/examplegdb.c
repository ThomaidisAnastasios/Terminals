#include <stdlib.h>
#include <stdio.h>

int main()
{
  int i, j;
  int matrix[10][10];

  //load values into matrix
  for (i = 0; i < 10; i++)
  {
   for (j = 0; j < 10; j++)
    {
      matrix[i][j] = (i+1) * (j+1);
    }
  }

  //display initial contents of matrix
  printf("Initial matrix contents:\n");
  for (i = 0; i < 10; i++)
  {
    for (j = 0; j < 10; j++)
    {
      printf("%4i", matrix[i][j]);
    }
    printf("\n");
  }

  transformMatrix(matrix);

  //display transformed contents of matrix
  printf("\nTransformed matrix contents:\n");
  for (i = 0; i < 10; i++)
  {
    for (j = 0; j < 10; j++)
    {
      printf("%4i", matrix[i][j]);
    }
    printf("\n");
  }

  exit(0);
}


