#include "cJSON_ENCONDING.h"
#define bit(i) (0x0000<<i)
#include <time.h>


int create_xiawucha_MsgKey_Req(char **outdata, int * outlen,int type);
int cJSONMsgKey_Req_to_struct(char *json_string, MsgKey_Req *person);
int create_xiawucha_MsgKey_Res(char **outdata, int * outlen, int type);
int cJSONMsgKey_Res_to_struct(char *json_string, MsgKey_Res *person);
int get_struct(char *json_string, int * flag);

/*---------------------------��������----------------------------*/
//cJSON���1
//����һ��������֧�־����嵥�ļ�����	
char* create_xiawucha_monitor(void)
{
	people person;

	person.id = 5;
	strcpy(person.firstName, "hehe");
	strcpy(person.lastName, "hehe1");
	strcpy(person.email, "hehe2");
	person.height = 12.7;

	//JSON��Ա���£� ȫ����� cJSON* ����
	cJSON *xiawucha = NULL;  //�Ӷ���

	cJSON *id = NULL;
	cJSON *firstName = NULL;
	cJSON *lastName = NULL;
	cJSON *email = NULL;
	cJSON *height = NULL;

	///////////////////////////////////////////////////////////////
	//// �׶�1�� ��������
	//1. �����ܶ�����  ���� {  }
	cJSON * monitor = cJSON_CreateObject();
	if (monitor == NULL)
	{
		goto end;
	}
	//2. ����һ���Ӷ��� ��Ϊ��һ��Ԫ�ص�ֵ
	xiawucha = cJSON_CreateObject();
	if (xiawucha == NULL)
	{
		goto end;
	}
	//3 Ϊ�������һ��Ԫ�أ� ��ֵΪһ���Ӷ���
	cJSON_AddItemToObject(monitor, "person", xiawucha);

	/////////////////////////////////////////////////////////////////////
	// ������ ��ʼ���룺

	//1.Ϊ�Ӷ������Ԫ����ֵ�� int����
	id = cJSON_CreateNumber(person.id);
	if (id == NULL)
	{
		goto end;
	}
	//��������ӵ�����Ŀ��
	cJSON_AddItemToObject(xiawucha, "id", id);

	//2����ַ���
	firstName = cJSON_CreateString(person.firstName);
	if (firstName == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "firstName", firstName);

	//3. ����ַ���
	lastName = cJSON_CreateString(person.lastName);
	if (lastName == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "lastName", lastName);


	//4. ����ַ���
	email = cJSON_CreateString(person.email);
	if (email == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "email", email);

	//5. ���double����
	height = cJSON_CreateNumber(person.height);
	if (height == NULL)
	{
		goto end;
	}
	//��������ӵ�����Ŀ��
	cJSON_AddItemToObject(xiawucha, "height", height);

	//���һ����
	//���棺 ����ʼ��������---��ӵ�--�����С�
	//���棺 ������---ת����Ҫ������ַ�����
	char *string = NULL;
	string = cJSON_Print(monitor);//���ܶ���---ת���ɣ� �ַ���
	if (string == NULL)
	{
		fprintf(stderr, "Failed to print monitor.\n");
	}

end:
	//��ն���//����������ַ����� ---Ҳ����ʹ�����������
	cJSON_Delete(monitor);
	return string;
}
//cJSON�����
//������ķ�ʽ��ͬ---ֱ����ֵ�����ܲ����㡣
//û��ʹ������
char* create_monitor(void)
{
	//JSON��Ա���£� ȫ����� cJSON* ����
	cJSON *xiawucha = NULL;  //�Ӷ���

	cJSON *id = NULL;
	cJSON *firstName = NULL;
	cJSON *lastName = NULL;
	cJSON *email = NULL;
	cJSON *height = NULL;

	///////////////////////////////////////////////////////////////
	//// �׶�1�� ��������
	//1. �����ܶ�����  ���� {  }
	cJSON *monitor = cJSON_CreateObject();
	if (monitor == NULL)
	{
		goto end;
	}
	//2. ����һ���Ӷ��� ��Ϊ��һ��Ԫ�ص�ֵ
	xiawucha = cJSON_CreateObject();
	if (xiawucha == NULL)
	{
		goto end;
	}
	//3 Ϊ�������һ��Ԫ�أ� ��ֵΪһ���Ӷ���
	cJSON_AddItemToObject(monitor, "person", xiawucha);

	/////////////////////////////////////////////////////////////////////
	// ������ ��ʼ���룺

	//1.Ϊ�Ӷ������Ԫ����ֵ�� int����
	id = cJSON_CreateNumber(5);
	if (id == NULL)
	{
		goto end;
	}
	//��������ӵ�����Ŀ��
	cJSON_AddItemToObject(xiawucha, "id", id);

	//2����ַ���
	firstName = cJSON_CreateString("hehe");
	if (firstName == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "firstName", firstName);

	//3. ����ַ���
	lastName = cJSON_CreateString("hehe1");
	if (lastName == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "lastName", lastName);


	//4. ����ַ���
	email = cJSON_CreateString("hehe2");
	if (email == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "email", email);

	//5. ���double����
	height = cJSON_CreateNumber(17.6);
	if (height == NULL)
	{
		goto end;
	}
	//��������ӵ�����Ŀ��
	cJSON_AddItemToObject(xiawucha, "height", height);

	//���һ����
	//���棺 ����ʼ��������---��ӵ�--�����С�
	//���棺 ������---ת����Ҫ������ַ�����
	char *string = NULL;
	string = cJSON_Print(monitor);//���ܶ���---ת���ɣ� �ַ���
	if (string == NULL)
	{
		fprintf(stderr, "Failed to print monitor.\n");
	}

end:
	//��ն���//����������ַ����� ---Ҳ����ʹ�����������
	cJSON_Delete(monitor);
	return string;
}
//���ȣ� ���
//����1������õ����ַ����� 
//����2������������ṹ��---����ȡ��ֵ�� ����ṹ���Ա
int cJSON_to_struct(char *json_string, people *person)
{
	cJSON *item;

	//1. ��ѹ�����ַ����� �����SJSON���͵ľ���� ��{}
	cJSON *root = cJSON_Parse(json_string);
	if (root == NULL)
	{
		printf("Error before0: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		//2. ����ɹ���ͨ�������ȡ�� ͨ����ֵ��ȡһ��Ԫ��
		//   ���� ��ȡ�ṹ����� person  {}
		cJSON *object = cJSON_GetObjectItem(root, "person");
		if (object == NULL)
		{
			printf("Error before1: [%s]\n", cJSON_GetErrorPtr());
			cJSON_Delete(root);
			return -1;
		}
		//�����ȡԪ�صģ� ��ֵ�����ͣ���ֵ
		printf("cJSON_GetObjectItem: type=%d, key is %s, value is %s\n", object->type, object->string, object->valuestring);

		///////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////
		//  ��ʼ��ȡ�Ӷ���ĳ�Ա
		if (object != NULL)
		{
			//��Ա1�� int ����id----����γ����� �ǲ��ǾͲ��� ��id��keyֵ��---ֱ��
			//        ʹ��ͷָ�뼴���ˡ�����������������������������������������
			item = cJSON_GetObjectItem(object, "id");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%d\n", item->type, item->string, item->valueint);
				person->id = item->valueint;
			}


			//��Ա2. ��ȡ�ṹ���Ա�� firstname   strcpy �� memcpy
			item = cJSON_GetObjectItem(object, "firstName");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->firstName, item->valuestring, strlen(item->valuestring));
			}

			//��Ա3�� lastname  strcpy �� memcpy
			item = cJSON_GetObjectItem(object, "lastName");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->lastName, item->valuestring, strlen(item->valuestring));
			}

			//��ȡ��Ա4. email�� strcpy �� memcpy
			item = cJSON_GetObjectItem(object, "email");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->email, item->valuestring, strlen(item->valuestring));
			}

			//height��Ա5.
			item = cJSON_GetObjectItem(object, "height");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuedouble=%f\n", item->type, item->string, item->valuedouble);
				person->height = item->valuedouble;
			}
		}

		//���ٳ�Ա
		cJSON_Delete(root);
	}
	return 0;
}

