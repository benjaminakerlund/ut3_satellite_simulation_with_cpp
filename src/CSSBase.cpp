/*
 * File CSSBase.cpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_auto_cpp_before_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

#include "CSS.hpp"
#include <simtg/smp/TimeKeeperAdapter.hpp>
#include <simtg/smp/ConnectionService.hpp>
#include <simtg/smp/LoggerMacros.hpp>
#include <simtg/kernel/MethodCallAsyncDataListener.hpp>
#include "Cell.hpp"
#include "Orientation_and_Baffle.hpp"

using namespace Add;

/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_auto_cpp_after_includeauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

CSS::CSS(Smp::String8 name_, simtg::NamedObject* parent_,
		Smp::String8 description_) :
		AsyncModelBase(name_, parent_, description_), _Current_Y_plus(
				"Current_Y_plus", 1, 1, "-", simtg::OUTPUT, &_data, this, 0), _Current_Y_minus(
				"Current_Y_minus", 1, 1, "-", simtg::OUTPUT, &_data, this, 0), _Current_Z_plus(
				"Current_Z_plus", 1, 1, "-", simtg::OUTPUT, &_data, this, 0), _Current_Z_minus(
				"Current_Z_minus", 1, 1, "-", simtg::OUTPUT, &_data, this, 0), _u_sun_SC(
				"u_sun_SC", 3, 1, "-", simtg::INPUT, &_data, this, 0), _e("e",
				1, 1, "-", simtg::INPUT, &_data, this, 0)

/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_defConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_Cell_Y_minus = new Cell("Cell_Y_minus", this, "");
	_Cell_Y_plus = new Cell("Cell_Y_plus", this, "");
	_Cell_Z_plus = new Cell("Cell_Z_plus", this, "");
	_Cell_Z_minus = new Cell("Cell_Z_minus", this, "");
	_Orientation_and_Baffle = new Orientation_and_Baffle(
			"Orientation_and_Baffle", this, "");

	_subModelsSequencer.push_back(_Orientation_and_Baffle);
	_subModelsSequencer.push_back(_Cell_Y_plus);
	_subModelsSequencer.push_back(_Cell_Y_minus);
	_subModelsSequencer.push_back(_Cell_Z_plus);
	_subModelsSequencer.push_back(_Cell_Z_minus);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_defConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
CSS::CSS(Smp::String8 name_, Smp::String8 description_,
		Smp::IComposite* parent_) :
		AsyncModelBase(name_, description_, parent_), _Current_Y_plus(
				"Current_Y_plus", 1, 1, "-", simtg::OUTPUT, &_data, this, 0), _Current_Y_minus(
				"Current_Y_minus", 1, 1, "-", simtg::OUTPUT, &_data, this, 0), _Current_Z_plus(
				"Current_Z_plus", 1, 1, "-", simtg::OUTPUT, &_data, this, 0), _Current_Z_minus(
				"Current_Z_minus", 1, 1, "-", simtg::OUTPUT, &_data, this, 0), _u_sun_SC(
				"u_sun_SC", 3, 1, "-", simtg::INPUT, &_data, this, 0), _e("e",
				1, 1, "-", simtg::INPUT, &_data, this, 0)

/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_namedConst_constructor_init) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/
{

	_Cell_Y_minus = new Cell("Cell_Y_minus", this, "");
	_Cell_Y_plus = new Cell("Cell_Y_plus", this, "");
	_Cell_Z_plus = new Cell("Cell_Z_plus", this, "");
	_Cell_Z_minus = new Cell("Cell_Z_minus", this, "");
	_Orientation_and_Baffle = new Orientation_and_Baffle(
			"Orientation_and_Baffle", this, "");

	_subModelsSequencer.push_back(_Orientation_and_Baffle);
	_subModelsSequencer.push_back(_Cell_Y_plus);
	_subModelsSequencer.push_back(_Cell_Y_minus);
	_subModelsSequencer.push_back(_Cell_Z_plus);
	_subModelsSequencer.push_back(_Cell_Z_minus);

	registerData();
	registerParams();
	registerStates();
	registerOthers();
	registerPorts();
	initDefaultValues();
	initScheduling();

	constructor();

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_namedConst) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
CSS::~CSS() {

	delete _Cell_Y_minus;
	delete _Cell_Y_plus;
	delete _Cell_Z_plus;
	delete _Cell_Z_minus;
	delete _Orientation_and_Baffle;

	destructor();

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_defDestr) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::Publish(Smp::IPublication* publication_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Publish(publication_);
	try {
		/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_publish_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_publish) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::Configure(Smp::Services::ILogger* logger_)
		throw (Smp::IModel::InvalidModelState) {

	ModelBase::Configure(logger_);

	try {
		configure();
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_configure) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::Connect(Smp::ISimulator* sim_) throw (Smp::IModel::InvalidModelState) {

	ModelBase::Connect(sim_);

	try {
		//data connections 
		connectData();
		//interface connections
		//system interface connections

		/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_connect_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_connect) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::connectData() throw (Smp::IModel::InvalidModelState) {

	try {
		//data connections 
		_Cell_Z_minus->getOutput("I_cell").connect(
				&this->getOutput("Current_Z_minus"));
		_Cell_Z_plus->getOutput("I_cell").connect(
				&this->getOutput("Current_Z_plus"));
		_Cell_Y_minus->getOutput("I_cell").connect(
				&this->getOutput("Current_Y_minus"));
		_Cell_Y_plus->getOutput("I_cell").connect(
				&this->getOutput("Current_Y_plus"));
		_Orientation_and_Baffle->getOutput("u_sun_CSS").connect(
				&_Cell_Y_plus->getInput("u_sun"), 0, -1, 0);
		_Orientation_and_Baffle->getOutput("u_sun_CSS").connect(
				&_Cell_Y_minus->getInput("u_sun"), 0, -1, 0);
		_Orientation_and_Baffle->getOutput("u_sun_CSS").connect(
				&_Cell_Z_plus->getInput("u_sun"), 0, -1, 0);
		_Orientation_and_Baffle->getOutput("u_sun_CSS").connect(
				&_Cell_Z_minus->getInput("u_sun"), 0, -1, 0);
		_Orientation_and_Baffle->getOutput("k").connect(
				&_Cell_Y_plus->getInput("k"), 0, -1, 0);
		_Orientation_and_Baffle->getOutput("k").connect(
				&_Cell_Y_minus->getInput("k"), 0, -1, 0);
		_Orientation_and_Baffle->getOutput("k").connect(
				&_Cell_Z_plus->getInput("k"), 0, -1, 0);
		_Orientation_and_Baffle->getOutput("k").connect(
				&_Cell_Z_minus->getInput("k"), 0, -1, 0);
		this->getInput("u_sun_SC").connect(
				&_Orientation_and_Baffle->getInput("u_sun_SC"), 0, -1, 0);
		this->getInput("e").connect(&_Cell_Y_plus->getInput("e"));
		this->getInput("e").connect(&_Cell_Y_minus->getInput("e"));
		this->getInput("e").connect(&_Cell_Z_plus->getInput("e"));
		this->getInput("e").connect(&_Cell_Z_minus->getInput("e"));

		/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_connectData_catching) ENABLED START*/
		//add user defined code here
		/*PROTECTED REGION END*/
	} catch (simtg::Exception& simtgException) {
		throw simtg::ModelBase::InvalidModelState(_state, simtgException);
	} catch (Smp::Exception& smpException) {
		throw simtg::ModelBase::InvalidModelState(_state, smpException);
	}

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_connectData) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::initDefaultValues() {

	//set init values of variables
	_Current_Y_plus = 0.0;
	_Current_Y_minus = 0.0;
	_Current_Z_plus = 0.0;
	_Current_Z_minus = 0.0;
	for (int row = 0; row < 3; row++) {
		_u_sun_SC[row] = 0.0;
	}
	_e = false;

	initSubModelsDefaultValues();

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_initDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::initSubModelsDefaultValues() {

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_initSubModelsDefaultValues) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::initScheduling() {

	std::list<MethodInfo> methods;

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_initScheduling_before_pushback) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	try {
		registerMethods(methods);
	} catch (simtg::Exception& e) {
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_initSheduling) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::callMethod(uint32_t methodId_, BaseType* params_)
		throw (SchedulableObject::BreakPointReached, simtg::Exception) {

	preCompute();
	switch (methodId_) {
	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_callMethod_switch) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/
	default:
		ModelBase::callMethod(methodId_, params_);
	}
	postCompute();
	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_callMethod) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}
void CSS::serializeMembers(simtg::SerializationStream& stream_)
		throw (simtg::SerializationException) {

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_start_serializeMembers) ENABLED START*/
	// add user defined code here
	/*PROTECTED REGION END*/

	_Cell_Y_minus->serialize(stream_);
	_Cell_Y_plus->serialize(stream_);
	_Cell_Z_plus->serialize(stream_);
	_Cell_Z_minus->serialize(stream_);
	_Orientation_and_Baffle->serialize(stream_);

	serializeExt(stream_);

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_serializeMembers) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

}

/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_auto_cpp_end_extensionsauto) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/
