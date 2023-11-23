import threading
from pb.ros.custom_msgs import CustomCommunication_pb2
import proxy
import time
import json
import os

with open('..\\config.json', 'r') as f:
    Config = json.load(f)
    env_name = Config['envid']
    ip = Config['ip']


def callback(communicationpara):
    CommunicationParaData = communicationpara
    print("huidiaochufa")
    print(communicationpara.Loss)
    print(communicationpara)


def subscribe(communication_subscribe):
    while True:
        time.sleep(1)
        communication_subscribe.SpinOnce()
        print("communicationsubqidong")


def main():

    communication_connector = proxy.Connector(f'{ip}' + ':15555')
    communicationSubscribe = communication_connector.Subscribe(f'{env_name}', "CommunicationPara",
                                                               '/' + f'{env_name}' + '/' + 'CommunicationPara',
                                                               CustomCommunication_pb2.CommunicationPara, callback)
    communicationSub = threading.Thread(target=subscribe(communicationSubscribe))

    communicationSub.start()
    print("123")
    communicationSub.join()





if __name__ == '__main__':
    main()
