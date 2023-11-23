from pb.ros.geometry_msgs import PoseStamped_pb2
from pb.ros.geometry_msgs import Transform_pb2
from pb.ros.geometry_msgs import Pose_pb2
from pb.ros.custom_msgs import CustomTransform_pb2
from pb.ros.custom_msgs import Float32Array_pb2
from pb.ros.data_control_msgs import Collector_new_pb2
from pb.ros.std_msgs import Bool_pb2
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
import matlab.engine

with open('..\\..\\..\\config.json', 'r') as f:
    Config = json.load(f)
    envid = Config['envid']
    ip = Config['ip']
    print(Config['envid'])
    print(Config['ip'])

engine = matlab.engine.start_matlab()

print(dir(PoseStamped_pb2))

node = proxy.Connector(f'{ip}' + ':15555')

publish = node.Advertise(f'{envid}', 'CW01_0', '/' + f'{envid}' + '/CW01_0/transform',
                         CustomTransform_pb2.CustomTransform)

publish_jiaohu = node.Advertise(f'{envid}', 'CW01_0', '/' + f'{envid}' + '/CW01_0/cmd_goal',
                                PoseStamped_pb2.PoseStamped)
publish1 = node.Advertise(f'{envid}', 'CW01_1', '/' + f'{envid}' + '/CW01_0/transform',
                          CustomTransform_pb2.CustomTransform)

publish_jiaohu1 = node.Advertise(f'{envid}', 'CW01_1', '/' + f'{envid}' + '/CW01_0/cmd_goal',
                                 PoseStamped_pb2.PoseStamped)

localcmd = ("127.0.0.1", 35000)  # pose-cmd
localstate = ("127.0.0.1", 35001)  # state
localreceive0 = ("127.0.0.1", 35002)  # datareceive0
localstate0 = ("127.0.0.1", 35004)
localcmd0 = ("127.0.0.1", 35003)
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


def callback0(aPose):
    receive0 = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    datareceive0 = Cmd()
    # datareceive0.member_0 = aPose.position.x
    # datareceive0.member_1 = -aPose.position.y
    # datareceive0.member_2 = -aPose.position.z
    #
    # x = aPose.orientation.x
    # y = aPose.orientation.y
    # z = aPose.orientation.z
    # w = aPose.orientation.w
    #
    # t0 = +2.0 * (w * x + y * z)
    # t1 = +1.0 - 2.0 * (x * x + y * y)
    # roll_x = math.atan2(t0, t1)
    #
    # t2 = +2.0 * (w * y - z * x)
    # t2 = +1.0 if t2 > +1.0 else t2
    # t2 = -1.0 if t2 < -1.0 else t2
    # pitch_y = math.asin(t2)
    #
    # t3 = +2.0 * (w * z + x * y)
    # t4 = +1.0 - 2.0 * (y * y + z * z)
    # yaw_z = math.atan2(t3, t4)
    #
    # datareceive0.member_3 = -yaw_z
    #
    #
    # receive0.sendto(datareceive0, localreceive0)
    # print( datareceive0.member_0)
    datareceive0.member_0 = aPose.pose.position.x  # model
    datareceive0.member_1 = aPose.pose.position.y  # vx
    datareceive0.member_2 = aPose.pose.position.z  # height
    datareceive0.member_3 = aPose.pose.orientation.x  # yaw 弧度制
    receive0.sendto(datareceive0, localcmd)
    print(datareceive0.member_0)
def callback(Pose):
    receive = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    cmd = Cmd()
    cmd.member_0 = Pose.position.x  # model
    cmd.member_1 = Pose.position.y  # vx
    cmd.member_2 = Pose.position.z  # height
    cmd.member_3 = Pose.orientation.x  # yaw 弧度制
    receive.sendto(cmd, localcmd)

# pose-cmd
def callback1(Pose):
    receive = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    cmd = Cmd()
    cmd.member_0 = Pose.position.x  # model
    cmd.member_1 = Pose.position.y  # vx
    cmd.member_2 = Pose.position.z  # height
    cmd.member_3 = Pose.orientation.x  # yaw 弧度制
    receive.sendto(cmd, localcmd0)


subscriber = node.Subscribe(f'{envid}', 'CW01_1', '/' + f'{envid}' + '/CW01_1/pose', Pose_pb2.Pose, callback)

subscriber_jiaohu = node.Subscribe(f'{envid}', 'CW01_1', '/' + f'{envid}' + '/CW01_1/cmd_goal',
                                   PoseStamped_pb2.PoseStamped, callback0)
subscriber1 = node.Subscribe(f'{envid}', 'CW01_0', '/' + f'{envid}' + '/CW01_0/pose', Pose_pb2.Pose, callback1)

subscriber_jiaohu1 = node.Subscribe(f'{envid}', 'CW01_0', '/' + f'{envid}' + '/CW01_0/cmd_goal',
                                    PoseStamped_pb2.PoseStamped, callback0)


def sub():
    while 1:
        subscriber.SpinOnce()

        #subscriber_jiaohu.SpinOnce()
        # s_time = 0
        # subscriber1.SpinOnce()
        #
        # subscriber_jiaohu1.SpinOnce()

class Publish0:
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
        send.bind(localstate0)
        while True:
            message, client = send.recvfrom(1024)
            memmove(addressof(datasend), (message), sizeof(DataSend))
            self.sent_UE4(datasend.member_0, datasend.member_1, datasend.member_2, datasend.member_3, datasend.member_4,
                          datasend.member_5)
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
            self.sent_UE4(datasend.member_0, datasend.member_1, datasend.member_2, datasend.member_3, datasend.member_4,
                          datasend.member_5)


class Publish_cmd_goal:
    def sent_UE4(self, x, y, z, roll, pitch, yaw):
        aTransform = CustomTransform_pb2.CustomTransform()
        aTransform.translation.x = x
        aTransform.translation.y = y
        aTransform.translation.z = z
        aTransform.rotation.x = roll
        aTransform.rotation.y = pitch
        aTransform.rotation.z = yaw
        publish_jiaohu.Publish(aTransform)

    def pub(self):
        send = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        send.bind(localcmd)
        while True:
            message, client = send.recvfrom(1024)
            memmove(addressof(datasend), (message), sizeof(DataSend))
            self.sent_UE4(datasend.member_0, datasend.member_1, datasend.member_2, datasend.member_3, datasend.member_4,
                          datasend.member_5)


def main(args):
    engine.Init_control(nargout=0)
    engine.Init_0(nargout=0)
    engine.simstart(nargout=0)

    publish = Publish()
    #publish_cmdgoal = Publish_cmd_goal()

    thread_pub = threading.Thread(target=publish.pub)
    thread_pub.start()


    # thread_pub = threading.Thread(target=publish_cmdgoal.pub)
    # thread_pub.start()

    thread_sub = threading.Thread(target=sub)
    thread_sub.start()

    while thread_sub.is_alive():
        if thread_sub.is_alive():
            time.sleep(5)
            print("Thread is still running")
        else:
            print("Thread has exited")

    n = input('')


if __name__ == '__main__':
    main(sys.argv)
