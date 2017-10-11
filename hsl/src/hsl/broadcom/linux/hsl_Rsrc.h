
/*��Դ��*/
#ifndef _HSL_RSRC_H_
#define _HSL_RSRC_H_



#define RSRC_OK (0)
#define RSRC_INVALID_PARAM (1)
#define RSRC_NO_AVAIL_MEMORY (2)
#define RSRC_INVALID_POINTER (3)
#define RSRC_RELEASE_AGAIN   (4)
#define RSRC_NO_AVAIL_RESOURCE (5)

#define RSRC_RESERV_VALUE (0xffff)


typedef struct
{
	unsigned short usMinValue;				/* ��С��Դ�ţ���Դʹ������д   */
	unsigned short usMaxValue;				/* �����Դ�ţ���Դʹ������д   */
	unsigned char  aRsrName[10];				/* ��Դ���ƣ���Դʹ������д     */
	unsigned short *pRsrLink;				/* ��Դ��                       */
	unsigned short usFreePos;				/* ��ǰ������Դ                 */
	unsigned short usAlloced;				/* ��ǰ�Է�����Դ��             */
	apn_sem_id   ulSim;					    /* �ź���                       */
}TRsrMangrInfo_t;



unsigned int RsrcMgrCreate(TRsrMangrInfo_t *ptRsr);
unsigned int RsrcMgrGet(TRsrMangrInfo_t *ptRsr, unsigned short *pValue);
unsigned int RsrcMgrRet(TRsrMangrInfo_t *ptRsr,unsigned short usValue);



#define HSL_CHECK_RESULT(rc, rst) \
{  \
    rc = rst; \
    if(rc != 0)  \
    {   \
          HSL_LOG (HSL_LOG_PLATFORM, HSL_LEVEL_INFO,"file: %s, line: %d, return err %d, bcm err:%s\n",  __FILE__, __LINE__, rc,  bcm_errmsg(rc));  \
          return rc;  \
    }  \
}

#endif

