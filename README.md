# CAN-BUS-AGV

### project based on research on LPDP Rispro (Autonomous Port Container Truck)
**partner : PT BAMEC**
**role : Navigation and Control Development**
**Developed by : Ade Rustandi & Husnul Amri**

**old system architecture :**
![Old system architecture](https://github.com/aderustandi/CAN-BUS-AGV/blob/master/Data/Architecture%20System/New%20Structure-Page-1.png)

**Need to replace the ethernet communication with CAN-BUS protocol (asynchronous) --> automotive standard**
in order to achieve the final goal, it is needed to learn further about CAN BUS communication system, from the basic to the advance. then, the learning progress is break to some part of progress : 
1. Establish CAN-BUS communication using Arduino (1 master and some slave)
   - [x] Send some command/string "hello world" to another arduino using CAN-BUS
   - [x] Send some sensor variable (replaced with potentiometer) from an arduino to another arduino using CAN-BUS
   - [ ] Send some feedback from the master to respond with the sensor value ("too high/another") using CAN-BUS so theres established two way communication
   - [ ] Using three Arduino to communicate with 1 master and 2 slave, master is the decision maker, give different decision to the slave (here we get the priority/id concept in the CAN-BUS protocol)
   - [ ] Integrate the result of the master to the python or C++ code, maybe including some calculation that sent via serial
2. Integrate the communication via ROS system 
   - [x] install the ROS system to Linux (on the office computer) --> ROS Melodic
   - [ ] create some simple communication between ROS to the Arduino via Serial, and give some notes on how it actually works
   - [ ] send some sensor/potentiometer data from slave arduino to master arduino and read it using serial communication on ROS 
   - [ ] Further work on previous step, with some feedback from the ROS system to the slave Arduino
   - [ ] Send and receive data from ROS via master arduino to 2 slave arduino, with different data sent/response for different data received as trigger (may be a sensor/potentiometer)


    






