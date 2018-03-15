#include "cJSON_ENCONDING.h"
#define bit(i) (0x0000<<i)
#include <time.h>


int create_xiawucha_MsgKey_Req(char **outdata, int * outlen,int type);
int cJSONMsgKey_Req_to_struct(char *json_string, MsgKey_Req *person);
int create_xiawucha_MsgKey_Res(char **outdata, int * outlen, int type);
int cJSONMsgKey_Res_to_struct(char *json_string, MsgKey_Res *person);
int get_struct(char *json_string, int * flag);

/*---------------------------测试资料----------------------------*/
//cJSON打包1
//创建一个带有受支持决议清单的监视器	
char* create_xiawucha_monitor(void)
{
	people person;

	person.id = 5;
	strcpy(person.firstName, "hehe");
	strcpy(person.lastName, "hehe1");
	strcpy(person.email, "hehe2");
	person.height = 12.7;

	//JSON成员如下： 全定义成 cJSON* 类型
	cJSON *xiawucha = NULL;  //子对象

	cJSON *id = NULL;
	cJSON *firstName = NULL;
	cJSON *lastName = NULL;
	cJSON *email = NULL;
	cJSON *height = NULL;

	///////////////////////////////////////////////////////////////
	//// 阶段1： 创建对象
	//1. 创建总对象句柄  代表 {  }
	cJSON * monitor = cJSON_CreateObject();
	if (monitor == NULL)
	{
		goto end;
	}
	//2. 创建一个子对象： 作为第一个元素的值
	xiawucha = cJSON_CreateObject();
	if (xiawucha == NULL)
	{
		goto end;
	}
	//3 为对象添加一个元素： 其值为一个子对象
	cJSON_AddItemToObject(monitor, "person", xiawucha);

	/////////////////////////////////////////////////////////////////////
	// 结点二： 开始编码：

	//1.为子对象添加元素与值： int类型
	id = cJSON_CreateNumber(person.id);
	if (id == NULL)
	{
		goto end;
	}
	//将数据添加到子项目中
	cJSON_AddItemToObject(xiawucha, "id", id);

	//2添加字符串
	firstName = cJSON_CreateString(person.firstName);
	if (firstName == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "firstName", firstName);

	//3. 添加字符串
	lastName = cJSON_CreateString(person.lastName);
	if (lastName == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "lastName", lastName);


	//4. 添加字符串
	email = cJSON_CreateString(person.email);
	if (email == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "email", email);

	//5. 添加double类型
	height = cJSON_CreateNumber(person.height);
	if (height == NULL)
	{
		goto end;
	}
	//将数据添加到子项目中
	cJSON_AddItemToObject(xiawucha, "height", height);

	//最后一步：
	//上面： 将初始化的数据---添加到--对象中。
	//下面： 将对象---转换成要输出的字符串。
	char *string = NULL;
	string = cJSON_Print(monitor);//将总对象---转换成： 字符串
	if (string == NULL)
	{
		fprintf(stderr, "Failed to print monitor.\n");
	}

end:
	//清空对象。//返回输出的字符串： ---也可以使用输出参数。
	cJSON_Delete(monitor);
	return string;
}
//cJSON打包：
//和上面的方式不同---直接填值，可能不方便。
//没有使用链表。
char* create_monitor(void)
{
	//JSON成员如下： 全定义成 cJSON* 类型
	cJSON *xiawucha = NULL;  //子对象

	cJSON *id = NULL;
	cJSON *firstName = NULL;
	cJSON *lastName = NULL;
	cJSON *email = NULL;
	cJSON *height = NULL;

	///////////////////////////////////////////////////////////////
	//// 阶段1： 创建对象
	//1. 创建总对象句柄  代表 {  }
	cJSON *monitor = cJSON_CreateObject();
	if (monitor == NULL)
	{
		goto end;
	}
	//2. 创建一个子对象： 作为第一个元素的值
	xiawucha = cJSON_CreateObject();
	if (xiawucha == NULL)
	{
		goto end;
	}
	//3 为对象添加一个元素： 其值为一个子对象
	cJSON_AddItemToObject(monitor, "person", xiawucha);

	/////////////////////////////////////////////////////////////////////
	// 结点二： 开始编码：

	//1.为子对象添加元素与值： int类型
	id = cJSON_CreateNumber(5);
	if (id == NULL)
	{
		goto end;
	}
	//将数据添加到子项目中
	cJSON_AddItemToObject(xiawucha, "id", id);

	//2添加字符串
	firstName = cJSON_CreateString("hehe");
	if (firstName == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "firstName", firstName);

	//3. 添加字符串
	lastName = cJSON_CreateString("hehe1");
	if (lastName == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "lastName", lastName);


	//4. 添加字符串
	email = cJSON_CreateString("hehe2");
	if (email == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "email", email);

	//5. 添加double类型
	height = cJSON_CreateNumber(17.6);
	if (height == NULL)
	{
		goto end;
	}
	//将数据添加到子项目中
	cJSON_AddItemToObject(xiawucha, "height", height);

	//最后一步：
	//上面： 将初始化的数据---添加到--对象中。
	//下面： 将对象---转换成要输出的字符串。
	char *string = NULL;
	string = cJSON_Print(monitor);//将总对象---转换成： 字符串
	if (string == NULL)
	{
		fprintf(stderr, "Failed to print monitor.\n");
	}

end:
	//清空对象。//返回输出的字符串： ---也可以使用输出参数。
	cJSON_Delete(monitor);
	return string;
}
//首先： 解包
//参数1：打包得到的字符串； 
//参数2：解析的输出结构体---将获取的值： 赋予结构体成员
int cJSON_to_struct(char *json_string, people *person)
{
	cJSON *item;

	//1. 将压缩的字符串： 解包成SJSON类型的句柄， 即{}
	cJSON *root = cJSON_Parse(json_string);
	if (root == NULL)
	{
		printf("Error before0: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		//2. 解包成功，通过句柄获取： 通过键值获取一个元素
		//   即： 获取结构体对象 person  {}
		cJSON *object = cJSON_GetObjectItem(root, "person");
		if (object == NULL)
		{
			printf("Error before1: [%s]\n", cJSON_GetErrorPtr());
			cJSON_Delete(root);
			return -1;
		}
		//输出获取元素的： 键值，类型，与值
		printf("cJSON_GetObjectItem: type=%d, key is %s, value is %s\n", object->type, object->string, object->valuestring);

		///////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////
		//  开始获取子对象的成员
		if (object != NULL)
		{
			//成员1： int 类型id----如果形成链表： 是不是就不用 “id”key值了---直接
			//        使用头指针即可了。！！！！！！！！！！！！！！！！！！！！
			item = cJSON_GetObjectItem(object, "id");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%d\n", item->type, item->string, item->valueint);
				person->id = item->valueint;
			}


			//成员2. 获取结构体成员： firstname   strcpy 或 memcpy
			item = cJSON_GetObjectItem(object, "firstName");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->firstName, item->valuestring, strlen(item->valuestring));
			}

			//成员3： lastname  strcpy 或 memcpy
			item = cJSON_GetObjectItem(object, "lastName");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->lastName, item->valuestring, strlen(item->valuestring));
			}

			//获取成员4. email： strcpy 或 memcpy
			item = cJSON_GetObjectItem(object, "email");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->email, item->valuestring, strlen(item->valuestring));
			}

			//height成员5.
			item = cJSON_GetObjectItem(object, "height");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuedouble=%f\n", item->type, item->string, item->valuedouble);
				person->height = item->valuedouble;
			}
		}

		//销毁成员
		cJSON_Delete(root);
	}
	return 0;
}

