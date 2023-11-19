//3.COMMON SUBSEQUENCE:
#include <stdio.h>
#include <string.h>
int i, j, m, n, table[20][20];
char arr[20], str[20], b[20][20];
void lcsAlgo() {
  m = strlen(arr);
  n = strlen(str);
  for (i = 0; i<= m; i++)
  {
    table[i][0] = 0;
  }
  for (i = 0; i<= n; i++)
  {

    table[0][i] = 0;
  }
  for (i = 1; i<= m; i++)
  {
    for (j = 1; j <= n; j++)
  {
      if (arr[i - 1] == str[j - 1])
       {
        table[i][j] = table[i - 1][j - 1] + 1;
       }
      else if (table[i - 1][j] >= table[i][j - 1])
        {
        table[i][j] = table[i - 1][j];
        }
      else
        {
        table[i][j] = table[i][j - 1];
        }
    }
  }
  int index = table[m][n];
  char lcsAlgo[index + 1];
lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i> 0 && j > 0) {
    if (arr[i - 1] == str[j - 1]) {
lcsAlgo[index - 1] = arr[i - 1];
i--;
      j--;
      index--;
    }

    else if (table[i - 1][j] > table[i][j - 1])
i--;
    else
      j--;
  }
printf("FIRST: %s \nSECOND : %s \n", arr, str);
printf("LCS: %s", lcsAlgo);
}

int main()
{
printf("\nEnter the first sequence of character:");
scanf("%s",arr);
printf("\nEnter the second sequence of character:");
scanf("%s",str);
lcsAlgo();
printf("\n");
}
