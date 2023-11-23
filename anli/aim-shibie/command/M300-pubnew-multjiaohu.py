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
import json
import struct
from ctypes import *
import math
import threading
import sys
import signal

with open('..\\..\\config.json', 'r', encoding='utf-8') as f:
    Config = json.load(f)
    envid = Config['envid']
    ip = Config['ip']
    print(envid)
    print(ip)
    print(Config['Port'])
# node_ = proxy.Node('FK', 'tcp://12.12.12.205:6006', 'tcp://12.12.12.205:7006')
# node1 = proxy.Node('collector','tcp://12.12.12.205:6004','tcp://12.12.12.205:7004')
# node_ = proxy.Node('FK', 'tcp://12.12.12.205:6021', 'tcp://12.12.12.205:7021')
# node1 = proxy.Node('collector','tcp://12.12.12.205:6021','tcp://12.12.12.205:7021')
node_ = proxy.Connector(f'{ip}' + ':15555')
node1 = proxy.Connector(f'{ip}' + ':15555')

publish = node_.Advertise(f'{envid}', 'M300_0', '/' + f'{envid}' + '/M300_0/pose', Pose_pb2.Pose)
publish1 = node_.Advertise(f'{envid}', 'M300_0', '/' + f'{envid}' + '/M300_0/gimbal_angle_cmd', Vector3_pb2.Vector3)
publish2 = node_.Advertise(f'{envid}', 'M300_1', '/' + f'{envid}' + '/M300_1/pose', Pose_pb2.Pose)
publish3 = node_.Advertise(f'{envid}', 'M300_1', '/' + f'{envid}' + '/M300_1/gimbal_angle_cmd', Vector3_pb2.Vector3)
publish4 = node_.Advertise(f'{envid}', 'M300_2', '/' + f'{envid}' + '/M300_2/pose', Pose_pb2.Pose)
publish5 = node_.Advertise(f'{envid}', 'M300_2', '/' + f'{envid}' + '/M300_2/gimbal_angle_cmd', Vector3_pb2.Vector3)


# s_time = 0


# class Control_Collect:
#
#     def __init__(self):
#         self.subscriber = node1.Subscribe("data", "command", '/collector', Collector_new_pb2.Collector, self.callback)
#
#         self.Collector_data = Collector_new_pb2.Collector()
#
#     def callback(self, data):
#         self.Collector_data = data
#
#     def sub(self):
#         while 1:
#             self.subscriber.SpinOnce()


class Publish:
    def sent_path(self, x, y, z, yawrate):
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
            self.sent_path(10, 0, -20, 0)
            self.sent_gimbal(0, -35, 0)


class Publish1:

    def sent_path1(self, x, y, z, yawrate):
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
            self.sent_path1(10, 0, -20, 0)
            self.sent_gimbal1(0, -33, 0)


class Publish2:
    def sent_path2(self, x, y, z, yawrate):
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
            self.sent_path2(10, 0, -20, 0)
            self.sent_gimbal2(0, -31, 0)


