/*!
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      PengKaixing(kaixing.peng@dfrobot.com)
  * @version     V0.1
  * @date        2021-05-31
  * @get         from https://www.dfrobot.com
  * @url         https://github.com/dfrobot/DFRobot_ECPRO
  */

#ifndef __DFRobot_ECPRO_H__
#define __DFRobot_ECPRO_H__
#endif

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "EEPROM.h"

#define KVALUEADDR 0x0A //the start address of the K value stored in the EEPROM
#define RES2 820.0
#define ECREF 200.0
#define GDIFF (30/1.8)
#define VR0  0.223
#define G0  2
#define I  (1.24 / 10000)

#define EEPROM_write(address, p) {int i = 0; byte *pp = (byte*)&(p);for(; i < sizeof(p); i++) EEPROM.write(address+i, pp[i]);}
#define EEPROM_read(address, p)  {int i = 0; byte *pp = (byte*)&(p);for(; i < sizeof(p); i++) pp[i]=EEPROM.read(address+i);}

class DFRobot_ECPRO
{
  public:
    DFRobot_ECPRO();
    DFRobot_ECPRO(float calibration);
    ~DFRobot_ECPRO(){};
/**
 * bref 获取的电导率电压值和温度电压值（带温度校准）
 * param voltage:adc获取的电压值
 * return 电导率
 */
    float getEC_us_cm(float voltage);

/**
 * bref 获取的电导率电压值和温度电压值（不带温度校准）
 * param voltage:adc获取的电压值
 * temperature 溶液温度
 * return 电导率
 */
    float getEC_us_cm(float voltage, float temperature);

/**
 * bref 设置校准值并在eeprom中永久保存
 * param calibration
 * return 是否成功
 */
    bool setCalibration(float calibration);

/**
 * bref 获取校准值
 */
    float getCalibration();

/**
 * bref 校准（自带参考k值为1）
 */
    float calibrate(float voltage);

/**
 * bref 校准
 * param voltage ：电导率传感器的输出电压值
 *       reference：参考k值（0.5<k<1.5）
 */
    float calibrate(float voltage, float reference); 
  private:
    float _kvalue;
};

#ifndef __DFRobot_ECPRO_PT1000_H__
#define __DFRobot_ECPRO_PT1000_H__
#endif

class DFRobot_ECPRO_PT1000
{
  public:
    DFRobot_ECPRO_PT1000(){};
    ~DFRobot_ECPRO_PT1000(){};
    float convVoltagetoTemperature_C(float voltage);
};
