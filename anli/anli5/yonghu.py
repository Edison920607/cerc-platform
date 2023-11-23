import proxy
import threading
import sys

# 传感
from pb.ros.std_msgs import Bool_pb2
import pause, datetime
# 图片
from pb.ros.sensor_msgs import Image_pb2
from pb.ros.sensor_msgs import CompressedImage_pb2
from pb.ros.geometry_msgs import Pose_pb2
import cv2 as cv2
import numpy as np
# 里程计、姿态仪
from pb.ros.nav_msgs import Odometry_pb2
# 测距仪
from pb.ros.std_msgs import Float32_pb2
# 激光雷达
from pb.ros.sensor_msgs import PointCloud2_pb2
# 全球定位系统
from pb.ros.sensor_msgs import NavSatFix_pb2


# 传感基类
class SensorCollect:
    # 通讯初始化：必须重载
    def __init__(self, connector, env_name: str, robot_name: str, namespace: str, message_type):
        """通讯初始化逻辑

        Args:
            connector (_type_): 通讯实例
            env_name (str): 环境变量
            robot_name (str): 载具名称
            namespace (str): 命名空间
            message_type (_type_): 消息类型
        """
        self.subscriber = connector.Subscribe(env_name, robot_name, '/' + env_name + '/' + robot_name + '/' + namespace,
                                              message_type, self.callback)
        self.sensor_data = message_type()

    # 逻辑实现：推荐重载
    def implement(self):
        # 数据封装统一遵循ROS标准，消息定义请查阅以下网页
        '''
        消息定义 https://github.com/ros/common_msgs
        单位标准 https://ros.org/reps/rep-0103.html
        '''
        print(self.sensor_data)

    # 通讯回调：谨慎重载
    def callback(self, receive_data):
        self.sensor_data = receive_data

    # 通讯逻辑：斟酌重载
    def subscribe(self, rate: float):
        """传感数据接收逻辑

        Args:
            rate (float): 频率（单位：Hz）
        """
        # 休眠变量初始化
        td = datetime.timedelta(seconds=1.0 / rate)
        dt = datetime.datetime.now()

        while True:
            # 接收逻辑
            if self.subscriber.SpinOnce():
                self.implement()  # 对于复杂逻辑，请重载为异步
            # 休眠逻辑
            dt += td
            pause.until(dt)

        '''
        #下面四种方法都是检查数据是否已经到达并且主动调用回调函数
        #根据实际情况选择一种方法

        #1. 不管数据是否已经到达都马上返回，如果数据已经到达，即引起回调函数的调用，否则什么都不做直接返回
        #subscriber.SpinOnce()

        #2.检查一次数据是否已经到,直到数据到达后才返回
        #subscriber.SpinFor()
            
        #3.检查一次数据是否已经到,直到数据或超时，数据到达后才返回，单位为：毫秒
        #等待一秒
        #subscriber.SpinFor(1000)

        #4.Spin方法，一直循环检查数据是否已经到，通知订阅回调，永不返回，直到用户调用UnSubscribe()方法
        subscriber.Spin()
        '''


# 原生彩图
class Image(SensorCollect):
    def __init__(self, connector, env_name: str, robot_name: str):
        super().__init__(connector, env_name, robot_name, 'color/image_raw', Image_pb2.Image)

    # http://docs.ros.org/en/api/sensor_msgs/html/msg/Image.html
    def implement(self):
        img = np.frombuffer(self.sensor_data.data, np.uint8)
        img_rgba = img.reshape(self.sensor_data.height, self.sensor_data.width, 4)
        img_brg = cv2.cvtColor(img_rgba, cv2.COLOR_RGBA2BGR)

        cv2.imshow("Temporary Image", img_brg)
        cv2.waitKey(1)


