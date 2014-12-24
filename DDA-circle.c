#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main() {
  float x1, y1, x2, y2, begin_x, begin_y, epsilon;
  int graph_draw, graph_mode, i, val, r;
  clrscr();
  printf("Enter the radius of the circle: ");
  scanf("%d",&r);
  detectgraph(&graph_draw,&graph_mode);
  initgraph(&graph_draw,&graph_mode,"");
  x1 = r * cos(0);
  y1 = r * sin(0);
  begin_x = x1;
  begin_y = y1;
  i = 0;
  do {
    val = pow(2,i);
    i++;
  } while(val < r);
  epsilon = 1/pow(2,i-1);
  do {
    x2 = x1 + y1 * epsilon;
    y2 = y1 - epsilon * x2;
    putpixel(200 + x2, 200 + y2, 15);
    x1 = x2;
    y1 = y2;
    delay(1000);
  } while((y1 - begin_y) < epsilon || (begin_x) > epsilon);
  getch();
  closegraph();
}