/*-----------------------------���Խ׶ν���----------------------------------*/

/*-----------------------------�ܱ��벿��--------------------------------------*/
//������������
/*int MngClient_InitInfo(MngClient_Info * pCltInfo)
{
	strcpy(pCltInfo->clientId, "clientID");  // �ͻ��˱��
	strcpy(pCltInfo->AuthCode, "authcode");  // ��֤��
	strcpy(pCltInfo->serverId, "serverID");  // �������˱��
	strcpy(pCltInfo->serverip, "127.0.0.1"); ////IP��ַ

	pCltInfo->serverport = 9999;             //�˿�
	pCltInfo->maxnode = 1;                   //�����ڴ�keyid ���������ڴ�ʱʹ��
	pCltInfo->shmkey = ftok("/", 'x');       //�����ڴ�keyid ���������ڴ�ʱʹ��
	// IPC_CreatShm(pCltInfo->shmkey, 100, &pCltInfo->shmhdl);
	return 0;
}*/

// ��Сд�ַ�, ����, �����ַ�: ���볤��--�����ȡ�ַ���
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

//�ܱ���
int MsgEncode(
	void			*pStruct, /*���룺�ṹ��*/
	int				type,      /*�ṹ����*/
	unsigned char	**outData, /*out--�ַ���*/
	int				*outLen)   //����ַ�������
{
   //��һ������֤��������ȷ��
   /*if ( outData == NULL || outLen == NULL)
	{
		perror("���������Ч\n");
		return -1;
	}*/

	//���ܱ��������
	char *ceshi = NULL;
	int len = -1;
	//�ڶ������ж����ĸ��ṹ��
	printf("%d\n",type);
	switch (type)
	{
	case ID_MsgKey_Req:
		printf("�ҽ�����60��\n");
		create_xiawucha_MsgKey_Req(&ceshi,&len,type);
		break;
	case ID_MsgKey_Res:
		printf("�ҽ�����61��\n");
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


//�ܽ���
int MsgDecode(
	unsigned char *inData,  /*��������*/
	int           inLen,    /*�������ݳ���*/
	void          *pStruct /*out--�ṹ��*/,
	int           *type)    /*out�ṹ����*/
{
	//������֤
	if (inData == NULL || inLen <= 0)
	{
		return -1;
	}

	//��ȡ��һ��ֵ�� ��ֵ�����---�ڸ�����ֵ�жϡ�
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


/*------------------------------�ܽ��벿�ֽ���----------------------------------*/
/*-------------------------------�ṹ�岿��1--------------------------------------*/
/*typedef struct _MsgKey_Req
{
	//1 ��ԿЭ��  	//2 ��ԿУ��; 	//3 ��Կע��
	int				cmdType;		//�������� 
	char			clientId[12];	//�ͻ��˱��
	char			AuthCode[16];	//��֤��
	char			serverId[12];	//�������˱�� 
	char			r1[64];			//�ͻ��������
}MsgKey_Req;*/
int create_xiawucha_MsgKey_Req(char **outdata,int * outlen,int type)
{
	MsgKey_Req person;
	person.cmdType = 1;
	strcpy(person.clientId, "hehe");
	strcpy(person.AuthCode, "hehe1");
	strcpy(person.serverId, "hehe2");
	strcpy(person.r1, "hehe2");

	//JSON��Ա���£� ȫ����� cJSON* ����
	cJSON *xiawucha = NULL;  //�Ӷ���
	cJSON *cmdType  = NULL;
	cJSON *clientId = NULL;
	cJSON *AuthCode = NULL;
	cJSON *serverId = NULL;
	cJSON *r1 = NULL;

	///////////////////////////////////////////////////////////////
	//// �׶�1�� ��������
	//1. �����ܶ�����  ���� {  }
	cJSON * monitor = cJSON_CreateObject();
	if (monitor == NULL)
	{
		printf("1\n");
		goto end;
	}
	//2. ����һ���Ӷ��� ��Ϊ��һ��Ԫ�ص�ֵ
	xiawucha = cJSON_CreateObject();
	if (xiawucha == NULL)
	{
		printf("2\n");
		goto end;
	}
	//3 Ϊ�������һ��Ԫ�أ� ��ֵΪһ���Ӷ���
	cJSON_AddItemToObject(monitor, "person", xiawucha);

	/////////////////////////////////////////////////////////////////////
	// ������ ��ʼ���룺
    //���ͷ--��������
	cJSON *flag = cJSON_CreateNumber(type);
	if (flag == NULL)
	{
		printf("3\n");
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "flag", flag);

	//1.Ϊ�Ӷ������Ԫ����ֵ�� int����
	cmdType = cJSON_CreateNumber(person.cmdType);
	if (cmdType == NULL)
	{
		printf("4\n");
		goto end;
	}
	//��������ӵ�����Ŀ��
	cJSON_AddItemToObject(xiawucha, "cmdType", cmdType);

	//2����ַ���
	clientId = cJSON_CreateString(person.clientId);
	if (clientId == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "clientId", clientId);

	//3. ����ַ���
	AuthCode = cJSON_CreateString(person.AuthCode);
	if (AuthCode == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "AuthCode", AuthCode);

	//4. ����ַ���
	serverId = cJSON_CreateString(person.serverId);
	if (serverId == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "serverId", serverId);

	//5. ����ַ�������
	r1= cJSON_CreateString(person.r1);
	if (r1 == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "r1", r1);

	//���һ����
	//���棺 ����ʼ��������---��ӵ�--�����С�
	//���棺 ������---ת����Ҫ������ַ�����
	char *string = NULL;
	string = cJSON_Print(monitor);//���ܶ���---ת���ɣ� �ַ���
	if (string == NULL)
	{
		fprintf(stderr, "Failed to print monitor.\n");
	}

	*outlen = strlen(string);
	*outdata = string;
end:
	//��ն���//����������ַ����� ---Ҳ����ʹ�����������
	cJSON_Delete(monitor);
	return 0;		
}

int cJSONMsgKey_Req_to_struct(char *json_string, MsgKey_Req *person)
{
	cJSON *item;

	//1. ��ѹ�����ַ����� �����SJSON���͵ľ���� ��{}
	cJSON *root = cJSON_Parse(json_string);
	if (root == NULL)
	{
		printf("Error before0: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		//2. ����ɹ���ͨ�������ȡ�� ͨ����ֵ��ȡһ��Ԫ��
		//   ���� ��ȡ�ṹ����� person  {}
		cJSON *object = cJSON_GetObjectItem(root, "person");
		if (object == NULL)
		{
			printf("Error before1: [%s]\n", cJSON_GetErrorPtr());
			cJSON_Delete(root);
			return -1;
		}
		//�����ȡԪ�صģ� ��ֵ�����ͣ���ֵ
		//printf("cJSON_GetObjectItem: type=%d, key is %s, value is %s\n", object->type, object->string, object->valuestring);

///////////////////////////////////////////////////////////////////////////////////////////////////
/////�׶ζ���   ��ʼ��ȡ�Ӷ���ĳ�Ա  intֱ�Ӹ�ֵ��  char*  ʹ�� strcpy �� memset
		if (object != NULL)
		{
			//��Ա1�� int ����id----����γ����� �ǲ��ǾͲ��� ��id��keyֵ��---ֱ��
			//        ʹ��ͷָ�뼴���ˡ�����������������������������������������
			item = cJSON_GetObjectItem(object, "cmdType");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%d\n", item->type, item->string, item->valueint);
				person->cmdType = item->valueint;  
			}

			//��Ա2. ��ȡ�ṹ���Ա�� firstname   strcpy �� memcpy
			item = cJSON_GetObjectItem(object, "clientId");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->clientId,item->valuestring, strlen(item->valuestring)+1);
			}

			//��Ա3�� lastname  strcpy �� memcpy
			item = cJSON_GetObjectItem(object, "AuthCode");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->AuthCode, item->valuestring, strlen(item->valuestring)+1);
			}

			//��ȡ��Ա4. email�� strcpy �� memcpy
			item = cJSON_GetObjectItem(object, "serverId");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->serverId, item->valuestring, strlen(item->valuestring)+1);
			}

			//��ȡ��Ա5 r1
			item = cJSON_GetObjectItem(object, "r1");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->r1, item->valuestring, strlen(item->valuestring)+1);
			}
		}

		//���ٳ�Ա
		cJSON_Delete(root);
	}
	return 0;
}

