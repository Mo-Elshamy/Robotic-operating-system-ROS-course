# This task is about adding plugins to a robot in an enviroment.

In this task we made two packages [robo_description pkg](./robo_description/) which includes our URDF files , mesh file and gazebo plugin file. the second pkg is [robo_gazebo pkg](./robo_gazebo/) which include our world and launch files(rviz and gazebo).

## First: Creating URDF file for the robot:
[model code](./URDF/robo.xacro)

To visualize the lidar real visualization, add the mesh file(.dae) in the mesh folder and call it in the geometry of the lidar_link.
``` xml
<link name="hokuyo_link">
    <collision>
      <origin xyz="0 0 0" rpy="0 0 0"/>
      <geometry>
    <box size="0.1 0.1 0.1"/>
      </geometry>
    </collision>

    <visual>
      <origin xyz="0 0 0" rpy="0 0 0"/>
      <geometry>
        <mesh filename="package://robo_description/meshes/hokuyo.dae"/>
      </geometry>
    </visual>

    <inertial>
      <mass value="1e-5" />
      <origin xyz="0 0 0" rpy="0 0 0"/>
      <inertia ixx="1e-6" ixy="0" ixz="0" iyy="1e-6" iyz="0" izz="1e-6" />
    </inertial>
  </link>
```

we will add the materials of the urdf in a separeted file [material code](./URDF/material.xacro) while the Gazebo materials color is add to the code of the model code.

```xml
  <gazebo reference="base">
    <material>Gazebo/Yellow</material>
  </gazebo>

  <gazebo reference="right_front_wheel">
   <material>Gazebo/Black</material>
  </gazebo>

  <gazebo reference="right_back_wheel">
   <material>Gazebo/Black</material>
  </gazebo>

  <gazebo reference="left_front_wheel">
   <material>Gazebo/Black</material>
  </gazebo>

  <gazebo reference="left_back_wheel">
   <material>Gazebo/Black</material>
  </gazebo>

  <gazebo reference="camera_link">
    <material>Gazebo/Red</material>
  </gazebo> 
```
The robot model:

![Screenshot from 2023-04-25 18-47-10](https://user-images.githubusercontent.com/121442515/234346731-94a1eff7-2ba7-40f4-8c2f-ecd8d3fba585.png)



## Second: making rviz and gazebo launch files:
[launch files](./robo_gazebo/launch/)



To launch our model on gazebo after running the roscore write this command in terminal:
```
roslaunch robo_gazebo robot.launch 
```

To launch our model on rviz write this command in terminal:
```
roslaunch robo_gazebo rviz.launch
```
and select the base as a fixed frame then add the robot model.

![Screenshot from 2023-04-25 20-12-56](https://user-images.githubusercontent.com/121442515/234365597-0aacefa5-2465-4eda-8140-a67b233f1e70.png)


## Third: Add plugins:
all the plugins are add to the [robot.gazebo file](./URDF/robot.gazebo).
To run a plugin you need to launch both rviz and gazebo.
 
 
### camera plugin:

To run the camera plugin write the command:

``` rosrun image_view image_view image:=/robo/camera1/image_raw```
then the camera window will apear

![Screenshot from 2023-04-25 20-29-25](https://user-images.githubusercontent.com/121442515/234369085-3225ddb5-d815-4f7e-8557-4dc0e77bc2bd.png)


or add image in the rviz.


![Screenshot from 2023-04-25 20-28-08](https://user-images.githubusercontent.com/121442515/234368709-8e4d5596-b99d-4b11-b02f-03cfe73a30fc.png)

### drive plugin:

This robot is a skid drive type. So, we will add its plugin and test it by the command:
``` rostopic pub -1 /cmd_vel geometry_msgs/Twist ``` 
the press double tape and add some parameters to make it move.

### lidar plugin:

To run the lidar add laser scan in the rviz then select the topic:

![Screenshot from 2023-04-25 20-40-05](https://user-images.githubusercontent.com/121442515/234371517-39ab7a80-a4f4-48e6-805d-809bd42f4eba.png)

## Fourth: creating the enviroment in gazebo:
to creat the enviroment in our world we need to open gazebo and select the building editor to insert some walls then saving it and start to add some tabels and shapes as shown:

![Screenshot from 2023-04-25 20-44-22](https://user-images.githubusercontent.com/121442515/234373100-60ef7e47-89d6-4fe1-b051-87b524b50188.png)

![Screenshot from 2023-04-25 20-45-16](https://user-images.githubusercontent.com/121442515/234373168-6281cb2e-3d55-402b-bf4c-41940b85ce6f.png)

## Last: the final output:

https://user-images.githubusercontent.com/121442515/234376490-1ac53d69-7a9c-43e8-89aa-20358a6bfde1.mp4


