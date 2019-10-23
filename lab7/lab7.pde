// Tomás Ryan
import java.util.*;
public class point {

  float[] p;
  public point(float xp, float yp, float zp) {
    this.p = new float[] {xp, yp, zp, 1.0};
  }
  
  void drawLine(point p2) {
    line(this.p[0], this.p[1], this.p[2], p2.p[0], p2.p[1], p2.p[2]);
  }
  void transform_point(float[][] m) {
    float[] p_new = {0.0,0.0,0.0,0.0}; // handle 4 elements as its 3D calc
    
   p_new[0] = m[0][0] * this.p[0] + m[1][0] * this.p[1] + m[2][0] * this.p[2] + m[3][0]*this.p[3];
   p_new[1] = m[0][1] * this.p[0] + m[1][1] * this.p[1] + m[2][1] * this.p[2]+ m[3][1]*this.p[3];
   p_new[2] = m[0][2] * this.p[0] + m[1][2] * this.p[1] + m[2][2] * this.p[2] +m[3][2]*this.p[3]; 
   p_new[3] = m[0][3] * this.p[0] + m[1][3] * this.p[1] + m[2][3] * this.p[2] +m[3][3]*this.p[3]; 
  
   this.p = p_new;
  }
}

point a = new point(20,60,50); // 0
point b = new point(40,60,50); // 1
point c = new point(40,40,50); // 2
point d = new point(20,40,50); // 3
point f = new point(30,30,40); // 4
point g = new point(40,60,0); // 5
point h = new point(30,30,10); // 6
point i = new point(40,40,0); // 7
point j = new point(20,60,0); // 8
point k = new point(20,40,0); // 9
point l = new point(40,60,23); // 10
point m = new point(40,50,23); // 11
point n = new point(40,50,27); // 12
point o = new point(40,60,27); // 13
point p = new point(40,47,7); // 14
point q = new point(40,50,10); // 15
point r = new point(40,47,10); // 16
point s = new point(40,50,7); // 17
point t = new point(40,47,43); // 18
point u = new point(40,50,40); // 19
point v = new point(40,47,40); // 20
point w = new point(40,50,43); // 21
ArrayList<point> listOfPoints = new ArrayList<point>();
float theta = radians(2);

float[][] transformMatrix = {{1,0.0,0.0,0},{0.0,1,0.0,0},{0.0,0.0,1,0},{5,5.0,5.0,1}};  // scale 1.1,1.1,1.1
 /*    1  0   0  5 
    =  0  1   0  5
       0  0   1  5
       0  0   0  1
 */
float[][] scaleMatrix = {{1.1,0.0,0.0,0.0},{0.0,1.1,0.0,0.0},{0.0,0.0,1.1,0.0},{0.0,0.0,0.0,1}};  // scale 1.1,1.1,1.1
 /*    1.1  0   0  0 
    =  0  1.1   0  0
       0  0   1.1  0
       0  0   0  1.1
 */
 float[][] xRotationMatrix = {{1.0,0.0,0.0,0.0},{0.0,cos(theta),sin(theta),0.0},{0.0,-sin(theta),cos(theta),0.0}, {0.0,0.0,0.0,1}};  // scale 1.1,1.1,1.1
 /*    1  0   0  0 
    =  0  cos(angle)   -sin(angle)  0
       0  sin(angle)   cos(angle) 0
       0  0   0  1
 */
 float[][] yRotationMatrix = {{cos(theta),0.0,-sin(theta),0.0},{0.0,1.0,0.0,0.0},{sin(theta),0,cos(theta),0.0}, {0.0,0.0,0.0,1}};  // scale 1.1,1.1,1.1
 /*     
    =  cos(angle) 0   sin(angle)  0
       0  1   0  0
       -sin(theta)  0   cos(theta)  1
       0  0   0  1
 */
 float[][] zRotationMatrix = {{cos(theta),-sin(theta),0.0,0.0},{sin(theta),cos(theta),0,0.0},{0.0,0,1,0.0}, {0.0,0.0,0.0,1}};  // scale 1.1,1.1,1.1
 /*    1  0   0  0 
    =  0  cos(angle)   -sin(angle)  0
       0  sin(angle)   cos(angle) 0
       0  0   0  1
 */
