/*
 ************************************************************************
 * 作者:  IntoRobot Team
 * 版本:  V1.0.0
 * 时间:  03-30-15
 ************************************************************************
 功能描述：
 鸟笼：智能鸟笼，不仅具有检测鸟是否存在功能，而且还有检测环境温湿度，
 光照强度，空气PM2.5颗粒浓度功能

 所需器件:
 1.E18-D80NK 红外光电开关 漫反射式避障传感器模块
 2.DHT11 温湿度传感器模块
 3.GY-30 数字光强度光照传感器
 4.GP2Y10 PM2.5浓度传感器模块

 接线说明：
 E18-D80NK                    核心板
 1.红色线                     +5V
 2.黑色线                     GND
 3.黄色线                     D0

 DH11
 1.VCC                        +3.3V
 2.GND                        GND
 3.DATA                       D3

 GY-30
 1.VCC                        +3.3V
 2.GND                        GND
 3.SDA                        I2C(Wire组)的SDA
 4.SCL                        I2C(Wire组)的SCL

 GP2Y10
 VCC	                     3V3
 GND                         GND
 LED                         D4
 OUT                         A0
 说明：带有“D”的为数字管脚，带有“A”的为模拟管脚，接线时请确认核心板引脚，避免接线错误。
 请注意各核心板的I2C引脚区别，避免接线错误。
 */

#include <IntoRobot_DHT.h>
#include <gy30.h>
#include <gp2y10.h>
#include <WidgetBirdcage.h>

#define InfraredSensorINPUT   D0
#define DHT_TYPE   DHT11
#define DHT11_PIN       D3
#define GP2Y10_LED_PIN  D4
#define GP2Y10_OUT_PIN  A0

GY30 gy30;
IntoRobot_DHT dht11(DHT11_PIN,DHT_TYPE);
GP2Y10 gp2y10 = GP2Y10(GP2Y10_OUT_PIN,GP2Y10_LED_PIN);

WidgetBirdcage birdCage = WidgetBirdcage();

void setup()
{
    //初始化
    gy30.begin();
    dht11.begin();
    gp2y10.begin();
    pinMode(InfraredSensorINPUT, INPUT_PULLUP);
}

void loop()
{
    birdCage.displayBirdStatus(!digitalRead(InfraredSensorINPUT));
    birdCage.displayTemperature(dht11.getTempCelcius());  //上送温度值
    birdCage.displayHumidity(dht11.getHumidity());         //上送湿度值
    birdCage.displayLightIntensity(gy30.Read());            //上送光照强度值
    birdCage.displayPM25(gp2y10.CalculatedConcentration());	//上送PM2.5浓度
    delay(3000);
}
