#include<stdio.h>
#include<math.h>
#include<graphics.h>
main() {
	float x, x1, x2, y, y1, y2, dx, dy, e;
	int i, graphics_draw, graphics_mode;
	printf("Enter the value of x1: \n");
	scanf("%f", &x1);
	printf("Enter the value of y1: \n");
	scanf("%f", &y1);
	printf("Enter the value of x2: \n");
	scanf("%f", &x2);
	printf("Enter the value of y2: \n");
	scanf("%f", &y2);
	detectgraph(&graphics_draw, &graphics_mode);
	initgraph(&graphics_draw, &graphics_mode, " ");
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	x = x1;
	y = y1;
	e = 2 * (dy - dx);
	i = 1;
	do {
		putpixel(x, y, 15);
		while(e >= 0) {
			y = y + 1;
			e = e - (2 * dx);
		}
		while(i <= dx);
		getch();
		closegraph();
	}
}
