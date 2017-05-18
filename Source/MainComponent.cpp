/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "SimSimEngine.h"
#include "InputManagerUI.h"
#include "OutputManagerUI.h"
#include "InputSimulationView.h"

//==============================================================================
MainContentComponent::MainContentComponent(ApplicationProperties * _appProperties) :
	appProperties(_appProperties)
{
    setSize (1280,800);

	Engine::mainEngine->addEngineListener(this);

	lookAndFeelOO = new LookAndFeelOO();
	LookAndFeel::setDefaultLookAndFeel(lookAndFeelOO);

	ShapeShifterFactory::getInstance()->defs.add(new ShapeShifterDefinition("Inputs", &InputManagerUI::create));
	ShapeShifterFactory::getInstance()->defs.add(new ShapeShifterDefinition("Outputs", &OutputManagerUI::create));
	ShapeShifterFactory::getInstance()->defs.add(new ShapeShifterDefinition("Simulation View", &InputSimulationView::create));

	ShapeShifterManager::getInstance()->setLayoutInformations("layout", "SimSim/layouts");
	ShapeShifterManager::getInstance()->loadLastSessionLayoutFile();


	commandManager.registerAllCommandsForTarget(this);
	commandManager.setFirstCommandTarget(this);

	commandManager.getKeyMappings()->resetToDefaultMappings();
	addKeyListener(commandManager.getKeyMappings());

#if JUCE_MAC
	setMacMainMenu(this, nullptr, "");
#else
	//setMenu (this); //done in Main.cpp as it's a method of DocumentWindow
#endif	

	addAndMakeVisible(&ShapeShifterManager::getInstance()->mainContainer);
}

MainContentComponent::~MainContentComponent()
{
#if JUCE_MAC
	setMacMainMenu(nullptr, nullptr, "");
#endif

	if (Engine::mainEngine != nullptr) Engine::mainEngine->removeEngineListener(this);
	ShapeShifterManager::deleteInstance();
}

void MainContentComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(BG_COLOR.darker());
}

void MainContentComponent::resized()
{
	Rectangle<int> r = getLocalBounds();
	ShapeShifterManager::getInstance()->mainContainer.setBounds(r);
}