/*------------------------------�ṹ�����1-------------------------------------*/
/*-----------------------------�ṹ�岿��2--------------------------------------*/
/*typedef struct  _MsgKey_Res
{
int					rv;				//����ֵ
char				clientId[12];	//�ͻ��˱��
char				serverId[12];	//���������
unsigned char		r2[64];			//�������������
int					seckeyid;		//�Գ���Կ���    keysn
}MsgKey_Res;*/
int create_xiawucha_MsgKey_Res(char **outdata, int * outlen,int type)
{
	MsgKey_Res person;
	person.rv = 1;
	strcpy(person.clientId, "hehe");
	strcpy(person.serverId, "hehe2");
	strcpy(person.r2,"hehe2");
	person.seckeyid = 1;

	//JSON��Ա���£� ȫ����� cJSON* ����
	cJSON *xiawucha = NULL;  //�Ӷ���

	cJSON *rv = NULL;
	cJSON *clientId = NULL;
	cJSON *serverId = NULL;
	cJSON *r2 = NULL;
	cJSON *seckeyid = NULL;

	///////////////////////////////////////////////////////////////
	//// �׶�1�� ��������
	//1. �����ܶ�����  ���� {  }
	cJSON * monitor = cJSON_CreateObject();
	if (monitor == NULL)
	{
		goto end;
	}
	//2. ����һ���Ӷ��� ��Ϊ��һ��Ԫ�ص�ֵ
	xiawucha = cJSON_CreateObject();
	if (xiawucha == NULL)
	{
		goto end;
	}
	//3 Ϊ�������һ��Ԫ�أ� ��ֵΪһ���Ӷ���
	cJSON_AddItemToObject(monitor, "person", xiawucha);

	/////////////////////////////////////////////////////////////////////
	// ������ ��ʼ���룺
	//���ͷ--��������
	cJSON *flag = cJSON_CreateNumber(type);
	if (flag == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "flag", flag);

	//1.Ϊ�Ӷ������Ԫ����ֵ�� int����
	rv = cJSON_CreateNumber(person.rv);
	if (rv == NULL)
	{
		goto end;
	}
	//��������ӵ�����Ŀ��
	cJSON_AddItemToObject(xiawucha, "rv", rv);

	//2����ַ���
	clientId = cJSON_CreateString(person.clientId);
	if (clientId == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "clientId", clientId);

	//3. ����ַ���
	serverId = cJSON_CreateString(person.serverId);
	if (serverId == NULL)
	{
		goto end;
	}
	cJSON_AddItemToObject(xiawucha, "serverId", serverId);

	//4. ����ַ�������
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
	//��������ӵ�����Ŀ��
	cJSON_AddItemToObject(xiawucha, "seckeyid", seckeyid);

	//���һ����
	//���棺 ����ʼ��������---��ӵ�--�����С�
	//���棺 ������---ת����Ҫ������ַ�����
	char *string = NULL;
	string = cJSON_Print(monitor);//���ܶ���---ת���ɣ� �ַ���
	if (string == NULL)
	{
		fprintf(stderr, "Failed to print monitor.\n");
	}

	*outlen =strlen(string);
	*outdata = string;
end:
	//��ն���//����������ַ����� ---Ҳ����ʹ�����������
	cJSON_Delete(monitor);
	return 0;
}
int cJSONMsgKey_Res_to_struct(char *json_string, MsgKey_Res *person)
{
	cJSON *item;

	//1. ��ѹ�����ַ����� �����SJSON���͵ľ���� ��{}
	cJSON *root = cJSON_Parse(json_string);
	if (root == NULL)
	{
		printf("Error before0: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		//2. ����ɹ���ͨ�������ȡ�� ͨ����ֵ��ȡһ��Ԫ��
		//   ���� ��ȡ�ṹ����� person  {}
		cJSON *object = cJSON_GetObjectItem(root, "person");
		if (object == NULL)
		{
			printf("Error before1: [%s]\n", cJSON_GetErrorPtr());
			cJSON_Delete(root);
			return -1;
		}
		//�����ȡԪ�صģ� ��ֵ�����ͣ���ֵ
		//printf("cJSON_GetObjectItem: type=%d, key is %s, value is %s\n", object->type, object->string, object->valuestring);

		///////////////////////////////////////////////////////////////////////////////////////////////////
		/////�׶ζ���   ��ʼ��ȡ�Ӷ���ĳ�Ա  intֱ�Ӹ�ֵ��  char*  ʹ�� strcpy �� memset
		if (object != NULL)
		{

			//��Ա1�� int ����----����γ����� �ǲ��ǾͲ��� ��id��keyֵ��---ֱ��
			item = cJSON_GetObjectItem(object, "rv");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%d\n", item->type, item->string, item->valueint);
				person->rv = item->valueint;
			}

			//��Ա2. ��ȡ�ṹ���Ա��   strcpy �� memcpy
			item = cJSON_GetObjectItem(object, "clientId");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->clientId, item->valuestring, strlen(item->valuestring)+1);
			}

			//��ȡ��Ա3. �� strcpy �� memcpy
			item = cJSON_GetObjectItem(object, "serverId");
			if (item != NULL)
			{
				printf("cJSON_GetObjectItem: type=%d, string is %s, valuestring=%s\n", item->type, item->string, item->valuestring);
				memcpy(person->serverId, item->valuestring, strlen(item->valuestring)+1);
			}

			//��ȡ��Ա4 r2
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

		//���ٳ�Ա
		cJSON_Delete(root);
	}
	return 0;
}
/*------------------------------�ṹ�����2-------------------------------------*/

