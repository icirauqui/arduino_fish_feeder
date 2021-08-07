#include <Servo.h>

unsigned long HRS_1 = 3600000;
unsigned long startTime;

// Number of servos to control, starting in pin 2
const int nServos = 10;
Servo servos[nServos];

// Active servo and go flag
int servoid = 0;
bool vgo = false;

// Hour counter and period
int ithr = 0;
int cnhr = 24;


void setup() {
  // Init all servos
  for (unsigned int i=0; i<nServos; i++){
    servos[i].attach(i+2);
    servos[i].write(0);
  }

  // Init led
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Init counter
  startTime = millis();
}

void loop() {

  // Blink 0.5 h
  if (millis() - startTime > HRS_1/2)
    digitalWrite(LED_BUILTIN, HIGH);
  else
    digitalWrite(LED_BUILTIN, LOW);

  // Count hours
  if (millis() - startTime > HRS_1){
    startTime = millis();
    ithr += 1;
    if (ithr >= cnhr)
      vgo = true;
  }

  // Control servo
  if (vgo == true){
    for (int pos = 0; pos <= 180; pos += 1){
      servos[servoid].write(pos);
      delay(20);
    }

    servoid++;
    vgo = false;
    ithr = 0;
  }
}
