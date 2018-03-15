#ifndef _cJSON_ENCONDING_
#define _cJSON_ENCONDING_
#include <stdio.h>  
#include <string.h>  
#include <sys/types.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include "cJSON.h"  

/*----------------------------测试部分开始---------------------------*/
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
/*-----------------------------测试部分结束---------------------------*/

/*-----------------------------逻辑部分：编码-------------------------*/

//为了统一：数据赋值--定义一个总的结构体用于初始化数据的
typedef struct _MngClient_Info
{
	char			clientId[12];	// 客户端编号
	char			AuthCode[16];	// 认证码
	char			serverId[12];	// 服务器端编号

	char			serverip[32];
	int 			serverport;

	int				maxnode; 		// 最大网点数 客户端默认1个
	int 			shmkey;	 		// 共享内存keyid 创建共享内存时使用	 
	int 			shmhdl; 		// 共享内存句柄	
}MngClient_Info;

// 初始化客户端 全局变量
//int MngClient_InitInfo(MngClient_Info *pCltInfo);

/*----------------------------------------------------------------------------*/



#define		KeyMng_NEWorUPDATE		1		//1 密钥协商 
#define		KeyMng_Check			2		//2 密钥校验
#define		KeyMng_Revoke			3		//3 密钥注销


//密钥请求报文
#define  ID_MsgKey_Req  60
typedef struct _MsgKey_Req
{
	//1 密钥协商  	//2 密钥校验; 	//3 密钥注销
	int				cmdType;		//报文类型 
	char			clientId[12];	//客户端编号
	char			AuthCode[16];	//认证码
	char			serverId[12];	//服务器端编号 
	char			r1[64];			//客户端随机数
}MsgKey_Req;



//密钥应答报文
#define  ID_MsgKey_Res  61
typedef struct  _MsgKey_Res
{
	int					rv;				//返回值
	char				clientId[12];	//客户端编号
	char				serverId[12];	//服务器编号
	unsigned char		r2[64];			//服务器端随机数
	int					seckeyid;		//对称密钥编号    keysn
}MsgKey_Res;


//总编码
int MsgEncode(
	void			*pStruct, /*输入：结构体*/
	int				type,      /*结构体编号*/
	unsigned char	**outData, /*out--字符串*/
	int				*outLen);   //输出字符串长度

int MsgDecode(
	unsigned char *inData,  /*输入数据*/
	int           inLen,    /*输入数据长度*/
	void          *pStruct /*out--结构体*/,
	int           *type);    /*out结构体编号*/




int create_xiawucha_MsgKey_Req(char **outdata, int * outlen, int type);
int cJSONMsgKey_Req_to_struct(char *json_string, MsgKey_Req *person);
int create_xiawucha_MsgKey_Res(char **outdata, int * outlen, int type);
int cJSONMsgKey_Res_to_struct(char *json_string, MsgKey_Res *person);
int get_struct(char *json_string, int * flag);

#endif // !_cJSON_ENCONDING_