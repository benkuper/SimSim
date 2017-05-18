/*
  ==============================================================================

    MouseInput.h
    Created: 18 May 2017 11:13:45am
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "Input.h"

class MouseInput :
	public Input
{
public:
	MouseInput();
	~MouseInput();

	String getTypeString() const override { return "Mouse"; }
	static MouseInput * create(var) { return new MouseInput(); }
};