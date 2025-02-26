/*
 * File Orientation_and_Baffle.cpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_impl_cpp_before_includeimplementation) ENABLED START*/
#include <math.h>

// Baffle maximum and minimum angle values definition for each sector (sectors in this case from [0, 39] as indexed
const float Zplus_min[40] = {75.275 ,75.450 ,75.968 ,76.822 ,77.998 ,79.474 ,79.638 ,78.615 ,77.871 ,77.418 ,77.264 ,68.965 ,52.764 ,41.770 ,34.553 ,29.761 ,26.539 ,24.384 ,23.005 ,22.233 ,21.984 ,22.233 ,23.005 ,24.384 ,26.539 ,29.761 ,34.553 ,41.770 ,52.764 ,68.965 ,77.264 ,77.418 ,77.871 ,78.615 ,79.638 ,79.474 ,77.998 ,76.822 ,75.968 ,75.450 };
const float Zplus_max[40] = {89.279 ,89.289 ,89.315 ,89.360 ,89.417 ,89.490 ,89.577 ,89.660 ,89.655 ,89.642 ,87.060 ,69.021 ,52.764 ,41.770 ,34.553 ,29.761 ,26.539 ,24.384 ,23.005 ,22.233 ,21.984 ,22.233 ,23.005 ,24.384 ,26.539 ,29.761 ,34.553 ,41.770 ,52.764 ,69.021 ,87.060 ,89.642 ,89.655 ,89.660 ,89.577 ,89.490 ,89.417 ,89.360 ,89.315 ,89.289 };
const float Yminus_min[40] = {77.263 ,77.418 ,77.871 ,78.615 ,79.638 ,79.474 ,77.998 ,76.822 ,75.968 ,75.450 ,75.276 ,75.450 ,75.968 ,76.822 ,77.998 ,77.590 ,68.482 ,66.528 ,65.130 ,64.295 ,64.016 ,63.686 ,52.764 ,41.770 ,34.553 ,29.761 ,26.539 ,24.384 ,23.005 ,22.233 ,21.984 ,22.233 ,23.005 ,24.384 ,26.539 ,29.761 ,34.553 ,41.770 ,52.764 ,68.965};
const float Yminus_max[40] = {87.318 ,89.642 ,89.655 ,89.660 ,89.577 ,89.490 ,89.417 ,89.360 ,89.315 ,89.289 ,89.279 ,89.289 ,89.315 ,89.360 ,89.417 ,89.490 ,89.577 ,87.162 ,82.122 ,81.822 ,81.550 ,69.021 ,52.764 ,41.770 ,34.553 ,29.761 ,26.539 ,24.384 ,23.005 ,22.233 ,21.984 ,22.233 ,23.005 ,24.384 ,26.539 ,29.761 ,34.553 ,41.770 ,52.764 ,69.021};
const float Zminus_min[40] = {21.982 ,22.233 ,23.005 ,24.384 ,26.539 ,29.761 ,34.553 ,41.770 ,52.764 ,68.965 ,77.264 ,77.418 ,77.871 ,75.805 ,71.582 ,68.167 ,65.371 ,63.210 ,61.676 ,60.759 ,60.456 ,60.759 ,61.676 ,63.210 ,65.371 ,68.167 ,71.582 ,75.805 ,77.871 ,77.418 ,77.264 ,68.965 ,52.764 ,41.770 ,34.553 ,29.761 ,26.539 ,24.384 ,23.005 ,22.233};
const float Zminus_max[40] = {21.982 ,22.233 ,23.005 ,24.384 ,26.539 ,29.761 ,34.553 ,41.770 ,52.764 ,69.021 ,87.060 ,89.642 ,89.655 ,89.651 ,89.565 ,81.939 ,76.850 ,75.570 ,74.642 ,74.081 ,73.892 ,74.081 ,74.642 ,75.570 ,76.850 ,81.939 ,89.565 ,89.651 ,89.655 ,89.642 ,87.060 ,69.021 ,52.764 ,41.770 ,34.553 ,29.761 ,26.539 ,24.384 ,23.005 ,22.233};
const float Yplus_min[40] = {77.263 ,68.965 ,52.764 ,41.770 ,34.553 ,29.761 ,26.539 ,24.384 ,23.005 ,22.233 ,21.984 ,22.233 ,23.005 ,24.384 ,26.539 ,29.761 ,34.553 ,41.770 ,52.764 ,63.686 ,64.016 ,64.295 ,65.130 ,66.528 ,68.482 ,77.590 ,77.998 ,76.822 ,75.968 ,75.450 ,75.276 ,75.450 ,75.968 ,76.822 ,77.998 ,79.474 ,79.638 ,78.615 ,77.871 ,77.418};
const float Yplus_max[40] = {87.318 ,69.021 ,52.764 ,41.770 ,34.553 ,29.761 ,26.539 ,24.384 ,23.005 ,22.233 ,21.984 ,22.233 ,23.005 ,24.384 ,26.539 ,29.761 ,34.553 ,41.770 ,52.764 ,69.021 ,81.550 ,81.822 ,82.122 ,87.162 ,89.577 ,89.490 ,89.417 ,89.360 ,89.315 ,89.289 ,89.279 ,89.289 ,89.315 ,89.360 ,89.417 ,89.490 ,89.577 ,89.660 ,89.655 ,89.642};

float get_k(float elev, float theta_min, float theta_max) {
	 elev = elev * M_PI/180.0;
	 theta_min = theta_min * M_PI / 180.0;
	 theta_max = theta_max * M_PI / 180.0;

	 if (elev < theta_min) {return 1.0;}
	 else if (elev >= theta_min && elev <= theta_max) {return (sin(theta_max-theta_min));}
	 else if (elev > theta_max) {return 0.0;}
	 else {return 0.0;}
	 }
/*PROTECTED REGION END*/

#include "Orientation_and_Baffle.hpp"

using namespace Add;

OBJECT_MAKER(Orientation_and_Baffle)

/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void Orientation_and_Baffle::constructor() {
	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::destructor() {
	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::serializeExt(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_vUy61POPEe-xNofk1IfsiQ) ENABLED START*/

	// Convert reference frame
	_u_sun_CSS[0] = -_u_sun_SC[2];
	_u_sun_CSS[1] = _u_sun_SC[1];
	_u_sun_CSS[2] = _u_sun_SC[0];

	/* COMMENTED OUT FOR TESTING PURPOSES, DEFAULT VALUES FOR K GIVEN IN MODEL AS K=1
	 // Baffle implementation
	 float az_el_magn = sqrt(
	 _u_sun_CSS[0] * _u_sun_CSS[0] + _u_sun_CSS[1] * _u_sun_CSS[1]
	 + _u_sun_CSS[2] * _u_sun_CSS[2])
	 float elevation = acos(_u_sun_CSS[0]) * 180 / M_PI; // elevation
	 float azimuth = acos(_u_sun_CSS[2] / (sin(elevation))) * 180 / M_PI;
	 k1 = getK(elevation, Zplus_min[0], Zplusmax[0]);
	 k2 = getK(elevation, Zminus_min[10], Zminus_max[10]);
	 k3 = getK(elevation, Yplus_min[20], Yplus_max[20]);
	 k4 = getK(elevation, Yminus_min[30], Yminus_max[30]);
	 _k = {k1, k2, k3, k4};
	 */


	// axis outputs
	_a0 = 0;
	_a1 = 1;
	_a2 = 2;
	_a3 = 3;
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
