import time
import RPi.GPIO as GPIO
servoPIN = 3
GPIO.setmode(GPIO.BCM)
GPIO.setup(servoPIN, GPIO.OUT)

p = GPIO.PWM(servoPIN, 50) # GPIO 17 for PWM with 50Hz
p.start(2.5) # Initialization

def closeDoor():
    p.ChangeDutyCycle(2.5) # close
    
def openDoor():
    p.ChangeDutyCycle(12.5)
    
    
