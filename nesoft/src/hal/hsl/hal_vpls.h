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

#ifndef HAL_MSG_BASE_MSG
#define HAL_MSG_BASE_MSG(n)                         (100 + (n))
#endif

/*djg 
 *HAL_MSG_BASE_MSG(1750) is used by ptp in file hal_ptp.h.so it can not be used here.
 */
#define HAL_MSG_VPN_BASE                           HAL_MSG_BASE_MSG(1500)
#define HAL_MSG_VPN_MSG(n)                        (HAL_MSG_VPN_BASE  + (n))
#define HAL_MSG_VPN_ADD	                           HAL_MSG_VPN_MSG(1)
#define HAL_MSG_VPN_DEL	                           HAL_MSG_VPN_MSG(2)
#define HAL_MSG_VPN_PORT_ADD                       HAL_MSG_VPN_MSG(3)
#define HAL_MSG_VPN_PORT_DEL                       HAL_MSG_VPN_MSG(4)
#define HAL_MSG_VPN_STATIC_MAC_ADD                 HAL_MSG_VPN_MSG(5)
#define HAL_MSG_VPN_STATIC_MAC_DEL                 HAL_MSG_VPN_MSG(6)


/*add cyh 2012 06 21*/
#define HAL_MSG_LSP_BASE                            HAL_MSG_BASE_MSG(1550)
#define HAL_MSG_LSP_MSG(n)                         (HAL_MSG_LSP_BASE  + (n))
#define HAL_MSG_LSP_ADD                             HAL_MSG_LSP_MSG(1)
#define HAL_MSG_LSP_DEL                             HAL_MSG_LSP_MSG(2)
#define HAL_MSG_LSP_GET_LINK_STATUS                 HAL_MSG_LSP_MSG(3)
#define HAL_MSG_LSP_PROTECT_GRP_ADD                 HAL_MSG_LSP_MSG(4)
#define HAL_MSG_LSP_PROTECT_GRP_DEL                 HAL_MSG_LSP_MSG(5)
#define HAL_MSG_LSP_PROTECT_GRP_MOD_PARAM           HAL_MSG_LSP_MSG(6)
#define HAL_MSG_LSP_PROTECT_GRP_SWITCH             HAL_MSG_LSP_MSG(7)
#define HAL_MSG_LSP_GET_PROTECT_GRP_INFO           HAL_MSG_LSP_MSG(8)


/*add cyh 2012 06 21*/
#define HAL_MSG_MULTICAST_BASE                      HAL_MSG_BASE_MSG(1600)
#define HAL_MSG_MULTICAST_MSG(n)                    (HAL_MSG_MULTICAST_BASE  + (n))
#define HAL_MSG_MULTICAST_GROUP_ADD                 HAL_MSG_MULTICAST_MSG(1)
#define HAL_MSG_MULTICAST_GROUP_DEL                 HAL_MSG_MULTICAST_MSG(2)
#define HAL_MSG_MULTICAST_GRP_PORT_ADD                 HAL_MSG_MULTICAST_MSG(3)
#define HAL_MSG_MULTICAST_GRP_PORT_DEL                 HAL_MSG_MULTICAST_MSG(4)

/*add cyh 2013 02 21 */
#define HAL_MSG_OAM_BASE                                     HAL_MSG_BASE_MSG(1650)
#define HAL_MSG_OAM_MSG(n)                                 (HAL_MSG_OAM_BASE  + (n))
#define HAL_MSG_OAM_ADD                                      HAL_MSG_OAM_MSG(1)
#define HAL_MSG_OAM_DEL                                       HAL_MSG_OAM_MSG(2)
#define HAL_MSG_OAM_GET_STATUS                        HAL_MSG_OAM_MSG(3)

//#define HAL_MSG_DEV_SRC_MAC_BASE                  HAL_MSG_BASE_MSG(1650)
//#define HAL_MSG_DEV_SRC_MAC_MSG(n)              (HAL_MSG_DEV_SRC_MAC_BASE  + (n))
//#define HAL_MSG_SET_DEV_SRC_MAC                   HAL_MSG_DEV_SRC_MAC_MSG(1)


/*2.vplsҵ��Ĵ�����ɾ����*/
/*HAL_MSG_VPN_ADD/HAL_MSG_VPN_DEL */
typedef struct
{
       unsigned int             hsl_vpn_id;          /*ƽ̨�·���vpn id */
       unsigned int             hsl_vpn_type;        /*vpls:1; vpws:0;  */
       /*δ֪�������鲥���㲥��ת����㲥ʹ��ֻ����vplsҵ����Ч, ֻ��vplsҵ����Ч*/
       unsigned int             un_pkt_flg;
       unsigned int             mac_learn_flg ;      /*mac ��ַѧϰʹ��,ֻ����vplsҵ����Ч*/
}hsl_bcm_msg_vpn_cfg;
/*ע��ɾ��ʱֻ��Ҫ����hsl_vpn_id��*/



