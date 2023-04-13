# Smart-trash-bins
![image](https://github.com/qlkaaron/Smart-Trash-Bin/blob/main/img/trashbin.png)
### Follow us! Here is our social media links.
Youtube channel:
https://www.youtube.com/channel/UC5s7DoMgMNC2AQGXQb5fd2A

Hackaday channel:
https://hackaday.io/project/190551-smart-trash-bins

### Project introduction
This project uses a Raspberry Pi 3B, Raspberry Pi camera, and four servos to create a trash sorting bin that can automatically separate different types of garbage. The principle of the project is to use the camera to identify the type of garbage being thrown away, and then use the servos to open the corresponding bin for proper disposal.
![image](https://github.com/qlkaaron/Smart-Trash-Bin/blob/main/img/draftdrawing.jpg)
### How it Works
#### Implement of garbage recognition and classification algorithm model construction
The Raspberry Pi camera is mounted above the trash bin and connected to the Raspberry Pi 3B. The Raspberry Pi runs an image recognition algorithm to identify the type of garbage being thrown away. The four servos are connected to the Raspberry Pi and are used to open the corresponding bin for disposal.

The image recognition algorithm uses machine learning to classify different types of garbage, such as plastics, paper, glass, and organic waste. The algorithm has been trained on a large dataset of images to accurately identify different types of garbage.
#### Implementation of servos
PCA9685 can drive 16 servos at the same time. In addition to connecting to the Raspberry Pi, it needs to be powered externally with 5V to drive the servos.
#### How to connect:
For PCA9685:
Connect the VCC pin of the PCA9685 to the 3.3V pin of the Raspberry Pi.
Connect the GND pin of the PCA9685 to the GND pin of the Raspberry Pi.
Connect the SDA pin of the PCA9685 to the SDA pin of the Raspberry Pi.
Connect the SCL pin of PCA9685 to the SCL pin of Raspberry Pi.

For MG996R:
The four MG996R servos are respectively connected to the VCC pin, GND pin, and signal pin of the driver board.

### Project Components
This project uses the following components:
1. Raspberry Pi 3B
2. Raspberry Pi HD camera
3. Four servos
4. Four trash bins
5. Loptop with GPU

The Raspberry Pi 3B is used to run the image recognition algorithm and control the servos. The Raspberry Pi camera is used to capture images of the garbage being thrown away. The four servos are used to open the corresponding bin for disposal. The four trash bins are labeled and the servo uses a simple device to open and close the lid of the trash can.

### Project Environment
The environment and software required for this project:
1. Ubuntu 18.04
2. Windows 10 for remote desktop and model traning
3. Qt Creator 4.6.2 (Enterprise)
4. YOLOv5
5. Opencv 4.7.0

### Getting Started
To get started with this project, you will need a Raspberry Pi 3B, Raspberry Pi camera, four servos, and four trash bins. You will also need to install the image recognition algorithm on the Raspberry Pi and connect the servos to the Raspberry Pi.

Once everything is set up, you can start using the trash sorting bin by throwing away different types of garbage and watching as the bin automatically separates and sorts the garbage for you.

### Conclusion
This is a project of the Real Time Embedded Programming (2022-23) at the University of Glasgow. Thanks to prof. Bernd Porr and Prof. Nicholas Bailey for the learning materials.The Smart-trash-bins project can have many benefits for protecting the environment, such as:
1. Reducing landfill waste: By automatically sorting different types of garbage, the project can help reduce the amount of waste that ends up in landfills. For example, organic waste can be composted, while plastics and other materials can be recycled.
2. Promoting recycling: The project can help promote recycling by making it easier for people to properly dispose of their recyclable materials. By providing a convenient and efficient way to sort and dispose of recyclable materials, the project can encourage more people to recycle.
3. Improving waste management: The project can help improve waste management by reducing the amount of waste that needs to be sorted manually by waste management workers. This can help save time and resources, and make waste management more efficient.
4. Raising awareness: By showcasing the benefits of proper waste management and recycling, the project can help raise awareness about the importance of protecting the environment. This can help encourage more people to adopt eco-friendly habits and reduce their impact on the environment.

Finally, we sincerely hope that our project can help the cause of environmental protection to a higher level
