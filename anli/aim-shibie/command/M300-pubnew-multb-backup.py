from site import abs_paths
from pb.ros.geometry_msgs import Transform_pb2
from pb.ros.geometry_msgs import Pose_pb2
from pb.ros.geometry_msgs import Vector3_pb2
from pb.ros.custom_msgs import CustomTransform_pb2
from pb.ros.custom_msgs import Float32Array_pb2
from pb.ros.data_control_msgs import Collector_new_pb2
import proxy
import os
import time
import socket
import struct
from ctypes import *
import math
import threading
import sys
import signal

node_ = proxy.Node('Case2', 'tcp://12.12.12.204:6006', 'tcp://12.12.12.204:7006')
node1 = proxy.Node('collector','tcp://12.12.12.204:6004','tcp://12.12.12.204:7004')

publish = node_.Advertise('M300_0', '/Case2/M300_0/pose', Pose_pb2.Pose)
publish1 = node_.Advertise('M300_0', '/Case2/M300_0/gimbal_angle_cmd', Vector3_pb2.Vector3)
publish2 = node_.Advertise('M300_1', '/Case2/M300_1/pose', Pose_pb2.Pose)
publish3 = node_.Advertise('M300_1', '/Case2/M300_1/gimbal_angle_cmd', Vector3_pb2.Vector3)
publish4 = node_.Advertise('M300_2', '/Case2/M300_2/pose', Pose_pb2.Pose)
publish5 = node_.Advertise('M300_2', '/Case2/M300_2/gimbal_angle_cmd', Vector3_pb2.Vector3)
#s_time = 0 


class Control_Collect:

    def __init__(self):

        self.subscriber = node1.Subscribe("M300_0",'/collector',Collector_new_pb2.Collector,self.callback)

        self.Collector_data = Collector_new_pb2.Collector()


    def callback(self,data):

        self.Collector_data = data


    def sub(self):
        while 1:
            self.subscriber.SpinOnce()



class Publish:
    def sent_path(self, x, y, z, yawrate ):
        pose = Pose_pb2.Pose()
        pose.position.x = x
        pose.position.y = y
        pose.position.z = z
        pose.orientation.x = yawrate
        publish.Publish(pose)

    def sent_gimbal(self, x, y, z):
        gimbal = Vector3_pb2.Vector3()
        gimbal.x = x
        gimbal.y = y
        gimbal.z = z
        publish1.Publish(gimbal)

    def pub(self):
        while True: 
            self.sent_path(10, 0, -20, 0 )
            self.sent_gimbal(0,-35,0)

class Publish1:
    def sent_path1(self, x, y, z, yawrate ):
        apose = Pose_pb2.Pose()
        apose.position.x = x
        apose.position.y = y
        apose.position.z = z
        apose.orientation.x = yawrate
        publish2.Publish(apose)

    def sent_gimbal1(self, x, y, z):
        agimbal = Vector3_pb2.Vector3()
        agimbal.x = x
        agimbal.y = y
        agimbal.z = z
        publish3.Publish(agimbal)

    def pub1(self):
        while True: 
            self.sent_path1(10, 0, -20, 0 )
            self.sent_gimbal1(0,-33,0)

class Publish2:
    def sent_path2(self, x, y, z, yawrate ):
        bpose = Pose_pb2.Pose()
        bpose.position.x = x
        bpose.position.y = y
        bpose.position.z = z
        bpose.orientation.x = yawrate
        publish4.Publish(bpose)

    def sent_gimbal2(self, x, y, z):
        bgimbal = Vector3_pb2.Vector3()
        bgimbal.x = x
        bgimbal.y = y
        bgimbal.z = z
        publish5.Publish(bgimbal)

    def pub2(self):
        while True: 
            self.sent_path2(10, 0, -20, 0 )
            self.sent_gimbal2(0,-31,0)          

def main(args):
    '''
    publish = Publish()
    thread_pub = threading.Thread(target = publish.pub)
    thread_pub.start()
    
    publish1 = Publish1()
    thread_pub1 = threading.Thread(target = publish1.pub1)
    thread_pub1.start()
    
    publish2 = Publish2()
    thread_pub2 = threading.Thread(target = publish2.pub2)
    thread_pub2.start()   
    n = input('')
    '''
    C_C = Control_Collect()
    C_C.Collector_data.flag = 4
    thread_sub = threading.Thread(target = C_C.sub)
    thread_sub.start()

    publish_s = Publish()
    publish1_s = Publish1()
    publish2_s = Publish2()
    
    while True: 
        publish_s.sent_path(10, 0, -20, 0 )
        publish_s.sent_gimbal(0,-35,0)

        publish1_s.sent_path1(10, 0, -20, 0 )
        publish1_s.sent_gimbal1(0,-33,0)

        publish2_s.sent_path2(10, 0, -20, 0 )
        publish2_s.sent_gimbal2(0,-31,0) 
        
        if C_C.Collector_data.flag == 1:
            print(C_C.Collector_data.flag)
            break

    print(os.getpid())
    os.system('taskkill /f /pid %s' % os.getpid())
    
if __name__ == '__main__':
    main(sys.argv)
