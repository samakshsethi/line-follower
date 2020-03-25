/* Line following robot
 * By Samaksh Sethi
 * 
 * Execution procedure:
 * 1. The motors will be turned on when the robot is aligned with the line
 * 2. If one of the IR sensors comes over black line, the opposite wheel will turn off, shifting the robot's alignment in the direction of the line 
 * 3. If both IR sensors are over the line (usually for sharp corners), both wheels are moved for 20ms to fix it and then, the loops are continued as is
 * 
 * GitHub link - https://github.com/samakshsethi/line-follower
 */

//m1-4 are pin numbers to be connected to IN1-4 (1,2 pins are for right motor and 3,4 are for left motors) on the L298 motor driver
int m1=7;
int m2=6;
int m3=8;
int m4=9;

//i1 and i2 are pin numbers of the left and right IR sensors respectively
int i1=2;
int i2=3;

//lw and rw are value containers of readings from IR sensors
//lw and rw will be 0 for black (line)
//                  1 for white (surface)
int lw=1;
int rw=1;

//Variable sets the maximum speed of motor. Range=0~255
int maxSpeed=70;

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(i1, INPUT);
  pinMode(i2, INPUT);
  digitalWrite(m1,LOW);
  digitalWrite(m3,LOW);
  delay(3000);        //delay of 3 seconds before the car begins moving
}

void loop() {
  lw=digitalRead(i1);
  rw=digitalRead(i2);

  if(lw==0){
    analogWrite(m2,0);
  }
  if(lw==1){
    analogWrite(m2,maxSpeed);
  }
  if(rw==0){
    analogWrite(m4,0);
  }
  if(rw==1){
    analogWrite(m4,maxSpeed);
  }
  if(rw==0 && lw==0){           //if both sensors come over black line, both wheels will work for 20ms and continue the loop
    analogWrite(m2,maxSpeed);
    analogWrite(m4,maxSpeed);
    delay(20);
    analogWrite(m2,0);
    analogWrite(m4,0);
  }
}
