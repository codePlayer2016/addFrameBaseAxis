1、根据DPM跑出的结果，对目标加框，并且标示次序
2、保存加框的图片
3、框的颜色变化
//////////////////////note////////////////////

1. the program use opencv will be note that when in debug,the lib of the opencv should
be debug version, or the imread will be failed.

2. imshow will be followed by waitKey,that the picture will be flush.

3. Mat :imread,imshow,imwrite Rect for c++ and
 IPLImag:cvLoadImag,cvShowImg,cvWriteImg,cvRect for c
 
 //next should be do:
1、增强耦合性，在文件中读取要处理的图片和坐标信息文件.
2、在文件中设置要配置的缩放比例，格式设置为xml文件
 例如：sourceImg c:/10.jpg
	   axisFileUrl c:/axisInfo.txt
	   axisRation 1
	   displayRation 1
2、在代码中实现：坐标缩放模块，显示缩放模块
 //next next should be do:
design UI by QT. 