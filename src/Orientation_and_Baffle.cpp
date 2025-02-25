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
//add user defined includes here
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

	// No baffle implementation yet, k=1
	//simtg::AsyncData<float> k = { 1, 1, 1, 1 };
	//_k = k;
	// Above does not work, set k value as default to 1, 1, 1, 1 in .smf model.

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
