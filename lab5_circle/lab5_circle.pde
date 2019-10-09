// example 1...
/*  

tranforming points through matrix multiplication...  
pressing the mouse button turns on looping, and relasing it turns off looping

*/

//points
float[] p1 = {50.0,0.0,1.0};
float[] p2 = {50.0,0.0,1.0};

// transform matrix
float[][] matrix1 = {{1.0,0.0,0.0},{0.0,1.0,0.0},{6.0,6.0,1.0}}; // translate 6,6
 /*    1  0  6
    =  0  1  6
       0  0   1
 */
 
           
float[][] matrix2 = {{2.0,0.0,0.0},{0.0,2.0,0.0},{0.0,0.0,1.0}};  // scale 2,2
 /*    2  0   0
    =  0  2   0
       0  0   1
 */

float[][] matrix3 = {{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0}};   // empty
 /*    1  0   0
    =  0  1   0
       0  0   1
 */
float[][] matrix4 = {{1.0,0.0,0.0},{0.0,1.0,0.0},{-80.0,-80.0,1.0}}; // translate -50,-50

float[][] matrix5 = {{1.0,0.0,0.0},{0.0,1.0,0.0},{80.0,80.0,1.0}}; // translate 50,50

float[][] m;  

void setup() 
{
  size(400,400);
  stroke(255);

  
  // rotation angle
  float theta = radians(7); // convert degrees to radians
  
  //

  // matrix3 = rotate... 
  
  matrix3[0][0] = cos(theta);
  matrix3[0][1] = - sin(theta);
  matrix3[1][0] = sin(theta);
  matrix3[1][1] = cos(theta);

 /*    cos(theta) -sin(theta)   0
    =  sin(theta)  cos(theta)   0
           0             0      1
 */
            
  // tranformation matrix...    

  m = mult_matrix(matrix1, matrix3); 
  p2 = transform_point(m, p2);
  /*
  p1 = transform_point(m, p1);
  p2 = transform_point(m, p2);
  p3 = transform_point(m, p3);
  p4 = transform_point(m, p4);
  */
     
  /*   // scale...
  p1 = transform_point(matrix2, p1);
  p2 = transform_point(matrix2, p2);
  p3 = transform_point(matrix2, p3);
  p4 = transform_point(matrix2, p4);
  */
  
  noLoop();
  
  frameRate(25);
}

/*draw will draw the shape on screen*/
void draw() 
{
  // by commenting the background() call out, the background is not refreshed, so each transformation can be seen.
  background(102);

  translate(100, 300);
  for(int i = 0; i < 100; i++) {
    p1 = transform_point(m, p1);
    p2 = transform_point(m, p2);
    fill(255);  
    myBox();
  }
  

  fill(255);    
  
  myBox();

}



float[] transform_point(float[][] m, float[] p){

   float[] p_new = {0.0,0.0,0.0};
   
   p_new[0] = m[0][0] * p[0] + m[1][0] * p[1] + m[2][0] * p[2];
   p_new[1] = m[0][1] * p[0] + m[1][1] * p[1] + m[2][1] * p[2];
   p_new[2] = m[0][2] * p[0] + m[1][2] * p[1] + m[2][2] * p[2];
  
   return p_new;
}



float[][] mult_matrix(float[][] m1, float[][] m2){

   float[][] m_new = {{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0}};
   
   m_new[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2];
   m_new[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2];
   m_new[0][2] = m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2];

   m_new[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2];
   m_new[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2];
   m_new[1][2] = m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2];

   m_new[2][0] = m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2];
   m_new[2][1] = m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2];
   m_new[2][2] = m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2];
  
   return m_new;
}


/* 
setting a low framerate() and noLoop() in setup() 
and turning looping on and off with mousePress and mouseRelease
allows us to see each itteration of 'draw()'
*/

void mousePressed() { 
  loop(); 
} 
 
void mouseReleased() { 
  noLoop(); 
} 
/*shape is defined as elements in the array*/
void myBox () {
  line(p1[0],p1[1], p2[0],p2[1]);
}
