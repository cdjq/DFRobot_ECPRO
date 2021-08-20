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

float volCal(float input){
  return input;
}

DFRobot_ECPRO::DFRobot_ECPRO()
{
  this->_kvalue = 1.0;
}

DFRobot_ECPRO::DFRobot_ECPRO(float calibration)
{
  this->_kvalue = calibration;
}

float DFRobot_ECPRO::getEC_us_cm(float voltage)
{
  voltage = volCal(voltage);
  float value = 100000*voltage/RES2/ECREF * this->_kvalue;                
  return value;
}

float DFRobot_ECPRO::getEC_us_cm(float voltage, float temperature)
{
  voltage = volCal(voltage);
  float ecvalueRaw = 100000 * voltage / RES2 / ECREF * this->_kvalue;
  float value = ecvalueRaw / (1.0 + 0.02 * (temperature - 25.0));
  return value;
}

bool DFRobot_ECPRO::setCalibration(float calibration)
{
  if((calibration>=0.5)&&(calibration<=1.5))
  {
    this->_kvalue = calibration;
    EEPROM_write(KVALUEADDR, this->_kvalue);
    return 1;
  }else
    return 0;
}

float DFRobot_ECPRO::getCalibration()
{
  EEPROM_read(KVALUEADDR, this->_kvalue);
  if (this->_kvalue == 0xff)
  {
    this->_kvalue = 1.0; // For new EEPROM, write default value( K = 1.0) to EEPROM
    EEPROM_write(KVALUEADDR, this->_kvalue);
  }
  return this->_kvalue;
}

float DFRobot_ECPRO::calibrate(float voltage)
{
  voltage = volCal(voltage);
  float KValueTemp = RES2*ECREF*1413/100000.0/voltage;
  return KValueTemp;
}

float DFRobot_ECPRO::calibrate(float voltage, float reference)
{
  voltage = volCal(voltage);
  float KValueTemp = RES2*ECREF*reference/100000.0/voltage;
  return KValueTemp;
}

float DFRobot_ECPRO_PT1000::convVoltagetoTemperature_C(float voltage)
{
  voltage = volCal(voltage);
  float Rpt1000 = (voltage/GDIFF+VR0)/I/G0;
  float temp = (Rpt1000-1000)/3.85;
  return temp;
}