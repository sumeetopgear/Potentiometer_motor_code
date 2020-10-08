#include <Servo.h>

int potPin = A1;  //input pin for potentiometer
int escLpin = 2;  //digital pin for escL
int escRpin = 3;  //digital pin for escR

Servo escL; // creating servo obj to control Left ESC
Servo escR; // creating servo obj to control Right ESC
int escLVal = 0;  
int escRVal = 0;  
int maxVal = 180; 
int minPW = 1000; //defining min Pulse Width
int maxPW = 2000; //defining max Pulse Width

void setup() {
  
  escL.attach(escLpin, minPW, maxPW);
  escR.attach(escLpin, minPW, maxPW);

  Serial.begin(9600); //opening serial port at 9600 bps for Serial Monitor
  

}

void loop() 
{
  int potVal = analogRead(potPin); // reads raw value from potentiometer
  potVal = map(potVal, 0, 1023, 0, maxVal);

      if(potVal == maxVal/2) { 
    
    escLVal = maxVal;
    escRVal = maxVal;
    
    } 
    else if (potVal < 90) {
  
    escLVal = 120 + (2.0/3) * potVal;
    escRVal = 180;
   }
      else if (potVal > 90){
    escLVal = 180;
    escRVal = 180 - (2.0/3) * (potVal - 90);
   }

   escL.write(escLVal);
   escR.write(escRVal);

   Serial.print("Mapped potVal: ");
   Serial.print(potVal); Serial.print("; ");
   Serial.print("ESC L Value: ");
   Serial.print(escLVal); Serial.print("; ");
   Serial.print("ESC R Value: ");
   Serial.print(escRVal); Serial.println("; ");
   delay(100);


}  
