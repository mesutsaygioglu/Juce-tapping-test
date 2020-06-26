/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TappingTestAudioProcessorEditor::TappingTestAudioProcessorEditor (TappingTestAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
  	addAndMakeVisible(lamp);
	clockRateButton.addListener(this);
	addAndMakeVisible(clockRateButton);
    addAndMakeVisible(clockRateLabel);
    setSize (300, 300);
}

TappingTestAudioProcessorEditor::~TappingTestAudioProcessorEditor()
{
}

//==============================================================================
void TappingTestAudioProcessorEditor::paint (Graphics& g)
{
     mBPMValue= lamp.blink(mClockrateValue);
    if(mBPMValue>0)
    clockRateLabel.setText(String(mBPMValue+1),NotificationType::sendNotification);
    
}

void TappingTestAudioProcessorEditor::resized()
{	
    
    Rectangle<int> lampFrame(100,100);
	juce::Point<int> lampcentre(150,150);
	lampFrame.setCentre(lampcentre);
	lamp.setBounds(lampFrame);
	repaint();
	clockRateButton.setBounds(lampFrame);
	clockRateButton.setAlpha(0.0);
    
    
    Rectangle<int> clockRateLabelFrame(50,200);
    juce::Point<int> clockRateLabelcentre(150,275);
    clockRateLabelFrame.setCentre(clockRateLabelcentre);
    clockRateLabel.setBounds(clockRateLabelFrame);

}

void TappingTestAudioProcessorEditor::buttonClicked(Button* _clockRateButton)
{
    MessageManagerLock lock;
	if (_clockRateButton == &clockRateButton && !pressedOnce)
	{
		clickTime = 0;
        pressedOnce = 1;
		startTimer(1);
		
		DBG("pressed once");

	}
	else if (_clockRateButton == &clockRateButton && pressedOnce )
	{

		stopTimer();
		
        if(platform ==0)
		average = average + clickTime*1.20f;
        DBG("clicktime value " << clickTime*1.2f);
		cycleCounter++;

		DBG("average   " << average);
		DBG("cycleCounter   " << cycleCounter);
		DBG("pressed twice");

		previousClickTime = clickTime;
		clickTime = 0;

		startTimer(1);
	}



}





void TappingTestAudioProcessorEditor::timerCallback()
{
	
	++clickTime;
	if (clickTime < refactorPercentage)
	{
		if (clickTime > (previousClickTime + previousClickTime * 0.3))
		{
		
			readyForSwitching = 1;
            stopTimer();
	    }


		if (readyForSwitching && cycleCounter>0 /* && lamp.counter>2 */)
		{

			average = (average / cycleCounter);



			if (average > refactorTimeValue)
				average = refactorTimeValue;
            DBG("value has been sent  .::::" << average);
              average = 1-(average/1000.0f);
            //average =jmap(average, .0f, refactorTimeValue, 1.0f, 0.0f);
            
            if(platform==0)
            {
			//in vst3 to pull knob to 5 at 120bpm.
              //average= average-0.095;
              if(average<=0.03f)
              average=0;
		      mClockrateValue=average;// for mac vst3 this is fine.
            }
            
			if (platform == 2)
			{
				//in vst3 to pull knob to 5 at 120bpm.
				//average = average - 0.05;
				if (average <= 0.05)
					average = 0;
				mClockrateValue=average;// for mac vst3 this is fine.
			}
            
            if(platform==1)
            {
                //in au to pull knob to 5 at 120bpm.
                average= average-0.02;// it was 0.8 
                if(average<=0.03)
                    average=0;
               mClockrateValue=average;// for mac au this is fine.
            }

			DBG("value has been sent  .::::" << average);


			average = 0;
			cycleCounter = 0;
			pressedOnce = 0;
			previousClickTime = refactorTimeValue;
			readyForSwitching = 0;
			stopTimer();
		}



	}
	else if (clickTime >= refactorPercentage )
	{
		DBG("time out");
		clickTime = 0;
		cycleCounter = 0;
		average = 0;
		pressedOnce = 0;
	

		stopTimer();
	}

}
