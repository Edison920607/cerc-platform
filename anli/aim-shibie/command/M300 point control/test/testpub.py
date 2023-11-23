import rosproxy
import os
import time
import socket
import struct
from ctypes import *
import math
import threading
import sys

rosproxy.proxy.Setup('Qiqihar', 'tcp://192.168.61.212:6658', 'tcp://192.168.61.212:6687')
publish = rosproxy.proxy.Topic()
publish.Init('M300_00', '/Qiqihar/M300_00/pos', 'geometry_msgs/Point', 10)
publish.Advertise()

def sent_UE4():
    aPoint = rosproxy.message.geometry_msgs.Point()
    aPoint.x = 10
    aPoint.y = 0
    aPoint.z = 2
    publish.Publish(aPoint)
    print(aPoint.z)

def main(args):
    while 1:
        sent_UE4()
        
    n = input('')


if __name__ == '__main__':
    main(sys.argv)