/*-----------------------------测试阶段结束----------------------------------*/

/*-----------------------------总编码部分--------------------------------------*/
//参数传出参数
/*int MngClient_InitInfo(MngClient_Info * pCltInfo)
{
	strcpy(pCltInfo->clientId, "clientID");  // 客户端编号
	strcpy(pCltInfo->AuthCode, "authcode");  // 认证码
	strcpy(pCltInfo->serverId, "serverID");  // 服务器端编号
	strcpy(pCltInfo->serverip, "127.0.0.1"); ////IP地址

	pCltInfo->serverport = 9999;             //端口
	pCltInfo->maxnode = 1;                   //共享内存keyid 创建共享内存时使用
	pCltInfo->shmkey = ftok("/", 'x');       //共享内存keyid 创建共享内存时使用
	// IPC_CreatShm(pCltInfo->shmkey, 100, &pCltInfo->shmhdl);
	return 0;
}*/

// 大小写字符, 数子, 特殊字符: 输入长度--输出获取字符串
void GetRandString(int len, char * buf)
{
	int flag = -1;
	srand(time(NULL));
	char chars[] = "~!@#$%^&*()_+";
	for (int i = 0; i < len; ++i)
	{
		flag = rand() % 4;
		switch (flag)
		{
		case 0:
			buf[i] = 'A' + rand() % 26;
			break;
		case 1:
			buf[i] = 'a' + rand() % 26;
			break;
		case 2:
			buf[i] = chars[rand() % strlen(chars)];
			break;
		case 3:
			buf[i] = '0' + rand() % 10;
			break;
		default:
			break;
		}
	}
}

