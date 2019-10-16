// Tomás Ryan
void setup() {
  size(600, 600, P3D);
  camera(70.0, 35.0, 120.0, 50.0, 50.0, 0.0, 
       0.0, 1.0, 0.0);

  smooth();
}

public class point {
  int x;
  int y;
  int z;
  public point(int xp, int yp, int zp) {
    this.x = xp;
    this.y = yp;
    this.z = zp;
  }
  
  void drawLine(point p2) {
    line(this.x, this.y, this.z, p2.x, p2.y, p2.z);
  }
}

void draw() {
  background(0);
  camera(mouseX, mouseY, 120.0, 50.0, 50.0, 0.0, 
       0.0, 1.0, 0.0);
  strokeWeight(5);
  //drawAxes();
  strokeWeight(1);
  stroke(255, 0,0) ;
  point a = new point(20,60,50);
  point b = new point(40,60,50);
  point d = new point(20,40,50);
  point c = new point(40,40,50);
  a.drawLine(b);
  a.drawLine(d);
  c.drawLine(b);
  c.drawLine(d);
  point f = new point(30,30,40);
  c.drawLine(f);
  d.drawLine(f);
  point h = new point(30,30,10);
  h.drawLine(f);
  point g = new point(40,60,0);
  point i = new point(40,40,0);
  g.drawLine(i);
  g.drawLine(b);
  i.drawLine(c);
  point j = new point(20,60,0);
  point k = new point(20,40,0);
  i.drawLine(h);
  d.drawLine(k);
  k.drawLine(i);
  k.drawLine(j);
  j.drawLine(a);
  j.drawLine(g);
  k.drawLine(h);
  // door
  point l = new point(40,60,23);
  point m = new point(40,50,23);
  point n = new point(40,50,27);
  point o = new point(40,60,27);
  l.drawLine(m);
  m.drawLine(n);
  n.drawLine(o);
  point p = new point(40,47,7);
  point q = new point(40,50,10);
  point r = new point(40,47,10);
  point s = new point(40,50,7);
  p.drawLine(s);
  q.drawLine(s);
  q.drawLine(r);
  p.drawLine(r);
  point t = new point(40,47,43);
  point u = new point(40,50,40);
  point v = new point(40,47,40);
  point w = new point(40,50,43);
  t.drawLine(v);
  u.drawLine(v);
  w.drawLine(t);
  w.drawLine(u);
  
  
 /* translate(30, 0, 0);
  rotateY(30*PI/180);
  
  strokeWeight(1);
  drawAxes();*/
  
}

void drawAxes() {
 stroke(255, 0, 0);
  line(-50, 0, 0, 50, 0, 0);
  
  stroke(0, 255, 0);
  line(0, -50, 0, 0, 50, 0);
  
  stroke(0, 0, 255);
  line(0, 0, -50, 0, 0, 50);
  
}
