# -*- coding: utf-8 -*
'''
  * @file  gain_conductivity.py
  * @brief ��ȡ��ǰ��Һ�絼��
  * @n ʵ�鷽ʽ�� ��������ͨ���������������ӣ���¼
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
  tempe_voltage = 0.78#�¶ȴ�������ѹ
  voltage = 0.78#�絼�ʴ�������ѹ
  temperature = ecpt.conv_voltageto_temperature_c(tempe_voltage)
  conductivity = ec.get_ec_us_cm(voltage,temperature)
  print "EC: " + str(conductivity) + "us/cm"
  time.sleep(1)
  
if __name__ == "__main__":
  setup()
  while True:
    loop()  