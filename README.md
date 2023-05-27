# GestureTest
Computer vision-based gesture recognition needs to solve a series of problems. The first is is how to split the hand from the background; then separate the useful information and redundant one, and extract the relevant information gesture; finally, decipher the specific meaning of the same gesture in accordance with the actual situation. To solve these problems, this paper discusses a gesture recognition interactive system with a kind of background separation methods based on specific color model, and a kind of gesture extraction method on key information, developed by Visual C + + 2010 and OpenCV, fits a variety of camera, which includes the following aspects:  
(1) For different quality defects among cameras, this system uses median filter or mean filter and restores the detail method to reduce the image noise conservatively. Then use different sampling radius of USM sharpening to enhance the image information.  
(2) According to the difference of colors between background and hands, this system uses the brightness and the two color channels as a color model for color separation. The not chosen distinct, such as the shadow and highlight areas will be further selected using a continuous color method.  
(3) According to the results there are a lot of interfering regions of selected areas. The system achieves the maximum connected area region extraction algorithm, which excludes the interference of the key information extraction.  
(4) According to the hand region of the case and for the naturalist interactive, the system uses the stable point -- gravity center of the hand as the hand position, and uses the size of the hand to know the distance from the area with the near-far smaller principle.  
(5) According to the results above, the system achieves some common interactive applications, including screen drawing control, mouse simulator, etc.  


基于计算机视觉的手势识别需要解决一系列的问题。首先是要做到的是从背景中将手分割出来；然后将有用的信息与冗余的信息分离开来，并将相关的手势信息提取出来；最后从相同的手势中根据实际情况，解读出它的特定的含义。针对这些问题，本文讨论里一种采用基于单目的特定颜色模型的背景分离方法和基于关键信息的手势提取方法，用Visual C++ 2010和OpenCV进行开发，实现在多种摄像头下的手势识别交互系统，主要包括以下方面：  
（1）针对不同摄像头画质的缺陷，采用中值滤波或均值滤波然后还原细节的方法实现图像较好的降噪，再用不同采样半径的USM锐化的方式实现图像信息的强化。  
（2）根据人手和背景色相等方面的差异，采用亮度+两个颜色通道的色彩模型进行色彩分离，并将未选择到的阴影和高光等区域利用连续色的原理进行进一步的选取。  
（3）根据选取结果有很多干扰区域的情况，实现最大面积连通区域的提取算法，以排除关键信息提取时的干扰。  
（4）根据手的区域的情况和交互的自然性，采用稳定的手的重心作为手的位置，利用近大远小的关系，采用手占摄像头面积的大小判断手离摄像头的距离。  
（5）针对以上识别的结果，实现了一些常见的人机交互应用，包括屏幕画图器、鼠标模拟器等。  
