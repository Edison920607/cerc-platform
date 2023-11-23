from pb.ros.sensor_msgs import Image_pb2
from pb.ros.nav_msgs import Odometry_pb2
from pb.ros.std_msgs import Float32_pb2
import time
import numpy as np
import cv2.cv2 as cv2
import proxy
import proxy
import os
import time
import socket
import struct
from ctypes import *
import math
import threading
import sys

B = 0
last_time = 0

node_ = proxy.Node('cjq', 'tcp://12.12.12.205:6008', 'tcp://12.12.12.205:7008')

def CB_IMAGE(image):
    global B
    E = time.time()
    imagedata = np.frombuffer(image.data, np.uint8)
    height, width = image.height, image. width
    # img_brg = RGBA2BGR(imagedata, height, width)
    img_rgba = imagedata.reshape(image.height, image. width, 4)
    img_brg = cv2.cvtColor(img_rgba, cv2.COLOR_RGBA2BGR)
    print (E-B)
    B = E
    cv2.imshow("Temporary Image", img_brg)
    cv2.waitKey(1)

def callback(Scan):
    x = Scan.data
    #print(x)

subcribe = node_.Subscribe('FW_0', '/cjq/FW_0/color/image_raw', Image_pb2.Image, CB_IMAGE)
subcribe1 = node_.Subscribe('FW_0', '/cjq/FW_0/scan', Float32_pb2.Float32, callback)

def sub():
	while 1:
		subcribe.SpinOnce()
def sub1():
	while 1:
		subcribe1.SpinOnce()

def main(args):

    thread_sub = threading.Thread(target = sub)
    thread_sub.start()
    thread_sub1 = threading.Thread(target = sub1)
    thread_sub1.start()
    n = input('')

if __name__ == '__main__':
    main(sys.argv)
