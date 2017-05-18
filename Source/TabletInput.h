/*
  ==============================================================================

    TabletInput.h
    Created: 18 May 2017 11:13:41am
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "Input.h"

class TabletInput :
	public Input
{
public:
	TabletInput();
	~TabletInput();
	
	String getTypeString() const override { return "Tablet"; }
	static TabletInput * create(var) { return new TabletInput(); }
};