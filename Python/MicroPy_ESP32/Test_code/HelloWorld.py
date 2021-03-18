from machine import Pin
import time

p = Pin(5, Pin.OUT)

def toggle(max):
    lap = 0

    while lap < max:
        lap = 0

        while lap < max:
            time.sleep(1)
            lap += 1
            print(lap)

toggle(5)
