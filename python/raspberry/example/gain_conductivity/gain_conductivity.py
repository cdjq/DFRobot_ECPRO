# -*- coding: utf-8 -*
'''
  * @file  gain_conductivity.py
  * @brief 获取当前溶液电导率
  * @n 实验方式： 将传感器通信引脚与主控连接，烧录
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      PengKaixing(kaixing.peng@dfrobot.com)
  * @version     V1.0
  * @date        2021-03-28
  * @get         from https://www.dfrobot.com
  * @url         https://github.com/dfrobot/DFRobot_ecpro
'''

import sys
import os
import time
sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.realpath(__file__)))))
from dfrobot_ecpro import *

ec=dfrobot_ecpro() 
ecpt=dfrobot_ecpro_pt1000() 

def setup():
  ec.set_calibration(1.0)

def loop():
  tempe_voltage = 0.78#温度传感器电压
  voltage = 0.78#电导率传感器电压
  temperature = ecpt.conv_voltageto_temperature_c(tempe_voltage)
  conductivity = ec.get_ec_us_cm(voltage,temperature)
  print "EC: " + str(conductivity) + "us/cm"
  time.sleep(1)
  
if __name__ == "__main__":
  setup()
  while True:
    loop()  