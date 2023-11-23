import os
import sys
from pb.ros.data_control_msgs import Collector_new_pb2
import proxy
import time
import json
import msvcrt
from ctypes import *
import threading
import signal
import multiprocessing

# node_ = proxy.Node('collector','tcp://12.12.12.205:6004','tcp://12.12.12.205:7004')
# node_ = proxy.Node('collector','tcp://12.12.12.205:6021','tcp://12.12.12.205:7021')
# node_ = proxy.Connector('tcp://12.12.12.204:15555')
#
# with open('config.json', 'r') as f:
#     Config = json.load(f)
#     envid = Config['envid']


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


#3
# C_C = Control_Collect()
# C_C.Collector_data.flag = 4
# thread_sub = threading.Thread(target=C_C.sub)
# thread_sub.start()
#print("Press any key to exit...")
# print(C_C.Collector_data.flag)
# print(C_C.Collector_data.env)
# print(C_C.Collector_data.time)
# time.sleep(6)
os.system('7huizongjiaohu.bat')
time.sleep(5)
print("123")
os.system('6qidong.bat')
input('Press Enter to exit...')

sys.exit()


    # print(os.getpid())
    # os.system('taskkill /f /pid %s' % os.getpid())


# if __name__ == '__main__':
#     main(sys.argv)
