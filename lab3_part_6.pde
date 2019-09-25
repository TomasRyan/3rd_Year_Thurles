
boolean isOn = true;
int x0;
int y0;  /* Left endpoint */
int x1, x;
int y1;  /* Right endpoint */
double dy = y1 - y0;
double dx = x1 - x0;
double y = y0;
double m = dy/dx;
double e;
double ne;

void setup()
{
  size(600, 600);
  background(255);
    x0=20;
  y0=20;
  x1=40;
  y1=50;
  dy = y1 - y0;
  dx = x1 - x0;
  y = y0;
  m = dy/dx;
  x = x0;
}

void draw() {

  if (x < x1 && isOn == true) {
    if(x%(dx/10) == 0) {
      isOn = false;
      print("we bad");
      isOn = false;
    }
    // get ne and e, y = q ae ecact point of line
    ne = Math.ceil(y);
    e = Math.floor(y);
    //check distance between
    if(Math.abs(y-ne) < Math.abs(y-e)) {
      point(x, (int)ne);
      print("N-");
    }
    else {
       point(x, (int)e);
       print("E-");
    }
    //point(x, (int)y);/* Set pixel to value */
    y+=m;
    x++;
  }
}

void mouseClicked() {
  print("click");
  isOn = true;
}

  
