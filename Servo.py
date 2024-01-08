# from cvzone.SerialModule import SerialObject
from cvzone.SerialModule import SerialObject
from time import sleep


# arduino = SerialObject(digits=3)
arduino = SerialObject("/dev/cu.usbmodem141101", 9600, digits=3) #맥은 풀로 써줘야 함
while True:

    # 먼저 이거 실행
    # arduino.sendData([90])
    for x in range(60, 120, 1):
        arduino.sendData([x])     # 1개 서보일때
        # arduino.sendData([x,x]) # 2개 서보일때
        sleep(0.015)
        print(x)
        # print(x,x)
    for x in range(120, 60, -1):
        arduino.sendData([x])     # 1개 서보일때
        # arduino.sendData([x,x]) # 2개 서보일때

        sleep(0.015)
        print(x)
        # print(x,x)