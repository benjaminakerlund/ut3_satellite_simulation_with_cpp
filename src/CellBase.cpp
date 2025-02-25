/*
 * File CellBase.cpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "Cell.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>

using namespace Add;

/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

Cell::Cell(Smp::String8 name_, simtg::NamedObject* parent_,
		Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_), _u_sun("u_sun", 3, 1, "-",
				simtg::INPUT, &_data, this, 0), _I_cell("I_cell", 1, 1, "-",
				simtg::OUTPUT, &_data, this, 0), _e("e", 1, 1, "-",
				simtg::INPUT, &_data, this, 0), _k("k", 4, 1, "-", simtg::INPUT,
				&_data, this, 0), _axis("axis", 1, 1, "-", simtg::INPUT, &_data,
				this, 0)

/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_defConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Cell::Cell(Smp::String8 name_, Smp::String8 description_,
		Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_), _u_sun("u_sun", 3, 1, "-",
				simtg::INPUT, &_data, this, 0), _I_cell("I_cell", 1, 1, "-",
				simtg::OUTPUT, &_data, this, 0), _e("e", 1, 1, "-",
				simtg::INPUT, &_data, this, 0), _k("k", 4, 1, "-", simtg::INPUT,
				&_data, this, 0), _axis("axis", 1, 1, "-", simtg::INPUT, &_data,
				this, 0)

/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_namedConst_constructor_init) ENABLED START*/
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

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
Cell::~Cell() {

	destructor();

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::Publish(Smp::IPublication* publication_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::Configure(Smp::Services::ILogger* logger_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Configure(logger_);

	try {
		configure();
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::Connect(Smp::ISimulator* sim_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 

		/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::initDefaultValues() {

	//set init values of variables
	for (int row = 0; row < 3; row++) {
		_u_sun[row] = 0.0;
	}
	_I_cell = 0.0;
	_e = false;
	for (int row = 0; row < 4; row++) {
		_k[row] = 0.0;
	}
	_axis = 0;

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	} catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::callMethod(uint32_t methodId_, BaseType* params_)
		throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void Cell::serializeMembers(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	serializeExt(stream_);

	/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_bDafANNTEe-HHfwhf86eRQ_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
