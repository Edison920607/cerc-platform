from pb.ros.sensor_msgs import Image_pb2
from pb.ros.nav_msgs import Odometry_pb2
from numba import njit, prange
import time
import numpy as np
import cv2.cv2 as cv2
import proxy
import rosproxy
import os
import time
import socket
import struct
from ctypes import *
import math
import threading
import sys

B = 0

rosproxy.proxy.Setup('cjq', 'tcp://12.12.12.205:6557', 'tcp://12.12.12.205:6587')

subcribe = rosproxy.proxy.Topic()
subcribe.Init('cjq', '/cjq/FW_0/color/image_raw', 'sensor_msgs/Image', 1)
subcribe1 = rosproxy.proxy.Topic()
subcribe1.Init('cjq', '/cjq/FW_0/scan', 'std_msgs/Float32', 1)

last_time = 0

#numba并行加速
@njit
def RGBA2BGR(ImageData, Height, Width):
    img_temp = np.empty((Height, Width, 3) ,dtype=np.uint8)

    for h in range(0, Height):
        for w in range(0, Width):
            img_temp[h][w] = [ImageData[4*(w + h * Width) + 2], ImageData[4*(w + h * Width) + 1], ImageData[4*(w + h * Width) + 0]]
    return img_temp

def CB_IMAGE(image):
    global B
    E = time.time()
    # global last_time
    # temp_time = time.time()
    # print(1/(temp_time - last_time))
    # last_time = temp_time

    imagedata = np.array(image.data[:])
    height, width = image.height,  image. width
    # print(imagedata.shape)

    img_brg = RGBA2BGR(imagedata, height, width)
    # imagedata = np.array(image.data[:])
    print (E-B)
    B = E
    
    cv2.imshow("Temporary Image", img_brg)
    cv2.waitKey(1)

def callback(Scan):
    x = Scan.data
    #print(x)

def sub():
    subcribe.Subscribe(CB_IMAGE)

def sub1():
    subcribe1.Subscribe(callback)


def main(args):

    thread_sub = threading.Thread(target = sub)
    thread_sub.start()
    thread_sub1 = threading.Thread(target = sub1)
    thread_sub1.start()
    n = input('')

if __name__ == '__main__':
    main(sys.argv)
