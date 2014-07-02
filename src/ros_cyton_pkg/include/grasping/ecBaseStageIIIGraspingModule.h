#ifndef ecBaseStageIIIGraspingModule_H_
#define ecBaseStageIIIGraspingModule_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseStageIIIGraspingModule.h
/// @class EcBaseStageIIIGraspingModule
/// @brief This class is a base class for stage I grasping
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecGraspStatus.h"
#include <control/ecIndVelContDesc.h>
#include <forceControl/ecForceControlDescription.h>
#include <xml/ecBaseExpTreeElement.h>

// forward declarations
class EcBaseStageIIGraspingModule;
class EcGraspInitParams;
class EcGraspUpdateParams;

/** This class is a base class for stage I grasping
*/
class EC_ACTIN_GRASPING_DECL EcBaseStageIIIGraspingModule : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseStageIIIGraspingModule
      (
      );

   /// destructor
   virtual ~EcBaseStageIIIGraspingModule
      (
      );

   /// copy constructor
   EcBaseStageIIIGraspingModule
      (
      const EcBaseStageIIIGraspingModule& orig
      );

   /// assignment operator
   EcBaseStageIIIGraspingModule& operator=
      (
      const EcBaseStageIIIGraspingModule& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseStageIIIGraspingModule& orig
      ) const;

   /// get the pointer to the Stage II module
   virtual const EcBaseStageIIGraspingModule* precursorPointer
      (
      ) const;

   /// set the pointer to the Stage II module
   virtual void setPrecursorPointer
      (
      EcBaseStageIIGraspingModule* precursorPointer
      );

   /// register XML member variables
   void registerComponents
      (
      );

   /// initialize the grasp calculation for the specified object and manipulator
   virtual EcBoolean calculateGrasp
      (
      const EcGraspInitParams& params
      ) = 0;

   /// Append control descriptions required for the calculated grasp to a vector
   virtual void appendControlDescriptions
      (
      EcVelocityControlDescriptionVector& controlDescriptions,
      const EcIndividualVelocityControlDescription& prototype = EcIndividualVelocityControlDescription()
      ) = 0;

   /// Append force control descriptions required for the calculated grasp to a vector
   virtual void appendForceControlDescriptions
      (
      EcForceControlDescriptionVector& controlDescriptions,
      const EcForceControlDescription& prototype = EcForceControlDescription()
      ) = 0;

   /// Return the ative control description index to be used for the grasp
   virtual EcU32 activeControlDescription
      (
      ) = 0;

   /// Return the ative force control description index to be used for the grasp
   virtual EcU32 activeForceControlDescription
      (
      ) = 0;

   /// Return the grasp status
   virtual EcGraspStatus::Enum update
      (
      EcReal time,
      const EcGraspUpdateParams& params
      ) = 0;

   /// return the placements for the end effectors used in the grasp motion
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPositions
      (
      ) = 0;

   /// Return the desired manipulator force required for the grasp
   virtual const EcManipulatorSensorForce& graspForce
      (
      ) = 0;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      ) const = 0;

protected:
   /// A pointer to the corresponding Stage II module
   EcBaseStageIIGraspingModule* m_pPrecursorPointer;
};

#endif // ecBaseStageIIIGraspingModule_H_