//总编码
int MsgEncode(
	void			*pStruct, /*输入：结构体*/
	int				type,      /*结构体编号*/
	unsigned char	**outData, /*out--字符串*/
	int				*outLen)   //输出字符串长度
{
   //第一步：验证参数的正确性
   /*if ( outData == NULL || outLen == NULL)
	{
		perror("输入参数无效\n");
		return -1;
	}*/

	//接受编码的数据
	char *ceshi = NULL;
	int len = -1;
	//第二步：判断是哪个结构体
	printf("%d\n",type);
	switch (type)
	{
	case ID_MsgKey_Req:
		printf("我进入了60号\n");
		create_xiawucha_MsgKey_Req(&ceshi,&len,type);
		break;
	case ID_MsgKey_Res:
		printf("我进入了61号\n");
		create_xiawucha_MsgKey_Res(&ceshi,&len,type);
		break;
	default:
		printf("123243243\n");
		return -1;
	}

	*outData = ceshi;
	*outLen = len;
	return 0;
}


//总解码
int MsgDecode(
	unsigned char *inData,  /*输入数据*/
	int           inLen,    /*输入数据长度*/
	void          *pStruct /*out--结构体*/,
	int           *type)    /*out结构体编号*/
{
	//参数验证
	if (inData == NULL || inLen <= 0)
	{
		return -1;
	}

	//获取第一个值： 赋值给输出---在根据其值判断。
	int flag = -1;
	get_struct(inData, &flag);
	*type = flag;
	switch (flag)
	{
	case ID_MsgKey_Req:
		cJSONMsgKey_Req_to_struct(inData, (MsgKey_Req *)pStruct);
		break;
	case ID_MsgKey_Res:
		cJSONMsgKey_Res_to_struct(inData, (MsgKey_Res *)pStruct);
		break;
	default:
		break;
	}
	return 0;
}


/*------------------------------总解码部分结束----------------------------------*/
/*-------------------------------结构体部分1--------------------------------------*/
/*typedef struct _MsgKey_Req
{
	//1 密钥协商  	//2 密钥校验; 	//3 密钥注销
	int				cmdType;		//报文类型 
	char			clientId[12];	//客户端编号
	char			AuthCode[16];	//认证码
	char			serverId[12];	//服务器端编号 
	char			r1[64];			//客户端随机数
}MsgKey_Req;*/
int create_xiawucha_MsgKey_Req(char **outdata,int * outlen,int type)
{
	MsgKey_Req person;
	person.cmdType = 1;
	strcpy(person.clientId, "hehe");
	strcpy(person.AuthCode, "hehe1");
	strcpy(person.serverId, "hehe2");
	strcpy(person.r1, "hehe2");

	//JSON成员如下： 全定义成 cJSON* 类型
	cJSON *xiawucha = NULL;  //子对象
	cJSON *cmdType  = NULL;
	cJSON *clientId = NULL;
	cJSON *AuthCode = NULL;
	cJSON *serverId = NULL;
	cJSON *r1 = NULL;

	///////////////////////////////////////////////////////////////
	//// 阶段1： 创建对象
	//1. 创建总对象句柄  代表 {  }
	cJSON * monitor = cJSON_CreateObject();
	if (monitor == NULL)
	{
		printf("1\n");
		goto end;
	}
	//2. 创建一个子对象： 作为第一个元素的值
	xiawucha = cJSON_CreateObject();
	if (xiawucha == NULL)
	{
		printf("2\n");
		goto end;
	}
	//3 为对象添加一个元素： 其值为一个子对象
	cJSON_AddItemToObject(monitor, "person", xiawucha);

	/////////////////////////////////////////////////////////////////////
	// 结点二： 开始编码：
    //添加头--参数输入
	cJSON *flag = cJSON_CreateNumber(type);
	if (flag == NULL)
	{
		printf("3\n");
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "flag", flag);

	//1.为子对象添加元素与值： int类型
	cmdType = cJSON_CreateNumber(person.cmdType);
	if (cmdType == NULL)
	{
		printf("4\n");
		goto end;
	}
	//将数据添加到子项目中
	cJSON_AddItemToObject(xiawucha, "cmdType", cmdType);

	//2添加字符串
	clientId = cJSON_CreateString(person.clientId);
	if (clientId == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "clientId", clientId);

	//3. 添加字符串
	AuthCode = cJSON_CreateString(person.AuthCode);
	if (AuthCode == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "AuthCode", AuthCode);

	//4. 添加字符串
	serverId = cJSON_CreateString(person.serverId);
	if (serverId == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "serverId", serverId);

	//5. 添加字符串类型
	r1= cJSON_CreateString(person.r1);
	if (r1 == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "r1", r1);

	//最后一步：
	//上面： 将初始化的数据---添加到--对象中。
	//下面： 将对象---转换成要输出的字符串。
	char *string = NULL;
	string = cJSON_Print(monitor);//将总对象---转换成： 字符串
	if (string == NULL)
	{
		fprintf(stderr, "Failed to print monitor.\n");
	}

	*outlen = strlen(string);
	*outdata = string;
end:
	//清空对象。//返回输出的字符串： ---也可以使用输出参数。
	cJSON_Delete(monitor);
	return 0;		
}

