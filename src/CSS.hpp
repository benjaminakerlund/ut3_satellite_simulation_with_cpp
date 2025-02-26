/*
 * File CSS.hpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

#ifndef __CSS__HPP
#define __CSS__HPP

#include <simtg/model/AsyncModelBase.hpp>
#include <Add/Add.hpp>
#include <simtg/kernel/Data.hpp>
#include <simtg/kernel/AsyncData.hpp>

/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_header_hpp_include) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

namespace Add {
class Cell;
class Orientation_and_Baffle;
}

namespace Add {

/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_hpp_inside_namespace) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

class CSS: public simtg::AsyncModelBase {

public:
	/**
	 [OUTPUT] 
	 */
	simtg::AsyncFloat _Current_Y_plus;
	/**
	 [OUTPUT] 
	 */
	simtg::AsyncFloat _Current_Y_minus;
	/**
	 [OUTPUT] 
	 */
	simtg::AsyncFloat _Current_Z_plus;
	/**
	 [OUTPUT] 
	 */
	simtg::AsyncFloat _Current_Z_minus;
	/**
	 [INPUT]  [3]
	 */
	simtg::AsyncFloat _u_sun_SC;
	/**
	 [INPUT] 
	 */
	simtg::AsyncInt _e;
	Cell* _Cell_Y_minus;
	Cell* _Cell_Y_plus;
	Cell* _Cell_Z_plus;
	Cell* _Cell_Z_minus;
	Orientation_and_Baffle* _Orientation_and_Baffle;

private:
	/**
	 Delegated constructor
	 */
	void constructor();
	/**
	 Delegated destructor
	 */
	void destructor();
	/**
	 Delegated configure
	 */
	void configure() throw (simtg::Exception);
	/**
	 Delegated serialize method. Permits to serialize additional fields.
	 @param stream_         a serialization stream
	 */
	void serializeExt(simtg::SerializationStream& stream_)
			throw (simtg::SerializationException);

protected:
	/**
	 Init default values
	 */
	void initDefaultValues();
	/**
	 Init sub models default values
	 */
	void initSubModelsDefaultValues();
	/**
	 Init scheduling
	 */
	void initScheduling();
	/**
	 Serialization method:
	 @param stream_         a serialization stream
	 */
	void serializeMembers(simtg::SerializationStream& stream_)
			throw (simtg::SerializationException);

public:
	/**
	 Default constructor
	 @param name_         the model instance name
	 @param parent_         the model parent
	 @param description_         the model description
	 */
	CSS(Smp::String8 name_ = "", simtg::NamedObject* parent_ = 0,
			Smp::String8 description_ = "");
	/**
	 SMP default Constructor
	 @param name_         the model instance name
	 @param description_         the model description
	 @param parent_         the model parent
	 */
	CSS(Smp::String8 name_, Smp::String8 description_,
			Smp::IComposite* parent_);
	/**
	 Default Destructor
	 */
	virtual ~CSS();
	/**
	 Default step method
	 */
	void step() throw (simtg::Exception);
	/**
	 InitMethod of CSS
	 */
	void init() throw (simtg::Exception);
	/**
	 Publish method of CSS
	 @param publication_         a SMP publishing interface
	 */
	void Publish(Smp::IPublication* publication_)
			throw (Smp::IModel::InvalidModelState);
	/**
	 Load configuration
	 @param logger_         a SMP logging interface
	 */
	void Configure(Smp::Services::ILogger* logger_)
			throw (Smp::IModel::InvalidModelState);
	/**
	 Connect Model to simulation environment.
	 @param sim_         a SMP simulation interface
	 */
	void Connect(Smp::ISimulator* sim_) throw (Smp::IModel::InvalidModelState);
	/**
	 Connect Models with each other.
	 */
	void connectData() throw (Smp::IModel::InvalidModelState);
	/**
	 Connect Model to simulation environment.
	 @param methodId_         a model method identifier
	 @param params_         a method parameters container
	 */
	void callMethod(uint32_t methodId_, BaseType* params_)
			throw (SchedulableObject::BreakPointReached, simtg::Exception);

public:
	CLASS_INFO(CSS,simtg::AsyncModelBase,Add)

public:

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_methodIDEnum_hpp_inside_namespace) ENABLED START*/
	//add user defined includes here
	/*PROTECTED REGION END*/

	/**
	 Enumeration fo method IDs
	 */
	enum methodIDs {

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_methodIDEnum_hpp_enum_extensions) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

	};
	// end enum methodIDs

	/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_hpp_class_extensions) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

};
// end class CSS
}//end Add

/*PROTECTED REGION ID(_7RfoQfONEe-xNYfk1IfsiQ_header_hpp_end_extensions) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/

#endif //end __CSS__HPP

