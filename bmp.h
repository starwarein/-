/*λͼ�ļ�ͷ*/
typedef  struct  tagBITMAPFILEHEADER
{ 
	unsigned short int  bfType;       //λͼ�ļ������ͣ�����ΪBM 
	unsigned long       bfSize;       //�ļ���С�����ֽ�Ϊ��λ
	unsigned short int  bfReserverd1; //λͼ�ļ������֣�����Ϊ0 
	unsigned short int  bfReserverd2; //λͼ�ļ������֣�����Ϊ0 
	unsigned long       bfbfOffBits;  //λͼ�ļ�ͷ�����ݵ�ƫ���������ֽ�Ϊ��λ
}BITMAPFILEHEADER; 

/*λͼ��Ϣͷ*/
typedef  struct  tagBITMAPINFOHEADER 
{ 
	long biSize;                        //�ýṹ��С���ֽ�Ϊ��λ
	long  biWidth;                     //ͼ�ο��������Ϊ��λ
	long  biHeight;                     //ͼ�θ߶�������Ϊ��λ
	short int  biPlanes;               //Ŀ���豸�ļ��𣬱���Ϊ1 
	short int  biBitcount;             //��ɫ��ȣ�ÿ����������Ҫ��λ��
	short int  biCompression;        //λͼ��ѹ������
	long  biSizeImage;              //λͼ�Ĵ�С�����ֽ�Ϊ��λ
	long  biXPelsPermeter;       //λͼˮƽ�ֱ��ʣ�ÿ��������
	long  biYPelsPermeter;       //λͼ��ֱ�ֱ��ʣ�ÿ��������
	long  biClrUsed;            //λͼʵ��ʹ�õ���ɫ���е���ɫ��
	long  biClrImportant;       //λͼ��ʾ��������Ҫ����ɫ��
}BITMAPINFOHEADER; 

/*��ɫ��*/
typedef struct RGB_QUAD 
{
	unsigned short rgbBlue; /* ��ɫǿ�� */
	unsigned short rgbGreen; /* ��ɫǿ�� */
	unsigned short rgbRed; /* ��ɫǿ�� */
	unsigned short rgbReversed; /* ����ֵ */
}RGBQUAD;