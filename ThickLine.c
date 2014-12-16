#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main() {
	int graphics_draw = DETECT, graphics_mode;
	float yy, xx, x1, x2, y1, y2;
	int i, thickness;
	initgraph(&graphics_draw, &graphics_mode, " ");
	printf("Enter the x1 coordinate: \n");
	scanf("%f", &x1);
	printf("Enter the y1 coordinate: \n");
	scanf("%f", &y1);
	printf("Enter the x2 coordinate: \n");
	scanf("%f", &x2);
	printf("Enter the y2 coordinate: \n");
	scanf("%f", &y2);
	printf("Enter the required thickness: \n");
	scanf("%d", &thickness);
	cleardevice();
	line(x1, y1, x2, y2);
	if((y2 - y1)/(x2 - x1) < 1) {
		yy = (thickness - 1) * sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))/(2 * fabs(x2 - x1));
		for(i = 0; i < yy; i++) {
			line(x1, y1 - i, x2, y2 - i);
			line(x1, y1 + i, x2, y2 + i);
		}
	} else {
		xx = (thickness - 1) * sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))/(2 * fabs(x2 - x1));
		for(i = 0; i < xx; i++) {
			line(x1, y1 - i, x2, y2 - i);
			line(x1, y1 + i, x2, y2 + i);
		}
	}
	printf("The line of thickness is %d units \n", thickness);
	getch();
}
