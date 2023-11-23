import os
import sys
from pb.ros.data_control_msgs import Collector_new_pb2
import proxy
import logging
import time
import json
from ctypes import *
import threading
import subprocess
import signal
import multiprocessing

# node_ = proxy.Node('collector','tcp://12.12.12.205:6004','tcp://12.12.12.205:7004')
# node_ = proxy.Node('collector','tcp://12.12.12.205:6021','tcp://12.12.12.205:7021')
logging.basicConfig(level=logging.INFO,
                    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                    filename='app.log')


# node_ = proxy.Connector('tcp://12.12.12.204:15555')
# with open('config.json', 'r') as f:
#     Config = json.load(f)
#     envid = Config["envid"]
# with open('FuHeYiExecuteScript.json', 'r') as s:
#     FuHeYiExecuteScript = json.load(s)
#
#     print(FuHeYiExecuteScript["scripts"][0])
#     logging.info("Hello world")


# result = subprocess.run(["ls", "-l"], stdout=subprocess.PIPE)
# def run_file1():
#     os.system('python {}'.format(FuHeYiExecuteScript["scripts"][0]))
#
#
# def run_file2():
#     os.system('python {}'.format(FuHeYiExecuteScript["scripts"][1]))
#
#
# def run_file3():
#     os.system('python {}'.format(FuHeYiExecuteScript["scripts"][2]))
#
#
# def run_file4():
#     os.system('python {}'.format(FuHeYiExecuteScript["scripts"][3]))
#
#
# def run_file5():
#     os.system('python {}'.format(FuHeYiExecuteScript["scripts"][4]))
#
#
# def run_file6():
#     os.system('python {}'.format(FuHeYiExecuteScript["scripts"][5]))
#
#
# t1 = threading.Thread(target=run_file1)
# t2 = threading.Thread(target=run_file2)
# t3 = threading.Thread(target=run_file3)
# t4 = threading.Thread(target=run_file4)
# t5 = threading.Thread(target=run_file5)
# t6 = threading.Thread(target=run_file6)


def run_file6():
    time.sleep(60)
    os.system('6qidong.bat')


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
M300pub = threading.Thread(target=run_file6)


def main(args):
    # C_C = Control_Collect()
    # C_C.Collector_data.flag = 4
    # thread_sub = threading.Thread(target=C_C.sub)
    # thread_sub.start()

    # while 1:
    #     if C_C.Collector_data.env == f"{envid}" and (C_C.Collector_data.flag == 0 or C_C.Collector_data.flag == 2):
    #         print(C_C.Collector_data.flag)
    #         print(C_C.Collector_data.env)
    #         print(C_C.Collector_data.time)
    # time.sleep(6)
    # time.sleep(5)
    os.system('7huizongjiaohu.bat')
    M300pub.start()

    os.system('fuheyi.bat')

    # os.system('D:\\jingshen\\Dy\\aim-shibie\\6M300_yonghu-pubjiaohubizhang.bat')
    print("qidong")
    # os.system('D:\\jingshen\\Dy\\aim-shibie\\6M300_yonghu-pub.bat')
    # os.system('python .\\command\\M300-pubnew-mult.py')
    # break

    input('Press Enter to exit...')

    sys.exit()


# print(os.getpid())
# os.system('taskkill /f /pid %s' % os.getpid())


if __name__ == '__main__':
    main(sys.argv)
