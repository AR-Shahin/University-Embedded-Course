import RPi.GPIO as GPIO
import time
 
class keypad():
    # CONSTANTS   
    KEYPAD = [
    [1,2,3],
    [4,5,6],
    [7,8,9],
    ["*",0,"#"]
    ]
     
    ROW         = [25,24,23,18]
    COLUMN      = [22,17,4]
     
    def __init__(self):
        GPIO.setmode(GPIO.BCM)

        # Set all columns as output low
        for j in range(len(self.COLUMN)):
            GPIO.setup(self.COLUMN[j], GPIO.OUT)
                
        # Set all rows as input
        for i in range(len(self.ROW)):
            GPIO.setup(self.ROW[i], GPIO.IN, pull_up_down=GPIO.PUD_UP)
         
     
    def getKey(self):
            
        for i in range(len(self.COLUMN)):
            GPIO.output(self.COLUMN[i], GPIO.LOW)
            for j in range(len(self.ROW)):
                tmpRead = GPIO.input(self.ROW[j])
                if tmpRead==0:
                    GPIO.output(self.COLUMN[i], GPIO.HIGH)

                    return self.KEYPAD[j][i]
                    print(self.KEYPAD[j][i])
            GPIO.output(self.COLUMN[i], GPIO.HIGH)
        
kp = keypad()

try:
    while True:
        digit = None
        while digit == None:
            digit = kp.getKey()
        time.sleep(0.5)
     
    # Print the result
        print (digit)
except KeyboardInterrupt:
    GPIO.cleanup()
