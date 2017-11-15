#include "WidgetBirdcage.h"


WidgetBirdcage::WidgetBirdcage(uint8_t ucItem)
{
    _Item = ucItem;
    memset(pDataStatusTopic,0,sizeof(pDataStatusTopic));
    memset(pDataHumidityTopic,0,sizeof(pDataHumidityTopic));
    memset(pDataTemperatureTopic,0,sizeof(pDataTemperatureTopic));
    memset(pDataLightIntensityTopic,0,sizeof(pDataLightIntensityTopic));
    memset(pDataPM25Topic,0,sizeof(pDataPM25Topic));

    sprintf(pDataStatusTopic,"channel/birdcage_%d/data/status",_Item);
    sprintf(pDataHumidityTopic,"channel/birdcage_%d/data/humidity",_Item);
    sprintf(pDataTemperatureTopic,"channel/birdcage_%d/data/temperature",_Item);
    sprintf(pDataLightIntensityTopic,"channel/birdcage_%d/data/illumination",_Item);
    sprintf(pDataPM25Topic,"channel/birdcage_%d/data/airdustconcentration",_Item);
}

WidgetBirdcage::~WidgetBirdcage()
{

}

void WidgetBirdcage::begin(void (*UserCallBack)(void))
{

}

void WidgetBirdcage::displayTemperature(char fTemperature)
{
    IntoRobot.publish(pDataTemperatureTopic,fTemperature);
}

void WidgetBirdcage::displayHumidity(uint8_t fHumidity)
{
    IntoRobot.publish(pDataHumidityTopic,fHumidity);
}

void WidgetBirdcage::displayLightIntensity(float fLightIntensity)
{
    IntoRobot.publish(pDataLightIntensityTopic,fLightIntensity);
}

void WidgetBirdcage::displayPM25(int iPM25)
{
    IntoRobot.publish(pDataPM25Topic,iPM25);
}

void WidgetBirdcage::displayBirdStatus(uint8_t ucVal)
{
    IntoRobot.publish(pDataStatusTopic,ucVal);
}

