/*
  ==============================================================================

    SimSimEngine.cpp
    Created: 18 May 2017 11:12:12am
    Author:  Ben

  ==============================================================================
*/

#include "SimSimEngine.h"
#include "InputManager.h"
#include "OutputManager.h"

SimSimEngine::SimSimEngine(ApplicationProperties * appProperties, const String & appVersion) :
	Engine("SimSim",".simsim",appProperties,appVersion)
{
	mainEngine = this;
	addChildControllableContainer(InputManager::getInstance());
	addChildControllableContainer(OutputManager::getInstance());
}

SimSimEngine::~SimSimEngine()
{
	InputManager::deleteInstance();
	OutputManager::deleteInstance();
}

void SimSimEngine::clearInternal()
{
	InputManager::getInstance()->clear();
	OutputManager::getInstance()->clear();
}

var SimSimEngine::getJSONData()
{
	var data = Engine::getJSONData();
	data.getDynamicObject()->setProperty("inputs", InputManager::getInstance()->getJSONData());
	data.getDynamicObject()->setProperty("outputs", OutputManager::getInstance()->getJSONData());

	return data;
}

void SimSimEngine::loadJSONDataInternalEngine(var data, ProgressTask *)
{
	InputManager::getInstance()->loadJSONData(data.getProperty("inputs", var()));
	OutputManager::getInstance()->loadJSONData(data.getProperty("outputs", var()));
	
}