int cJSONMsgKey_Req_to_struct(char *json_string, MsgKey_Req *person)
{
	cJSON *item;

	//1. 将压缩的字符串： 解包成SJSON类型的句柄， 即{}
	cJSON *root = cJSON_Parse(json_string);
	if (root == NULL)
	{
		printf("Error before0: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		//2. 解包成功，通过句柄获取： 通过键值获取一个元素
		//   即： 获取结构体对象 person  {}
		cJSON *object = cJSON_GetObjectItem(root, "person");
		if (object == NULL)
		{
			printf("Error before1: [%s]\n", cJSON_GetErrorPtr());
			cJSON_Delete(root);
			return -1;
		}
		//输出获取元素的： 键值，类型，与值
		//printf("cJSON_GetObjectItem: type=%d, key is %s, value is %s\n", object->type, object->string, object->valuestring);

///////////////////////////////////////////////////////////////////////////////////////////////////
/////阶段二：   开始获取子对象的成员  int直接赋值，  char*  使用 strcpy 或 memset
		if (object != NULL)
		{
			//成员1： int 类型id----如果形成链表： 是不是就不用 “id”key值了---直接
			//        使用头指针即可了。！！！！！！！！！！！！！！！！！！！！
			item = cJSON_GetObjectItem(object, "cmdType");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%d\n", item->type, item->string, item->valueint);
				person->cmdType = item->valueint;  
			}

			//成员2. 获取结构体成员： firstname   strcpy 或 memcpy
			item = cJSON_GetObjectItem(object, "clientId");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->clientId,item->valuestring, strlen(item->valuestring)+1);
			}

			//成员3： lastname  strcpy 或 memcpy
			item = cJSON_GetObjectItem(object, "AuthCode");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->AuthCode, item->valuestring, strlen(item->valuestring)+1);
			}

			//获取成员4. email： strcpy 或 memcpy
			item = cJSON_GetObjectItem(object, "serverId");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->serverId, item->valuestring, strlen(item->valuestring)+1);
			}

			//获取成员5 r1
			item = cJSON_GetObjectItem(object, "r1");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->r1, item->valuestring, strlen(item->valuestring)+1);
			}
		}

		//销毁成员
		cJSON_Delete(root);
	}
	return 0;
}

