# University-Embedded-Course
In this repository, I uploaded a couple of lab experiment codes and a project I've done in my universities **Embedded System course**. For those projects, we have used **Raspberry PI** (version 3) and several types of sensors and actuators, like Ultra Sonic sensors, IR sensors, PIR sensors, Servo Motor, LED lights, Relays, and many more. Finally, We have done a project that **Attendance System using Face Recognition**. 


## The Lab Experiments are  
- LED light blinking
- Distance measure using Ultra Sonic Sensor
- Door Open using Servo Motor
- High Voltage Control using Relay
- PIR Motion Sensor
- IR Module

## Final Project (Attendance System Using Face Recognition)
**Youtube Link :** https://youtu.be/llVhJw__qSY

Our Automated attendance system represents a significant advancement in attendance tracking. We have developed a highly accurate, efficient, and user-friendly system by integrating cutting-edge technologies such as Raspberry Pi and machine learning. The system utilizes a combination of three sensors and three actuators to ensure that attendance is recorded accurately and in real-time. The use of the Raspberry Pi allows for a compact and portable design, making it easy to implement in any setting. Furthermore, implementing machine learning algorithms allows the system to improve continuously over time, ensuring maximum accuracy and efficiency. This makes it an ideal solution for organizations of all types and sizes, from small businesses to large corporations. The successful implementation of this project is a testament to the power of technological innovation and its ability to revolutionize how we track attendance. It is a product of hard work, creativity, and passion for providing an efficient solution for attendance tracking. We are proud of our accomplishment and look forward to its future applications.

### Actuators and Sensors
- Raspberry Pi (3)
- Pi Camera
- Ultrasonic Distance Sensor
- IR Sensor
- Servo Motor
- LCD Display (16*2)
- LED
- Relay module
- Breadboard
- Wires

### Working Procedure

In this project, we have developed an Automated attendance system using a Raspberry Pi, a camera module, and machine learning. The process of creating this system is as follows:
- Connect the Raspberry Pi camera module to the Raspberry Pi.
- Enable Camera Legacy support to use the camera.
- Create a virtual environment with Python 3 and install essential libraries such as Numpy, OpenCV, Tensorflow Lite, PiCamera, and RPi.
- Collect 500 images of all group members to train the face recognition model. The images were captured using Python, OpenCV, and the Pi Camera.
- Train the model using Google's Teachable Machine and download the TFLite version of the model.
- Connect all of the sensors and actuators to the Raspberry Pi correctly.
- In the programming part, first, take input from the Ultrasonic Distance Sensor to get the person's distance from the camera. If the space is between 40 and 70 cm, turn on the camera and predict with the trained TFLite model. If the face matches, open the classroom door using a servo motor.
- Use an IR sensor to detect whether the person has entered the classroom. If the person has entered, close the room door and turn on the classroom light using a Relay module.


### Few snapshots of our project. 

[![image](https://www.linkpicture.com/q/photo_২০২৩-০১-১২_১৯-৫৭-৫৮.jpg)](https://www.linkpicture.com/view.php?img=LPic63c24e7a13f521410797471)

[![image](https://www.linkpicture.com/q/photo_২০২৩-০১-১২_১৯-৫৭-৫৯.jpg)](https://www.linkpicture.com/view.php?img=LPic63c24ebcb52101475792211)


### Limitations
While our Automated attendance system has been successfully implemented, a few limitations should be acknowledged. One area for improvement is that the current face recognition model can only understand and recognize three faces. To increase the number of individuals the system can remember, a higher configuration version of the Raspberry Pi would be required to implement a larger model. Another limitation is that more time could make the project more efficient. With additional time, we could have further optimized the system's performance and accuracy and added more features to enhance the user experience. It's also worth noting that the system depends on the quality of the image taken so it could be affected by lighting conditions, angle, and distance of the person. Overall, while the Automated attendance system has proven to be a functional and reliable solution, there is room for improvement and further development. With more advanced technology and optimization time, the system can become an even more efficient and effective solution for attendance tracking.

### References:  
Here are some references we used to do this project.
- https://www.tensorflow.org/
- https://opencv.org/
- https://mart.ecer.com/
- https://teachablemachine.withgoogle.com/
