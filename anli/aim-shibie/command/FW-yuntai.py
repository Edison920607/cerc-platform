from pb.ros.geometry_msgs import Transform_pb2
from pb.ros.geometry_msgs import Twist_pb2
from pb.ros.geometry_msgs import Vector3_pb2
from pb.ros.custom_msgs import CustomTransform_pb2
from pb.ros.custom_msgs import Float32Array_pb2
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

node_ = proxy.Node('cjq', 'tcp://12.12.12.205:6001', 'tcp://12.12.12.205:7001')
#publish1 = node_.Advertise('FW_0', '/cjq/FW_0/arm_angle_cmd', Vector3_pb2.Vector3)
publish1 = node_.Advertise('FW01_2', '/cjq/FW01_2/arm_angle_cmd', Vector3_pb2.Vector3)

#s_time = 0 
class Publish:
    
    def sent_arm(self, x, y, z):
        arm = Vector3_pb2.Vector3()
        arm.x = x
        arm.y = y
        arm.z = z
        publish1.Publish(arm)

    def pub(self):
        while True: 
            self.sent_arm(0,-60,0)
            
def main(args):
    publish = Publish()
    thread_pub = threading.Thread(target = publish.pub)
    thread_pub.start()
    
    n = input('')

if __name__ == '__main__':
    main(sys.argv)
