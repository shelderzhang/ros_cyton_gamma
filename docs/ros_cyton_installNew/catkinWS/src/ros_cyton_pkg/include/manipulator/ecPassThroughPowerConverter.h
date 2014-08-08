#ifndef ecPassThroughPowerConverter_H_
#define ecPassThroughPowerConverter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecPassThroughPowerConverter.h
/// @class EcPassThroughPowerConverter
/// @brief A class describing power conversion that does nothing.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBasePowerConverter.h"

/**
\class EcPassThroughPowerConverter
\brief A class describing power conversion that does nothing.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcPassThroughPowerConverter : public EcBasePowerConverter
{
public:
   /// default constructor
   EcPassThroughPowerConverter
      (
      );

   /// destructor
   virtual ~EcPassThroughPowerConverter
      (
      );

   /// copy constructor
   EcPassThroughPowerConverter
      (
      const EcPassThroughPowerConverter& orig
      );

   /// assignment operator
   EcPassThroughPowerConverter& operator=
      (
      const EcPassThroughPowerConverter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPassThroughPowerConverter& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return the number of state variables for this power converter
   virtual EcU32 numStateVariables
      (
      ) const;

   /// computes and returns the output torque. The torque is generated by this power converter and passed on as an input torque to the mechanical part of the actuator.
   /**
   \param[in] input The control input
   \param[in] actState The actuator state
   */
   virtual EcReal outputTorque
      (
      EcReal input,
      EcActuatorState& actState
      ) const;

   /// computes the time derivatives of the states of this power converter.
   /**
   \param[in] input The control input
   \param[in] actuatorState The actuator state
   \param[out] derivatives Upon return, it will contain the time derivatives of the states.
   */
   virtual void computeStateDerivatives
   (
      EcReal input,
      EcActuatorState& actuatorState,
      EcXmlRealVector& derivatives
   ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// get an zero-information instance
   static EcPassThroughPowerConverter nullObject
      (
      );
protected:
   /// non-XML data
   static const EcU32   m_theStateSize;
};

#endif // ecPassThroughPowerConverter_H_