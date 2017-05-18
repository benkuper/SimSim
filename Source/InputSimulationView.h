/*
  ==============================================================================

    InputSimulationView.h
    Created: 18 May 2017 12:16:45pm
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "InputManager.h"


class PointDataView :
	public BaseItemMinimalUI<PointData>
{
public:
	PointDataView(PointData * item) : BaseItemMinimalUI(item) {}
	~PointDataView() {}

};

class PointDataManagerView :
	public BaseManagerUI<BaseManager<PointData>,PointData,PointDataView>
{
public:
	PointDataManagerView(BaseManager<PointData> * manager) : BaseManagerUI(manager->niceName, manager, false) {}
};

class InputSimulationView :
	public ShapeShifterContentComponent,
	public InspectableSelectionManager::Listener,
	public Inspectable::InspectableListener
{
public:
	InputSimulationView(const String &contentName);
	~InputSimulationView();

	Input * currentInput;
	ScopedPointer<PointDataManagerView> pointManagerView;

	void setCurrentInput(Input *);

	void paint(Graphics &g) override;
	void resized() override;

	void inspectablesSelectionChanged() override;
	void inspectableDestroyed(Inspectable *) override;


	static InputSimulationView * create(const String &contentName) { return new InputSimulationView(contentName); }
};
