/*
 * File CSS.cpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "CSS.hpp"
#include "Cell.hpp"
#include "Orientation_and_Baffle.hpp"

using namespace Add;

OBJECT_MAKER(CSS)

/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void CSS::constructor() {
	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::destructor() {
	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::serializeExt(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_7RfoRPONEe-xNYfk1IfsiQ) ENABLED START*/

	/*PROTECTED REGION END*/

}
void CSS::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	_Cell_Y_minus->init();
	_Cell_Y_plus->init();
	_Cell_Z_plus->init();
	_Cell_Z_minus->init();
	_Orientation_and_Baffle->init();

	AsyncModelBase::init();

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