# 压缩彩图
class CompressedImage(SensorCollect):
    def __init__(self, connector, env_name: str, robot_name: str):
        super().__init__(connector, env_name, robot_name, 'color/image_raw/compressed',
                         CompressedImage_pb2.CompressedImage)

    # http://docs.ros.org/en/api/sensor_msgs/html/msg/CompressedImage.html
    def implement(self):
        img = np.frombuffer(self.sensor_data.data, np.uint8)
        img_rgba = cv2.imdecode(self.sensor_data.data, cv2.IMREAD_COLOR)

        cv2.imshow("Temporary Image", img_rgba)
        cv2.waitKey(1)


# 原生深度图
class DepthImage(SensorCollect):
    def __init__(self, connector, env_name: str, robot_name: str):
        super().__init__(connector, env_name, robot_name, 'depth/image_raw', Image_pb2.Image)

    # https://ros.org/reps/rep-0118.html
    def implement(self):
        img = np.frombuffer(self.sensor_data.data, np.uint16)
        img_gray = img.reshape(self.sensor_data.height, self.sensor_data.width, 1)

        cv2.imshow("Temporary Image", img_gray)
        cv2.waitKey(1)


# 里程计
class Odom(SensorCollect):
    def __init__(self, connector, env_name: str, robot_name: str):
        super().__init__(connector, env_name, robot_name, 'odom', Odometry_pb2.Odometry)

    # http://docs.ros.org/en/api/nav_msgs/html/msg/Odometry.html


# 姿态仪（上帝信息）
class State(SensorCollect):
    def __init__(self, connector, env_name: str, robot_name: str):
        super().__init__(connector, env_name, robot_name, 'state', Odometry_pb2.Odometry)

    # http://docs.ros.org/en/api/nav_msgs/html/msg/Odometry.html


# 测距仪
class Scan(SensorCollect):
    def __init__(self, connector, env_name: str, robot_name: str):
        super().__init__(connector, env_name, robot_name, 'scan', Float32_pb2.Float32)

    # http://docs.ros.org/en/api/nav_msgs/html/msg/Odometry.html


# 激光雷达
class Lidar(SensorCollect):
    def __init__(self, connector, env_name: str, robot_name: str):
        super().__init__(connector, env_name, robot_name, 'points', PointCloud2_pb2.PointCloud2)

    # http://docs.ros.org/en/api/sensor_msgs/html/msg/PointCloud2.html


# 全球定位系统
class Gnss(SensorCollect):
    def __init__(self, connector, env_name: str, robot_name: str):
        super().__init__(connector, env_name, robot_name, 'natsat/fix', NavSatFix_pb2.NavSatFix)

    # http://docs.ros.org/en/api/sensor_msgs/html/msg/NavSatFix.html


class Path:
    def __init__(self, connector, env_name: str, robot_name: str, namespace: str, message_type):
        """通讯初始化逻辑

        Args:
            connector (_type_): 通讯实例
            env_name (str): 环境变量
            robot_name (str): 载具名称
            namespace (str): 命名空间
            message_type (_type_): 消息类型
        """
        self.Advertise = connector.Advertise(env_name, robot_name, '/' + env_name + '/' + robot_name + '/' + namespace,
                                             Pose_pb2.Pose)
        self.sensor_data = message_type()

    # 按方向移动一定距离
    def sent_path(self, x, y, z, yawrate):
        pose = Pose_pb2.Pose()
        pose.position.x = x
        pose.position.y = y
        pose.position.z = z
        pose.orientation.x = yawrate
        self.Advertise.Publish(pose)


def main(args):
    connector = proxy.Connector('tcp://172.22.56.12:15555')

    # 传感例子
    img_example = CompressedImage(connector, 'NT2', 'M300_0')
    img_thread = threading.Thread(target=img_example.subscribe(10))
    img_thread.start()

    # 移动例子
    path_m300_0 = Path(connector, 'NT2', 'M300_0', Pose_pb2.Pose)
    # 移动（X=1,Y=1,Z=1,Yaw =1）
    path_m300_0.sent_path(1, 1, 1, 1)
    # path_m300_0_thread = threading.Thread(target=path_m300_0.sent_path(1, 1, 1, 1))
    # path_m300_0_thread.start()


if __name__ == '__main__':
    main(sys.argv)
