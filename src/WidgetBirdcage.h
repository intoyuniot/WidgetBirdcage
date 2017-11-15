#ifndef WIDGET_BIRDCAGE_H_
#define WIDGET_BIRDCAGE_H_

#include "application.h"

class WidgetBirdcage
{
    public:
        WidgetBirdcage(uint8_t ucItem = 0);
        ~WidgetBirdcage();
        void begin(void (*UserCallBack)(void) = NULL);
        void displayBirdStatus(uint8_t ucVal);
        void displayTemperature(char fTemperature);
        void displayHumidity(uint8_t fHumidity);
        void displayLightIntensity(float fLightIntensity);
        void displayPM25(int iPM25);

    private:
        char pDataHumidityTopic[64];
        char pDataTemperatureTopic[64];
        char pDataLightIntensityTopic[64];
        char pDataPM25Topic[64];
        char pDataStatusTopic[64];
        uint8_t _Item=0;
};

#endif
