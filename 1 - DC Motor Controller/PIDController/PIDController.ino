#include <PID_v1.h>
#include <PID_AutoTune_v0.h>

#define PIN_INPUT 0
#define PIN_OUTPUT 3

double SetPoint, Input, Output;
double Kp=4289.6,Ki=1,Kd=1;
PID mPid(&Input, &Output, &SetPoint, Kp, Ki, Kd, DIRECT);

void setup() {
  Input = analogRead(PIN_INPUT);
  SetPoint = 100;
  mPid.SetMode(AUTOMATIC);
}

void loop() {
  Input = analogRead(PIN_INPUT);
  mPid.Compute();
  analogWrite(PIN_OUTPUT, Output);
}
