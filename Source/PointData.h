/*
  ==============================================================================

    PointData.h
    Created: 18 May 2017 11:26:53am
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class PointData :
	public BaseItem,
	public Point<float>
{
public:
	PointData(float x = 0, float y = 0);
	~PointData();
	
	//add extra data if needed (velocity, size..)

};