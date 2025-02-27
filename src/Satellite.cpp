/*
 * File Satellite.cpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_impl_cpp_before_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "Satellite.hpp"
#include "Ori_and_Baffle.hpp"
#include "Controller.hpp"
#include "Cell.hpp"

using namespace Add;

OBJECT_MAKER(Satellite)

/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_impl_cpp_after_includeimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

void Satellite::constructor() {
	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSAdelegated_constructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::destructor() {
	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSAdelegated_destructor) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::configure() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSAdelegated_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::serializeExt(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {
	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSAserializeExt) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::step() throw (simtg::Exception) {
	/*PROTECTED REGION ID(_Aax71PPGEe-t7NJznMhiSA) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::init() throw (simtg::Exception) {

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_startInit) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	_Ori_and_Baffle->init();
	_Controller->init();
	_plus_y_cell->init();
	_minus_y_cell->init();

	ModelBase::init();

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_init) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_impl_cpp_end_extensionsimplementation) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
