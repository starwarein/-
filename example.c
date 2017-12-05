#include <stdio.h> 
#include <stdlib.h>

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

//����һ��λͼ�ṹ���˽ṹ�Ա�������������� 
typedef  struct 
{ 
	BITMAPFILEHEADER  file; //�ļ���Ϣ��
	BITMAPINFOHEADER  info; //ͼ����Ϣ��
}bmp;


int main(){
 	bmp  m;        //����һ��λͼ�ṹ���˽ṹ�Ա�������������� 
  	FILE *fp; 
	if((fp=fopen( "test.bmp", "r"))==NULL){ 
		printf( "can't open the bmp imgae.\n "); 
   		exit(0); 
 	}

	fread(&m.file.bfType,sizeof(char),1,fp); 
	printf("����Ϊ%c",m.file.bfType); 
	fread(&m.file.bfType,sizeof(char),1,fp); 
	printf("%c\n",m.file.bfType);        
	fread(&m.file.bfSize,sizeof(long),1,fp); 
	printf("�ļ�����Ϊ%d\n",m.file.bfSize);  
	fread(&m.file.bfReserverd1,sizeof(short int),1,fp); 
	printf("������1Ϊ%d\n",m.file.bfReserverd1); 
	fread(&m.file.bfReserverd2,sizeof(short int),1,fp); 
	printf("������2Ϊ%d\n",m.file.bfReserverd2); 
	fread(&m.file.bfbfOffBits,sizeof(long),1,fp); 
	printf("ƫ����Ϊ%d\n",m.file.bfbfOffBits);
	fread(&m.info.biSize,sizeof(long),1,fp); 
	printf("�˽ṹ��СΪ%d\n",m.info.biSize); 
	fread(&m.info.biWidth,sizeof(long),1,fp); 
	printf("λͼ�Ŀ��Ϊ%d\n",m.info.biWidth);
	fread(&m.info.biHeight,sizeof(long),1,fp); 
	printf("λͼ�ĸ߶�Ϊ%d\n",m.info.biHeight);
	fread(&m.info.biPlanes,sizeof(short),1,fp); 
	printf("Ŀ���豸λͼ��%d\n",m.info.biPlanes);
	fread(&m.info.biBitcount,sizeof(short),1,fp); 
	printf("��ɫ���Ϊ%d\n",m.info.biBitcount);
	fread(&m.info.biCompression,sizeof(long),1,fp); 
	printf("λͼѹ������%d\n",m.info.biCompression); 
	fread(&m.info.biSizeImage,sizeof(long),1,fp); 
	printf("λͼ��С%d\n",m.info.biSizeImage); 
	fread(&m.info.biXPelsPermeter,sizeof(long),1,fp); 
	printf("λͼˮƽ�ֱ���Ϊ%d\n",m.info.biXPelsPermeter); 
	fread(&m.info.biYPelsPermeter,sizeof(long),1,fp); 
	printf("λͼ��ֱ�ֱ���Ϊ%d\n",m.info.biYPelsPermeter); 
	fread(&m.info.biClrUsed,sizeof(long),1,fp); 
	printf("λͼʵ��ʹ����ɫ��%d\n",m.info.biClrUsed);
	fread(&m.info.biClrImportant,sizeof(long),1,fp); 
	printf("λͼ��ʾ�бȽ���Ҫ��ɫ��%d\n",m.info.biClrImportant); 
	
	getchar();
	return 0; 
}
