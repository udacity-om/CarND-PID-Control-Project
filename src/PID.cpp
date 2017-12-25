#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
   this->Kp = Kp;
   this->Ki = Ki;
   this->Kd = Kd;
   
   p_error = 0;
   i_error = 0;
   d_error = 0;
   prev_error = 0;
}

void PID::UpdateError(double error) {
   p_error = error;
   i_error += error;
   d_error = error - prev_error; /* delta time is 1, so skipping division */
   prev_error = error;
}

double PID::TotalError() {
   double total_error;
   
   total_error = (Kp*p_error) + (Ki*i_error) + (Kd*d_error);
   
   return total_error;
}

