/*!
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      PengKaixing(kaixing.peng@dfrobot.com)
  * @version     V0.1
  * @date        2021-05-31
  * @get         from https://www.dfrobot.com
  * @url         https://github.com/dfrobot/DFRobot_ECPRO
  */
#include "DFRobot_ECPRO.h"

#define EC_PIN A1
#define TE_PIN A2

#define ADC_DIGIT 1024.0
#define REFERENCE_VOLTAGE 5.0

/**
 * 获取的电导率电压值和温度电压值
 */
float EC_voltage,TE_voltage;
float temp,conductivity;

DFRobot_ECPRO ec;
DFRobot_ECPRO_PT1000 ecpt;

void setup()
{
  Serial.begin(115200);

  /**
   * 校准
   */
  EC_voltage = analogRead(EC_PIN) / ADC_DIGIT * REFERENCE_VOLTAGE;
  ec.setCalibration(ec.calibrate(EC_voltage));
  Serial.print("calibration value is :");
  Serial.println(ec.getCalibration());
}

void loop()
{
/**
 * 获取温度值
 */  
  TE_voltage = analogRead(TE_PIN)/1024.0*5;
  temp= ecpt.convVoltagetoTemperature_C(TE_voltage); 
  
/**
 * 获取电导率值
 */
  EC_voltage = analogRead(EC_PIN) / ADC_DIGIT * REFERENCE_VOLTAGE;
  conductivity = ec.getEC_us_cm(EC_voltage,temp);
  
  Serial.print("temperature:");
  Serial.print(temp);
  Serial.print("^C  EC:");
  Serial.print(conductivity);
  Serial.println("us/cm");
  delay(1000);
}
