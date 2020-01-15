import java.util.*;
import java.io.*;
import peasy.*;
import g4p_controls.*;

class point {
  float SensorID;
  float segmentNumber;
  float Xorig;
  float Yorig;
  float Zorig;
  float Xend;
  float Yend;
  float Zend;
  float ZVectorXRelAngle;
  float ZVectorYRelAngle;
  float ZVectorZRelAngle;
  int scale = 100;
  
  public point(float ID, float segment,  float Xor,  float Yor,  float Zor,  float Xen,  float Yen,  float Zen,  float XRelAngle,  float YRelAngle,  float ZRelAngle) {
    this.SensorID = ID*scale;
    this.segmentNumber = segment*scale;
    this.Xorig = Xor*scale;
    this.Yorig = Yor*scale;
    this.Zorig = Zor*scale;
    this.Xend = Xen*scale;
    this.Yend = Yen*scale;
    this.Zend = Zen*scale;
    this.ZVectorXRelAngle = XRelAngle*scale;
    this.ZVectorYRelAngle = YRelAngle*scale;
    this.ZVectorZRelAngle = ZRelAngle*scale;
  }
  
  void PrintPoint() {
    print(this.SensorID + "\n");
    print(this.segmentNumber + "\n");
    print(this.Xorig + "\n");
    print(this.Yorig + "\n");
    print(this.Zorig + "\n");
    print(this.Xend + "\n");
    print(this.Yend + "\n");
    print(this.Zend + "\n");
    print(this.ZVectorXRelAngle + "\n");
    print(this.ZVectorYRelAngle + "\n");
    print(this.ZVectorZRelAngle + "\n");
  }
  
  void drawLine() {
    strokeWeight(1);
    stroke(255, 255, 255);
    line(this.Xorig, this.Yorig, this.Zorig, this.Xend,this.Yend,this.Zend);
  }
};
ArrayList<point> listOfPOints = new ArrayList<point>();
int frame = 0;
int lengthOfDraw = 23;
float frameReference = lengthOfDraw;
int currentFrame = 1;
int maxFrames = 684;
//  peasycam for camera
PeasyCam cam;
// slider
GSlider2D g;
void setup() {
  size(600,600,P3D);
  cam = new PeasyCam(this,0, 50, 0, 400);
  cam.setMinimumDistance(300);
  cam.setMaximumDistance(500);
  cam.rotateZ(radians(80));
  cam.rotateY(radians(180));
  cam.rotateX(radians(100));
  g = new GSlider2D(this, 10, 10, 100, 20);
  //
  g.setLimitsX(0, -2.0, 2.0);
  g.setLimitsY(0,0,0);
  g.setNumberFormat(G4P.INTEGER, 2);
  g.setOpaque(false);
  //
  frameRate(60);
  try //need to be able to catch an exception that was throw when reading in from the file
  {
    ReadinFile();  //a call to my file i/o function
  }
  catch(IOException  e)
  {
    System.out.println(e);
  }
  background(0);
}

void draw() {
  background(0);
  //for(int f = 0; frame < frameReference; frame++) {
  //  listOfPOints.get(frame).drawLine();
  //}
  /*while(frame < frameReference) {
    listOfPOints.get(frame).drawLine();
    //frame+= g.getValueXI();
    //print(g.getValueXI());
    frame++;
  }*/
  drawFrame(currentFrame);
  currentFrame += g.getValueXI();
  if(currentFrame > maxFrames) {
    currentFrame -= maxFrames;
  }
  else if(currentFrame < 0) {
    currentFrame += maxFrames;
  }
  /*frameReference =  frame+(g.getValueXI()*23);
  if(frameReference > listOfPOints.size()) {
    frame = 0;
    frameReference = lengthOfDraw;
  }*/
  
  cam.beginHUD();
  g.draw();
  cam.endHUD();
}



void ReadinFile() throws FileNotFoundException  //function to read in from file
{
  //Scanner scan;
  String file = "C:\\cg\\movement.csv"; //getting the file path
  String input = "";   //creating the string that will hold the data
  Scanner scan = new Scanner(new BufferedReader(new FileReader(file)));  //link the scanner to the file
  int line = 0;  
  scan.nextLine();  
  
  while(scan.hasNextLine())
  {
    input = scan.nextLine();    //read in a line of the file  
    String[] inputArr = input.split(",");  // put each value into an array while ignoring the comma's
      float[] floatArr = new float[inputArr.length];
    for (int y = 0; y < inputArr.length; y++) {
        float number = Float.parseFloat(inputArr[y]);
        floatArr[y] = number;
    }
    point test = new point(floatArr[0], floatArr[1], floatArr[2], floatArr[3], floatArr[4], floatArr[5], floatArr[6], floatArr[7], floatArr[8], floatArr[9], floatArr[10]);
    listOfPOints.add(test);
    line++; //increment the line so that i can read the next line from the file
  }
  scan.close();
  print(line);
  print("\n" + "fin");
}

void drawFrame(int frameNumber) {
  print(frameNumber);
  int frameToDraw = frameNumber*23;
  int frameStopDraw = frameToDraw+23;
   while(frameToDraw < frameStopDraw) {
     if(frameToDraw < 15732) {
      listOfPOints.get(frameToDraw).drawLine();
      //frame+= g.getValueXI();
      //print(g.getValueXI());
     }
     frameToDraw++;
  }
}