/*3.��vpn��ӻ�ɾ���˿�*/
/*HAL_MSG_VPN_PORT_ADD/HAL_MSG_VPN_PORT_DEL*/
typedef struct
{
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
    /*unsigned int in_tunnel_label;
    int   tunnel_in_vlan;*/     /*=4096, ��ʾuntag����*/

    unsigned int  out_pw_label;
    unsigned char  out_pw_exp;
    /*unsigned int out_tunnel_label;
    unsigned char out_tunnel_exp;
    unsigned char   tunnel_out_mac[6];
    int   tunnel_out_vlan;*/    /*=4096�� ��ʾuntag����*/
    unsigned int lsp_id; /*�����id*/

}hsl_bcm_msg_vpn_port_cfg;
/*ע��ɾ���˿�ʱ��ac�˿���Ҫ����pannel_port + ac_vlan; pw�˿�ֻ��Ҫ����pannel_port + in_pw_label;*/


/*4.���ӡ�ɾ�����*/
/*lsp_type: 0�ϻ���1�»���2����*/
/*HAL_MSG_LSP_ADD\HAL_MSG_LSP_DEL*/
typedef struct
{
    unsigned int lsp_id;
    unsigned int  lsp_type;
	 
    unsigned int in_port;
    unsigned int in_label;        /*���ǩ*/
    unsigned short tunnel_in_vlan;     /*=0, ��ʾuntag����*/

    unsigned int out_port;
    unsigned int out_label;       /*mpls ����ǩ*/
    unsigned char out_tunnel_exp;
	unsigned short tunnel_out_vlan;    /*=0�� ��ʾuntag����*/
    unsigned char tunnel_out_mac[6];
}hsl_bcm_msg_mpls_tunnel_cfg;
/*ע��ɾ�����ʱ��ֻ��Ҫ�·�lsp_id*/
/*ע����ǰ�汾��ɾ�����ʱ����Ҫ����in_label + in_port*/

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

/*8.vpls ��̬mac��ַ���ӣ�ɾ��*/
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
/*ɾ��mac��ַ�� ֻ��Ҫ�·�vpn id��mac��ַ*/

/*9.��ȡ���״̬�ӿ�*/
typedef enum
{    
    IAL_LSP_STATUS_INVALID = 0,
    IAL_LSP_STATUS_DOWN,
    IAL_LSP_STATUS_UP
}ial_lsp_link_status;

typedef struct
{
    unsigned int lsp_id;
    ial_lsp_link_status lsp_ingress_status;  
    ial_lsp_link_status lsp_egress_status;
}ial_mpls_lsp_status;

/*10.���ӡ�ɾ�����������*/

typedef struct
{
    unsigned int grp_id;   /*������id�� 0~63*/
    unsigned int  protect_type;  /*�������ͣ�����ֻ֧��IAL_PROTECT_TYPE_1BY1*/
    unsigned int    sw_back_flag; /*����IAL_PROTECT_SWITCH_BACK_DIS*/
    unsigned int    back_time;        /*���ӣ�ɾ�������鲻������*/
    unsigned int    work_lsp_id;        /*�������id*/
    unsigned int    backup_lsp_id;      /*�������Id*/
}ial_mpls_protect_group_cfg;
//ע�⣺ɾ��ֻ��Ҫ�·�grp_id.

/*11.�������л� */

typedef enum
{
    IAL_PROTECT_SWITCH_CLEAR=0,
    IAL_PROTECT_SWITCH_LOCK,
    IAL_PROTECT_SWITCH_FORCE
}ial_protect_switch_status;

typedef struct
{
    unsigned int grp_id;
    unsigned int switch_lsp_id;
    ial_protect_switch_status  switch_status;
    unsigned int    lock_lsp_id;
}ial_mpls_protect_switch_cfg;

/*12.��ȡ��������Ϣ */
typedef struct
{
    unsigned int grp_id;
    ial_protect_type  protect_type;
    ial_protect_switch_status  switch_status;;
    ial_protect_switch_back          sw_back_flag;
    unsigned int    back_time;
    unsigned int    lock_lsp_id;
    unsigned int    current_lsp_id;
    unsigned int    work_lsp_id;
    unsigned int    backup_lsp_id;
}ial_mpls_protect_group_info;
//ע��grp_idΪ�·�����������Ϊ�������

/*13.oam���ӣ�ɾ��*/
typedef struct
{
    unsigned int   oam_id;
    unsigned int   lsp_id;
    unsigned int   ccm_period;
	unsigned int in_port;
	unsigned int out_port;
    char     ma_name[48];
    char     mep_name;
}ial_oam_cfg;

/*14.��ȡoam״̬��Ϣ */
typedef struct
{
    unsigned int oam_id;
    unsigned int  lsp_id;
     
    unsigned int          rdi_error;
    unsigned int          xcon_error;
    unsigned int          ccm_timeout;
    unsigned int         unexpected_mep; 
    //unsigned int    in_port;
    //unsigned int    out_port;
}ial_oam_status;


#endif
