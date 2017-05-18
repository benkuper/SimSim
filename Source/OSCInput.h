/*
  ==============================================================================

    OSCInput.h
    Created: 18 May 2017 11:13:37am
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "Input.h"

class OSCInput :
	public Input
{
public:
	OSCInput();
	~OSCInput();

	String getTypeString() const override { return "OSC"; }
	static OSCInput * create(var) { return new OSCInput(); }
};