/*------------------------------结构体结束1-------------------------------------*/
/*-----------------------------结构体部分2--------------------------------------*/
/*typedef struct  _MsgKey_Res
{
int					rv;				//返回值
char				clientId[12];	//客户端编号
char				serverId[12];	//服务器编号
unsigned char		r2[64];			//服务器端随机数
int					seckeyid;		//对称密钥编号    keysn
}MsgKey_Res;*/
int create_xiawucha_MsgKey_Res(char **outdata, int * outlen,int type)
{
	MsgKey_Res person;
	person.rv = 1;
	strcpy(person.clientId, "hehe");
	strcpy(person.serverId, "hehe2");
	strcpy(person.r2,"hehe2");
	person.seckeyid = 1;

	//JSON成员如下： 全定义成 cJSON* 类型
	cJSON *xiawucha = NULL;  //子对象

	cJSON *rv = NULL;
	cJSON *clientId = NULL;
	cJSON *serverId = NULL;
	cJSON *r2 = NULL;
	cJSON *seckeyid = NULL;

	///////////////////////////////////////////////////////////////
	//// 阶段1： 创建对象
	//1. 创建总对象句柄  代表 {  }
	cJSON * monitor = cJSON_CreateObject();
	if (monitor == NULL)
	{
		goto end;
	}
	//2. 创建一个子对象： 作为第一个元素的值
	xiawucha = cJSON_CreateObject();
	if (xiawucha == NULL)
	{
		goto end;
	}
	//3 为对象添加一个元素： 其值为一个子对象
	cJSON_AddItemToObject(monitor, "person", xiawucha);

	/////////////////////////////////////////////////////////////////////
	// 结点二： 开始编码：
	//添加头--参数输入
	cJSON *flag = cJSON_CreateNumber(type);
	if (flag == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "flag", flag);

	//1.为子对象添加元素与值： int类型
	rv = cJSON_CreateNumber(person.rv);
	if (rv == NULL)
	{
		goto end;
	}
	//将数据添加到子项目中
	cJSON_AddItemToObject(xiawucha, "rv", rv);

	//2添加字符串
	clientId = cJSON_CreateString(person.clientId);
	if (clientId == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "clientId", clientId);

	//3. 添加字符串
	serverId = cJSON_CreateString(person.serverId);
	if (serverId == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "serverId", serverId);

	//4. 添加字符串类型
	r2 = cJSON_CreateString(person.r2);
	if (r2 == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha,"r2",r2);

	//5int 
	seckeyid = cJSON_CreateNumber(person.seckeyid);
	if (rv == NULL)
	{
		goto end;
	}
	//将数据添加到子项目中
	cJSON_AddItemToObject(xiawucha, "seckeyid", seckeyid);

	//最后一步：
	//上面： 将初始化的数据---添加到--对象中。
	//下面： 将对象---转换成要输出的字符串。
	char *string = NULL;
	string = cJSON_Print(monitor);//将总对象---转换成： 字符串
	if (string == NULL)
	{
		fprintf(stderr, "Failed to print monitor.\n");
	}

	*outlen =strlen(string);
	*outdata = string;
end:
	//清空对象。//返回输出的字符串： ---也可以使用输出参数。
	cJSON_Delete(monitor);
	return 0;
}
int cJSONMsgKey_Res_to_struct(char *json_string, MsgKey_Res *person)
{
	cJSON *item;

	//1. 将压缩的字符串： 解包成SJSON类型的句柄， 即{}
	cJSON *root = cJSON_Parse(json_string);
	if (root == NULL)
	{
		printf("Error before0: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		//2. 解包成功，通过句柄获取： 通过键值获取一个元素
		//   即： 获取结构体对象 person  {}
		cJSON *object = cJSON_GetObjectItem(root, "person");
		if (object == NULL)
		{
			printf("Error before1: [%s]\n", cJSON_GetErrorPtr());
			cJSON_Delete(root);
			return -1;
		}
		//输出获取元素的： 键值，类型，与值
		//printf("cJSON_GetObjectItem: type=%d, key is %s, value is %s\n", object->type, object->string, object->valuestring);

		///////////////////////////////////////////////////////////////////////////////////////////////////
		/////阶段二：   开始获取子对象的成员  int直接赋值，  char*  使用 strcpy 或 memset
		if (object != NULL)
		{

			//成员1： int 类型----如果形成链表： 是不是就不用 “id”key值了---直接
			item = cJSON_GetObjectItem(object, "rv");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%d\n", item->type, item->string, item->valueint);
				person->rv = item->valueint;
			}

			//成员2. 获取结构体成员：   strcpy 或 memcpy
			item = cJSON_GetObjectItem(object, "clientId");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->clientId, item->valuestring, strlen(item->valuestring)+1);
			}

			//获取成员3. ： strcpy 或 memcpy
			item = cJSON_GetObjectItem(object, "serverId");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->serverId, item->valuestring, strlen(item->valuestring)+1);
			}

			//获取成员4 r2
			item = cJSON_GetObjectItem(object, "r2");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->r2, item->valuestring, strlen(item->valuestring)+1);
			}

			//5 int
			item = cJSON_GetObjectItem(object, "seckeyid");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%d\n", item->type, item->string, item->valueint);
				person->seckeyid = item->valueint;
			}

		}

		//销毁成员
		cJSON_Delete(root);
	}
	return 0;
}
/*------------------------------结构体结束2-------------------------------------*/

