#include "cJSON_ENCONDING.h"
#include <assert.h>
int main(int argc, char **argv)
{
	unsigned char *outData = NULL;
	int outLen = -1;
    int m= MsgEncode(NULL,60,&outData, &outLen);
    if(m==0)
	 printf("编码成功\n");
	printf("%s\n",outData);
	printf("%d\n", outLen);

	MsgKey_Req person;
	int type = -1;
	MsgDecode(outData, outLen,&person, &type);

	/*
	printf("%d\n",person.seckeyid);
	printf("%s\n", person.r2);
	printf("%s\n", person.serverId);
	printf("%s\n", person.clientId);
	printf("%d\n", person.rv);
	*/
	printf("%d\n", person.cmdType);
	printf("%s\n", person.r1);
	printf("%s\n", person.serverId);
	printf("%s\n", person.clientId);
	printf("%s\n", person.AuthCode);


	/*
	//将数据编码
	char *string = create_monitor(); 
	printf("编码成功\n");

	//将数据解码
	people person;
	int ret = cJSON_to_struct(string, &person);
	assert(ret==0);// 为真--不执行； 为假： 中断
	
	// 释放： 编码内部申请堆空间，需要释放。
	free(string);
	*/

	/*
	char *outData = NULL;
	int outLen = -1;
	create_xiawucha_MsgKey_Req(&outData, &outLen, 60);
	printf("%d\n",outLen);
	printf("%s\n", outData);

	int flag = -1;
	get_struct(outData, &flag);
	printf("%d\n",flag);

	MsgKey_Req person;
	cJSONMsgKey_Req_to_struct(outData, &person);
	*/

	/*
	char *outData = NULL;
	int outLen = -1;
	create_xiawucha_MsgKey_Res(&outData, &outLen, 61);
	printf("%d\n", outLen);
	printf("%s\n", outData);

	int flag = -1;
	get_struct(outData, &flag);
	printf("%d\n", flag);

	MsgKey_Res person;
	cJSONMsgKey_Res_to_struct(outData, &person);
	*/


	return 0;
}
