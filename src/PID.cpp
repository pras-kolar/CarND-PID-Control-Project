#include "PID.h"

using namespace std;
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
}

void PID::UpdateError(double setpoint, double pv) {
  /**
   * TODO: Update PID errors based on cte.
   */
  	double _dt;
	double _max;
	double _min;
	double _pre_error=0.0;
	double _integral=0.0;

    double error = setpoint - pv;
  
    double p_value = Kp * error;
    double integral += error * _dt;
  
    double i_value = Ki * integral;

    double derivative = (error - _pre_error) / _dt;
    double d_value = Kd *  derivative;
    pre_error = error;
    
    TotalError(p_value, i_value, d_value);
}

double PID::TotalError(double p_value, double i_value, double d_value) {
  /**
   * TODO: Calculate and return the total error
   */
  return (p_value + i_value + d_value);  // TODO: Add your total error calc here!
}
