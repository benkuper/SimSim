/*
  ==============================================================================

	Input.h
	Created: 18 May 2017 11:14:28am
	Author:  Ben

  ==============================================================================
*/

#pragma once

#include "PointData.h"

class Input :
	public BaseItem
{
public:
	
	Input(const String &name = "Input");
	~Input();

	BaseManager<PointData> pointManager;
};