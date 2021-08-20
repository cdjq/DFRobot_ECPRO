# -*- coding: utf-8 -*
'''
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      PengKaixing(kaixing.peng@dfrobot.com)
  * @version     V0.1
  * @date        2021-06-02
  * @get         from https://www.dfrobot.com
  * @url         https://github.com/dfrobot/DFRobot_ecpro
'''
import serial
import time
import os

_kvalue = 1.0
RES2 = 820.0
ECREF = 200.0
GDIFF = (30/1.8)
VR0  = 0.223
G0  = 2
I  = (1.24 / 10000)

class dfrobot_ecpro(object):

  def volCal(self,input):
    return input

  def get_ec_us_cm(self,voltage,temperature):
    voltage=self.volCal(voltage)
    ecvalueRaw = 100000 * voltage / RES2 / ECREF * _kvalue
    value = ecvalueRaw / (1.0 + 0.02 * (temperature - 25.0))
    return value
    
  def set_calibration(self,calibration):
    global _kvalue
    if((calibration>=0.5)and(calibration<=1.5)):
      _kvalue = calibration
      return 1
    else:
      return 0 

class dfrobot_ecpro_pt1000(object):     
  def conv_voltageto_temperature_c(self,voltage):
    voltage=self.volCal(voltage)
    Rpt1000 = (voltage/GDIFF+VR0)/I/G0
    temp = (Rpt1000-1000)/3.85
    return temp
   