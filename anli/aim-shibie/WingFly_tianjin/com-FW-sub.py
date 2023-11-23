import rosproxy
import os
import time
import socket
import struct
from ctypes import *
import math
import threading
import sys
import matlab.engine


rosproxy.proxy.Setup('cjq', 'tcp://12.12.12.205:6658', 'tcp://12.12.12.205:6687')
subcribe = rosproxy.proxy.Topic()
subcribe1 = rosproxy.proxy.Topic()
subcribe.Init('FW_0', '/cjq/FW_0/path', 'custom_msgs/Float32ArrayStamped', 10)

localreceive = ("127.0.0.1", 16000)
#localsend = ("127.0.0.1", 16001)

class Datareceive(Structure):
    _pack_ = 1  
    _fields_ = [("member_0", c_double),
                     ("member_1", c_double),
                     ("member_2", c_double),
                     ("member_3", c_double),
                     ("member_4", c_double),
                     ("member_5", c_double),
	     ("member_6", c_double),
                     ("member_7", c_double),
                     ("member_8", c_double),
                     ("member_9", c_double),
                     ("member_10", c_double),
                     ("member_11", c_double),
                     ("member_12", c_double),
                     ("member_13", c_double),
                     ("member_14", c_double),
                     ("member_15", c_double),
	     ("member_16", c_double),
                     ("member_17", c_double),
                     ("member_18", c_double),
                     ("member_19", c_double),
                     ("member_20", c_double),
                     ("member_21", c_double),
                     ("member_22", c_double),
                     ("member_23", c_double),
                     ("member_24", c_double),
                     ("member_25", c_double),
                     ("member_26", c_double),
                     ("member_27", c_double),
                     ("member_28", c_double),
                     ("member_29", c_double),
                     ("member_30", c_double),
                     ("member_31", c_double),
                     ("member_32", c_double),
                     ("member_33", c_double),
                     ("member_34", c_double),
                     ("member_35", c_double),
	     ("member_36", c_double),
                     ("member_37", c_double),
                     ("member_38", c_double),
                     ("member_39", c_double),
                     ("member_40", c_double),
                     ("member_41", c_double),
                     ("member_42", c_double),
                     ("member_43", c_double),
                     ("member_44", c_double),
                     ("member_45", c_double),
	     ("member_46", c_double),
                     ("member_47", c_double),
                     ("member_48", c_double),
                     ("member_49", c_double),
                     ("member_50", c_double),
                     ("member_51", c_double),
                     ("member_52", c_double),
                     ("member_53", c_double),
                     ("member_54", c_double),
                     ("member_55", c_double),
                     ("member_56", c_double),
                     ("member_57", c_double),
                     ("member_58", c_double),
                     ("member_59", c_double),
                     ("member_60", c_double),
                     ("member_61", c_double),
                     ("member_62", c_double),
                     ("member_63", c_double),
                     ("member_64", c_double),
                     ("member_65", c_double),
	     ("member_66", c_double),
                     ("member_67", c_double),
                     ("member_68", c_double),
                     ("member_69", c_double),
                     ("member_70", c_double),
                     ("member_71", c_double),
                     ("member_72", c_double),
                     ("member_73", c_double),
                     ("member_74", c_double),
                     ("member_75", c_double),
	     ("member_76", c_double),
                     ("member_77", c_double),
                     ("member_78", c_double),
                     ("member_79", c_double),
                     ("member_80", c_double),
                     ("member_81", c_double),
                     ("member_82", c_double),
                     ("member_83", c_double),
                     ("member_84", c_double),
                     ("member_85", c_double),
                     ("member_86", c_double),
                     ("member_87", c_double),
                     ("member_88", c_double),
                     ("member_89", c_double),
                     ("member_90", c_double)]

