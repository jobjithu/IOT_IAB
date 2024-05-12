import RPi.GPIO as GPIO
import time

pir_sensor = 29
buzzer = 4

GPIO.setwarings(False)

GPIO.setmode(GPIO.BOARD)

GPIO.setup(pir_sensor,GPIO.IN)
GPIO.setup(buzzer,GPIO.OUT)

while True:
    if(GPIO.input(pir_sensor)):
        print("Motion Detected")
        GPIO.OUT(buzzer,GPIO.HIGH)
        time.sleep(3)