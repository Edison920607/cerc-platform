import os
import sys
from pb.ros.data_control_msgs import Collector_new_pb2
import proxy
import time
import json
import msvcrt
from ctypes import *
import threading
import subprocess
from pb.ros.custom_msgs import CustomCommunication_pb2
from pb.ros.custom_msgs import CustomCommunicationLinks_pb2
import signal
import multiprocessing


# node_ = proxy.Node('collector','tcp://12.12.12.205:6004','tcp://12.12.12.205:7004')
# node_ = proxy.Node('collector','tcp://12.12.12.205:6021','tcp://12.12.12.205:7021')
# node_ = proxy.Connector('tcp://12.12.12.204:15555')
#


# class Control_Collect:
#
#     def __init__(self):
#         self.subscriber = node_.Subscribe("data", "command", '/collector', Collector_new_pb2.Collector, self.callback)
#
#         self.Collector_data = Collector_new_pb2.Collector()
#
#     def callback(self, data):
#         self.Collector_data = data
#
#     def sub(self):
#         while 1:
#             self.subscriber.SpinOnce()


def run_file6():
    time.sleep(60)
    os.system('6qidong.bat')
    print("6qidong")


def run_script():
    subprocess.call(["python", "tongxinjiehsou.py"])
    print("tongxinqidong")


# 3
# C_C = Control_Collect()
# C_C.Collector_data.flag = 4
# thread_sub = threading.Thread(target=C_C.sub)
# thread_sub.start()
# print("Press any key to exit...")
# print(C_C.Collector_data.flag)
# print(C_C.Collector_data.env)
# print(C_C.Collector_data.time)
# time.sleep(6)


# print(os.getpid())
# os.system('taskkill /f /pid %s' % os.getpid())
def main():
    os.system('7huizongjiaohu.bat')
    M300pub = threading.Thread(target=run_file6)
    # communicationSub = threading.Thread(target=subscribe(communicationSubscribe))
    tongxinpy = threading.Thread(target=run_script)
    M300pub.start()
    tongxinpy.start()
    # communicationSub.start()
    print("123")
    # communicationSub.join()
    M300pub.join()


if __name__ == '__main__':
    main()
