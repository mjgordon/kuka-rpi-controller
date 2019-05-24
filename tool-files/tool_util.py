#!/usr/bin/env python3

import logging
import socket
import serial

def setup_logging(name):
    """Starts a log file in the logs folder with the supplied name"""
    logging.basicConfig(filename="/home/pi/kuka-rpi-controller/logs/" + name + ".log",level=logging.INFO,filemode='w',format='%(message)s')

def setup_server():
    """Sets up a simple socket server. The robot connects as a client"""
    kuka_socket = socket.socket()
    #host = socket.gethostname()
    #host = "192.168.0.101"
    host = "192.168.2.203"
    port = 52323
    kuka_socket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
    kuka_socket.bind((host,port))
    #kuka_socket.setblocking(0)
    kuka_socket.listen(5)

    logging.info("Host : " + host)

    return kuka_socket


usb_strings = ('/dev/ttyUSB0','/dev/ttyUSB1','/dev/ttyUSB2','/dev/ttyUSB3','/dev/ttyACM0','/dev/ttyACM1')

def connect_serial():
    """Returns a serial connection from the common USB serial sources"""
    global usb_strings
    for s in usb_strings:
        try:
            s = serial.Serial(s)
            return(s)
        except (OSError, serial.SerialException):
            pass
    print("No serial connection found")
    return(None)


def writeInt(value):
    """Writes a single integer to the serial connection"""
    ser.write(value.to_bytes(4,byteorder='little'))

def writeBytes(values):
    """Writes an array of bytes to the serial connection"""
    ser.write(bytes(values))
