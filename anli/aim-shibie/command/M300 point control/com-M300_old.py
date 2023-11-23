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

localcmd = ("127.0.0.1", 20000) #pose-cmd
localstate = ("127.0.0.1", 20001) #state

class DataSend(Structure):
    _pack_ = 1
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double),
                ("member_4", c_double),
                ("member_5", c_double)]
datasend = DataSend()

class Cmd(Structure):
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


subscriber = node.Subscribe('M300_0', '/cjq/M300_0/pose', Pose_pb2.Pose, callback)

def sub():
	while 1:
		subscriber.SpinOnce()
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
        publish.Publish(aTransform)

    def pub(self):
        send = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        send.bind(localstate)
        while True: 
            message, client = send.recvfrom(1024)
            memmove(addressof(datasend), (message), sizeof(DataSend))
            self.sent_UE4(datasend.member_0, datasend.member_1, datasend.member_2, datasend.member_3, datasend.member_4, datasend.member_5)
           
def main(args):

    engine = matlab.engine.start_matlab()
    engine.Init_control(nargout=0)
    engine.simstart(nargout=0)

    publish = Publish()
    thread_pub = threading.Thread(target = publish.pub)
    thread_pub.start()

    thread_sub = threading.Thread(target = sub)
    thread_sub.start()

    n = input('')


if __name__ == '__main__':
    main(sys.argv)
