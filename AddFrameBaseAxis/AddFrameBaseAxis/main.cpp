#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

typedef struct tagAxisData_t
{
	int x;
	int y;
	int width;
	int heigth;
} axisData_t;

int main()
{
    int retVal=0;

	const string imgFilePath="C:\\lhsCodeDir\\AddFrameBaseAxis\\AddFrameBaseAxis\\multiMotor_16.jpg";
	Mat imgSrc=imread(imgFilePath,1);
	assert(imgSrc.data!=NULL);

	ifstream axisInfoFile("D:/C6678_PC_WorkSpace/DPM_tested/Debug/dectectFastRegion.txt");
	if (!axisInfoFile)
	{
		cerr<<"open file error."<<endl;
		return (-1);
	}
	
	//get the info of the file.
	string picUriInfo;
	getline(axisInfoFile,picUriInfo);
	
	String axisInfoBuf;
	axisData_t axisInfo;
	vector<axisData_t> axisDataVector;
	while(!axisInfoFile.eof())
	{
		getline(axisInfoFile,axisInfoBuf);
		if (axisInfoBuf.empty())
		{
			break;
		}
		sscanf(axisInfoBuf.c_str(),"%d,%d,%d,%d",&axisInfo.x,&axisInfo.y,&axisInfo.width,&axisInfo.heigth);
		axisDataVector.push_back(axisInfo);
	}

	//show the frame.
	Rect rect;
	int i=0;
	int r,g,b;
	int colorIndex=0;
	// 单一颜色改变的间隔
	int colorDelta=(255/(axisDataVector.size()/3));

	int soloColorIndex_r,soloColorIndex_g,soloColorIndex_b;
	soloColorIndex_r=soloColorIndex_g=soloColorIndex_b=0;
	
	for(i=0;i<axisDataVector.size();i++)
	{
		rect.x=axisDataVector[i].x;
		rect.y=axisDataVector[i].y;
		rect.width =axisDataVector[i].width;
		rect.height   =axisDataVector[i].heigth;

		colorIndex=i%3;
		switch (colorIndex)
		{
		case 0:
			{
					r=255;
					g=colorDelta*soloColorIndex_r;
					b=255-g;
					soloColorIndex_r++;
					break;
			}
		case 1:
			{
					g=255;
					b=colorDelta*soloColorIndex_g;
					r=(255-b);
					soloColorIndex_g++;
					break;
			}
		case 2:
			{
					b=255;
					r=colorDelta*soloColorIndex_b;
					g=(255-r);
					soloColorIndex_b++;
					break;
			}
					default:
			break;

		}

		;
		//cout<<r<<','<<g<<','<<b<<endl;
		char showTextBuf[255];
		sprintf(showTextBuf,"%dth",i);
		string showText(showTextBuf);
		putText(imgSrc,showText,Point(rect.x,rect.y-2),CV_FONT_HERSHEY_SIMPLEX,0.5,Scalar(r,g,b));
		rectangle(imgSrc,rect,Scalar(r,g,b),2);
	}

	Mat imgDst;
	resize(imgSrc,imgDst,Size(imgSrc.rows/2,imgSrc.cols/2),0.5,0.5,INTER_LINEAR);
	

	



	//todo:resize();
	imshow("imgSrc",imgSrc);
	imwrite("./test.jpg",imgSrc);
	// if not add after the imshow() ,the picture will not display,
	waitKey(0);

	//getchar();

	return(retVal);
}