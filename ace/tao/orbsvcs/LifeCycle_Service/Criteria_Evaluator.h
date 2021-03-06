// Criteria_Evaluator.h,v 1.5 1999/06/30 08:19:35 nanbor Exp

// ============================================================================
//
// = FILENAME
//    Criteria_Evaluaotr.h
//
// = DESCRIPTION
//    An Evaluator for the CosLifeCycle Criteria
//
// = AUTHOR
//    Michael Kircher (mk1@cs.wustl.edu)
//
// ============================================================================


#include "orbsvcs/CosLifeCycleC.h"
#include "orbsvcs/LifeCycleServiceC.h"

#ifndef CRITERIA_EVALUATOR_H_H
#define CRITERIA_EVALUATOR_H_H

class Criteria_Evaluator// : public LifeCycleService::Criteria_Evaluator
{
  // = TITLE
  //
public:
  Criteria_Evaluator (const CosLifeCycle::Criteria &criteria);
  ~Criteria_Evaluator (void);

  LifeCycleService::Criteria_Evaluator::SeqNamedValuePair * getInitialization (CORBA::Environment &);

  char * getFilter (CORBA::Environment &);

  LifeCycleService::Criteria_Evaluator::SeqNamedValuePair * getLogicalLocation (CORBA::Environment &)
    {
      return 0;
    }

  char * getPreferences (CORBA::Environment &)
    {
      return 0;
    }

private:
  CORBA::Any *getCriteriaMember (const char *member_name);

  const CosLifeCycle::Criteria &criteria_;
};

#endif /* CRITERIA_EVALUATOR_H */






