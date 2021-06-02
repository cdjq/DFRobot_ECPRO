## DFRobot_EC Library 
---------------------------------------------------------

## Table of Contents

* [Methods](#methods)
* [Compatibility](#Compatibility)
* [History](#history)
* [Credits](#credits)
<snippet>
<content>

## Methods

```C++
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
```

## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno  |      √       |             |            | 
Leonardo  |      √       |             |            | 
Meag2560 |      √       |             |            | 

## History

- date 2021-6-1
- version V1.0

## Credits

Written by Peng Kaixing(Welcome to our [website](https://www.dfrobot.com/))
