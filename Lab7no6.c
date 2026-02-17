#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random100to200();

int main() 
{
    int N, M, i, j, x, y, rnum, numok;
    int A[100][200];

    scanf("%d %d", &N, &M);
    if (N > 100) N = 100;
    if (M > 200) M = 200;

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {

            numok = 1;
            while (numok == 1) {
                rnum = random100to200();
                numok = 0;

               
                for (x = 0; x <= i; x++) {
                    for (y = 0; y < (x == i ? j : M); y++) {
                        if (A[x][y] == rnum) {
                            numok = 1;
                            break;
                        }
                    }
                    if (numok) break;
                }
            }
            A[i][j] = rnum;
        }
    }

    
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    return 0;
}

int random100to200() {
    return (rand() % 101) + 100; 
}



