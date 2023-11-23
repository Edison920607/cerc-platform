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
subcribe = rosproxy.proxy.Topic()
subcribe.Init('M300_00', '/Qiqihar/M300_00/transform', 'custom_msgs/CustomTransform', 10)


def callback(aTransform):
        x = aTransform.translation.x
        y = aTransform.translation.y
        z = aTransform.translation.z
        roll = aTransform.rotation.x
        pitch = aTransform.rotation.y
        psi = aTransform.rotation.z
        print(x)

def sub():
    subcribe.Subscribe(callback)
            

def main(args):

    thread_sub = threading.Thread(target = sub)
    thread_sub.start()
    
    n = input('')


if __name__ == '__main__':
    main(sys.argv)