int get_struct(char *json_string,int * flag)
{
	cJSON *item;
	//1. ��ѹ�����ַ����� �����SJSON���͵ľ���� ��{}
	cJSON *root = cJSON_Parse(json_string);
	if (root == NULL)
	{
		printf("Error before0: [%s]\n", cJSON_GetErrorPtr());
		return -1;
	}
	else
	{
		//2. ����ɹ���ͨ�������ȡ�� ͨ����ֵ��ȡһ��Ԫ��
		//   ���� ��ȡ�ṹ����� person  {}
		cJSON *object = cJSON_GetObjectItem(root, "person");
		if (object == NULL)
		{
			printf("Error before1: [%s]\n", cJSON_GetErrorPtr());
			cJSON_Delete(root);
			return -1;
		}
	
		if (object != NULL)
		{
			//��Ա1�� int ����id----����γ����� �ǲ��ǾͲ��� ��id��keyֵ��---ֱ��
			item = cJSON_GetObjectItem(object, "flag");
			if (item != NULL)
			{
				*flag= item->valueint;
				printf("��ȡ��־λ%d\n",*flag);
			}

		}
	}
	return 0;
}

// �����쿪---ʧ�ܣ�
/*
//����1�� ����Ľṹ�塣  ����2�� �ṹ���Ա��  ����3�� 0x0000 0000 
// int =0�� string=1
char* create_xiawucha_encoding(MsgKey_Req  person, int n, int m)
{
	///////////////////////////////////////////////////////////////
	//// �׶�1�� ��������
	//1. �����ܶ�����  ���� {  }
	cJSON * monitor = cJSON_CreateObject();
	if (monitor == NULL)
	{
		goto end;
	}
	//2. ����һ���Ӷ��� ��Ϊ��һ��Ԫ�ص�ֵ
	cJSON * xiawucha = cJSON_CreateObject();
	if (xiawucha == NULL)
	{
		goto end;
	}
	//3 Ϊ�������һ��Ԫ�أ� ��ֵΪһ���Ӷ���
	cJSON_AddItemToObject(monitor, "person", xiawucha);


	person.cmdType = 1;
	strcpy(person.clientId, "hehe");
	strcpy(person.AuthCode, "hehe1");
	strcpy(person.serverId, "hehe2");
	strcpy(person.r1, "hehe2");

	//JSON��Ա���£� ȫ����� cJSON* ����
	cJSON *xiawucha_int = NULL;
	cJSON *xiawucha_string = NULL;
	cJSON *AuthCode = NULL;
	cJSON *serverId = NULL;
	cJSON *r1 = NULL;

	/////////////////////////////////////////////////////////////////////
	// ������ ��ʼ���룺
	for (int i = 0; i < n; i++)
	{
		if (m & bit(i) == 0) //int
		{
			//1.Ϊ�Ӷ������Ԫ����ֵ�� int����
			xiawucha_int = cJSON_CreateNumber(person.cmdType);
			if (xiawucha_int == NULL)
			{
				goto end;
			}
			//��������ӵ�����Ŀ��
			cJSON_AddItemToObject(xiawucha, "xiawucha_int", xiawucha_int);
		}
		else               // �ַ���
		{
			xiawucha_string = cJSON_CreateString(person.AuthCode);
			if (xiawucha_string == NULL)
			{
				goto end;
			}
			cJSON_AddItemToObject(xiawucha, "AuthCode", xiawucha_string);
		}
	}

	//���һ����
	//���棺 ����ʼ��������---��ӵ�--�����С�
	//���棺 ������---ת����Ҫ������ַ�����
	char *string = NULL;
	string = cJSON_Print(monitor);//���ܶ���---ת���ɣ� �ַ���
	if (string == NULL)
	{
		fprintf(stderr, "Failed to print monitor.\n");
	}
end:
	//��ն���//����������ַ����� ---Ҳ����ʹ�����������
	cJSON_Delete(monitor);
	return string;
}*/

