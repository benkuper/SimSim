/*
  ==============================================================================

    InputManager.cpp
    Created: 18 May 2017 11:14:25am
    Author:  Ben

  ==============================================================================
*/

#include "InputManager.h"
#include "MouseInput.h"
#include "OSCInput.h"
#include "TabletInput.h"

juce_ImplementSingleton(InputManager)

InputManager::InputManager() :
	BaseManager("Inputs")
{
	factory.defs.add(InputDef::createDef("", "Mouse", MouseInput::create));
	factory.defs.add(InputDef::createDef("", "Tablet", TabletInput::create));
	factory.defs.add(InputDef::createDef("", "OSC", OSCInput::create));

	managerFactory = &factory;
}

InputManager::~InputManager()
{
}
