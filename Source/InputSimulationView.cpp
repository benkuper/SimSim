/*
  ==============================================================================

    InputSimulationView.cpp
    Created: 18 May 2017 12:16:45pm
    Author:  Ben

  ==============================================================================
*/

#include "InputSimulationView.h"

InputSimulationView::InputSimulationView(const String & contentName) :
	ShapeShifterContentComponent(contentName), 
	currentInput(nullptr)
{
	contentIsFlexible = true;
}

InputSimulationView::~InputSimulationView()
{
	setCurrentInput(nullptr);
}

void InputSimulationView::setCurrentInput(Input * i)
{
	if (currentInput != nullptr)
	{
		currentInput->removeInspectableListener(this);
		removeChildComponent(pointManagerView);
		pointManagerView = nullptr;
	}

	currentInput = i;

	if (currentInput != nullptr)
	{
		currentInput->addInspectableListener(this);
		pointManagerView = new PointDataManagerView(&currentInput->pointManager);
		addAndMakeVisible(pointManagerView);
	}

	resized();
}

void InputSimulationView::paint(Graphics & g)
{
	//paint background, grid, here
	g.fillCheckerBoard(getLocalBounds(), 32, 32, BG_COLOR, BG_COLOR.brighter(.02f));
}

void InputSimulationView::resized()
{
	if (currentInput == nullptr) return;
	if (pointManagerView != nullptr) pointManagerView->setBounds(getLocalBounds());
	//resize and replace all elements here
}

void InputSimulationView::inspectablesSelectionChanged()
{
	if (InspectableSelectionManager::getInstance()->currentInspectables.size() == 0) return;
	Input * i = static_cast<Input *>(InspectableSelectionManager::getInstance()->currentInspectables[0]);
	if (i == nullptr) return;
	setCurrentInput(i);
}

void InputSimulationView::inspectableDestroyed(Inspectable *)
{
	setCurrentInput(nullptr);
}
