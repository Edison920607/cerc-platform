from pb.ros.geometry_msgs import Transform_pb2
from pb.ros.geometry_msgs import Twist_pb2
from pb.ros.geometry_msgs import Point_pb2
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
import matlab.engine
import signal

#node_ = proxy.Node('FK', 'tcp://12.12.12.205:6006', 'tcp://12.12.12.205:7006')
#node1 = proxy.Node('collector','tcp://12.12.12.205:6004','tcp://12.12.12.205:7004')
#node_ = proxy.Node('FK', 'tcp://12.12.12.205:6021', 'tcp://12.12.12.205:7021')
#node1 = proxy.Node('collector','tcp://12.12.12.205:6021','tcp://12.12.12.205:7021')

node_ = proxy.Connector('tcp://12.12.12.204:15555')
node1 = proxy.Connector('tcp://12.12.12.204:15555')

#publish_ = node_.Advertise('FW_0', '/Case2/FW_0/transform',CustomTransform_pb2.CustomTransform)
publish_ = node_.Advertise('FK','FW01_0', '/FK/FW01_0/transform',CustomTransform_pb2.CustomTransform)

#localreceive = ("127.0.0.1", 16000)
localsend = ("127.0.0.1", 16001)


class Control_Collect:

    def __init__(self):

        self.subscriber = node1.Subscribe("data","command",'/collector',Collector_new_pb2.Collector,self.callback)

        self.Collector_data = Collector_new_pb2.Collector()


    def callback(self,data):

        self.Collector_data = data


    def sub(self):
        while 1:
            self.subscriber.SpinOnce()


class DataSend(Structure):
    _pack_ = 1
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double),
                ("member_4", c_double),
                ("member_5", c_double)]
datasend = DataSend()

class Publish:
    def sent_UE4(self,x, y, z, roll, pitch, yaw):
        aTransform = CustomTransform_pb2.CustomTransform()
        aTransform.translation.x = x
        aTransform.translation.y = y
        aTransform.translation.z = z
        aTransform.rotation.x = roll
        aTransform.rotation.y = pitch
        aTransform.rotation.z = yaw
        aTransform.motor_speed.data.append(1000)
        aTransform.motor_speed.data.append(1000)
        aTransform.motor_speed.data.append(1000)
        aTransform.motor_speed.data.append(1000)

        publish_.Publish(aTransform)       
    
    
    def pub(self):
        send = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        send.bind(localsend)
        while True: 
            message, client = send.recvfrom(1024)
            memmove(addressof(datasend), (message), sizeof(DataSend))
            self.sent_UE4(datasend.member_0, datasend.member_1, datasend.member_2, datasend.member_3, datasend.member_4, datasend.member_5)
        
def main(args):
    engine0 = matlab.engine.start_matlab()
    engine0.Initial(nargout=0)
    engine0.simstart(nargout=0)
    publish_s = Publish()
    #thread_pub = threading.Thread(target = publish.pub)
    #thread_pub.start()
    
    C_C = Control_Collect()
    C_C.Collector_data.flag = 4
    thread_sub = threading.Thread(target = C_C.sub)
    thread_sub.start()

    send = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    send.bind(localsend)
    while True: 
        message, client = send.recvfrom(1024)
        memmove(addressof(datasend), (message), sizeof(DataSend))
        publish_s.sent_UE4(datasend.member_0, datasend.member_1, datasend.member_2, datasend.member_3, datasend.member_4, datasend.member_5)
        
        if C_C.Collector_data.env == "FK" and C_C.Collector_data.flag == 1:
            print(C_C.Collector_data.flag)
            break

    #n = input('')
    print(os.getpid())
    os.system('taskkill /f /pid %s' % os.getpid())
    
if __name__ == '__main__':
    main(sys.argv)
