from pb.ros.geometry_msgs import Transform_pb2
from pb.ros.geometry_msgs import Twist_pb2
from pb.ros.geometry_msgs import Pose_pb2
from pb.ros.custom_msgs import CustomTransform_pb2
from pb.ros.custom_msgs import Float32Array_pb2
import math
import proxy
import json
# import rosproxy
import os
import time
import socket
import struct
from ctypes import *
import math
import threading
import sys

with open('..\\..\\..\\config.json', 'r') as f:
    Config = json.load(f)
    ip = Config['ip']
    envid = Config['envid']

node = proxy.Connector(f'{ip}' + ':15555')

publish = node.Advertise(f'{envid}', 'CW01_1', '/' + f'{envid}' + '/CW01_1/pose', Pose_pb2.Pose)

# publish_cmd_goal = node.Advertise(f'{envid}', 'CW01_1', '/' + f'{envid}' + '/CW01_1/cmd_goal', Pose_pb2.Pose)
#
# publish1 = node.Advertise(f'{envid}', 'CW01_0', '/' + f'{envid}' + '/CW01_0/pose', Pose_pb2.Pose)
#
# publish_cmd_goal1 = node.Advertise(f'{envid}', 'CW01_0', '/' + f'{envid}' + '/CW01_0/cmd_goal', Pose_pb2.Pose)
print("开始复合翼")


# class Publish1:
#     def cmd(self, model, vx, height, yaw):
#         cmd = Pose_pb2.Pose()
#         cmd.position.x = model  # model 1：多旋翼模式 2：固定翼模式
#         cmd.position.y = vx  # vx 固定翼模式 平飞速度
#         cmd.position.z = height  # height 多旋翼模式 上升高度
#         cmd.orientation.x = yaw  # yaw 弧度制  固定翼模式 偏转
#         publish1.Publish(cmd)
#
#     def pub(self):
#         # 上升
#         model = 1
#         vx = 1
#         height = -50
#         yaw = 0
#         self.cmd(model, vx, height, yaw)
#         print("上升")
#         time.sleep(10)
#
#         # 巡航-转圈
#         model = 2
#         vx = 10
#         height = -50
#         yaw = 0.314159
#         self.cmd(model, vx, height, yaw)
#         print("转圈")
#         time.sleep(30)
#
#         # 巡航——平飞
#         model = 2
#         vx = 10
#         height = -50
#         yaw = 0
#         self.cmd(model, vx, height, yaw)
#         print("平飞")
#         time.sleep(10)
#
#         # 降落
#         model = 1
#         vx = 0
#         height = -20
#         yaw = 0
#         self.cmd(model, vx, height, yaw)
#         print("降落")
#         time.sleep(10)
#

class Publish:
    def cmd(self, model, vx, height, yaw):
        cmd = Pose_pb2.Pose()
        cmd.position.x = model  # model 1：多旋翼模式 2：固定翼模式
        cmd.position.y = vx  # vx 固定翼模式 平飞速度
        cmd.position.z = height  # height 多旋翼模式 上升高度
        cmd.orientation.x = yaw  # yaw 弧度制  固定翼模式 偏转
        publish.Publish(cmd)

    def pub(self):
        # 上升
        print("上升")
        model = 1
        vx = 1
        height = -50
        yaw = 0
        self.cmd(model, vx, height, yaw)
        time.sleep(10)

        # 巡航-转圈
        print("转圈")
        model = 2
        vx = 10
        height = -50
        yaw = 0.314159
        self.cmd(model, vx, height, yaw)
        time.sleep(30)

        # 巡航——平飞
        print("平飞")
        model = 2
        vx = 10
        height = -50
        yaw = 0
        self.cmd(model, vx, height, yaw)
        time.sleep(10)

        # 降落
        print("降落")
        model = 1
        vx = 0
        height = -20
        yaw = 0
        self.cmd(model, vx, height, yaw)
        time.sleep(10)


def main(args):
    publish = Publish()
    # publish1 = Publish1()
    thread_pub = threading.Thread(target=publish.pub)
    thread_pub.start()
    # thread_pub = threading.Thread(target=publish1.pub)
    # thread_pub.start()
    # thread_pub_cmdgoal = threading.Thread(target=)
    time.sleep(65)
    # os.system('taskkill /f /pid %s' % os.getpid())
    # n = input('')


if __name__ == '__main__':
    main(sys.argv)
