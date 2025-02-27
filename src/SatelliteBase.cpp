/*
 * File SatelliteBase.cpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "Satellite.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include "Ori_and_Baffle.hpp"
#include "Controller.hpp"
#include "Cell.hpp"

using namespace Add;

/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

Satellite::Satellite(Smp::String8 name_, simtg::NamedObject* parent_,
		Smp::String8 description_) :
		ModelBase(name_, parent_, description_), _u_sun("u_sun", 3, 1, "-",
				simtg::INPUT, &_data, 0), _u_sun_out("u_sun_out", 3, 1, "-",
				simtg::OUTPUT, &_data, 0)

/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_defConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_Ori_and_Baffle = new Ori_and_Baffle("Ori_and_Baffle", this, "");
	_Controller = new Controller("Controller", this, "");
	_plus_y_cell = new Cell("plus_y_cell", this, "");
	_minus_y_cell = new Cell("minus_y_cell", this, "");

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Satellite::Satellite(Smp::String8 name_, Smp::String8 description_,
		Smp::IComposite* parent_) :
		ModelBase(name_, description_, parent_), _u_sun("u_sun", 3, 1, "-",
				simtg::INPUT, &_data, 0), _u_sun_out("u_sun_out", 3, 1, "-",
				simtg::OUTPUT, &_data, 0)

/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_namedConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_Ori_and_Baffle = new Ori_and_Baffle("Ori_and_Baffle", this, "");
	_Controller = new Controller("Controller", this, "");
	_plus_y_cell = new Cell("plus_y_cell", this, "");
	_minus_y_cell = new Cell("minus_y_cell", this, "");

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Satellite::~Satellite() {

	delete _Ori_and_Baffle;
	delete _Controller;
	delete _plus_y_cell;
	delete _minus_y_cell;

	destructor();

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::Publish(Smp::IPublication* publication_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::Configure(Smp::Services::ILogger* logger_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Configure(logger_);

	try {
		configure();
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::Connect(Smp::ISimulator* sim_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 
		_plus_y_cell->getOutput("I_cell").connect(
				&_Controller->getInput("I_Y_plus"));
		_minus_y_cell->getOutput("I_cell").connect(
				&_Controller->getInput("I_Y_minus"));
		_Ori_and_Baffle->getOutput("u_Sun_CSS").connect(
				&_plus_y_cell->getInput("u_sun"), 0, -1, 0);
		_Ori_and_Baffle->getOutput("k").connect(&_plus_y_cell->getInput("k"), 0,
				-1, 0);
		_Ori_and_Baffle->getOutput("k").connect(&_minus_y_cell->getInput("k"),
				0, -1, 0);
		_Ori_and_Baffle->getOutput("u_Sun_CSS").connect(
				&_minus_y_cell->getInput("u_sun"), 0, -1, 0);
		this->getInput("u_sun").connect(&_Ori_and_Baffle->getInput("u_Sun_Sat"),
				0, -1, 0);
		_Controller->getOutput("u_Sun_CSS").connect(
				&this->getOutput("u_sun_out"), 0, -1, 0);
		_Ori_and_Baffle->getOutput("0").connect(
				&_plus_y_cell->getInput("axis"));
		_Ori_and_Baffle->getOutput("1").connect(
				&_minus_y_cell->getInput("axis"));

		/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::initDefaultValues() {

	//set init values of variables
	for (int row = 0; row < 3; row++) {
		_u_sun[row] = 0.0;
	}
	for (int row = 0; row < 3; row++) {
		_u_sun_out[row] = 0.0;
	}

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	} catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::callMethod(uint32_t methodId_, BaseType* params_)
		throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	switch (methodId_) {
	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Satellite::serializeMembers(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	_Ori_and_Baffle->serialize(stream_);
	_Controller->serialize(stream_);
	_plus_y_cell->serialize(stream_);
	_minus_y_cell->serialize(stream_);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_Aax70fPGEe-t7NJznMhiSA_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
