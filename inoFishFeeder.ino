#include <Servo.h>
 
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

#define HRS_12 43100000UL 
//#define HRS_12 4000UL 

#define HRS_8  28800000UL 
#define HRS_4  14400000UL 
#define HRS_1  3600000UL

//#define HRS_8  8000UL 
//#define HRS_4  4000UL

unsigned long startTime;
int servoid = 0;
bool vgo = false;

int igo = 0;


void setup() {
  servo0.attach(2);  servo0.write(0);
  servo1.attach(3);  servo1.write(0);
  servo2.attach(4);  servo2.write(0);
  servo3.attach(5);  servo3.write(0);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  startTime = millis();
}
 
void loop() {

  if (millis() - startTime > HRS_4)
    digitalWrite(LED_BUILTIN, HIGH);
  else
    digitalWrite(LED_BUILTIN, LOW);

/*
  if ((millis() - startTime > HRS_8) && servoid==0)
    vgo = true;
      
  if ((millis() - startTime > HRS_12) && servoid>0) {
    if (igo==0)
      igo = 1;
    else if (igo>0) {
      vgo = true;
      igo = 0;
    }
  }
*/
      
  if ((millis() - startTime > HRS_12)) {
    if (igo==0)
      igo = 1;
    else if (igo>0) {
      vgo = true;
      igo = 0;
    }
  }
      

  if (vgo == true){
    
    if (servoid==0)
      for (int pos = 0; pos <= 180; pos += 1) {
        servo0.write(pos);              
        delay(20);                       
      }
    
    if (servoid==1)
      for (int pos = 0; pos <= 180; pos += 1) {
        servo1.write(pos);              
        delay(20);                       
      }

    if (servoid == 2)
      for (int pos = 0; pos <= 180; pos += 1) {
        servo2.write(pos);              
        delay(20);                       
      }

    if (servoid == 3)
      for (int pos = 0; pos <= 180; pos += 1) {
        servo3.write(pos);              
        delay(20);                       
      }

    servoid++;
    vgo = false;
    startTime = millis();
  }
   
}
