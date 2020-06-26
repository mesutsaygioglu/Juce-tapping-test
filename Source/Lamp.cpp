

#include "../JuceLibraryCode/JuceHeader.h"
#include "Lamp.h"

//==============================================================================
Lamp::Lamp()
{
	setSize(20,20);
	counter = 0;
}

Lamp::~Lamp()
{

}

void Lamp::paint (Graphics& g)
{

	
	Rectangle<int> lampCropArea(2, 2, 70, 70);
	lampImage = lampImage.getClippedImage(lampCropArea);
	Rectangle<float> lampArea(0, 0, getWidth(), getHeight());
	g.drawImage(lampImage, lampArea);

	

}

int Lamp::blink (float clockRate)// BPM
{
	

	if (counter == 0)
	{
		stopTimer();
		float value = 36-(clockRate * 36);//jmap(clockRate, 0.0f, 1.0f, 35.0f, 3.5f);
		if (value <= 3)
		{
			stopTimer();
			value = 2;
		}
		
		startTimer(value);
		
		gBPMValue = 60000.0f / (value * 28.0f);
		return gBPMValue;
	}

    return -1;
}


void Lamp::timerCallback()
{
	
	    lampImage = ImageCache::getFromMemory(returnImageName(counter), returnImageSize(counter));
	++counter;
	if (counter == 28)
	{
	    counter=0;
	}
    repaint(); // if i remove this one it wont blink
}

int Lamp::returnImageSize(int i)
{
	int imagename[28];
	imagename[0] = BinaryData::Image_0_pngSize;
	imagename[1] = BinaryData::Image_1_pngSize;
	imagename[2] = BinaryData::Image_2_pngSize;
	imagename[3] = BinaryData::Image_3_pngSize;
	imagename[4] = BinaryData::Image_4_pngSize;
	imagename[5] = BinaryData::Image_5_pngSize;
	imagename[6] = BinaryData::Image_6_pngSize;
	imagename[7] = BinaryData::Image_7_pngSize;
	imagename[8] = BinaryData::Image_8_pngSize;
	imagename[9] = BinaryData::Image_9_pngSize;
	imagename[10] = BinaryData::Image_10_pngSize;
	imagename[11] = BinaryData::Image_11_pngSize;
	imagename[12] = BinaryData::Image_12_pngSize;
	imagename[13] = BinaryData::Image_13_pngSize;
	imagename[14] = BinaryData::Image_13_pngSize;
	imagename[15] = BinaryData::Image_12_pngSize;
	imagename[16] = BinaryData::Image_11_pngSize;
	imagename[17] = BinaryData::Image_10_pngSize;
	imagename[18] = BinaryData::Image_9_pngSize;
	imagename[19] = BinaryData::Image_8_pngSize;
	imagename[20] = BinaryData::Image_7_pngSize;
	imagename[21] = BinaryData::Image_6_pngSize;
	imagename[22] = BinaryData::Image_5_pngSize;
	imagename[23] = BinaryData::Image_4_pngSize;
	imagename[24] = BinaryData::Image_3_pngSize;
	imagename[25] = BinaryData::Image_2_pngSize;
	imagename[26] = BinaryData::Image_1_pngSize;
	imagename[27] = BinaryData::Image_0_pngSize;
	return imagename[i];
}


const char* Lamp::returnImageName(int i)
{
	switch (i)
	{
	case 0:
		return BinaryData::Image_0_png;
		break;
	case 1:
		return BinaryData::Image_1_png;
		break;
	case 2:
		return BinaryData::Image_2_png;
		break;
	case 3:
		return BinaryData::Image_3_png;
		break;
	case 4:
		return BinaryData::Image_4_png;
		break;
	case 5:
		return BinaryData::Image_5_png;
		break;
	case 6:
		return BinaryData::Image_6_png;
		break;
	case 7:
		return BinaryData::Image_7_png;
		break;
	case 8:
		return BinaryData::Image_8_png;
		break;
	case 9:
		return BinaryData::Image_9_png;
		break;
	case 10:
		return BinaryData::Image_10_png;
		break;
	case 11:
		return BinaryData::Image_11_png;
		break;
	case 12:
		return BinaryData::Image_12_png;
		break;
	case 13:
		return BinaryData::Image_13_png;
		break;
	case 14:
		return BinaryData::Image_13_png;
		break;
	case 15:
		return BinaryData::Image_12_png;
		break;
	case 16:
		return BinaryData::Image_11_png;
		break;
	case 17:
		return BinaryData::Image_10_png;
		break;
	case 18:
		return BinaryData::Image_9_png;
		break;
	case 19:
		return BinaryData::Image_8_png;
		break;
	case 20:
		return BinaryData::Image_7_png;
		break;
	case 21:
		return BinaryData::Image_6_png;
		break;
	case 22:
		return BinaryData::Image_5_png;
		break;
	case 23:
		return BinaryData::Image_4_png;
		break;
	case 24:
		return BinaryData::Image_3_png;
		break;
	case 25:
		return BinaryData::Image_2_png;
		break;
	case 26:
		return BinaryData::Image_1_png;
		break;
	case 27:
		return BinaryData::Image_0_png;
		break;
    default:
            return BinaryData::Image_13_png;
	 }
}

void Lamp::resized()
{
	setBounds(getBounds());
	
}
