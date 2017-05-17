#include <EYW.h>
#include <Servo.h>
#include <Wire.h>
//define things here, everything else should run automatically
//-------------------------- CAMERA SUBTEAM
int pinNum = 1; //red wire
int signalPin1 = 9; // white wire
int angleHome = 0;
int holdTime = 2000; //time in between parts
int angle1 = 30;
int angle2 = -30;
int angle3 = 30;
int delay1 = 2000; //time holding down
int delay2 = 2000; //time holding down
int delay3 = 2000; //time holding down
Servo servo;
//--------------------------- STRUCTURE SUBTEAM
float drop_height = 0; //input initial drop height
float current_height = 0; //input initial drop height
EYW::Altimeter a;
//--------------------------- DESCENT SUBTEAM
int signalPin2=5;
int deltaV=0;
int idealDeltaV=3;
int i=0;
int heights[dropHeight/idealDeltaV];
//--------------------------- END OF DEFINING
void alarm(int i){
while(heights[i]==heights[i-1]&&lifted==true&&dropped==true){
    switch(height[i-2]-height[i-1]){
      case 1:
      a.alarm(1,880,250);
      delay(10);
      a.alarm(4, 880,1000);
      break;
      case 2:
      a.alarm(2,880,250);
      delay(10);
      a.alarm(3, 880,1000);
      break;
      case 3:
      a.alarm(3,880,250);
      delay(10);
      a.alarm(2, 880,1000);
      break;
      case 4:
      a.alarm(4,880,250);
      delay(10);
      a.alarm(1, 880,1000);
      break;
      case 5:
      a.alarm(5,880,250);
      break;
      case 6:
      a.alarm(1, 880,1000);
      delay(10);                    
      a.alarm(4,880,250);
      break;
      case 7:
      a.alarm(2, 880,1000);
      delay(10);
      a.alarm(3,880,250);
      break;
      case 8:
      a.alarm(3, 880,500*2);
      delay(10);
      a.alarm(2,880,250);
      break;
      case 9:
      a.alarm(4, 880,500*2);
      delay(10);
      a.alarm(1,880,250);
      break;
      case 0:
      a.alarm(5, 880,500*2);
      break;
      default:
      a.led(1);
    }
    delay(1000);
}
 delay(1000);
}
}
//---------------------------VOID SETUP
void setup() {

//--------------------------- CAMERA SUBGROUP CODE
  servo.attach(signalPin1); // attach the signal pin of servo to signalPin1 of arduino, white wire
  // part 1, hold on/off for 1.5s
  for(int angle = angleHome; angle <= angle1; angle ++){    // command to move from angleHome degrees to angle1 degrees
    servo.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
  delay(delay1); //holds button for delay1 time
  for(int angle = angle1; angle >= angleHome; angle--){     // command to move from angle1 degrees to angleHome degrees
    servo.write(angle);              //command to rotate the servo to the specified angle
    delay(15);                       
  }
    delay(holdTime); //stays at angleHome for holdTime time
  // part 2, press mode button
  for (int angle = angleHome; angle <= angle2; angle ++){    // command to move from angleHome degrees to angle2 degrees
    servo.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
  delay(delay2);         //holds button for delay2 time
  for(int angle = angle2; angle >= angleHome; angle--){     // command to move from angle1 degrees to angleHome degrees
    servo.write(angle);              //command to rotate the servo to the specified angle
    delay(15);                       
  } 
    delay(holdTime); //stays at angleHome for holdTime time
  // part 3, click on/off to take photo
  for(int angle = angleHome; angle <= angle3; angle ++){    // command to move from angleHome degrees to angle2 degrees
    servo.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  }
  delay(delay3); //holds button for delay2 time
  for(int angle = angle3; angle >= angleHome; angle--){     // command to move from angle1 degrees to angleHome degrees
    servo.write(angle);              //command to rotate the servo to the specified angle
    delay(15);                    
  }//stays at rest forever
//--------------------------- STRUCTURE SUBGROUP CODE
  Serial.begin(9600);
  a.begin();
  a.calibrate(100); //takes first 100 measurements as calibration
  a.alarm();
//--------------------------- DESCENT SUBGROUP CODE
  pinMode(signalPin2,OUTPUT);
  
} //--------------------------- END OF VOID SETUP

//---------------------------------------- VOID LOOP
void loop(){
  //--------------------------- CAMERA SUBGROUP CODE
  //--------------------------- STRUCTURE SUBGROUP CODE
  current_height = a.getHeightAvg (20);//takes the average of 20 measurements to get current height
  Serial.print("Current Height: "+current_height+"");
  if (current_height > drop_height) {
  a.alarm(6,2000,500); } //intiates the drop mechanism
  //--------------------------- DESCENT SUBGROUP CODE
  if (altitude==0){
   a.alarm(heights[i-1]-heights[i]);//gonna have to overwrite the alarm method here
  }
  heights[i]=a.getHeightAvg(20);
  i++;
  delay(1000);
} //--------------------------- END OF VOID LOOP
