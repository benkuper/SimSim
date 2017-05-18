/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

#include "SimSimEngine.h"

//==============================================================================
class SimSimApplication : public JUCEApplication
{
public:
	//==============================================================================
	SimSimApplication() {}

	ScopedPointer<ApplicationProperties> appProperties;
	ScopedPointer<SimSimEngine> engine;

	const String getApplicationName() override { return ProjectInfo::projectName; }
	const String getApplicationVersion() override { return ProjectInfo::versionString; }
	bool moreThanOneInstanceAllowed() override { return true; }

	//==============================================================================
	void initialise(const String& commandLine) override
	{
		// This method is where you should put your application's initialisation code..

		PropertiesFile::Options options;
		options.applicationName = "SimSim";
		options.filenameSuffix = "settings";
		options.osxLibrarySubFolder = "Preferences";

		appProperties = new ApplicationProperties();
		appProperties->setStorageParameters(options);

		engine = new SimSimEngine(appProperties, getApplicationVersion());

		mainWindow = new MainWindow(getApplicationName());
		engine->parseCommandline(commandLine);

		if (!engine->getFile().existsAsFile()) {
			engine->createNewGraph();
			engine->setChangedFlag(false);
		}

		AppUpdater::getInstance()->checkForUpdates();
	}

	void shutdown() override
	{
		// Add your application's shutdown code here..
		mainWindow = nullptr; // (deletes our window)
		AppUpdater::deleteInstance();
	}

	//==============================================================================
	void systemRequestedQuit() override
	{
		// This is called when the app is being asked to quit: you can ignore this
		// request and let the app carry on running, or call quit() to allow the app to close.
		quit();
	}

	void anotherInstanceStarted(const String& commandLine) override
	{
		// When another instance of the app is launched while this one is running,
		// this method is invoked, and the commandLine parameter tells you what
		// the other instance's command-line arguments were.
	}

	//==============================================================================
	/*
		This class implements the desktop window that contains an instance of
		our MainContentComponent class.
	*/
	class MainWindow : public DocumentWindow
	{
	public:
		MainContentComponent * mainComponent;

		MainWindow(String name) : DocumentWindow(name,
			Desktop::getInstance().getDefaultLookAndFeel()
			.findColour(ResizableWindow::backgroundColourId),
			DocumentWindow::allButtons)
		{
			setUsingNativeTitleBar(true);
			mainComponent = new MainContentComponent(static_cast<SimSimApplication *>(JUCEApplication::getInstance())->appProperties);
			setContentOwned(mainComponent, true);
			setResizable(true, true);
			setOpaque(true);

			ApplicationProperties * p = static_cast<SimSimApplication *>(JUCEApplication::getInstance())->appProperties;
			int tx = p->getCommonSettings(true)->getIntValue("windowX");
			int ty = p->getCommonSettings(true)->getIntValue("windowY");
			int tw = p->getCommonSettings(true)->getIntValue("windowWidth");
			int th = p->getCommonSettings(true)->getIntValue("windowHeight");
			bool fs = p->getCommonSettings(true)->getBoolValue("fullscreen", true);

			setBounds(jmax<int>(tx, 20), jmax<int>(ty, 20), jmax<int>(tw, 100), jmax<int>(th, 100));
			setFullScreen(fs);

#if !JUCE_MAC
			setMenuBar(mainComponent);
#endif

			setVisible(true);

#if JUCE_OPENGL && JUCE_WINDOWS
			openGLContext.setComponentPaintingEnabled(true);
			openGLContext.attachTo(*this);
#endif
		}

		void closeButtonPressed() override
		{

			var boundsVar = var(new DynamicObject());
			juce::Rectangle<int> r = getScreenBounds();

			ApplicationProperties * p = static_cast<SimSimApplication *>(JUCEApplication::getInstance())->appProperties;
			p->getCommonSettings(true)->setValue("windowX", r.getPosition().x);
			p->getCommonSettings(true)->setValue("windowY", r.getPosition().y);
			p->getCommonSettings(true)->setValue("windowWidth", r.getWidth());
			p->getCommonSettings(true)->setValue("windowHeight", r.getHeight());
			p->getCommonSettings(true)->setValue("fullscreen", isFullScreen());
			p->getCommonSettings(true)->saveIfNeeded();



#if JUCE_OPENGL && JUCE_WINDOWS
			openGLContext.detach();
#endif

			JUCEApplication::getInstance()->systemRequestedQuit();
		}

		/* Note: Be careful if you override any DocumentWindow methods - the base
		   class uses a lot of them, so by overriding you might break its functionality.
		   It's best to do all your work in your content component instead, but if
		   you really have to override any DocumentWindow methods, make sure your
		   subclass also calls the superclass's method.
		*/

	private:
#if JUCE_OPENGL
		OpenGLContext openGLContext;
#endif

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
	};

private:
	ScopedPointer<MainWindow> mainWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION(SimSimApplication)
