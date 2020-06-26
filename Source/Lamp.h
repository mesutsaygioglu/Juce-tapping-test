

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Lamp : public Component,
	         public Timer
{
public:
	Lamp();
	~Lamp();

	void paint(Graphics&) override;
	void resized() override;
	int blink( float clockRate);
	Image lampImage;
	void timerCallback() override;
	int counter;
	int gBPMValue;
	
	int imageNumber=0 ;
	int returnImageSize(int i);
	const char* returnImageName(int i);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Lamp)
};
