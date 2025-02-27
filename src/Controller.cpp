/*
 * File Controller.cpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
#include <math.h>
#include <stdio.h>
/*PROTECTED REGION END*/

#include "Controller.hpp"

using namespace Add;

OBJECT_MAKER(Controller)

/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void Controller::constructor() {
	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDwdelegated_constructor) ENABLED START*/
	//add user defined code here
	K_p = 0.9;
	K_d = 0;
	K_i = 0.03;

	Y_error_prior = 0;
	Z_error_prior = 0;

	Y_integral_prior = 0;
	Z_integral_prior = 0;

	//Y_history
	/*PROTECTED REGION END*/

}
void Controller::destructor() {
	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDwdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDwdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::serializeExt(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDwserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_GjTOlPBrEe-2qtLpG8DnDw) ENABLED START*/
	//add user defined code here
	float stepTime = 0.01;
	// Y and Z difference
	float Y_error = (_I_Y_plus - _I_Y_minus);
	float Z_error = (_I_Z_plus - _I_Z_minus);

	// PID Controller:
	float Y_integral = Y_integral_prior + Y_error * stepTime;
	float Y_derivative = (Y_error - Y_error_prior) / stepTime;
	float Y_output = K_p * Y_error + K_i * Y_integral + K_d * Y_derivative;
	Y_error_prior = Y_error;
	Y_integral_prior = Y_integral;

	float Z_integral = Z_integral_prior + Z_error * stepTime;
	float Z_derivative = (Z_error - Z_error_prior) / stepTime;
	float Z_output = K_p * Z_error + K_i * Z_integral + K_d * Z_derivative;
	Z_error_prior = Z_error;
	Z_integral_prior = Z_integral;

	_y_angle = Y_output;
	_z_angle = Z_output;

	Y_history.push_back(Y_output);
	Z_history.push_back(Z_output);

	// Transform back to spacecraft coordinates
	float x = cos(_y_angle);
	float y = sin(_y_angle) * sin(_z_angle);
	float z = sin(_y_angle) * cos(_z_angle);

	_u_Sun_CSS[0] = -z;
	_u_Sun_CSS[1] = y;
	_u_Sun_CSS[2] = x;

	FILE *f = fopen("data.csv", "a");
	char msg[512];

	sprintf(msg, "%f, %f\n", Y_output, Z_output);
	fprintf(f, msg);
	fclose(f);

	/*PROTECTED REGION END*/

}
void Controller::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_startInit) ENABLED START*/
	// add user defined code here
	FILE *f = fopen("data.csv", "w");
	fclose(f);
	Y_history.push_back(0);
	Z_history.push_back(0);
	/*PROTECTED REGION END*/

	ModelBase::init();

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
