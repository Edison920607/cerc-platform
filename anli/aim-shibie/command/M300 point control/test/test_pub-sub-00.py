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
publish.Init('M300_00', '/Qiqihar/M300_00/transform', 'custom_msgs/CustomTransform', 10)
publish.Advertise()

subcribe = rosproxy.proxy.Topic()
subcribe.Init('M300_00', '/Qiqihar/M300_00/pos', 'geometry_msgs/Point', 10)

localreceive = ("127.0.0.1", 29000)
localsend = ("127.0.0.1", 29001)

class DataSend(Structure):
    _pack_ = 1
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double),
                ("member_4", c_double),
                ("member_5", c_double)]
datasend = DataSend()

class Datareceive(Structure):
    _pack_ = 1  
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double)]


def callback(Point):
    receive = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    datareceive = Datareceive( )  
    datareceive.member_0= Point.x 
    datareceive.member_1= Point.y 
    datareceive.member_2= Point.z 
    print(datareceive.member_2)
    receive.sendto(datareceive, localreceive)

def sub():
    subcribe.Subscribe(callback)

class Publish:
    def sent_UE4(self,x, y, z, roll, pitch, yaw):
        aTransform = rosproxy.message.custom_msgs.CustomTransform()
        aTransform.translation.x = x
        aTransform.translation.y = y
        aTransform.translation.z = z
        aTransform.rotation.x = roll
        aTransform.rotation.y = pitch
        aTransform.rotation.z = yaw
        publish.Publish(aTransform)
    
    def pub(self):
        send = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        send.bind(localsend)
        while True: 
            message, client = send.recvfrom(1024)
            memmove(addressof(datasend), (message), sizeof(DataSend))
            self.sent_UE4(datasend.member_0, datasend.member_1, datasend.member_2, datasend.member_3, datasend.member_4, datasend.member_5)
            

def main(args):

    publish = Publish()
    thread_pub = threading.Thread(target = publish.pub)
    thread_pub.start()
    thread_sub = threading.Thread(target = sub)
    thread_sub.start()
    
    n = input('')


if __name__ == '__main__':
    main(sys.argv)
