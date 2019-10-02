/**
 * PrimitivePShape. 
 * 
 * Using a PShape to display a custom polygon. 
 */

// The PShape object
PShape house;
PShape bridge;
int x1 = 0;
int y1 = 0;
int x2 = 200;
int y2 = 0;
int speed = 5;
void setup() {
  size(640, 360, P2D);
  smooth();
  // part 1
  //------------------------------------
  // First create the shape
  house = createShape();
  house.beginShape();
  // You can set fill and stroke
  house.fill(102);
  house.stroke(255);
  house.strokeWeight(2);
  // Here, we are hardcoding a series of vertices
  house.vertex(0, -50);
  house.vertex(24, -20);
  house.vertex(24, 20);
  house.vertex(-24, 20);
  house.vertex(-24, -20);
  house.vertex(0, -50);
  house.vertex(80, -80);
  house.vertex(104, -50);
  house.vertex(104, -10);
  house.vertex(24, 20);
  house.endShape();
  house.translate(-50, -50);
  //part 2 
  //-----------------------------------
  bridge = createShape();
  bridge.beginShape();
  bridge.fill(102);
  bridge.stroke(255);
  bridge.strokeWeight(2);
  bridge.vertex(40, 40);
  bridge.vertex(40, 0);
  bridge.vertex(-40, 0);
  bridge.vertex(-40, 40);
  bridge.vertex(-30, 40);
  bridge.curveVertex(-30, 40);
  bridge.curveVertex(-20, 15);
  bridge.curveVertex(20, 15);
  bridge.curveVertex(30, 40);
  bridge.vertex(30, 40);
  bridge.vertex(40, 40);
  bridge.endShape();
  bridge.translate(50, 50);
  //part 2 
  //-----------------------------------
}

void draw() {
  //background(255);
  // We can use translate to move the PShape
  //translate(mouseX, mouseY);
  // Display the shape
  //shape(bridge);
  //shape(house);
  //house.rotate(0.01);
  //bridge.rotate(0.01);
  if(x1 < 200 && x1 >= 0) {
     x1+=speed; 
     y2+=speed;
     line(x1, y1, x2, y2);
  }
  else {
    speed *= -1;
    x1+=speed; 
     y2+=speed;
     line(x1, y1, x2, y2);
  }
}

void mouseClicked() {
  house.rotate(1);
}
