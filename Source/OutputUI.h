/*
  ==============================================================================

    OutputUI.h
    Created: 18 May 2017 11:34:37am
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "Output.h"

class OutputUI :
	public BaseItemUI<Output>
{
public:
	OutputUI(Output * i);
	~OutputUI();

};