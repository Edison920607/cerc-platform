from pb.ros.geometry_msgs import Transform_pb2
from pb.ros.geometry_msgs import Pose_pb2
from pb.ros.custom_msgs import CustomTransform_pb2
from pb.ros.custom_msgs import Float32Array_pb2
from pb.ros.data_control_msgs import Collector_new_pb2
import proxy
#import rosproxy
import os
import time
import socket
import struct
from ctypes import *
import math
import threading
import sys
import signal

node_ = proxy.Node('Case2', 'tcp://12.12.12.205:6006', 'tcp://12.12.12.205:7006')
node1 = proxy.Node('collector','tcp://12.12.12.205:6004','tcp://12.12.12.205:7004')
#                              场景名称    IP地址及通信发送端口          IP地址及通信接收端口 
localreceive0 = ("127.0.0.1", 15000)
localreceive1 = ("127.0.0.1", 15002)
localreceive2 = ("127.0.0.1", 15004)
#              使用本机IP  UDP端口：需要与动力学模型中保持一致，一般为150xx偶数，便于区分


class Control_Collect:

    def __init__(self):

        self.subscriber = node1.Subscribe("FW01_0",'/collector',Collector_new_pb2.Collector,self.callback)

        self.Collector_data = Collector_new_pb2.Collector()


    def callback(self,data):

        self.Collector_data = data


    def sub(self):
        while 1:
            self.subscriber.SpinOnce()



class Datareceive0(Structure):
    _pack_ = 1  
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double)]
class Datareceive1(Structure):
    _pack_ = 1  
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double)]
class Datareceive2(Structure):
    _pack_ = 1  
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double)]

def callback0(aPose):
    receive0 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    datareceive0 = Datareceive0( )  
    datareceive0.member_0= aPose.position.x 
    datareceive0.member_1= aPose.position.y 
    datareceive0.member_2= aPose.position.z 
    datareceive0.member_3= aPose.orientation.x
    receive0.sendto(datareceive0, localreceive0)
    #print( datareceive0.member_0)
def callback1(bPose):
    receive1 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    datareceive1 = Datareceive1( )  
    datareceive1.member_0= bPose.position.x 
    datareceive1.member_1= bPose.position.y 
    datareceive1.member_2= bPose.position.z 
    datareceive1.member_3= bPose.orientation.x
    receive1.sendto(datareceive1, localreceive1)
def callback2(cPose):
    receive2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    datareceive2 = Datareceive2( )  
    datareceive2.member_0= cPose.position.x 
    datareceive2.member_1= cPose.position.y 
    datareceive2.member_2= cPose.position.z 
    datareceive2.member_3= cPose.orientation.x
    receive2.sendto(datareceive2, localreceive2)

subcribe0 = node_.Subscribe('M300_0', '/Case2/M300_0/pose', Pose_pb2.Pose, callback0)
subcribe1 = node_.Subscribe('M300_1', '/Case2/M300_1/pose', Pose_pb2.Pose, callback1)
subcribe2 = node_.Subscribe('M300_2', '/Case2/M300_2/pose', Pose_pb2.Pose, callback2)
#                   第几架无人机 0开始  /场景名/第几架无人机/话题名   消息体
def sub0():
    	while 1:
            subcribe0.SpinOnce()
def sub1():
    	while 1:
            subcribe1.SpinOnce()
def sub2():
    	while 1:
            subcribe2.SpinOnce()

def main(args):

    thread_sub0 = threading.Thread(target = sub0)
    thread_sub0.start()
    thread_sub1 = threading.Thread(target = sub1)
    thread_sub1.start()
    thread_sub2 = threading.Thread(target = sub2)
    thread_sub2.start()
    
    C_C = Control_Collect()
    C_C.Collector_data.flag = 4
    thread_sub_collect = threading.Thread(target = C_C.sub)
    thread_sub_collect.start()

    #n = input('')
    while True:
        if C_C.Collector_data.flag == 1:
            print(C_C.Collector_data.flag)
            break

    print(os.getpid())
    os.system('taskkill /f /pid %s' % os.getpid())

if __name__ == '__main__':
    main(sys.argv)
