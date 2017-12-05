/*位图文件头*/
typedef  struct  tagBITMAPFILEHEADER
{ 
	unsigned short int  bfType;       //位图文件的类型，必须为BM 
	unsigned long       bfSize;       //文件大小，以字节为单位
	unsigned short int  bfReserverd1; //位图文件保留字，必须为0 
	unsigned short int  bfReserverd2; //位图文件保留字，必须为0 
	unsigned long       bfbfOffBits;  //位图文件头到数据的偏移量，以字节为单位
}BITMAPFILEHEADER; 

/*位图信息头*/
typedef  struct  tagBITMAPINFOHEADER 
{ 
	long biSize;                        //该结构大小，字节为单位
	long  biWidth;                     //图形宽度以象素为单位
	long  biHeight;                     //图形高度以象素为单位
	short int  biPlanes;               //目标设备的级别，必须为1 
	short int  biBitcount;             //颜色深度，每个象素所需要的位数
	short int  biCompression;        //位图的压缩类型
	long  biSizeImage;              //位图的大小，以字节为单位
	long  biXPelsPermeter;       //位图水平分辨率，每米像素数
	long  biYPelsPermeter;       //位图垂直分辨率，每米像素数
	long  biClrUsed;            //位图实际使用的颜色表中的颜色数
	long  biClrImportant;       //位图显示过程中重要的颜色数
}BITMAPINFOHEADER; 

/*彩色表*/
typedef struct RGB_QUAD 
{
	unsigned short rgbBlue; /* 蓝色强度 */
	unsigned short rgbGreen; /* 绿色强度 */
	unsigned short rgbRed; /* 红色强度 */
	unsigned short rgbReversed; /* 保留值 */
}RGBQUAD;