/******************************************************************************
  �� �� ��    : vpls.h
  �� �� ��    : ����
  ��    ��   	:cai
  �������� : 2012��2��
  �������� : vpls ģ���ڲ�ʵ�ֵ�ͷ�ļ�
  �����б� :
  �޸���ʷ :
  ******************************************************************************/
#ifndef _HAL_VPLS_H_
#define _HAL_VPLS_H_

#define HAL_MSG_VPLS_BASE                           (100+1600)
#define HAL_MSG_VPLS_MSG(n)                         (HAL_MSG_VPLS_BASE  + (n))
#define HAL_MSG_VPLS_VPN_ADD	                    HAL_MSG_VPLS_MSG(1)
#define HAL_MSG_VPLS_VPN_DEL	                    HAL_MSG_VPLS_MSG(2)
#define HAL_MSG_VPLS_PORT_ADD                    	HAL_MSG_VPLS_MSG(3)
#define HAL_MSG_VPLS_PORT_DEL                       HAL_MSG_VPLS_MSG(4)

#define HSL_VPN_PORT_AC 0
#define HSL_VPN_PORT_PW 1

#define HSL_VPORT_DIR_INGRESS 0
#define HSL_VPORT_DIR_EGRESS 1


enum hal_vport_role{
	HUB,
	SPOKE
};


struct hal_msg_vpls_port_s
{
	signed int vpnIndex;

	signed int vportId;
	signed int portType;
	enum hal_vport_role portRole;

	struct vport_infor
	{
		signed int port;

		//ac
		signed int tag;

		//pw
		unsigned int tunnel;
		unsigned int pw;
	}vport[2];

};



/////for l2elin temp///////////////////////////////////////////////////////

#define HAL_MSG_L2ELINE_BASE                           (100+1650)
#define HAL_MSG_L2ELINE_MSG(n)                         (HAL_MSG_L2ELINE_BASE  + (n))
#define HAL_MSG_L2ELINE_ADD	                    HAL_MSG_L2ELINE_MSG(1)
#define HAL_MSG_L2ELINE_DEL	                    HAL_MSG_L2ELINE_MSG(2)

struct hal_msg_l2eline_s
{
	signed int Index;

	signed int inPort;
	signed int inTag;

	signed int outPort;
	signed int outTag;
};

/*2.vplsҵ��Ĵ�����ɾ����*/
/*HAL_MSG_VPN_ADD/HAL_MSG_VPN_DEL */                 
typedef struct {       
     unsigned int             hsl_vpn_id;          /*ƽ̨�·���vpn id */       
     unsigned int             hsl_vpn_type;        /*vpls:1; vpws:0;  */         
     /*δ֪�������鲥���㲥��ת����㲥ʹ��ֻ����vplsҵ����Ч, ֻ��vplsҵ����Ч*/       
    unsigned int             un_pkt_flg;                  
    unsigned int             mac_learn_flg ;      /*mac ��ַѧϰʹ��,ֻ����vplsҵ����Ч*/   
}hsl_bcm_msg_vpn_cfg;
/*ע��ɾ��ʱֻ��Ҫ����hsl_vpn_id��*/

/*3.��vpn��ӻ�ɾ���˿�*/
/*HAL_MSG_VPN_PORT_ADD/HAL_MSG_VPN_PORT_DEL*/

/* add from 0213 use tunnel add */
typedef struct {

    unsigned int   hsl_vpn_id;    
    unsigned int svp_port_type; /*�˿����� AC��0�� pw��1*/       
    unsigned int pannel_port;    /*���˿ںţ� acΪ����˿ڣ� pwΪtunnel���˿�*/        
    unsigned int   vpn_port_attr;   /*hub spoke �������ã�hub��0�� spoke��1*/  
    int out_disable;      /*=1�رճ��˿�*/   
    int in_disable;       /*=1�رն˿���*/    

    /*ac�˿�vlan*/    
    int ac_vlan;  //int16        

    //pw port
    unsigned int  in_pw_label;
    unsigned int  out_pw_label;
    unsigned char  out_pw_exp;
	unsigned int lsp_id;
}hsl_bcm_msg_vpn_port_cfg;

