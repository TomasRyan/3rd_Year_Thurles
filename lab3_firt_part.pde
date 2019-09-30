void setup()
{
  int x0;
  int y0;
  int x1;
  int x;
  int y1;  /* Right endpoint */
  x0=300;
  y0=400;
  x1=20;
  y1=30;
  
  double dy = y1 - y0;
  double dx = x1 - x0;
  double m;
  if(dy == 0) {
     m = dx; 
  }
  else if(dx == 0) {
    m = dy;
  }
  else {
   m = dy/dx;
  }
  if(m > 1) {
     int temp = y1;
     y1 = y0;
     y0 = temp;
     //
     temp = x1;
     x1 = x0;
     x0 = temp;
     //
     dy = y1 - y0;
     dx = x1 - x0;
     m = dy/dx;
     print(m);
  }
  double y = y0;

  size(600, 600);
  background(255);

  for ( x = x0; x < x1; x++ ) {
    point(x, (int)y);/* Set pixel to value */
    y+=m;
  }
}