int get_struct(char *json_string,int * flag)
{
	cJSON *item;
	//1. 将压缩的字符串： 解包成SJSON类型的句柄， 即{}
	cJSON *root = cJSON_Parse(json_string);
	if (root == NULL)
	{
		printf("Error before0: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		//2. 解包成功，通过句柄获取： 通过键值获取一个元素
		//   即： 获取结构体对象 person  {}
		cJSON *object = cJSON_GetObjectItem(root, "person");
		if (object == NULL)
		{
			printf("Error before1: [%s]\n", cJSON_GetErrorPtr());
			cJSON_Delete(root);
			return -1;
		}
	
		if (object != NULL)
		{
			//成员1： int 类型id----如果形成链表： 是不是就不用 “id”key值了---直接
			item = cJSON_GetObjectItem(object, "flag");
			if (item != NULL)
			{
				*flag= item->valueint;
				printf("获取标志位%d\n",*flag);
			}

		}
	}
	return 0;
}

// 异想天开---失败：
/*
//参数1： 输入的结构体。  参数2： 结构体成员数  参数3： 0x0000 0000 
// int =0； string=1
char* create_xiawucha_encoding(MsgKey_Req  person, int n, int m)
{
	///////////////////////////////////////////////////////////////
	//// 阶段1： 创建对象
	//1. 创建总对象句柄  代表 {  }
	cJSON * monitor = cJSON_CreateObject();
	if (monitor == NULL)
	{
		goto end;
	}
	//2. 创建一个子对象： 作为第一个元素的值
	cJSON * xiawucha = cJSON_CreateObject();
	if (xiawucha == NULL)
	{
		goto end;
	}
	//3 为对象添加一个元素： 其值为一个子对象
	cJSON_AddItemToObject(monitor, "person", xiawucha);


	person.cmdType = 1;
	strcpy(person.clientId, "hehe");
	strcpy(person.AuthCode, "hehe1");
	strcpy(person.serverId, "hehe2");
	strcpy(person.r1, "hehe2");

	//JSON成员如下： 全定义成 cJSON* 类型
	cJSON *xiawucha_int = NULL;
	cJSON *xiawucha_string = NULL;
	cJSON *AuthCode = NULL;
	cJSON *serverId = NULL;
	cJSON *r1 = NULL;

	/////////////////////////////////////////////////////////////////////
	// 结点二： 开始编码：
	for (int i = 0; i < n; i++)
	{
		if (m & bit(i) == 0) //int
		{
			//1.为子对象添加元素与值： int类型
			xiawucha_int = cJSON_CreateNumber(person.cmdType);
			if (xiawucha_int == NULL)
			{
				goto end;
			}
			//将数据添加到子项目中
			cJSON_AddItemToObject(xiawucha, "xiawucha_int", xiawucha_int);
		}
		else               // 字符串
		{
			xiawucha_string = cJSON_CreateString(person.AuthCode);
			if (xiawucha_string == NULL)
			{
				goto end;
			}
			cJSON_AddItemToObject(xiawucha, "AuthCode", xiawucha_string);
		}
	}

	//最后一步：
	//上面： 将初始化的数据---添加到--对象中。
	//下面： 将对象---转换成要输出的字符串。
	char *string = NULL;
	string = cJSON_Print(monitor);//将总对象---转换成： 字符串
	if (string == NULL)
	{
		fprintf(stderr, "Failed to print monitor.\n");
	}
end:
	//清空对象。//返回输出的字符串： ---也可以使用输出参数。
	cJSON_Delete(monitor);
	return string;
}*/

