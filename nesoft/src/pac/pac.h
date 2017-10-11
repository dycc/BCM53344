/******************************************************************************
 *
 *  pac/pac.h
 *
 *****************************************************************************/

/*
 *  Copyright (C) 2012 Ku Ying <PacBridge Corp.>
 *  All rights reserved.
 *
 *  == ˵�� ==
 *  pacģ��ͷ�ļ����ṩ�ӿڹ��ⲿģ����ã�������2012.2.16
 *  ԭ����ֻ���ṩ�����ӿڡ�ö�١���Ϣ�ӿ *  ���ܱ�©�ṹ�塢���ݽṹ���ڲ�ʵ�ָ��ⲿģ��
 *
 */

#ifndef _PAC_H_
#define _PAC_H_


/******************************************************************************
 *
 *  �����ӿ�
 *
 *****************************************************************************/
void vport_master_init();

void ac_cli_init(struct cli_tree *ctree);
void pw_cli_init(struct cli_tree *ctree);
void tun_cli_init(struct cli_tree *ctree);

void service_master_init();
void vpn_cli_init(struct cli_tree *ctree);
void lsp_cli_init(struct cli_tree *ctree);
void lsp_grp_cli_init(struct cli_tree *ctree);
void lsp_oam_cli_init(struct cli_tree *ctree);


void ptp_cli_init(struct cli_tree *ctree);
void ptp_port_cli_init(struct cli_tree *ctree);


#endif
