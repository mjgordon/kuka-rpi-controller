#!/usr/bin/env python3

import logging
import socket

def setup_logging(name):
    logging.basicConfig(filename="/home/pi/kuka-rpi-controller/logs/" + name + ".log",level=logging.INFO,filemode='w',format='%(message)s')

def setup_server():
    # Set up networking connection with robot
    kuka_socket = socket.socket()
    #host = socket.gethostname()
    host = "192.168.0.101"
    #host = "192.168.2.203"
    port = 52323
    kuka_socket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
    kuka_socket.bind((host,port))
    #kuka_socket.setblocking(0)
    kuka_socket.listen(5)

    logging.info("Host : " + host)

    return kuka_socket
