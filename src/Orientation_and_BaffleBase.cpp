/*
 * File Orientation_and_BaffleBase.cpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "Orientation_and_Baffle.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>

using namespace Add;

/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

Orientation_and_Baffle::Orientation_and_Baffle(Smp::String8 name_,
		simtg::NamedObject* parent_, Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_), _u_sun_CSS("u_sun_CSS", 3,
				1, "-", simtg::OUTPUT, &_data, this, 0), _u_sun_SC("u_sun_SC",
				3, 1, "-", simtg::INPUT, &_data, this, 0), _k("k", 4, 1, "-",
				simtg::OUTPUT, &_data, this, 0)

/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_defConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Orientation_and_Baffle::Orientation_and_Baffle(Smp::String8 name_,
		Smp::String8 description_, Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_), _u_sun_CSS("u_sun_CSS", 3,
				1, "-", simtg::OUTPUT, &_data, this, 0), _u_sun_SC("u_sun_SC",
				3, 1, "-", simtg::INPUT, &_data, this, 0), _k("k", 4, 1, "-",
				simtg::OUTPUT, &_data, this, 0)

/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_namedConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Orientation_and_Baffle::~Orientation_and_Baffle() {

	destructor();

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::Publish(Smp::IPublication* publication_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::Configure(Smp::Services::ILogger* logger_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Configure(logger_);

	try {
		configure();
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::Connect(Smp::ISimulator* sim_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::connectData()
		throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 

		/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::initDefaultValues() {

	//set init values of variables
	for (int row = 0; row < 3; row++) {
		_u_sun_CSS[row] = 0.0;
	}
	for (int row = 0; row < 3; row++) {
		_u_sun_SC[row] = 0.0;
	}
	for (int row = 0; row < 4; row++) {
		_k[row] = 0.0;
	}

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	} catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::callMethod(uint32_t methodId_, BaseType* params_)
		throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Orientation_and_Baffle::serializeMembers(
		simtg::SerializationStream& stream_)
				throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	serializeExt(stream_);

	/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_vUy60fOPEe-xNofk1IfsiQ_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
