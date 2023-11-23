from site import abs_paths
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
#publish = node_.Advertise('FW_0', '/cjq/FW_0/path', Float32Array_pb2.Float32Array)
#publish1 = node_.Advertise('FW_0', '/cjq/FW_0/arm_angle_cmd', Vector3_pb2.Vector3)
publish = node_.Advertise('FW01_2', '/cjq/FW01_2/path', Float32Array_pb2.Float32Array)
publish1 = node_.Advertise('FW01_2', '/cjq/FW01_2/arm_angle_cmd', Vector3_pb2.Vector3)

#s_time = 0 
class Publish:
    def sent_path(self, num, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8, x9, y9, z9, x10, y10, z10, x11, y11, z11, x12, y12, z12, x13, y13, z13, x14, y14, z14, x15, y15, z15, x16, y16, z16, x17, y17, z17, x18, y18, z18, x19, y19, z19, x20, y20, z20, x21, y21, z21, x22, y22, z22, x23, y23, z23, x24, y24, z24, x25, y25, z25, x26, y26, z26, x27, y27, z27, x28, y28, z28, x29, y29, z29, x30, y30, z30):
        pose = Float32Array_pb2.Float32Array()
        pose.data.append(num)
        pose.data.append(x1)
        pose.data.append(y1)
        pose.data.append(z1)
        pose.data.append(x2)
        pose.data.append(y2)
        pose.data.append(z2)
        pose.data.append(x3)
        pose.data.append(y3)
        pose.data.append(z3)
        pose.data.append(x4)
        pose.data.append(y4)
        pose.data.append(z4)
        pose.data.append(x5)
        pose.data.append(y5)
        pose.data.append(z5)
        pose.data.append(x6)
        pose.data.append(y6)
        pose.data.append(z6)
        pose.data.append(x7)
        pose.data.append(y7)
        pose.data.append(z7)
        pose.data.append(x8)
        pose.data.append(y8)
        pose.data.append(z8)
        pose.data.append(x9)
        pose.data.append(y9)
        pose.data.append(z9)
        pose.data.append(x10)
        pose.data.append(y10)
        pose.data.append(z10)
        pose.data.append(x11)
        pose.data.append(y11)
        pose.data.append(z11)       
        pose.data.append(x12)
        pose.data.append(y12)
        pose.data.append(z12)
        pose.data.append(x13)
        pose.data.append(y13)
        pose.data.append(z13)
        pose.data.append(x14)
        pose.data.append(y14)
        pose.data.append(z14)
        pose.data.append(x15)
        pose.data.append(y15)
        pose.data.append(z15)
        pose.data.append(x16)
        pose.data.append(y16)
        pose.data.append(z16)
        pose.data.append(x17)
        pose.data.append(y17)
        pose.data.append(z17)
        pose.data.append(x18)
        pose.data.append(y18)
        pose.data.append(z18)
        pose.data.append(x19)
        pose.data.append(y19)
        pose.data.append(z19)
        pose.data.append(x20)
        pose.data.append(y20)
        pose.data.append(z20)
        pose.data.append(x21)
        pose.data.append(y21)
        pose.data.append(z21)
        pose.data.append(x22)
        pose.data.append(y22)
        pose.data.append(z22)
        pose.data.append(x23)
        pose.data.append(y23)
        pose.data.append(z23)
        pose.data.append(x24)
        pose.data.append(y24)
        pose.data.append(z24)
        pose.data.append(x25)
        pose.data.append(y25)
        pose.data.append(z25)
        pose.data.append(x26)
        pose.data.append(y26)
        pose.data.append(z26)
        pose.data.append(x27)
        pose.data.append(y27)
        pose.data.append(z27)
        pose.data.append(x28)
        pose.data.append(y28)
        pose.data.append(z28)
        pose.data.append(x29)
        pose.data.append(y29)
        pose.data.append(z29)
        pose.data.append(x30)
        pose.data.append(y30)
        pose.data.append(z30)

        publish.Publish(pose)

    def sent_arm(self, x, y, z):
        arm = Vector3_pb2.Vector3()
        arm.x = x
        arm.y = y
        arm.z = z
        publish1.Publish(arm)

    def pub(self):
        while True: 
            self.sent_path(12, 0,0,0, 250,0,75, 500,0,150, 1300,0,150, 1300,-800,150, 500,-800,150, 500,0,150, 1300,0,150, 1300,-800,150, 500,-800,150, 250,-400,75, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0 )
            self.sent_arm(0,-60,0)
            
def main(args):
    publish = Publish()
    thread_pub = threading.Thread(target = publish.pub)
    thread_pub.start()
    
    n = input('')

if __name__ == '__main__':
    main(sys.argv)
