import serial
import time
import os.path

port_name = raw_input("Set port: \n")

if os.path.isfile(port_name):
    print "Port is exist"
else:
    print "Port is not exist, check again !"

print "Setup COM port !!!"
ser = serial.Serial(
    port=str(port_name),
    baudrate=115200,
    parity=serial.PARITY_ODD,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS
)

if ser.isOpen():
    ser.close()

try:
    ser.open()
except Exception, e:
    print "Error open serial port: " + str(e)
    exit()

if ser.isOpen():
    print "Wait for Module setup!!!"
    time.sleep(1)
    while 1:
        input_data = raw_input("Set command: \n")
        # print "Try to run command: {}".format(str(input_data))
        if (input_data == "exit"):
            print "Out script......."
            exit()

        try:
            out_string = str(input_data) +'\n'
            ser.write(out_string)
        except Exception, e1:
            print "error communicating...: " + str(e1)
else:
    print "Cannot open serial port!"
