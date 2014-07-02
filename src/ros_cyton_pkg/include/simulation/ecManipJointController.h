#ifndef ecManipJointController_H_
#define ecManipJointController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipJointController.h
/// @class EcManipulatorJointController
/// @brief Holds a description of a feedback controller for a single joint.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlEnumType.h>
#include <xml/ecXmlBasicType.h>
#include "ecBaseManipulatorJointController.h"
#include <xml/ecXmlVectorType.h>
#include "ecIndJointController.h"
#include <manipulator/ecPositionState.h>
#include <manipulator/ecVelocityState.h>
#include <manipulator/ecGravitationalTorqueTool.h>

class EcManipulatorTorque;
class EcIndividualManipulator;
class EcStatedSystem;

/** Holds a description of feedback controllers for an entire manipulator.
*/
class EC_ACTIN_SIMULATION_DECL EcManipulatorJointController : public EcBaseManipulatorJointController
{
public:
   /// default constructor
   EcManipulatorJointController
      (
      );

   /// destructor
   virtual ~EcManipulatorJointController
      (
      );

   /// copy constructor
   EcManipulatorJointController
      (
      const EcManipulatorJointController& orig
      );

   /// assignment operator
   EcManipulatorJointController& operator=
      (
      const EcManipulatorJointController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorJointController& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
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

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the collection of controllers for each joint
   virtual const EcIndividualJointControllerCollection& jointControllerCollection
      (
      ) const;

   /// sets the collection of controllers for each joint
   virtual void setJointControllerCollection
      (
      const EcIndividualJointControllerCollection& jointControllerCollection
      );

   /// calculate control torques
   virtual void calculateControlTorques
      (
         const EcPositionState& actualPositionState,
         const EcVelocityState& actualVelocityState,
         const EcPositionState& desiredPositionState,
         const EcVelocityState& desiredVelocityState,
         const EcIndividualManipulator& manipulator,
         const EcStatedSystem& statedSystem,
         EcManipulatorTorque& manipulatorTorque
      ) const;

   /// calculate control inputs
   virtual void calculateControlInputs
      (
         const EcPositionState& actualPositionState,
         const EcVelocityState& actualVelocityState,
         const EcPositionState& desiredPositionState,
         const EcVelocityState& desiredVelocityState,
         const EcIndividualManipulator& manipulator,
         const EcStatedSystem& statedSystem,
         EcManipulatorControlInput& manipulatorControlInput
      ) const;

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

   /// get a null object
   static EcManipulatorJointController nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// the joint controllers
   EcIndividualJointControllerCollection m_JointControllerCollection;

   /// non-XML data below

   /// a gravitational torque tool
   mutable EcGravitationalTorqueTool m_GravitationalTorqueTool;

   /// gravitational torques
   mutable EcReArray m_GravitationalTorques;
};

#endif // ecManipJointController_H_
