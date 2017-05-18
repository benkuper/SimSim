/*
  ==============================================================================

    OutputManager.h
    Created: 18 May 2017 12:05:01pm
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "Output.h"

class OutputManager :
	public BaseManager<Output>
{
public:
	juce_DeclareSingleton(OutputManager, true)
	OutputManager();
	~OutputManager();

	Factory<Output> factory;
	typedef Factory<Output>::Definition OutputDef;
};