1、根据DPM跑出的结果，对目标加框，并且标示次序
2、保存加框的图片
3、框的颜色变化
//////////////////////note////////////////////

1. the program use opencv will be note that when in debug,the lib of the opencv should
be debug version, or the imread will be failed.

2. imshow will be followed by waitKey,that the picture will be flush.

3. Mat :imread,imshow,imwrite Rect for c++ and
 IPLImag:cvLoadImag,cvShowImg,cvWriteImg,cvRect for c