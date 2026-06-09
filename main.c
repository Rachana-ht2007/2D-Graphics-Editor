#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 25
#define COLS 50

char canvas[ROWS][COLS];

void initCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) canvas[i][j] = '_';
    }
}

void displayCanvas() {
    system("clear || cls"); 
    printf("\n--- My Coustom Canvas ---\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) printf("%c", canvas[i][j]);
        printf("\n");
    }
}

void drawLine(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        int start = (y1 < y2) ? y1 : y2;
        int end = (y1 > y2) ? y1 : y2;
        for (int i = start; i <= end; i++) {
            if (x1 >= 0 && x1 < ROWS && i >= 0 && i < COLS) canvas[x1][i] = '*';
        }
    } else if (y1 == y2) {
        int start = (x1 < x2) ? x1 : x2;
        int end = (x1 > x2) ? x1 : x2;
        for (int i = start; i <= end; i++) {
            if (i >= 0 && i < ROWS && y1 >= 0 && y1 < COLS) canvas[i][y1] = '*';
        }
    }
}


void drawRectangle(int top, int left, int bottom, int right) {
    drawLine(top, left, top, right);
    drawLine(bottom, left, bottom, right);
    drawLine(top, left, bottom, left);
    drawLine(top, right, bottom, right);
}


void drawCircle(int centerX, int centerY, int radius) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            double dist = pow(i - centerX, 2) + pow((j - centerY) * 0.5, 2);
            double r2 = pow(radius, 2);
            if (fabs(dist - r2) < (radius * 0.8)) {
                canvas[i][j] = '*';
            }
        }
    }
}

int main() {
    int choice;
    initCanvas();

    while (1) {
        displayCanvas();
        printf("\nOptions:\n1. Draw Line\n2. Draw Rectangle\n3. Draw Circle\n4. Reset Canvas\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        switch(choice) {
            case 1: {
                int x1, y1, x2, y2;
                printf("Enter Start Row & Col: "); scanf("%d %d", &x1, &y1);
                printf("Enter End Row & Col: "); scanf("%d %d", &x2, &y2);
                drawLine(x1, y1, x2, y2);
                break;
            }
            case 2: {
                int t, l, b, r;
                printf("Enter Top Row, Left Col, Bottom Row, Right Col: "); scanf("%d %d %d %d", &t, &l, &b, &r);
                drawRectangle(t, l, b, r);
                break;
            }
            case 3: {
                int cx, cy, rad;
                printf("Enter Center Row, Center Col, and Radius: "); scanf("%d %d %d", &cx, &cy, &rad);
                drawCircle(cx, cy, rad);
                break;
            }
            case 4:
                initCanvas();
                break;
        }
    }
    return 0;
}
