import serial
from tkinter import *
import time

root = Tk()
r = "\n"
ser = serial.Serial('COM4', 9600, timeout=0)

def motion(event):
    x, y = event.x, event.y
    # print('{}, {}'.format(x, y))
    var = str(x) + "," + str(y)
    print(var)
    print(type(var))
    ser.write(var.encode())
    ser.write(r.encode())

root.bind('<Motion>', motion)
root.mainloop()