typedef struct {

    unsigned int   hsl_vpn_id;    
    unsigned int svp_port_type; /*�˿����� AC��0�� pw��1*/       
    unsigned int pannel_port;    /*���˿ںţ� acΪ����˿ڣ� pwΪtunnel���˿�*/        
    unsigned int   vpn_port_attr;   /*hub spoke �������ã�hub��0�� spoke��1*/  
    int out_disable;      /*=1�رճ��˿�*/   
    int in_disable;       /*=1�رն˿���*/    

    /*ac�˿�vlan*/    
    int ac_vlan;  //int16        

    //pw port
    unsigned int  in_pw_label;
	
    unsigned int in_tunnel_label;
    int   tunnel_in_vlan;     /*=0, ��ʾuntag����*/

    unsigned int  out_pw_label;
    unsigned char  out_pw_exp;
    unsigned int out_tunnel_label;
    unsigned char out_tunnel_exp;
    unsigned char   tunnel_out_mac[6];
    int   tunnel_out_vlan;    /*=0�� ��ʾuntag����*/

}hsl_bcm_msg_vpn_port_cfg_1307;

/*ע��ɾ���˿�ʱ��ac�˿���Ҫ����pannel_port + ac_vlan; pw�˿�ֻ��Ҫ����pannel_port + in_pw_label;*/


/*4.���ӡ�ɾ���������*/
/*HAL_MSG_LSP_ADD\HAL_MSG_LSP_DEL*/
typedef enum
{
      IAL_LSP_NONE = 0,
      IAL_LSP_PE_UP,
      IAL_LSP_PE_DOWN,
      IAL_LSP_P_SWITCH
}ial_lsp_type;



typedef struct
{
    unsigned int tunnel_id;//add from hsl-0213
    ial_lsp_type  lsp_type;//add from hsl-0213
    unsigned int in_port;
    unsigned int in_label;        /*���ǩ*/
    unsigned int tunnel_in_vlan;     /*=0, ��ʾuntag����*/

    unsigned int out_port;
    unsigned int out_lable;       /*mpls ����ǩ*/
    unsigned char out_tunnel_exp;
    unsigned char tunnel_out_mac[6];
    unsigned int tunnel_out_vlan;    /*=0�� ��ʾuntag����*/
}hsl_bcm_msg_mpls_tunnel_cfg;
/*ע��ɾ�����ʱ��ֻ��Ҫ����in_label + in_port*/

/*5.�����豸mac��ַ�� �˿ڵ�ַΪ�豸mac+port*/
/*HAL_MSG_SET_DEV_SRC_MAC*/
typedef struct
{
    unsigned char   dev_src_mac[6];
}hsl_bcm_msg_dev_mac;

/*6.�鲥����ӡ�ɾ�����ݶ�ÿ��vpn��������8���鲥��)*/
/*HAL_MSG_MULTICAST_GROUP_ADD/HAL_MSG_MULTICAST_GROUP_DEL*/
typedef struct
{
    unsigned int hsl_vpn_id;
    unsigned int hsl_mc_group_id;  /*��0~7���*/
    unsigned char  mc_mac[6];
}hsl_bcm_msg_mcast_grp;
/*ע��ɾ�����ʱ��ֻ��Ҫ����hsl_vpn_id + hsl_mc_group_id*/

/*7.���ɾ���鲥�˿�*/
/*HAL_MSG_MULTICAST_GRP_PORT_ADD\HAL_MSG_MULTICAST_GRP_PORT_DEL*/
typedef struct
{
    unsigned int hsl_vpn_id;
    unsigned int hsl_mc_group_id;

    unsigned int svp_port_type; /*�˿����� AC��0�� pw��1*/
    unsigned int pannel_port;    /*���˿ںţ� acΪ����˿ڣ� pwΪtunnel���˿�*/

    unsigned int ac_vlan;
    unsigned int pw_label;
}hsl_bcm_msg_mcast_grp_port;


typedef struct
{
    unsigned int hsl_vpn_id;      /*vpn id*/
    unsigned int  port;           /*�˿ں�*/
    unsigned char mac_addr[6];
    unsigned char src_drop;       /*ԭmac��ַΪ��mac����*/
    unsigned char dst_drop;       /*Ŀ��mac��ַΪ��mac����*/
	
    unsigned int svp_type;         /*�˿����� AC��0�� pw��1*/
    unsigned int ac_vlan;
    unsigned int pw_label;
}hsl_bcm_msg_static_mac_cfg;


#endif

