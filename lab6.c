#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/* Задание 912*/
void task912(void) {
    printf("Task912\n");
    int n, m, i, j;
    int a[20][20];
    int max_row = 0;
    double max_avg = -1e9;
    double sum, avg;

    printf("Enter the number of rows n and columns m: ");
    scanf("%d %d", &n, &m);
    if (n < 1 || n > 20 || m < 1 || m > 20) {
        printf("Error!\n");
        return;
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }


    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < m; j++) {
            sum += a[i][j];
        }
        avg = sum / m;
        if (i == 0 || avg > max_avg) {
            max_avg = avg;
            max_row = i;
        }
    }

    printf("Row with the maximum average value: %d, average value = %.4lf\n", max_row + 1, max_avg);
}
/* Задание 926*/
void task926(void) {
    printf("Task926\n");
    int n, m, i, j, r, c;
    int a[20][20];
    int unique = 0;
	int val, count;

    printf("Enter the number of rows n and columns m: ");
    scanf("%d %d", &n, &m);
    if (n < 1 || n > 20 || m < 1 || m > 20) {
        printf("Error!\n");
        return;
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    
	printf("Elements that do not repeat (unique):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            val = a[i][j];
            count = 0;
            for (r = 0; r < n; r++) {
                for (c = 0; c < m; c++) {
                    if (a[r][c] == val) {
                        count++;
                    }
                }
            }
            if (count == 1) {
                unique = 1;
                printf(" %d ", val);
            }
        }
    }
    if (unique == 0) {
        printf("No unique elements.");
    }
}

/* Задание 947*/
void task947(void) {
    printf("Task947\n");
    int n, i, j;
    int a[20][20];

    printf("Enter the size of the square matrix n: ");
    scanf("%d", &n);
    if (n < 1 || n > 20) {
        printf("Input error!\n");
        return;
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    int max_main_val = a[0][0];
    int first_max_main_i = 0, first_max_main_j = 0;

    int min_sec_val = a[0][n - 1];
    int first_min_sec_i = 0, first_min_sec_j = n - 1;

    int min_main_val = a[0][0];
    int last_min_main_i = 0, last_min_main_j = 0;

    int max_sec_val = a[0][n - 1];
    int last_max_sec_i = 0, last_max_sec_j = n - 1;

    for (i = 0; i < n; i++) {
        int val = a[i][i];
        if (i == 0 || val > max_main_val) {
            max_main_val = val;
            first_max_main_i = i;
            first_max_main_j = i;
        }
        if (i == 0 || val <= min_main_val) {
            min_main_val = val;
            last_min_main_i = i;
            last_min_main_j = i;
        }
    }

    for (i = 0; i < n; i++) {
        j = n - 1 - i;
        int val = a[i][j];
        if (i == 0 || val < min_sec_val) {
            min_sec_val = val;
            first_min_sec_i = i;
            first_min_sec_j = j;
        }
        if (i == 0 || val >= max_sec_val) {
            max_sec_val = val;
            last_max_sec_i = i;
            last_max_sec_j = j;
        }
    }

    printf("a) First max: %d, coordinates: row %d, column %d\n", max_main_val, first_max_main_i + 1, first_max_main_j + 1);
    printf("b) First min: %d, coordinates: row %d, column %d\n", min_sec_val, first_min_sec_i + 1, first_min_sec_j + 1);
    printf("c) Last min: %d, coordinates: row %d, column %d\n", min_main_val, last_min_main_i + 1, last_min_main_j + 1);
    printf("d) Last max: %d, coordinates: row %d, column %d\n", max_sec_val, last_max_sec_i + 1, last_max_sec_j + 1);
}

/* Задание 952*/
void task952(void) {
    printf("Task952\n");
    int n, m, i, j;
    int a[20][20];
    int row_idx, col_idx;
    int val_row, val_col;

    printf("Enter the number of rows n and columns m: ");
    scanf("%d %d", &n, &m);
    if (n < 1 || n > 20 || m < 1 || m > 20) {
        printf("Error!\n");
        return;
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the row for replacement (1-%d): ", n);
    scanf("%d", &row_idx);
    printf("Enter the number to fill this row: ");
    scanf("%d", &val_row);

    printf("Enter the column for replacement (1-%d): ", m);
    scanf("%d", &col_idx);
    printf("Enter the number to fill this column: ");
    scanf("%d", &val_col);

    if (row_idx >= 1 && row_idx <= n) {
        for (j = 0; j < m; j++) {
            a[row_idx - 1][j] = val_row;
        }
    }

    if (col_idx >= 1 && col_idx <= m) {
        for (i = 0; i < n; i++) {
            a[i][col_idx - 1] = val_col;
        }
    }

    printf("Matrix after replacement:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf(" %6d ", a[i][j]);
        }
        printf("\n");
    }
}
/* Задание 996*/
void task996(void) {
    printf("Task996\n");
    int n, i, j;
    double a[20][20];
    double diag[20];
    double trace = 0;

    printf("Enter the size of the square matrix n: ");
    scanf("%d", &n);
    if (n < 1 || n > 20) {
        printf("Error\n");
        return;
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &a[i][j]);
        }
    }

	printf("Diagonal elements: ");
    for (i = 0; i < n; i++) {
        diag[i] = a[i][i];
        trace += diag[i];
        printf(" %.2lf ", diag[i]);
    }
    printf("\nTrace of the matrix: %.4lf\n", trace);

    if (fabs(trace) < 1e-9) {
        printf("Error.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        if (i % 2 != 0) {
            for (j = 0; j < n; j++) {
                a[i][j] /= trace;
            }
        }
    }

    printf("Matrix after transformation:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf(" %10.4lf ", a[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    task912();
    task926();
    task947();
    task952();
    task996();

    return 0;
}