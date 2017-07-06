import serial
import time

ser = serial.Serial('COM4', 9600, timeout=0)



while 1:
    var = input()
    r = "\n"
    # varNum = int(var)
    varB = var.encode()
    print(var)
    print(var.encode())
    print(type(varB))
    ser.write(var.encode())
    ser.write(r.encode())