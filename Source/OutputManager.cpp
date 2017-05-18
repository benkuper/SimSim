/*
  ==============================================================================

    OutputManager.cpp
    Created: 18 May 2017 12:05:01pm
    Author:  Ben

  ==============================================================================
*/

#include "OutputManager.h"
#include "OSCOutput.h"
#include "AugmentaOutput.h"

juce_ImplementSingleton(OutputManager)

OutputManager::OutputManager() :
	BaseManager("Outputs")
{
	factory.defs.add(OutputDef::createDef("", "OSC", OSCOutput::create));
	factory.defs.add(OutputDef::createDef("", "Augmenta", AugmentaOutput::create));
	
	managerFactory = &factory;
}

OutputManager::~OutputManager()
{
}

