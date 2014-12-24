#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main() {
  float d;
  int x, y, graphics_draw, graphics_mode, r;
  clrscr();
  printf("Enter the radius of the circle: ");
  scanf("%d",&r);
  detectgraph(&graphics_draw,&graphics_mode);
  initgraph(&graphics_draw,&graphics_mode,"");
  x = 0;
  y = r;
  d = 3 - 2 * r;
  do {
    putpixel(200 + x, 200 + y, 15);
    putpixel(200 + y, 200 + x, 15);
    putpixel(200 + y, 200 - x, 15);
    putpixel(200 + x, 200 - y, 15);
    putpixel(200 - x, 200 - y, 15);
    putpixel(200 - y, 200 - x, 15);
    putpixel(200 - y, 200 + x, 15);
    putpixel(200 - x, 200 + y, 15);
    if(d <= 0) {
      d = d + 4 * x + 6;
    } else {
      d = d + 4 * (x - y) + 10;
      y = y-1;
    }
    x = x + 1;
    delay(1000);
  } while(x < y);
  getch();
  closegraph();
}
