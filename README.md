# Rover Project

## This is the main github for the Rover project.
The purpose of this project is to create a self driving all terrain surverying robot, Used for checking out areas that could be unsafe for people to get to.

We want to be able to have it get over and around hazardous areas autonomously and map out areas using a lidar to show any risks and areas of concern.


# Members
- Reuben Watt
- Taylor Medder
- Dhugald Spry


# Plan
## Base plan

Rover has a 540mm x 320mm base.
Need to trim off the sides of the existing frame, maybe create a smaller box frame for the internal components?

## Wheels and legs planning
750mm length for the rocker-bogie when set-up, need to calculate the total length of parts
150mm diameter wheels (Similar to the ones used to farmbot(killbot) if possible to find).

Might need to make a 3d model of the base and the legs to get a better feel of them.

## Sensor layout
- Lidar to make a minimap to find entrys and exits.
- Lidar to spin and map a room in 3d on unity
- Camera to view through
- Sensors on all 4 sides to help with obstacle avoidance and detection

As a group we need to work out a sensor layout that we all agree on.

# Research links

Nvidia Jetson? Possible replacement for the Raspberry Pi, Could be cool to try
https://www.nvidia.com/en-us/autonomous-machines/jetson-store/

ROS with Lidar
https://www.generationrobots.com/blog/en/lidar-integration-with-ros-quickstart-guide-and-projects-ideas/
https://www.daslhub.org/unlv/wiki/doku.php?id=using_ros_to_read_data_from_a_hokuyo_scanning_laser_rangefinder

ROS Tutorial:
http://wiki.ros.org/ROS/Tutorials

Information on stepper motors:
https://nz.rs-online.com/web/generalDisplay.html?id=ideas-and-advice/stepper-motors-guide

NASA software:
https://software.nasa.gov/

Open Source Scaled Down 6 wheeled rover:
https://github.com/nasa-jpl/open-source-rover

CAD Parts for it: 
https://github.com/nasa-jpl/open-source-rover/tree/master/mechanical/rocker_bogie

Lidar 3D scan:
https://www.youtube.com/watch?v=gCpCGkwwy8I&ab_channel=TechsOnTube

Curiosity Rover 3D model and part descriptions:
https://mars.nasa.gov/msl/rover-3d/

Some More Images for ideas on the differential bar and rocker bogie system:
https://beatty-robotics.com/curiosity-mars-rover/

Lidar object detection:
https://www.youtube.com/watch?v=_--8K1BW_O4&t=2s&ab_channel=GreatScott%21
# Similar Projects

Uses Ardupilot and ROS, Contains alot of information and ideas that we can use:
https://dronebotworkshop.com/6-wheel-rover-introduction/

6 Wheeled Mars rover design for terrain traversing, equipment servicing, astronaut assistance and on-board testing.
More detailed and hightech than what we are going for but still contains information that might be usefull:
https://www.researchgate.net/publication/313543991_6_Wheeled_Mars_rover_design_for_terrain_traversing_equipment_servicing_astronaut_assistance_and_on-board_testing

A replica of the Perseverance rover, includes code and other helpful hints in the guide:
https://www.youtube.com/watch?v=NOZZMsMAGh0&ab_channel=HowToMechatronics
https://howtomechatronics.com/projects/diy-mars-perseverance-rover-replica-with-arduino/

ROS rover project, might have some useful information on the OS:
https://github.com/danielsnider/ros-rover

Example of what ROS can do, Ardupilot used to set a path:
https://www.youtube.com/watch?v=tqVH4lWk51Y&ab_channel=RandyMackay

Really useful robot, uses ROS:
https://youtu.be/M9ABtlEM788

# 3D printed parts list

Wheels (Need to be edited for casting):


# Shopping List
(Possible Stepper Motors from JayCar https://www.jaycar.co.nz/arduino-compatible-5v-stepper-motor-with-controller/p/XC4458?gclid=CjwKCAjwuvmHBhAxEiwAWAYj-I8mAoWuHBumeFN9Gpo8tAAJETvrxtpyf-LaF3YU_MHC2sovdrO0RBoCKjkQAvD_BwE - Have a feeling these will be to small for the work load.)

Wheels, the same ones from farmbot:
https://shop.wheelco.co.nz/shop//Wheels/Rubber+Wheels/Zero+Pressure+Wheel+150mm+-+Offset+Hub+-+ZPM150B.html

Possible stepper motors, might change type of motors.
https://www.digikey.co.nz/product-detail/en/trinamic-motion-control-gmbh/QSH6018-56-28-165/1460-1082-ND/4843432
https://www.digikey.co.nz/product-detail/en/trinamic-motion-control-gmbh/QSH6018-56-28-165/1460-1082-ND/4843433

Coupler for wheel and wheel motor 
https://www.jaycar.co.nz/solid-shaft-couplers-female-type-ii/p/YG2602?pos=1&queryId=4b0afef208a4a262bed3c274e3180ced&sort=relevance

Slipring
https://core-electronics.com.au/slip-ring-with-flange-22mm-diameter-6-wires-max-240v-at-2a.html
