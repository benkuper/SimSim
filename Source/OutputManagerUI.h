/*
  ==============================================================================

    OutputManagerUI.h
    Created: 18 May 2017 11:34:34am
    Author:  Ben

  ==============================================================================
*/

#pragma once


#include "OutputManager.h"
#include "OutputUI.h"

class OutputManagerUI :
	public BaseManagerShapeShifterUI<OutputManager, Output, OutputUI>
{
public:
	OutputManagerUI(const String &contentName, OutputManager * manager);
	~OutputManagerUI();


	static OutputManagerUI * create(const String &contentName) { return new OutputManagerUI(contentName, OutputManager::getInstance()); }
};