#include "PID.h"
#include <iostream>
#include <cmath>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */
/*
* As a deviation from the current implementation format,
* I am implementing using the pimpl - pointer to implementation
* refer : cppreference.com  - https://en.cppreference.com/w/cpp/language/pimpl
*/


class PIDImpl
{
public:

	PIDImpl(double Kp, double Kd, double Ki, double dt, double max, double min);
	~PIDImpl();
	double calculate(double setpoint, double pv);
private

	double _Kp;
	double _Kd;
	double _Ki;
	double _dt;
	double _max;
	double _min;
	double _pre_error;
	double _integral;
};

PID::PID() {
	
}

PID::~PID() {
	delete pimpl;
}

void PID::Init(double Kp_, double Ki_, double Kd_, double dt, double max, double min) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
	Kp = Kp_;
	Ki = Ki_;
	kd = Kd_;
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
	pimpl = new PIDImpl(Kp, Kd, Ki, dt, max, min);
}

double PID::calculate(double setpoint, double pv) {
	return pimpl->calculate(setpoint, pv);
}


PIDImpl::PIDImpl(double dt, double max, double min, double Kp, double Kd, double Ki) :
	_dt(dt),
	_max(max),
	_min(min),
	_Kp(Kp),
	_Kd(Kd),
	_Ki(Ki),
	_pre_error(0),
	_integral(0)
{

}

double PIDImpl::calculate(double setpoint, double pv) {
	double error = setpoint - pv;
	P_value = _Kp* error;
	
	_integral += error * _dt;
	double i_value = _Ki * _integral;

	double derivative = (error - _pre_error) / _dt;
	double d_value = _Kd * derivative;

	double total_error = p_value + i_value + d_value;

}


void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
	p_error = Kp - cte;
	P_value = Kp * p_error;
	i_error += p_error;
	d_error += Kd * (d_error - ;


}
PIDImpl::~PIDImpl() {
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */

  return Kp*p_error + Ki*i_error + Kd*d_error;  // TODO: Add your total error calc here!

}