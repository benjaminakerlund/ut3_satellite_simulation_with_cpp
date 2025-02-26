/*
 * File Cell.cpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_impl_cpp_before_includeimplementation) ENABLED START*/
#include <math.h>
#include <numeric>
/*PROTECTED REGION END*/

#include "Cell.hpp"

using namespace Add;

OBJECT_MAKER(Cell)

/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void Cell::constructor() {
	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::destructor() {
	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::serializeExt(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_bDafA9NTEe-HHfwhf86eRQ) ENABLED START*/
	float alpha = 22 * (M_PI / 180);		// sunsensor angle, converted to rad
	float I_max = 31.0 / 1000;			// max current in [A]
	float v = 9.6;						// largest incident coeff [-]
	//float N_CSS = 2.3 * pow(10, -10);	// Noise coefficient
	//float N = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / N_CSS)); // Noise
	float N = 0.0;

	float n[4][3];
	n[0][0] = sin(alpha);
	n[0][1] = cos(alpha);
	n[0][2] = 0;
	n[1][0] = sin(alpha);
	n[1][1] = -cos(alpha);
	n[1][2] = 0;
	n[2][0] = sin(alpha);
	n[2][1] = 0;
	n[2][2] = cos(alpha);
	n[3][0] = sin(alpha);
	n[3][1] = 0;
	n[3][2] = -cos(alpha);

	float dotProd = (_u_sun[0] * n[_axis][0]) + (_u_sun[1] * n[_axis][1])
			+ (_u_sun[2] * n[_axis][2]);

	float lambda = 1 - pow(((2 / M_PI) * acos(dotProd)), v);

	_I_cell = ((I_max * (dotProd * lambda * _k[_axis] * _e)) + N);
	/*PROTECTED REGION END*/

}
void Cell::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
