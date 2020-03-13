/**

   this set to work


*/

#include <PID_v1.h>

const float epsilon = 0.01;
const float dt = 0.01;
const float MAX = 255;
const float MIN = 0;

//const float Kp = 0.1;
//const float Kd = 0.01;
//const float Ki = 0.005;

const float Kp = 0;
const float Kd = 0;
const float Ki = 10;

//static float per_error = 0;
//static float integral = 0;
//

const int interiorLdr0 = A0;

const int interiorLightControler = 13;

//***********************************************/
double Setpoint , Input, Output;

//double aggKp = 4, aggKi = 0.2, aggKd = 1;
//double consKp = 1, consKi = 0.05, consKd = 0.25;

//**********************************************/

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

//void pidLigthController();

void setup() {

  Serial.begin(9600);
  //  Input = analogRead(interiorLdr0);
  Setpoint = 100;
  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp, Ki, Kd);

}

void loop() {

  Input = map(analogRead(interiorLdr0), 0, 1024, 255, 0);

  myPID.Compute();
  analogWrite(interiorLightControler, Output);

  Serial.print(Input);
  Serial.print(" ");
  Serial.println(Output);
  Serial.print(" ");
  Serial.println(Setpoint);
  delay(100);


  //  pidLigthController();
  //  delay(1000);

  //  double gap = abs(Setpoint - Input);
  //
  //  if (gap < 10) {
  //
  //  } else if (gap > 10) {
  //
  //  } else {
  //
  //  }

}

//float pidLigthController(int setpoint, int actual_position) {
//
//  //  double gap = abs(Setpoint - Input);
//  //
//  //  if (gap < 10) {
//  //    myPID.SetTunings(consKp, consKi, consKd);
//  //  } else {
//  //    myPID.SetTunings(aggKp, aggKi, aggKd);
//  //  }
//  //
//  //  myPID.Compute();
//  //  Serial.println((255 - Output));
//  //  analogWrite(interiorLightControler, (255 - Output));
//
//
//
//  float error = 0;
//  float derivative = 0;
//  float output = 0;
//
//  error = setpoint - actual_position;
//  float error_abs = abs(error);
//
//  if (error_abs > epsilon) {
//    integral = integral + error * dt;
//  }
//
//  derivative = (error - per_error) / dt;
//
//  output = (Kp * error) + (Ki * integral) + (Kd * derivative);
//
//  if (output > MAX) {
//
//    putput = MAX;
//
//  } else if (output < MIN) {
//
//    output = MIN;
//
//  }
//
//  per_error = error;
//
//  return output;
//
//
//}
