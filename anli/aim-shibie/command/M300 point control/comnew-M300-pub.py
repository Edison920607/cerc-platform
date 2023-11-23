from pb.ros.geometry_msgs import Transform_pb2
from pb.ros.geometry_msgs import Twist_pb2
from pb.ros.geometry_msgs import Point_pb2
from pb.ros.geometry_msgs import Pose_pb2
from pb.ros.custom_msgs import CustomTransform_pb2
from pb.ros.custom_msgs import Float32Array_pb2
from pb.ros.data_control_msgs import Collector_new_pb2
import proxy
import os
import time
import socket
import struct
import json
from ctypes import *
import math
import threading
import sys
import matlab.engine
import signal

with open('..\\..\\..\\config.json', 'r') as f:
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

#                           场景名称    IP地址及通信发送端口          IP地址及通信接收端口 
publish0_ = node_.Advertise(f'{envid}', 'M300_0', '/' + f'{envid}' + '/M300_0/transform', CustomTransform_pb2.CustomTransform)
publish1_ = node_.Advertise(f'{envid}', 'M300_1', '/' + f'{envid}' + '/M300_1/transform', CustomTransform_pb2.CustomTransform)
publish2_ = node_.Advertise(f'{envid}', 'M300_2', '/' + f'{envid}' + '/M300_2/transform', CustomTransform_pb2.CustomTransform)
#                   第几架无人机 0开始  /场景名/第几架无人机/话题名   消息体
localsend0 = ("127.0.0.1", 15001)
localsend1 = ("127.0.0.1", 15003)
localsend2 = ("127.0.0.1", 15005)


#              使用本机IP  UDP端口：需要与动力学模型中保持一致，一般为150xx奇数，便于区分


# class Control_Collect:

    # def __init__(self):
    #     self.subscriber = node1.Subscribe("data", "command", '/collector', Collector_new_pb2.Collector, self.callback)
    #
    #     self.Collector_data = Collector_new_pb2.Collector()
    #
    # def callback(self, data):
    #     self.Collector_data = data
    #
    # def sub(self):
    #     while 1:
    #         self.subscriber.SpinOnce()


class DataSend0(Structure):
    _pack_ = 1
    _fields_ = [("member_0", c_double),
                ("member_1", c_double),
                ("member_2", c_double),
                ("member_3", c_double),
                ("member_4", c_double),
                ("member_5", c_double)]


datasend0 = DataSend0()


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


class Publish:
    def sent_UE0(self, x, y, z, roll, pitch, yaw):
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
        publish0_.Publish(aTransform)

    def sent_UE1(self, x, y, z, roll, pitch, yaw):
        bTransform = CustomTransform_pb2.CustomTransform()
        bTransform.translation.x = x
        bTransform.translation.y = y
        bTransform.translation.z = z
        bTransform.rotation.x = roll
        bTransform.rotation.y = pitch
        bTransform.rotation.z = yaw
        bTransform.motor_speed.data.append(1000)
        bTransform.motor_speed.data.append(1000)
        bTransform.motor_speed.data.append(1000)
        bTransform.motor_speed.data.append(1000)
        publish1_.Publish(bTransform)

    def sent_UE2(self, x, y, z, roll, pitch, yaw):
        cTransform = CustomTransform_pb2.CustomTransform()
        cTransform.translation.x = x
        cTransform.translation.y = y
        cTransform.translation.z = z
        cTransform.rotation.x = roll
        cTransform.rotation.y = pitch
        cTransform.rotation.z = yaw
        cTransform.motor_speed.data.append(1000)
        cTransform.motor_speed.data.append(1000)
        cTransform.motor_speed.data.append(1000)
        cTransform.motor_speed.data.append(1000)
        publish2_.Publish(cTransform)

    def pub0(self):
        send0 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        send0.bind(localsend0)
        while True:
            message0, client0 = send0.recvfrom(1024)
            memmove(addressof(datasend0), (message0), sizeof(DataSend0))
            self.sent_UE0(datasend0.member_0, datasend0.member_1, datasend0.member_2, datasend0.member_3,
                          datasend0.member_4, datasend0.member_5)

    def pub1(self):
        send1 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        send1.bind(localsend1)
        while True:
            message1, client1 = send1.recvfrom(1024)
            memmove(addressof(datasend1), (message1), sizeof(DataSend1))
            self.sent_UE1(datasend1.member_0, datasend1.member_1, datasend1.member_2, datasend1.member_3,
                          datasend1.member_4, datasend1.member_5)

    def pub2(self):
        send2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        send2.bind(localsend2)
        while True:
            message2, client2 = send2.recvfrom(1024)
            memmove(addressof(datasend2), (message2), sizeof(DataSend2))
            self.sent_UE2(datasend2.member_0, datasend2.member_1, datasend2.member_2, datasend2.member_3,
                          datasend2.member_4, datasend2.member_5)


def main(args):
    engine = matlab.engine.start_matlab()
    engine.Init_control(nargout=0)
    engine.simstart(nargout=0)
    publish_s = Publish()
    '''
    thread_pub0 = threading.Thread(target = publish.pub0)
    thread_pub0.start()
    thread_pub1 = threading.Thread(target = publish.pub1)
    thread_pub1.start()
    thread_pub2 = threading.Thread(target = publish.pub2)
    thread_pub2.start()
    '''

    # C_C = Control_Collect()
    # C_C.Collector_data.flag = 4
    # thread_sub = threading.Thread(target=C_C.sub)
    # thread_sub.start()

    send0 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    send0.bind(localsend0)

    send1 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    send1.bind(localsend1)

    send2 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    send2.bind(localsend2)

    while True:
        message0, client0 = send0.recvfrom(1024)
        message1, client1 = send1.recvfrom(1024)
        message2, client2 = send2.recvfrom(1024)
        memmove(addressof(datasend0), (message0), sizeof(DataSend0))
        memmove(addressof(datasend1), (message1), sizeof(DataSend1))
        memmove(addressof(datasend2), (message2), sizeof(DataSend2))
        publish_s.sent_UE0(datasend0.member_0, datasend0.member_1, datasend0.member_2, datasend0.member_3,
                           datasend0.member_4, datasend0.member_5)
        publish_s.sent_UE1(datasend1.member_0, datasend1.member_1, datasend1.member_2, datasend1.member_3,
                           datasend1.member_4, datasend1.member_5)
        publish_s.sent_UE2(datasend2.member_0, datasend2.member_1, datasend2.member_2, datasend2.member_3,
                           datasend2.member_4, datasend2.member_5)

    #     if C_C.Collector_data.env == "FK" and C_C.Collector_data.flag == 1:
    #         print(C_C.Collector_data.flag)
    #         break
    #
    # # n = input('')
    # print(os.getpid())
    # os.system('taskkill /f /pid %s' % os.getpid())


if __name__ == '__main__':
    main(sys.argv)