def main(args):
    # C_C = Control_Collect()
    # C_C.Collector_data.flag = 4
    # thread_sub = threading.Thread(target=C_C.sub)
    # thread_sub.start()

    publish_s = Publish()
    publish1_s = Publish1()
    publish2_s = Publish2()

    publish_s.sent_path(0, 0, -15, 0)
    publish_s.sent_gimbal(0, -35, 0)

    publish1_s.sent_path1(0, 0, -15, 0)
    publish1_s.sent_gimbal1(0, -33, 0)

    publish2_s.sent_path2(0, 0, -15, 0)
    publish2_s.sent_gimbal2(0, -31, 0)
    time.sleep(10)  #### 悬停起飞

    input('Press Enter to exit...')

    sys.exit()

    ''' 
    publish_s.sent_path(197, -415, 80, 0)
    publish_s.sent_gimbal(0, -35, 0)
    publish1_s.sent_path1(-90, -137, 80, 0)
    publish1_s.sent_gimbal1(0, -33, 0)
    publish2_s.sent_path2(-506, -167, 80, 0)
    publish2_s.sent_gimbal2(0, -31, 0)
    time.sleep(35)  ####飞去目标点

    publish_s.sent_path(197, -415, 80, 1.9)
    publish_s.sent_gimbal(0, -82, 159)
    publish1_s.sent_path1(-90, -137, 80, -1.9182)
    publish1_s.sent_gimbal1(0, -82, -109)
    publish2_s.sent_path2(-506, -167, 80, 1.1683)
    publish2_s.sent_gimbal2(0, -82, 70)
    time.sleep(35)  ### 目标点

    publish_s.sent_path(0, 0, 60, 0)
    publish_s.sent_gimbal(0, -35, 0)
    publish1_s.sent_path1(0, 0, 60, 0)
    publish1_s.sent_gimbal1(0, -33, 0)
    publish2_s.sent_path2(0, 0, 60, 0)
    publish2_s.sent_gimbal2(0, -31, 0)
    time.sleep(27)  ### 撤离回原点

    publish_s.sent_path(0, 0, 1, 0)
    publish_s.sent_gimbal(0, -35, 0)
    publish1_s.sent_path1(0, 0, 1, 0)
    publish1_s.sent_gimbal1(0, -33, 0)
    publish2_s.sent_path2(0, 0, 1, 0)
    publish2_s.sent_gimbal2(0, -31, 0)
    time.sleep(3)  ####降落
    '''

    '''
    publish_s.sent_path(0, 0, -20, 0)
    publish_s.sent_gimbal(0 ,-10 , -10)
    publish1_s.sent_path1(0, 0, -20, 0)
    publish1_s.sent_gimbal1(0, -10, -10)
    publish2_s.sent_path2(0, 0, -20, 0)
    publish2_s.sent_gimbal2(0, -10, -10) 
    time.sleep(3)

    publish_s.sent_path(0, 0, -20, 1.56232)
    publish_s.sent_gimbal(0 , -10 , 42)
    publish1_s.sent_path1(0, 0, -20, 1.56352)
    publish1_s.sent_gimbal1(0, -10, 42)
    publish2_s.sent_path2(0, 0, -20, 1.56232)
    publish2_s.sent_gimbal2(0, -10, 42)
    time.sleep(6)
    
    publish_s.sent_path(350, -370, -60, 2.1255)
    publish_s.sent_gimbal(0, -30, -57)

    publish1_s.sent_path1(-40, -345, -60, 1.56232)
    publish1_s.sent_gimbal1(0, -30, 42)

    publish2_s.sent_path2(-430, -350, -60, 1.4252)
    publish2_s.sent_gimbal2(0, -30, 32)

    time.sleep(27)
    publish_s.sent_path(350, -370, -20, 1.56232)
    publish_s.sent_gimbal(0,-18,125)
    publish1_s.sent_path1(-40, -345, -20, 1.56232)
    publish1_s.sent_gimbal1(0,-28,58)
    publish2_s.sent_path2(-430, -350, -20, 1.5423)
    publish2_s.sent_gimbal2(0,-36,51)

    
    while True: 
        #publish_s.sent_path(10, 0, -20, 0 )
        publish_s.sent_path(350, -370, -60, 1.56232)
        publish_s.sent_gimbal(0,-35,0)

        #publish1_s.sent_path1(10, 0, -20, 0 )
        publish1_s.sent_path1(-40, -345, -60, 1.56232 )
        publish1_s.sent_gimbal1(0,-33,0)

        #publish2_s.sent_path2(10, 0, -20, 0 )
        publish2_s.sent_path2(-430, -350, -60, 1.56232 )
        publish2_s.sent_gimbal2(0,-31,0) 
        
        if C_C.Collector_data.flag == 1:
            print(C_C.Collector_data.flag)
            break
    '''
    # while True:
    #     if C_C.Collector_data.env == "FK" and C_C.Collector_data.flag == 1:
    #         print(C_C.Collector_data.flag)
    #         break

    # print(os.getpid())
    # os.system('taskkill /f /pid %s' % os.getpid())


if __name__ == '__main__':
    main(sys.argv)
