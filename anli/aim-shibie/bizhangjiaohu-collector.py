import os
import sys
from pb.ros.data_control_msgs import Collector_new_pb2
import proxy
import time
from ctypes import *
import threading
import signal
import multiprocessing


#node_ = proxy.Node('collector','tcp://12.12.12.205:6004','tcp://12.12.12.205:7004')
#node_ = proxy.Node('collector','tcp://12.12.12.205:6021','tcp://12.12.12.205:7021')
node_ = proxy.Connector('tcp://12.12.12.204:15555')

class Control_Collect:

    def __init__(self):

        self.subscriber = node_.Subscribe("data","command",'/collector',Collector_new_pb2.Collector,self.callback)

        self.Collector_data = Collector_new_pb2.Collector()


    def callback(self,data):

        self.Collector_data = data


    def sub(self):
        while 1:
            self.subscriber.SpinOnce()


def main(args):
    C_C = Control_Collect()
    C_C.Collector_data.flag = 4
    thread_sub = threading.Thread(target = C_C.sub)
    thread_sub.start()

    while 1:
        if C_C.Collector_data.env == "FK" and (C_C.Collector_data.flag == 0 or C_C.Collector_data.flag == 2):
            print(C_C.Collector_data.flag)
            print(C_C.Collector_data.env)
            print(C_C.Collector_data.time)
            #time.sleep(6)      
            os.system('D:\\jingshen\\Dy\\aim-shibie\\7huizongjiaohu.bat')
            time.sleep(70)
            print("123")
            os.system('D:\\jingshen\\Dy\\aim-shibie\\6M300_yonghu-pubjiaohubizhang.bat')
            break
            
    print(os.getpid())
    os.system('taskkill /f /pid %s' % os.getpid())
   


if __name__ == '__main__':
    main(sys.argv)


