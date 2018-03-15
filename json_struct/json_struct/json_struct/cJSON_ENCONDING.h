#ifndef _cJSON_ENCONDING_
#define _cJSON_ENCONDING_
#include <stdio.h>  
#include <string.h>  
#include <sys/types.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include "cJSON.h"  

/*----------------------------���Բ��ֿ�ʼ---------------------------*/
typedef struct
{
	int id;
	char firstName[32];
	char lastName[32];
	char email[64];
	float height;
}people;
char* create_monitor(void);
int cJSON_to_struct(char *json_string, people *person);
/*-----------------------------���Բ��ֽ���---------------------------*/

/*-----------------------------�߼����֣�����-------------------------*/

//Ϊ��ͳһ�����ݸ�ֵ--����һ���ܵĽṹ�����ڳ�ʼ�����ݵ�
typedef struct _MngClient_Info
{
	char			clientId[12];	// �ͻ��˱��
	char			AuthCode[16];	// ��֤��
	char			serverId[12];	// �������˱��

	char			serverip[32];
	int 			serverport;

	int				maxnode; 		// ��������� �ͻ���Ĭ��1��
	int 			shmkey;	 		// �����ڴ�keyid ���������ڴ�ʱʹ��	 
	int 			shmhdl; 		// �����ڴ���	
}MngClient_Info;

// ��ʼ���ͻ��� ȫ�ֱ���
//int MngClient_InitInfo(MngClient_Info *pCltInfo);

/*----------------------------------------------------------------------------*/



#define		KeyMng_NEWorUPDATE		1		//1 ��ԿЭ�� 
#define		KeyMng_Check			2		//2 ��ԿУ��
#define		KeyMng_Revoke			3		//3 ��Կע��


//��Կ������
#define  ID_MsgKey_Req  60
typedef struct _MsgKey_Req
{
	//1 ��ԿЭ��  	//2 ��ԿУ��; 	//3 ��Կע��
	int				cmdType;		//�������� 
	char			clientId[12];	//�ͻ��˱��
	char			AuthCode[16];	//��֤��
	char			serverId[12];	//�������˱�� 
	char			r1[64];			//�ͻ��������
}MsgKey_Req;



//��ԿӦ����
#define  ID_MsgKey_Res  61
typedef struct  _MsgKey_Res
{
	int					rv;				//����ֵ
	char				clientId[12];	//�ͻ��˱��
	char				serverId[12];	//���������
	unsigned char		r2[64];			//�������������
	int					seckeyid;		//�Գ���Կ���    keysn
}MsgKey_Res;


//�ܱ���
int MsgEncode(
	void			*pStruct, /*���룺�ṹ��*/
	int				type,      /*�ṹ����*/
	unsigned char	**outData, /*out--�ַ���*/
	int				*outLen);   //����ַ�������

int MsgDecode(
	unsigned char *inData,  /*��������*/
	int           inLen,    /*�������ݳ���*/
	void          *pStruct /*out--�ṹ��*/,
	int           *type);    /*out�ṹ����*/




int create_xiawucha_MsgKey_Req(char **outdata, int * outlen, int type);
int cJSONMsgKey_Req_to_struct(char *json_string, MsgKey_Req *person);
int create_xiawucha_MsgKey_Res(char **outdata, int * outlen, int type);
int cJSONMsgKey_Res_to_struct(char *json_string, MsgKey_Res *person);
int get_struct(char *json_string, int * flag);

#endif // !_cJSON_ENCONDING_