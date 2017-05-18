/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : 
	public Component,
	public ApplicationCommandTarget,
	public MenuBarModel,
	public Engine::EngineListener
{
public:

	ApplicationProperties * appProperties;
	ApplicationCommandManager commandManager;
	ScopedPointer<LookAndFeelOO> lookAndFeelOO;
	TooltipWindow tooltipWindow; // to add tooltips to an application, you
								 // just need to create one of these and leave it
								 // there to do its work..


    //==============================================================================
	MainContentComponent(ApplicationProperties * appProperties);
	~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;

	// inherited from MenuBarModel , ApplicationCommandTarget
	ApplicationCommandTarget* getNextCommandTarget() override { return findFirstTargetParentComponent(); }
	void getAllCommands(Array<CommandID>& commands) override;
	virtual void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
	virtual bool perform(const InvocationInfo& info) override;
	StringArray getMenuBarNames() override;
	virtual PopupMenu getMenuForIndex(int topLevelMenuIndex, const String& menuName) override;
	void menuItemSelected(int /*menuItemID*/, int /*topLevelMenuIndex*/) override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