void setup() {
  size(600, 600, P3D);
  
  listOfPoints.add(a);
  listOfPoints.add(b);
  listOfPoints.add(c);
  listOfPoints.add(d);
  listOfPoints.add(f);
  listOfPoints.add(g);
  listOfPoints.add(h);
  listOfPoints.add(i);
  listOfPoints.add(j);
  listOfPoints.add(k);
  listOfPoints.add(l);
  listOfPoints.add(m);
  listOfPoints.add(n);
  listOfPoints.add(o);
  listOfPoints.add(p);
  listOfPoints.add(q);
  listOfPoints.add(r);
  listOfPoints.add(s);
  listOfPoints.add(t);
  listOfPoints.add(u);
  listOfPoints.add(v);
  listOfPoints.add(w);
  smooth();
}



void draw() {
  camera(mouseX, mouseY, 120.0, 50.0, 50.0, 0.0, 
       0.0, 1.0, 0.0);
  background(0);
  camera(220, 20, 10.0, 50.0, 50.0, 0.0,0.0, 1.0, 0.0);
  drawHouse();
  for(point p:listOfPoints) {
    p.transform_point(xRotationMatrix);
    p.transform_point(yRotationMatrix);
    p.transform_point(zRotationMatrix);
  }

 /* translate(30, 0, 0);
  rotateY(30*PI/180);
  
  strokeWeight(1);
  drawAxes();*/
  
}

void mousePressed() {
  for(point p:listOfPoints) {
    p.transform_point(scaleMatrix);
  }
    for(point p:listOfPoints) {
    p.transform_point(transformMatrix);
  }
}

void drawAxes() {
 stroke(255, 0, 0);
  line(-50, 0, 0, 50, 0, 0);
  
  stroke(0, 255, 0);
  line(0, -50, 0, 0, 50, 0);
  
  stroke(0, 0, 255);
  line(0, 0, -50, 0, 0, 50);
  
}

void drawHouse() {
 strokeWeight(5);
  //drawAxes();
  strokeWeight(1);
  stroke(255, 0,0) ;
  
  /*a.drawLine(b);
  a.drawLine(d);
  c.drawLine(b);
  c.drawLine(d);
  
  c.drawLine(f);
  d.drawLine(f);
  
  h.drawLine(f);
  
  g.drawLine(i);
  g.drawLine(b);
  i.drawLine(c);
  //////////////////////
  i.drawLine(h);
  d.drawLine(k);
  k.drawLine(i);
  ////
  k.drawLine(j);
  j.drawLine(a);
  j.drawLine(g);
  k.drawLine(h);
  ////
  l.drawLine(m);
  m.drawLine(n);
  n.drawLine(o);
  //
  p.drawLine(s);
  q.drawLine(s);
  q.drawLine(r);
  p.drawLine(r);
 
  t.drawLine(v);
  u.drawLine(v);
  w.drawLine(t);
  w.drawLine(u); */
  
  listOfPoints.get(0).drawLine(listOfPoints.get(1));
  listOfPoints.get(0).drawLine(listOfPoints.get(3));
  listOfPoints.get(2).drawLine(listOfPoints.get(1));
  listOfPoints.get(2).drawLine(listOfPoints.get(3));
  
  listOfPoints.get(2).drawLine(listOfPoints.get(4));
  listOfPoints.get(3).drawLine(listOfPoints.get(4));
  
  listOfPoints.get(6).drawLine(listOfPoints.get(4));
  
  listOfPoints.get(5).drawLine(listOfPoints.get(7));
  listOfPoints.get(5).drawLine(listOfPoints.get(1));
  listOfPoints.get(7).drawLine(listOfPoints.get(2));
  
  listOfPoints.get(7).drawLine(listOfPoints.get(6));
  listOfPoints.get(3).drawLine(listOfPoints.get(9));
  listOfPoints.get(9).drawLine(listOfPoints.get(7));
  
  listOfPoints.get(8).drawLine(listOfPoints.get(9));
  listOfPoints.get(8).drawLine(listOfPoints.get(0));
  listOfPoints.get(8).drawLine(listOfPoints.get(5));
  listOfPoints.get(9).drawLine(listOfPoints.get(6));
  
  listOfPoints.get(10).drawLine(listOfPoints.get(11));
  listOfPoints.get(11).drawLine(listOfPoints.get(12));
  listOfPoints.get(12).drawLine(listOfPoints.get(13));
  
  listOfPoints.get(14).drawLine(listOfPoints.get(17));
  listOfPoints.get(15).drawLine(listOfPoints.get(17));
  listOfPoints.get(15).drawLine(listOfPoints.get(16));
  listOfPoints.get(14).drawLine(listOfPoints.get(16));
  
  listOfPoints.get(18).drawLine(listOfPoints.get(21));
  listOfPoints.get(19).drawLine(listOfPoints.get(21));
  listOfPoints.get(19).drawLine(listOfPoints.get(20));
  listOfPoints.get(18).drawLine(listOfPoints.get(20));
}
