#!/usr/bin/env python
import RPi.GPIO as GPIO
import time
import servo

sensor = 2
rl = 27

GPIO.setmode(GPIO.BCM)
GPIO.setup(sensor,GPIO.IN)
GPIO.setup(rl,GPIO.OUT)
GPIO.output(rl,False)
def waitTillEnter():
    while True:
        if GPIO.input(sensor):
          print("Object leave")
          while GPIO.input(sensor):
              time.sleep(0.01)
              break
        else:
            print ("Object entered")
            servo.closeDoor()
            GPIO.output(rl,True)
            break
        break
