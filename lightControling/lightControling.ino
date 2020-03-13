/**

   this set to work


*/

#include <PID_v1.h>

const int interiorLdr0 = A0;

const int interiorLightControler = 13;

//***********************************************/
double Setpoint , Input, Output;

double aggKp = 4, aggKi = 0.2, aggKd = 1;
double consKp = 1, consKi = 0.05, consKd = 0.25;
//**********************************************/

PID myPID(&Input, &Output, &Setpoint, consKp, consKi, consKd, DIRECT);

void pidLigthController();

void setup() {

  Serial.begin(9600);
  Input = analogRead(interiorLdr0);
  Setpoint = 100;
  myPID.SetMode(AUTOMATIC);

}

void loop() {

  Input = analogRead(interiorLdr0);
  //  pidLigthController();
  //  delay(1000);

  double gap = abs(Setpoint - Input);

  if (gap < 10) {

  } else if (gap > 10) {

  } else {

  }

}

void pidLigthController() {

  double gap = abs(Setpoint - Input);

  if (gap < 10) {
    myPID.SetTunings(consKp, consKi, consKd);
  } else {
    myPID.SetTunings(aggKp, aggKi, aggKd);
  }

  myPID.Compute();
  Serial.println(Output);
  analogWrite(interiorLightControler, 255 - Output);

}
