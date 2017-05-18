/*
  ==============================================================================

    OSCOutput.h
    Created: 18 May 2017 11:13:24am
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "Output.h"

class OSCOutput :
	public Output
{
public:
	OSCOutput();
	~OSCOutput();

	String getTypeString() const override { return "OSC"; }
	static OSCOutput * create(var) { return new OSCOutput(); }
};
