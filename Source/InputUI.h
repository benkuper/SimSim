/*
  ==============================================================================

    InputUI.h
    Created: 18 May 2017 11:34:23am
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "Input.h"

class InputUI :
	public BaseItemUI<Input>
{
public:
	InputUI(Input * i);	
	~InputUI();

};