def callback(Path):
    receive = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    datareceive = Datareceive( )  
    p_dist = [dist for dist in Path._Data]
    #print(p_dist) 
    datareceive.member_0 = p_dist[0]  
    datareceive.member_1 = p_dist[1] 
    datareceive.member_2 = p_dist[2]
    datareceive.member_3 = p_dist[3]
    datareceive.member_4 = p_dist[4]
    datareceive.member_5 = p_dist[5]
    datareceive.member_6 = p_dist[6]  
    datareceive.member_7 = p_dist[7] 
    datareceive.member_8 = p_dist[8]
    datareceive.member_9 = p_dist[9]
    datareceive.member_10 = p_dist[10]
    datareceive.member_11 = p_dist[11]
    datareceive.member_12 = p_dist[12]  
    datareceive.member_13 = p_dist[13] 
    datareceive.member_14 = p_dist[14]
    datareceive.member_15 = p_dist[15]
    datareceive.member_16 = p_dist[16]
    datareceive.member_17 = p_dist[17]
    datareceive.member_18 = p_dist[18]  
    datareceive.member_19 = p_dist[19] 
    datareceive.member_20 = p_dist[20]
    datareceive.member_21 = p_dist[21]
    datareceive.member_22 = p_dist[22]
    datareceive.member_23 = p_dist[23]
    datareceive.member_24 = p_dist[24]
    datareceive.member_25 = p_dist[25]
    datareceive.member_26 = p_dist[26]
    datareceive.member_27 = p_dist[27]
    datareceive.member_28 = p_dist[28]
    datareceive.member_29 = p_dist[29]
    datareceive.member_30 = p_dist[30]
    datareceive.member_31 = p_dist[31] 
    datareceive.member_32 = p_dist[32]
    datareceive.member_33 = p_dist[33]
    datareceive.member_34 = p_dist[34]
    datareceive.member_35 = p_dist[35]
    datareceive.member_36 = p_dist[36]  
    datareceive.member_37 = p_dist[37] 
    datareceive.member_38 = p_dist[38]
    datareceive.member_39 = p_dist[39]
    datareceive.member_40 = p_dist[40]
    datareceive.member_41 = p_dist[41]
    datareceive.member_42 = p_dist[42]  
    datareceive.member_43 = p_dist[43] 
    datareceive.member_44 = p_dist[44]
    datareceive.member_45 = p_dist[45]
    datareceive.member_46 = p_dist[46]
    datareceive.member_47 = p_dist[47]
    datareceive.member_48 = p_dist[48]  
    datareceive.member_49 = p_dist[49] 
    datareceive.member_50 = p_dist[50]
    datareceive.member_51 = p_dist[51]
    datareceive.member_52 = p_dist[52]
    datareceive.member_53 = p_dist[53]
    datareceive.member_54 = p_dist[54]
    datareceive.member_55 = p_dist[55]
    datareceive.member_56 = p_dist[56]
    datareceive.member_57 = p_dist[57]
    datareceive.member_58 = p_dist[58]
    datareceive.member_59 = p_dist[59]
    datareceive.member_60 = p_dist[60]
    datareceive.member_61 = p_dist[61] 
    datareceive.member_62 = p_dist[62]
    datareceive.member_63 = p_dist[63]
    datareceive.member_64 = p_dist[64]
    datareceive.member_65 = p_dist[65]
    datareceive.member_66 = p_dist[66]  
    datareceive.member_67 = p_dist[67] 
    datareceive.member_68 = p_dist[68]
    datareceive.member_69 = p_dist[69]
    datareceive.member_70 = p_dist[70]
    datareceive.member_71 = p_dist[71]
    datareceive.member_72 = p_dist[72]  
    datareceive.member_73 = p_dist[73] 
    datareceive.member_74 = p_dist[74]
    datareceive.member_75 = p_dist[75]
    datareceive.member_76 = p_dist[76]
    datareceive.member_77 = p_dist[77]
    datareceive.member_78 = p_dist[78]  
    datareceive.member_79 = p_dist[79] 
    datareceive.member_80 = p_dist[80]
    datareceive.member_81 = p_dist[81]
    datareceive.member_82 = p_dist[82]
    datareceive.member_83 = p_dist[83]
    datareceive.member_84 = p_dist[84]
    datareceive.member_85 = p_dist[85]
    datareceive.member_86 = p_dist[86]
    datareceive.member_87 = p_dist[87]
    datareceive.member_88 = p_dist[88]
    datareceive.member_89 = p_dist[89]
    datareceive.member_90 = p_dist[90]
    receive.sendto(datareceive, localreceive)

def sub():
    subcribe.Subscribe(callback)

def main(args):
    thread_sub = threading.Thread(target = sub)
    thread_sub.start()
    
    n = input('')


if __name__ == '__main__':
    main(sys.argv)
