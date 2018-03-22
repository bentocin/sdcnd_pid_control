#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  
  // Set initial values for the parameters
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;

  p_error_ = 0.0;
  i_error_ = 0.0;
  d_error_ = 0.0;

  counter_ = 1;
}

void PID::UpdateError(double cte) {

  // Initial p_error
  if (counter_ == 1)
  {
    p_error_ = cte;
  }
  // Update the errors
  d_error_ = cte - p_error_;
  p_error_ = cte;
  i_error_ += cte;

  counter_++;
}

double PID::TotalError() {
  return - Kp_ * p_error_ - Kd_ * d_error_ - Ki_ * i_error_;
}

