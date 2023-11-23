from pb.ros.geometry_msgs import Transform_pb2
from pb.ros.geometry_msgs import Pose_pb2
from pb.ros.geometry_msgs import Vector3_pb2
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

node_ = proxy.Node('cjq', 'tcp://12.12.12.205:6001', 'tcp://12.12.12.205:7001')
publish1 = node_.Advertise('M300_0', '/cjq/M300_0/gimbal_angle_cmd', Vector3_pb2.Vector3)


#s_time = 0 
class Publish:
    def sent_gimbal(self, x, y, z):
        gimbal = Vector3_pb2.Vector3()
        gimbal.x = x
        gimbal.y = y
        gimbal.z = z
        publish1.Publish(gimbal)

    def pub(self):
        while True: 
            self.sent_gimbal(0,-30,0)
            

def main(args):
    publish = Publish()
    thread_pub = threading.Thread(target = publish.pub)
    thread_pub.start()
    
    n = input('')

if __name__ == '__main__':
    main(sys.argv)
