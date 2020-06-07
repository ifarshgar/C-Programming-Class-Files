#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello, World!\n");

    int row = 2, col = 3;
    int **array;
    array = malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        array[i] = malloc(col * sizeof(int *));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < row; i++) {
        free(array[i]);
    }
    free(array);

    printf("\n\n");
    return 0;
}
