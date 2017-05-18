/*
  ==============================================================================

    InputManagerUI.h
    Created: 18 May 2017 11:34:15am
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "InputManager.h"
#include "InputUI.h"

class InputManagerUI :
	public BaseManagerShapeShifterUI<InputManager, Input, InputUI>
{
public:
	InputManagerUI(const String &contentName, InputManager * manager);
	~InputManagerUI();


	static InputManagerUI * create(const String &contentName) { return new InputManagerUI(contentName, InputManager::getInstance()); }
};