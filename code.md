[Home](https://assumepositiveintentions.github.io/Final/) | [Figures](https://assumepositiveintentions.github.io/Final/figures) | [Photos](https://assumepositiveintentions.github.io/Final/photos) | [Videos](https://assumepositiveintentions.github.io/Final/videos) | [Our Code Explained](https://assumepositiveintentions.github.io/Final/decoded)

# All of the code uploaded to the Arduino
```c++
#include <EYW.h>
  EYW::Altimeter a;
void setup(){
  Serial.begin(9600);
  Serial.println("Initializing.....");
  Serial.print(a.begin());
  a.calibrate(10);
  pinMode(5,OUTPUT); }
boolean lifted=false,dropped=false;
int height[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void loop(){
 for(int i=0;i<10;i++){
 Serial.print("Measuring Altitude: ");
 height[i]=(int)a.getHeightAvg(10);
 Serial.println(height[i]);
 if(height[i-1]<height[i]){
  lifted=true; }
 if(height[i-1]>height[i]){
  dropped=true; }
 int speed=(height[i-3]-height[i-2])*2;
 while(height[i]==height[i-1]&&lifted==true&&dropped==true){
    switch(speed%10){
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
      a.led(1); }
    delay(1500);
    if(a.getHeightAvg(10)>height[i]){
      lifted=false;
      int height[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
      i=0; }
 }
 delay(500);
}
}
```
# Arduino Circuit Diagram
![Circuit Diagram](https://assumepositiveintentions.github.io/Final/assets/Circuit.jpg)
