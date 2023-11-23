from pb.ros.geometry_msgs import Transform_pb2
from pb.ros.geometry_msgs import Pose_pb2
from pb.ros.custom_msgs import CustomTransform_pb2
from pb.ros.custom_msgs import Float32Array_pb2
import proxy
import os
import time
import socket
import struct
from ctypes import *
import math
import threading
import sys
import matlab.engine

node = proxy.Node('cjq', 'tcp://12.12.12.205:6001', 'tcp://12.12.12.205:7001')
publish = node.Advertise('M300_0', '/cjq/M300_0/transform',CustomTransform_pb2.CustomTransform)
publish1 = node.Advertise('M300_1', '/cjq/M300_1/transform',CustomTransform_pb2.CustomTransform)
publish2 = node.Advertise('M300_2', '/cjq/M300_2/transform',CustomTransform_pb2.CustomTransform)

localcmd = ("127.0.0.1", 20000) #pose-cmd
localstate = ("127.0.0.1", 20001) #state
localcmd1 = ("127.0.0.1", 20002) #pose-cmd
localstate1 = ("127.0.0.1", 20003) #state
localcmd2 = ("127.0.0.1", 20004) #pose-cmd
localstate2 = ("127.0.0.1", 20005) #state

class DataSend(Structure):
    _pack_ = 1
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double),
                ("member_4", c_double),
                ("member_5", c_double)]
datasend = DataSend()

class DataSend1(Structure):
    _pack_ = 1
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double),
                ("member_4", c_double),
                ("member_5", c_double)]
datasend1 = DataSend1()

class DataSend2(Structure):
    _pack_ = 1
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double),
                ("member_4", c_double),
                ("member_5", c_double)]
datasend2 = DataSend2()

class Cmd(Structure):
    _pack_ = 1  
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double)]
    
class Cmd1(Structure):
    _pack_ = 1  
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double)]
    
class Cmd2(Structure):
    _pack_ = 1  
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double)]

#pose-cmd
def callback(Pose):
    receive = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    cmd = Cmd( )  
    cmd.member_0 = Pose.position.x   
    cmd.member_1 = Pose.position.y 
    cmd.member_2 = Pose.position.z
    cmd.member_3 = Pose.orientation.x 
    receive.sendto(cmd, localcmd)

def callback1(Pose):
    receive1 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    cmd1 = Cmd1( )  
    cmd1.member_0 = Pose.position.x   
    cmd1.member_1 = Pose.position.y 
    cmd1.member_2 = Pose.position.z
    cmd1.member_3 = Pose.orientation.x 
    receive1.sendto(cmd1, localcmd1)
         
def callback2(Pose):
    receive2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    cmd2 = Cmd2( )  
    cmd2.member_0 = Pose.position.x   
    cmd2.member_1 = Pose.position.y 
    cmd2.member_2 = Pose.position.z
    cmd2.member_3 = Pose.orientation.x 
    receive2.sendto(cmd2, localcmd2)

subscriber = node.Subscribe('M300_0', '/cjq/M300_0/pose', Pose_pb2.Pose, callback)
subscriber1 = node.Subscribe('M300_1', '/cjq/M300_1/pose', Pose_pb2.Pose, callback1)
subscriber2 = node.Subscribe('M300_2', '/cjq/M300_2/pose', Pose_pb2.Pose, callback2)

def sub():
	while 1:
		subscriber.SpinOnce()
                
def sub1():
	while 1:
		subscriber1.SpinOnce()
                
def sub2():
	while 1:
		subscriber2.SpinOnce()
                
#s_time = 0 
class Publish:
    def sent_UE4(self, x, y, z, roll, pitch, yaw):
        aTransform = CustomTransform_pb2.CustomTransform()
        aTransform.translation.x = x
        aTransform.translation.y = y
        aTransform.translation.z = z
        aTransform.rotation.x = roll
        aTransform.rotation.y = pitch
        aTransform.rotation.z = yaw
        #print(aTransform.translation.z)
        publish.Publish(aTransform)

    def pub(self):
        send = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        send.bind(localstate)
        while True: 
            message, client = send.recvfrom(1024)
            memmove(addressof(datasend), (message), sizeof(DataSend))
            self.sent_UE4(datasend.member_0, datasend.member_1, datasend.member_2, datasend.member_3, datasend.member_4, datasend.member_5)

class Publish1:
    def sent_UE41(self, x, y, z, roll, pitch, yaw):
        bTransform = CustomTransform_pb2.CustomTransform()
        bTransform.translation.x = x
        bTransform.translation.y = y
        bTransform.translation.z = z
        bTransform.rotation.x = roll
        bTransform.rotation.y = pitch
        bTransform.rotation.z = yaw
        publish1.Publish(bTransform)

    def pub1(self):
        send1 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        send1.bind(localstate1)
        while True: 
            message1, client1 = send1.recvfrom(1024)
            memmove(addressof(datasend1), (message1), sizeof(DataSend1))
            self.sent_UE41(datasend1.member_0, datasend1.member_1, datasend1.member_2, datasend1.member_3, datasend1.member_4, datasend1.member_5)

class Publish2:
    def sent_UE42(self, x, y, z, roll, pitch, yaw):
        cTransform = CustomTransform_pb2.CustomTransform()
        cTransform.translation.x = x
        cTransform.translation.y = y
        cTransform.translation.z = z
        cTransform.rotation.x = roll
        cTransform.rotation.y = pitch
        cTransform.rotation.z = yaw
        publish2.Publish(cTransform)

    def pub2(self):
        send2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        send2.bind(localstate2)
        while True: 
            message2, client2 = send2.recvfrom(1024)
            memmove(addressof(datasend2), (message2), sizeof(DataSend2))
            self.sent_UE42(datasend2.member_0, datasend2.member_1, datasend2.member_2, datasend2.member_3, datasend2.member_4, datasend2.member_5)
                      
def main(args):

    engine = matlab.engine.start_matlab()
    engine.Init_control(nargout=0)
    engine.simstart(nargout=0)

    publish = Publish()
    thread_pub = threading.Thread(target = publish.pub)
    thread_pub.start()

    publish1 = Publish1()
    thread_pub1 = threading.Thread(target = publish1.pub1)
    thread_pub1.start()

    publish2 = Publish2()
    thread_pub2 = threading.Thread(target = publish2.pub2)
    thread_pub2.start()

    thread_sub = threading.Thread(target = sub)
    thread_sub.start()

    thread_sub1 = threading.Thread(target = sub1)
    thread_sub1.start()

    thread_sub2 = threading.Thread(target = sub2)
    thread_sub2.start()

    n = input('')


if __name__ == '__main__':
    main(sys.argv)
