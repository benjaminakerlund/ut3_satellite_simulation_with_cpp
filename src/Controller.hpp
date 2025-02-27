/*
 * File Controller.hpp
 *
 * Project Add
 *
 *
 * Copyright (c) Astrium 2011. All rights reserved.
 *
 */

#ifndef __CONTROLLER__HPP
#define __CONTROLLER__HPP

#include <simtg/model/ModelBase.hpp>
#include <Add/Add.hpp>
#include <simtg/kernel/Data.hpp>

/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_header_hpp_include) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

namespace Add {

/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_hpp_inside_namespace) ENABLED START*/
//add user defined includes here
/*PROTECTED REGION END*/

class Controller: public simtg::ModelBase {

public:
	/**
	 [INPUT] 
	 */
	simtg::Float _I_Y_plus;
	/**
	 [INPUT] 
	 */
	simtg::Float _I_Y_minus;
	/**
	 [INPUT] 
	 */
	simtg::Float _I_Z_plus;
	/**
	 [INPUT] 
	 */
	simtg::Float _I_Z_minus;
	/**
	 [OUTPUT]  [3]
	 */
	simtg::Float _u_Sun_CSS;
	/**
	 [OUTPUT] 
	 */
	simtg::Float _y_angle;
	/**
	 [OUTPUT] 
	 */
	simtg::Float _z_angle;

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
	Controller(Smp::String8 name_ = "", simtg::NamedObject* parent_ = 0,
			Smp::String8 description_ = "");
	/**
	 SMP default Constructor
	 @param name_         the model instance name
	 @param description_         the model description
	 @param parent_         the model parent
	 */
	Controller(Smp::String8 name_, Smp::String8 description_,
			Smp::IComposite* parent_);
	/**
	 Default Destructor
	 */
	virtual ~Controller();
	/**
	 Default step method
	 */
	void step() throw (simtg::Exception);
	/**
	 InitMethod of Controller
	 */
	void init() throw (simtg::Exception);
	/**
	 Publish method of Controller
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
	CLASS_INFO(Controller,simtg::ModelBase,Add)

public:

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_methodIDEnum_hpp_inside_namespace) ENABLED START*/
	//add user defined includes here
	float K_p;
	float K_d;
	float K_i;

	float Y_error_prior;
	float Z_error_prior;

	float Y_integral_prior;
	float Z_integral_prior;

	std::vector<float> Y_history;
	std::vector<float> Z_history;
	/*PROTECTED REGION END*/

	/**
	 Enumeration fo method IDs
	 */
	enum methodIDs {

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_methodIDEnum_hpp_enum_extensions) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

	};
	// end enum methodIDs

	/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_hpp_class_extensions) ENABLED START*/
	//add user defined code here
	/*PROTECTED REGION END*/

};
// end class Controller
}//end Add

/*PROTECTED REGION ID(_GjTOkfBrEe-2qtLpG8DnDw_header_hpp_end_extensions) ENABLED START*/
//add user defined code here
/*PROTECTED REGION END*/

#endif //end __CONTROLLER.HPP__H  

