/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Lamp.h"

//==============================================================================
/**
*/
class TappingTestAudioProcessorEditor  : public AudioProcessorEditor,
                                         public Button::Listener,
                                        // public HighResolutionTimer
	                                     public Timer
{
public:
    TappingTestAudioProcessorEditor (TappingTestAudioProcessor&);
    ~TappingTestAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	//=======================================================
	void buttonClicked(Button* _clockRateButton) override;
	void timerCallback() override;
	bool pressedOnce = 0;
	
	float refactorTimeValue=1000;
    float refactorPercentage= refactorTimeValue+refactorTimeValue*0.3;
	float average=0.0f;
	float cycleCounter=0.0f;
	int readyForSwitching = 0;
	float clickTime;
	float previousClickTime = refactorTimeValue;
	float thresholdValue = refactorTimeValue;
    int platform=0; //1 au,    0 vst3,    2 win-vst3
    float mClockrateValue=0.3;
    float mBPMValue;
private:
    Lamp    lamp;
    TextButton clockRateButton;
    Label clockRateLabel;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TappingTestAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TappingTestAudioProcessorEditor)
};
