#!/usr/bin/env python3
from serial import Serial
import time
import keyboard

ser = Serial('/dev/ttyACM0', 9600, timeout=1) #/dev/ttyACM0
ser.reset_input_buffer()
b = time.time()
while True:
    try:
            line = ser.readline().decode('utf-8').rstrip()
    except:
            print("N/A")
    print(line)
    time.sleep(0.05)
    if keyboard.is_pressed("a"):
        ser.write(b"a\n")
    elif keyboard.is_pressed("q"):
            ser.write(b"x\n")
            ser.close()
    elif keyboard.is_pressed("s"):
            ser.write(b"s\n")
    elif keyboard.is_pressed("d"):
            ser.write(b"d\n")
    elif keyboard.is_pressed("x"):
            ser.write(b"x\n")
    else:
            ser.write(b"r\n")
    
