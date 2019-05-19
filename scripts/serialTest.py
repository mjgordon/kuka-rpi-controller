import serial

usb_strings = ('/dev/ttyUSB0','/dev/ttyUSB1','/dev/ttyACM0','/dev/ttyACM1')

def serOpen():
    global ser
    ser = connect()

def serClose():
    global ser
    ser.close()

def writeInt(value):
    global ser
    ser.write(value.to_bytes(4,byteorder='little'))

def writeBytes(values):
    global ser
    ser.write(bytes(values))

def connect():
    global usb_strings
    for s in usb_strings:
        try:
            s = serial.Serial(s)
            return(s)
        except (OSError, serial.SerialException):
            pass
    return(None)


serOpen()
