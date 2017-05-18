/*
  ==============================================================================

    InputManager.h
    Created: 18 May 2017 11:14:25am
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "Input.h"

class InputManager :
	public BaseManager<Input>
{
public:
	juce_DeclareSingleton(InputManager, true)
	InputManager();
	~InputManager();

	Factory<Input> factory;
	typedef Factory<Input>::Definition InputDef;
};