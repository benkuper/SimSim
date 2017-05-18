/*
  ==============================================================================

    AugmentaOutput.h
    Created: 18 May 2017 11:13:28am
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "Output.h"

class AugmentaOutput :
	public Output
{
public:
	AugmentaOutput();
	~AugmentaOutput();

	String getTypeString() const override { return "Augmenta"; }
	static AugmentaOutput * create(var) { return new AugmentaOutput(); }
};
