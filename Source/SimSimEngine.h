/*
  ==============================================================================

    SimSimEngine.h
    Created: 18 May 2017 11:12:12am
    Author:  Ben

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"



class SimSimEngine :
	public Engine
{
public:
	SimSimEngine(ApplicationProperties * appProperties, const String &appVersion);
	~SimSimEngine();

	void clearInternal() override;

	var getJSONData() override;
	void loadJSONDataInternalEngine(var data, ProgressTask * loadingTask) override;

};