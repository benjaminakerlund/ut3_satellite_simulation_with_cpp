/*
 * File ControllerBase.cpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "Controller.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>

using namespace Add;

/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

Controller::Controller(Smp::String8 name_, simtg::NamedObject* parent_,
		Smp::String8 description_) :
		ModelBase(name_, parent_, description_), _I_Y_plus("I_Y_plus", 1, 1,
				"-", simtg::INPUT, &_data, 0), _I_Y_minus("I_Y_minus", 1, 1,
				"-", simtg::INPUT, &_data, 0), _I_Z_plus("I_Z_plus", 1, 1, "-",
				simtg::INPUT, &_data, 0), _I_Z_minus("I_Z_minus", 1, 1, "-",
				simtg::INPUT, &_data, 0), _u_Sun_CSS("u_Sun_CSS", 3, 1, "-",
				simtg::OUTPUT, &_data, 0), _y_angle("y_angle", 1, 1, "-",
				simtg::OUTPUT, &_data, 0), _z_angle("z_angle", 1, 1, "-",
				simtg::OUTPUT, &_data, 0)

/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_defConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Controller::Controller(Smp::String8 name_, Smp::String8 description_,
		Smp::IComposite* parent_) :
		ModelBase(name_, description_, parent_), _I_Y_plus("I_Y_plus", 1, 1,
				"-", simtg::INPUT, &_data, 0), _I_Y_minus("I_Y_minus", 1, 1,
				"-", simtg::INPUT, &_data, 0), _I_Z_plus("I_Z_plus", 1, 1, "-",
				simtg::INPUT, &_data, 0), _I_Z_minus("I_Z_minus", 1, 1, "-",
				simtg::INPUT, &_data, 0), _u_Sun_CSS("u_Sun_CSS", 3, 1, "-",
				simtg::OUTPUT, &_data, 0), _y_angle("y_angle", 1, 1, "-",
				simtg::OUTPUT, &_data, 0), _z_angle("z_angle", 1, 1, "-",
				simtg::OUTPUT, &_data, 0)

/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_namedConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Controller::~Controller() {

	destructor();

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::Publish(Smp::IPublication* publication_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::Configure(Smp::Services::ILogger* logger_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Configure(logger_);

	try {
		configure();
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::Connect(Smp::ISimulator* sim_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 

		/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::initDefaultValues() {

	//set init values of variables
	_I_Y_plus = 0.0;
	_I_Y_minus = 0.0;
	_I_Z_plus = 0.0;
	_I_Z_minus = 0.0;
	for (int row = 0; row < 3; row++) {
		_u_Sun_CSS[row] = 0.0;
	}
	_y_angle = 0.0;
	_z_angle = 0.0;

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	} catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::callMethod(uint32_t methodId_, BaseType* params_)
		throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	switch (methodId_) {
	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Controller::serializeMembers(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	serializeExt(stream_);

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
