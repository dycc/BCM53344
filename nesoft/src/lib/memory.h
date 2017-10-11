/* Copyright (C) 2002-2003   All Rights Reserved.  */

#ifndef _PACOS_MEMORY_H
#define _PACOS_MEMORY_H

#include "modbmap.h"

/* Memory types. */
enum memory_type
{
  MTYPE_TMP = 0,        /* Must always be first and should be zero. */

  /* Hash */
  MTYPE_HASH,
  MTYPE_HASH_INDEX,
  MTYPE_HASH_BUCKET,

  /* Thread */
  MTYPE_THREAD_MASTER,
  MTYPE_THREAD,

  /* Linklist */
  MTYPE_LINK_LIST,
  MTYPE_LIST_NODE,

  /* Buffer */
  MTYPE_BUFFER,
  MTYPE_BUFFER_BUCKET,
  MTYPE_BUFFER_DATA,
  MTYPE_BUFFER_IOV,

  /* Show */
  MTYPE_SHOW,
  MTYPE_SHOW_PAGE,
  MTYPE_SHOW_SERVER,

  /* Prefix */
  MTYPE_PREFIX,
  MTYPE_PREFIX_IPV4,
  MTYPE_PREFIX_IPV6,

  /* Route table */
  MTYPE_ROUTE_TABLE,
  MTYPE_ROUTE_NODE,

  /* LS table */
  MTYPE_LS_TABLE,
  MTYPE_LS_NODE,
  MTYPE_LS_PREFIX,

  /* QoS Resource. */
  MTYPE_QOS_RESOURCE,

  /* Vector */
  MTYPE_VECTOR,
  MTYPE_VECTOR_INDEX,

  /* snmp : agentx/smux */
  MTYPE_SNMP_SUBTREE,
  MTYPE_SMUX_PASSWD,

  /* Host configuration. */
  MTYPE_CONFIG,
  MTYPE_CONFIG_MOTD,
  MTYPE_CONFIG_LOGIN,
  MTYPE_CONFIG_PASSWORD,

  /* IMI client.  */
  MTYPE_IMI_CLIENT,

  /* Interface database. */
  MTYPE_IF_DB,

  /* Memory globals. */
  MTYPE_MEMORY_GLOBALS,

  /* VTY */
  MTYPE_VTY_MASTER,
  MTYPE_VTY,
  MTYPE_VTY_HIST,
  MTYPE_VTY_PATH,
  MTYPE_VTY_OUT_BUF,
  MTYPE_IF,
  MTYPE_CONNECTED,
  MTYPE_STREAM,
  MTYPE_STREAM_DATA,
  MTYPE_STREAM_FIFO,

  /* Label pool */
  MTYPE_LABEL_POOL_SERVER,
  MTYPE_LABEL_POOL_CLIENT,
  MTYPE_LABEL_POOL_GENERIC_LABEL,
  MTYPE_LABEL_SET_NODE,

  /* Stream Socket Control Block */
  MTYPE_SSOCK_CB,
  /* Circular Queue Buffer */
  MTYPE_CQUEUE_BUF,

  /* Access list */
  MTYPE_ACCESS_LIST,
  MTYPE_ACCESS_LIST_STR,
  MTYPE_ACCESS_FILTER,

  /* Prefix list */
  MTYPE_PREFIX_LIST,
  MTYPE_PREFIX_LIST_STR,
  MTYPE_PREFIX_LIST_ENTRY,
  MTYPE_PREFIX_LIST_DESC,

  /* Route map */
  MTYPE_ROUTE_MAP,
  MTYPE_ROUTE_MAP_NAME,
  MTYPE_ROUTE_MAP_INDEX,
  MTYPE_ROUTE_MAP_RULE,
  MTYPE_ROUTE_MAP_RULE_STR,
  MTYPE_ROUTE_MAP_COMPILED,

#ifdef HAVE_PBR
  MTYPE_PBR_NEXTHOP,
  MTYPE_PBR_STRING,
  MTYPE_ROUTE_MAP_PBR_IF,
#endif /* HAVE_PBR */

  /* VR data */
  MTYPE_VRF_NAME,

  /* Keys */
  MTYPE_KEYCHAIN,
  MTYPE_KEYCHAIN_NAME,
  MTYPE_KEY,
  MTYPE_KEY_STRING,

  /* Bit map */
  MTYPE_BITMAP,
  MTYPE_BITMAP_BLOCK,
  MTYPE_BITMAP_BLOCK_ARRAY,
  MTYPE_STRING_BUFF,

  /* Ptree */
  MTYPE_PTREE,
  MTYPE_PTREE_NODE,

  /* Avl tree */
  MTYPE_AVL_TREE,
  MTYPE_AVL_TREE_NODE,

  /* Binary Heap */
  MTYPE_BINARY_HEAP,
  MTYPE_BINARY_HEAP_ARRAY,

  /* Redundancy data */
  MTYPE_RMM,
  MTYPE_RMM_MSG,
  MTYPE_RMM_TMP,

#ifdef HAVE_TUNNEL
  MTYPE_TUNNEL_IF,
#endif

#ifdef HAVE_GMPLS
  /* GMPLS data */
  MTYPE_GMPLS_IF,
  MTYPE_GMPLS_IF_DESC,
  MTYPE_GMPLS_SRLG,
  MTYPE_DATALINK,
  MTYPE_TELINK,
  MTYPE_CONTROL_CHANNEL,
  MTYPE_CONTROL_ADJ,
  MTYPE_GMPLS_LINK_ID,
  MTYPE_LINK_PROP,
  MTYPE_GMPLS_BIDIR,
#endif /* HAVE_GMPLS */

  /* Message */
  MTYPE_MESSAGE_ENTRY,
  MTYPE_MESSAGE_HANDLER,

  /* NSM messaging structure */
  MTYPE_NSM_MSG_NEXTHOP_IPV4,
  MTYPE_NSM_MSG_NEXTHOP_IPV6,
  MTYPE_NSM_CLIENT_HANDLER,
  MTYPE_NSM_CLIENT,
  MTYPE_NSM_SERVER_ENTRY,
  MTYPE_NSM_SERVER_CLIENT,
  MTYPE_NSM_SERVER,
  MTYPE_NSM_PENDING_MSG,
  MTYPE_NSM_MSG_LABEL_POOL,

  /* NSM redistribute. */
  MTYPE_NSM_REDISTRIBUTE,

  /* NSM route table and route node. */
  MTYPE_NSM_PTREE_TABLE,
  MTYPE_NSM_PTREE_NODE,

  /* NSM Nexthop registration/deregistration info. */
  MTYPE_NSM_NEXTHOP_LOOKUP_REG,
  MTYPE_NSM_SNMP_ROUTE_ENTRY,

  /* NSM ARP entry configuration*/
  MTYPE_NSM_ARP_MASTER,
  MTYPE_NSM_ARP_STATIC_ENTRY,
#ifdef HAVE_IPV6
  MTYPE_NSM_IPV6_STATIC_NBR_ENTRY,
#endif /* HAVE_IPV6 */

  /* RIP */
  MTYPE_RIP,
  MTYPE_RIP_NAME,
  MTYPE_RIP_INFO,
  MTYPE_RIP_IF,
  MTYPE_RIP_IF_NAME,
  MTYPE_RIP_IF_PARAMS,
  MTYPE_RIP_PASSIVE_IF,
  MTYPE_RIP_PEER,
  MTYPE_RIP_OFFSET_LIST,
  MTYPE_RIP_OFFSET_IF_NAME,
  MTYPE_RIP_OFFSET_ALIST,
  MTYPE_RIP_DISTANCE,
  MTYPE_RIP_DISTANCE_ALIST,
  MTYPE_RIP_RMAP_COMPILED,
  MTYPE_RIP_RMAP_NAME,
  MTYPE_RIP_AUTH_STRING,
  MTYPE_RIP_KEY_CHAIN,
  MTYPE_RIP_NH,

  /* RIPng */
  MTYPE_RIPNG,
  MTYPE_RIPNG_NAME,
  MTYPE_RIPNG_INFO,
  MTYPE_RIPNG_AGGREGATE,
  MTYPE_RIPNG_IF,
  MTYPE_RIPNG_IF_NAME,
  MTYPE_RIPNG_IF_PARAMS,
  MTYPE_RIPNG_NBR,
  MTYPE_RIPNG_NBR_IF,
  MTYPE_RIPNG_PASSIVE_IF,
  MTYPE_RIPNG_OFFSET_LIST,
  MTYPE_RIPNG_OFFSET_IF_NAME,
  MTYPE_RIPNG_OFFSET_ALIST,
  MTYPE_RIPNG_RMAP_COMPILED,
  MTYPE_RIPNG_RMAP_NAME,
  MTYPE_RIPNG_DISTANCE,
  MTYPE_RIPNG_DISTANCE_ALIST,

  /* BGP */
  MTYPE_BGP,
  MTYPE_BGP_VR,
  MTYPE_BGP_GLOBAL,
  MTYPE_BGP_PEER,
  MTYPE_BGP_PEER_CONF,
  MTYPE_BGP_PEER_GROUP,
  MTYPE_BGP_PEER_NOTIFY_DATA,
  MTYPE_BGP_ROUTE,
  MTYPE_BGP_STATIC,
  MTYPE_BGP_AGGREGATE,
  MTYPE_BGP_MPCAP,
  MTYPE_BGP_ADJACENCY,
  MTYPE_BGP_ADVERTISE,
  MTYPE_BGP_ADVERTISE_ATTR,
  MTYPE_BGP_ADJ_IN,
  MTYPE_ATTR,
  MTYPE_AS_PATH,
  MTYPE_AS_SEG,
  MTYPE_AS_STR,
  MTYPE_COMMUNITY,
  MTYPE_COMMUNITY_VAL,
  MTYPE_COMMUNITY_STR,
  MTYPE_COMMUNITY_LIST_CONFIG,
  MTYPE_COMMUNITY_LIST_NAME,
  MTYPE_ECOMMUNITY,
  MTYPE_ECOMMUNITY_VAL,
  MTYPE_ECOMMUNITY_STR,
  MTYPE_CLUSTER,
  MTYPE_CLUSTER_VAL,
  MTYPE_TRANSIT,
  MTYPE_TRANSIT_VAL,
  MTYPE_AS_LIST,
  MTYPE_AS_LIST_MASTER,
  MTYPE_AS_FILTER,
  MTYPE_AS_FILTER_STR,
  MTYPE_COMMUNITY_LIST_HANDLER,
  MTYPE_COMMUNITY_LIST,
  MTYPE_COMMUNITY_LIST_ENTRY,
  MTYPE_COMMUNITY_REGEXP,
  MTYPE_BGP_CONFED_LIST,
  MTYPE_BGP_DISTANCE,
  MTYPE_BGP_NEXTHOP_CACHE,
  MTYPE_BGP_RFD_HINFO,
  MTYPE_BGP_RFD_DECAY_ARRAY,
  MTYPE_BGP_RFD_REUSE_LIST_ARRAY,
  MTYPE_BGP_RFD_CB,
  MTYPE_BGP_RFD_CFG,
  MTYPE_BGP_TABLE,
  MTYPE_BGP_NODE,
  MTYPE_BGP_WALKER,
  MTYPE_PEER_UPDATE_SOURCE,
  MTYPE_PEER_DESC,
  MTYPE_BGP_VRF,
  MTYPE_BGP_DUMP,
  MTYPE_BGP_MPLS_LABEL_REQ,
#ifdef HAVE_EXT_CAP_ASN
  MTYPE_AS4_PATH,
  MTYPE_AS4_SEG,
  MTYPE_AS4_STR,
#endif /* HAVE_EXT_CAP_ASN */
  MTYPE_PEER_BGP_NODE,

  /* NSM */
  MTYPE_NSM_GLOBAL,
  MTYPE_NSM_MASTER,
  MTYPE_NSM_DESC,
  MTYPE_NSM_RIB,
  MTYPE_NSM_VRF,
  MTYPE_NEXTHOP,
  MTYPE_NSM_STATIC,
#ifdef HAVE_BFD
  MTYPE_NSM_BFD_STATIC_SESSION,
#endif /* HAVE_BFD */
  MTYPE_NSM_IF,
  MTYPE_NSM_IFNAME,
  MTYPE_NSM_IF_PARAMS,
  MTYPE_NSM_PW,
  MTYPE_NSM_SI,
  MTYPE_NSM_AC,
  MTYPE_NSM_TUN,
  MTYPE_NSM_RPORT,//zk 2012.07.26
  MTYPE_NSM_MEG,//czh
  MTYPE_NSM_OAM,//czh  2011.11.11
  MTYPE_NSM_STACK,
  MTYPE_NSM_STAGGER_NODE,
  MTYPE_NSM_RESTART_OPTION,
  MTYPE_NSM_MSG_QUEUE,
  MTYPE_NSM_MSG_QUEUE_BUF,
  MTYPE_RTADV,
  MTYPE_RTADV_IF,
  MTYPE_RTADV_PREFIX,
  MTYPE_RTADV_HOME_AGENT,
  MTYPE_NSM_MPLS,
  MTYPE_NSM_MPLS_IF,
  MTYPE_NSM_LABEL_SPACE,
  MTYPE_NSM_QOS_IF,
  MTYPE_NSM_STATIC_DESC,
#ifdef HAVE_VLAN
  MTYPE_NSM_VLAN_BMP,
#endif /* HAVE_VLAN */
#ifdef HAVE_MPLS_VC
  MTYPE_NSM_VIRTUAL_CIRCUIT,
  MTYPE_NSM_VC_CONTAINER,
  MTYPE_NSM_VC_GROUP,
  MTYPE_NSM_VC_FIB,
  MTYPE_NSM_VC_PERF_CNTR,
#endif /* HAVE_MPLS_VC */

#ifdef HAVE_VPLS
  MTYPE_NSM_VPLS,
  MTYPE_NSM_VPLS_PEER,
  MTYPE_NSM_VPLS_SPOKE_VC,
#endif /* HAVE_VPLS */
  MTYPE_NSM_LSP_DEP_CONFIRM,
  MTYPE_MPLS_CONFIRM_LIST,
  MTYPE_MPLS_FTN_ENTRY,
  MTYPE_MPLS_ILM_ENTRY,
  MTYPE_MPLS_XC_ENTRY,
  MTYPE_MPLS_NHLFE_ENTRY,
  MTYPE_MPLS_MAPPED_ROUTE,
  MTYPE_MPLS_MAPPED_LSP_ENTRY,
  MTYPE_NSM_MPLS_VRF_TABLE,
#ifdef HAVE_BFD
  MTYPE_NSM_MPLS_BFD_CONF,
#endif /* HAVE_BFD */
#ifdef HAVE_HAL
  MTYPE_NSM_HAL_TLV_DECODE,
#endif /* HAVE_HAL */
#ifdef HAVE_MCAST_IPV4
  MTYPE_NSM_MCAST,
  MTYPE_NSM_MCAST_VIF,
  MTYPE_NSM_MCAST_MRT,
  MTYPE_NSM_MCAST_MRT_OLIST,
  MTYPE_NSM_MCAST_STAT_BLOCK,
  MTYPE_NSM_MCAST_MRT_REG,
  MTYPE_NSM_MCAST_TUN_CONF,
  MTYPE_NSM_MTRACE_STATE,
  MTYPE_NSM_MTRACE_PKT,
#endif /* HAVE_MCAST_IPV4 */

#if defined (HAVE_MCAST_IPV4) || defined (HAVE_IGMP_SNOOP)
  /* IGMP */
  MTYPE_IGMP_INST,
  MTYPE_IGMP_SVC_REG,
  MTYPE_IGMP_SSM_MAP_STATIC,
  MTYPE_IGMP_IF,
  MTYPE_IGMP_IF_IDX,
  MTYPE_IGMP_GRP_REC,
  MTYPE_IGMP_SRC_REC,
  MTYPE_IGMP_SRC_LIST,
  MTYPE_IGMP_SNMP_VAR,
#endif /* (HAVE_MCAST_IPV4) || (HAVE_IGMP_SNOOP) */

#ifdef HAVE_MCAST_IPV6
  MTYPE_NSM_MCAST6,
  MTYPE_NSM_MCAST6_MIF,
  MTYPE_NSM_MCAST6_MRT,
  MTYPE_NSM_MCAST6_MRT_OLIST,
  MTYPE_NSM_MCAST6_STAT_BLOCK,
  MTYPE_NSM_MCAST6_MRT_REG,
#endif /* HAVE_MCAST_IPV6 */

#if defined (HAVE_MCAST_IPV6) || defined (HAVE_MLD_SNOOP)
  /* MLD */
  MTYPE_MLD_INST,
  MTYPE_MLD_SVC_REG,
  MTYPE_MLD_SSM_MAP_STATIC,
  MTYPE_MLD_IF,
  MTYPE_MLD_IF_IDX,
  MTYPE_MLD_GRP_REC,
  MTYPE_MLD_SRC_REC,
  MTYPE_MLD_SRC_LIST,
  MTYPE_MLD_SNMP_VAR,
#endif /* (HAVE_MCAST_IPV6) || (HAVE_MLD_SNOOP) */

  MTYPE_NSM_MROUTE_CONFIG,
  MTYPE_NSM_MRIB,
  MTYPE_NSM_MNH_REG,
  MTYPE_NSM_MNH_REG_CL,

  /* OSPF */
  MTYPE_OSPF_MASTER,
  MTYPE_OSPF,
  MTYPE_OSPF_AREA,
  MTYPE_OSPF_IF,
  MTYPE_OSPF_NEIGHBOR,
  MTYPE_OSPF_VERTEX,
  MTYPE_OSPF_NEXTHOP,
  MTYPE_OSPF_ROUTE,
  MTYPE_OSPF_ROUTE_CALC,
  MTYPE_OSPF_PATH,
  MTYPE_OSPF_LSA,
  MTYPE_OSPF_LSA_DATA,
  MTYPE_OSPF_ROUTER_LSA_MAP,
  MTYPE_OSPF_SUMMARY_LSA_MAP,
  MTYPE_OSPF_LSDB,
  MTYPE_OSPF_LS_REQUEST,
  MTYPE_OSPF_PACKET,
  MTYPE_OSPF_REDIST_INFO,
  MTYPE_OSPF_REDIST_CONF,
  MTYPE_OSPF_REDIST_MAP,
  MTYPE_OSPF_DISTANCE,
  MTYPE_OSPF_NETWORK,
  MTYPE_OSPF_VLINK,
#ifdef HAVE_OSPF_MULTI_AREA
  MTYPE_OSPF_MULTI_AREA_LINK,
#endif /* HAVE_OSPF_MULTI_AREA */
  MTYPE_OSPF_IF_PARAMS,
  MTYPE_OSPF_PASSIVE_IF,
  MTYPE_OSPF_AUTH_KEY,
  MTYPE_OSPF_CRYPT_KEY,
  MTYPE_OSPF_AREA_RANGE,
  MTYPE_OSPF_SUMMARY,
  MTYPE_OSPF_NEIGHBOR_STATIC,
  MTYPE_OSPF_HOST_ENTRY,
  MTYPE_OSPF_OPAQUE_MAP,
  MTYPE_OSPF_OPAQUE_SHOW,
  MTYPE_OSPF_NOTIFIER,
  MTYPE_OSPF_VRF,
  MTYPE_OSPF_DESC,
  MTYPE_OSPF_IGP_SHORTCUT_LSP,
  MTYPE_OSPF_IGP_SHORTCUT_ROUTE,
  MTYPE_OSPF_DOMAIN_ID,
  MTYPE_OSPF_RTR_ID,
#ifdef HAVE_GMPLS
  MTYPE_OSPF_TELINK,
  MTYPE_OSPF_TLINK_PARAMS,
  MTYPE_OSPF_SRLG,
#endif /* HAVE_GMPLS */

  /* OSPFv3 */
  MTYPE_OSPF6_MASTER,
  MTYPE_OSPF6,
  MTYPE_OSPF6_AREA,
  MTYPE_OSPF6_IF,
  MTYPE_OSPF6_VLINK,
  MTYPE_OSPF6_NEIGHBOR,
  MTYPE_OSPF6_NBR_STATIC,
  MTYPE_OSPF6_VERTEX,
  MTYPE_OSPF6_ROUTE,
  MTYPE_OSPF6_ROUTE_CALC,
  MTYPE_OSPF6_PATH,
  MTYPE_OSPF6_NEXTHOP,
  MTYPE_OSPF6_LSA,
  MTYPE_OSPF6_LSA_DATA,
  MTYPE_OSPF6_LSA_MAP,
  MTYPE_OSPF6_LSDB,
  MTYPE_OSPF6_LSDB_SLOT,
  MTYPE_OSPF6_PREFIX,
  MTYPE_OSPF6_PREFIX_MAP,
  MTYPE_OSPF6_PACKET,
  MTYPE_OSPF6_FIFO,
  MTYPE_OSPF6_REDIST_INFO,
  MTYPE_OSPF6_REDIST_CONF,
  MTYPE_OSPF6_REDIST_MAP,
  MTYPE_OSPF6_IF_PARAMS,
  MTYPE_OSPF6_AREA_RANGE,
  MTYPE_OSPF6_RMAP_COMPILED,
  MTYPE_OSPF6_DESC,
  MTYPE_OSPF6_VRF,
  MTYPE_OSPF6_RTR_ID,

  /* VRRP */
  MTYPE_VRRP_GLOBAL_INFO,
  MTYPE_VRRP_SESSION,
  MTYPE_VRRP_ASSO_TABLE,
  MTYPE_VRRP_VIP_ADDR,
  MTYPE_VRRP_IF_AUTH,
  MTYPE_VRRP_LINUX_DATA,
  MTYPE_VRRP_BSD_DATA,
  MTYPE_VRRP_ASSO,

  /* VTYSH */
  MTYPE_VTYSH_INTEGRATE,
  MTYPE_VTYSH_CONFIG,
  MTYPE_VTYSH_CONFIG_LINE,

  /* LDP */
  MTYPE_LDP,
  MTYPE_LDP_IF,
  MTYPE_LDP_ADJACENCY,
  MTYPE_LDP_ENTITY,
  MTYPE_LDP_SESSION,
  MTYPE_LDP_FEC,
  MTYPE_LDP_FEC_ELEMENT,
  MTYPE_LDP_LABEL,
  MTYPE_LDP_LABEL_REQUEST,
  MTYPE_LDP_ATTR_NODE,
  MTYPE_LDP_REMOTE_ADDR,
  MTYPE_LDP_UPSTREAM,
  MTYPE_LDP_DOWNSTREAM,
  MTYPE_LDP_USM_PARAM,
  MTYPE_LDP_DSM_PARAM,
  MTYPE_LDP_IPV4_NEXT_HOP,
  MTYPE_LDP_TMP,
  MTYPE_LDP_PATH_VECTOR,
  MTYPE_LDP_ATTR,
  MTYPE_LDP_CR_ATTR,
  MTYPE_LDP_TLV_ER_HOP,
  MTYPE_LDP_ER,
  MTYPE_LDP_ER_HOP,
  MTYPE_LDP_PATH,
  MTYPE_LDP_TRUNK,
#ifdef HAVE_IPV6
  MTYPE_LDP_IPV6_NEXT_HOP,
#endif /* HAVE_IPV6 */

#ifdef HAVE_TE
  MTYPE_LDP_TRUNK_ADMIN_GROUP,
#endif /* HAVE_TE */

  MTYPE_LDP_TARGETED_PEER,
  MTYPE_LDP_LS_TO_ADDR,

#ifdef HAVE_MPLS_VC
  MTYPE_LDP_VC,
  MTYPE_VC_LSP_CB,
  MTYPE_SESSION_VC_LINK,
  MTYPE_VC_EVENT_PARAM,
  MTYPE_VC_EVENT_PARAM_DATA,
#endif /* HAVE_MPLS_VC */

#ifdef HAVE_VPLS
  MTYPE_LDP_VPLS,
#endif /* HAVE_VPLS */
  MTYPE_LDP_ADV_LIST,
  MTYPE_LDP_ADV_LIST_STR,

#ifdef HAVE_LINUX_TCP_MD5_H
  MTYPE_LDP_NBR_TO_PASSWD,
#endif /* HAVE_LINUX_TCP_MD5_H */

#ifdef HAVE_RESTART
  MTYPE_LDP_FEC_STALE_INFO,
#endif /* HAVE_RESTART */

  /* RSVP */
  MTYPE_RSVP,
  MTYPE_RSVP_IF,
  MTYPE_RSVP_WRITE_QUEUE_NODE,
  MTYPE_RSVP_TRUNK,
  MTYPE_RSVP_PATH,
  MTYPE_RSVP_PATH_HOP,
  MTYPE_RSVP_SESSION,
  MTYPE_RSVP_EXPLICIT_ROUTE_VAL,
  MTYPE_RSVP_ROUTE_RECORD_VAL,
  MTYPE_RSVP_NEIGHBOR,
  MTYPE_RSVP_LABEL,
  MTYPE_RSVP_SESSION_ADMIN_GROUP,
  MTYPE_RSVP_RCVD_PKT_NODE,
  MTYPE_RSVP_NEXTHOP,
  MTYPE_RSVP_MAPPED_ROUTE,
  MTYPE_RSVP_PATH_REFRESH_BUF,
  MTYPE_RSVP_RESV_REFRESH_BUF,
  MTYPE_RSVP_MESSAGE,
  MTYPE_RSVP_ACK_WAIT_NODE,
  MTYPE_RSVP_NEIGH_ACK_BUF,
  MTYPE_RSVP_NEIGH_BUNDLE_BUF,
#ifdef HAVE_MPLS_FRR
  MTYPE_RSVP_SUBOBJ_AVOID_NODE,
  MTYPE_RSVP_BYPASS,
#endif /* HAVE_MPLS_FRR */

#ifdef HAVE_GMPLS
  MTYPE_GMPLS_RSVP_IF,
  MTYPE_RSVP_GMPLS_ATTR,
  MTYPE_RSVP_SESS_GMPLS_ATTR,
  MTYPE_RSVP_GMPLS_LABEL_SET,
  /* RSVP Notification related */
  MTYPE_RSVP_GMPLS_NOTIFN_TARGET,
  MTYPE_RSVP_GMPLS_NOTIFN_AGGREG_BUF,
  MTYPE_RSVP_GMPLS_NOTIFN_AGGREG_NODE,
  MTYPE_RSVP_GMPLS_NOTIFN_RESEND_BUF,
  MTYPE_RSVP_GMPLS_NOTIFN_RESEND_NODE,
  MTYPE_RSVP_GMPLS_NOTIFN_TARGET_ENTRY,
  MTYPE_RSVP_GMPLS_REMOTE_ACK_BUF,
#ifdef HAVE_PCE
  MTYPE_RSVP_PCE_ATTR,
#endif /* HAVE_PCE */
#endif /* HAVE_GMPLS */

/*Resource Table Entry for SNMP */
  MTYPE_SNMP_RSVP_RESOURCE_ENTRY,

 /*Hop Table Entry for SNMP */
 MTYPE_SNMP_RSVP_HOP_ENTRY,

 /*Tunnel Table Entry For SNMP */
 MTYPE_SNMP_RSVP_TUNNEL_ENTRY,

  /* CSPF */
  MTYPE_CSPF,
  MTYPE_CSPF_LSP,
  MTYPE_CSPF_LSP_ADDR_BINDING,
  MTYPE_CSPF_ROUTE_CONSTRAINT,
  MTYPE_CSPF_VERTEX,
  MTYPE_CSPF_PATH_ELEMENT,
  MTYPE_CSPF_DATA,
  MTYPE_CSPF_SESSION,
  MTYPE_CSPF_MSG_BUF,
  MTYPE_CSPF_NEXTHOP_DATA,
  MTYPE_CSPF_UNNUMBERED_IF_DATA,
  MTYPE_CSPF_LSP_LIST,
  MTYPE_TE_LSA_NODE,
  MTYPE_OSPF_TE_LSA_DATA,
  MTYPE_CSPF_CLIENT,
  MTYPE_CSPF_LSP_KEY,
  MTYPE_CSPF_IPADDR_LIST_ELEMENT,
  MTYPE_CSPF_SRLG_DATA,

  /* IS-IS */
  MTYPE_ISIS_MASTER,
  MTYPE_ISIS_INSTANCE,
  MTYPE_ISIS_AREA_ADDR,
  MTYPE_ISIS_RECV_AREA_ADDR,
  MTYPE_ISIS_IF,
  MTYPE_ISIS_IF_NAME,
  MTYPE_ISIS_IF_PARAMS,
  MTYPE_ISIS_NEIGHBOR,
  MTYPE_ISIS_TLV,
  MTYPE_ISIS_TLV_DATA,
  MTYPE_ISIS_STLV,
  MTYPE_ISIS_STLV_DATA,
  MTYPE_ISIS_LSP,
  MTYPE_ISIS_LSP_HEADER,
  MTYPE_ISIS_PACKET,
  MTYPE_ISIS_FIFO,
  MTYPE_ISIS_IP_IFADDR,
  MTYPE_ISIS_BITMAP,
  MTYPE_ISIS_BITMAP_BITS,
  MTYPE_ISIS_VERTEX,
  MTYPE_ISIS_VERTEX_NEXTHOP,
  MTYPE_ISIS_ROUTE,
  MTYPE_ISIS_PATH,
  MTYPE_ISIS_NEXTHOP,
  MTYPE_ISIS_PASSWD,
  MTYPE_ISIS_TAG,
  MTYPE_ISIS_HOSTNAME,
  MTYPE_ISIS_REDIST_INFO,
  MTYPE_ISIS_REDIST_MAP,
  MTYPE_ISIS_REACH_INFO,
  MTYPE_ISIS_REACH_MAP,
  MTYPE_ISIS_REACH_SOURCE,
  MTYPE_ISIS_IS_REACH_MAP,
  MTYPE_ISIS_IS_REACH_INFO,
  MTYPE_ISIS_SUMMARY,
  MTYPE_ISIS_RESTART_IF,
  MTYPE_ISIS_DESC,
  MTYPE_ISIS_DISTANCE,
  MTYPE_ISIS_VRF,
  MTYPE_ISIS_IGP_SHORTCUT_LSP,
#ifdef HAVE_MD5
  MTYPE_ISIS_KEY_CHAIN,
#endif /* HAVE_MD5 */

  /* IS-IS CSPF */
  MTYPE_ISIS_CSPF,
  MTYPE_ISIS_CSPF_LSP,
  MTYPE_ISIS_CSPF_ROUTE_CONSTRAINT,
  MTYPE_ISIS_CSPF_VERTEX,
  MTYPE_ISIS_CSPF_VERTEX_NEXTHOP,

  /* PIM-DM */
  MTYPE_PDM_GLOBAL,
  MTYPE_PDM_VR,
  MTYPE_PDM_VRF,
  MTYPE_PDM_NBR,
  MTYPE_PDM_VIF,
  MTYPE_PDM_VIF_LIST,
  MTYPE_PDM_VIF_LMEM,
  MTYPE_PDM_AF_VIF,
  MTYPE_PDM_MRT,
  MTYPE_PDM_MRT_VIF,
  MTYPE_PDM_NHOP,
  MTYPE_PDM_MSG_RECORD,

  /* PIM-SM */
  MTYPE_PIM,
  MTYPE_PIM_VIF,
  MTYPE_PIM_NEIGHBOR,
  MTYPE_PIM_MIB_NEIGHBOR,
  MTYPE_PIM_SG,
  MTYPE_PIM_G,
  MTYPE_PIM_SRC,
  MTYPE_PIM_GROUP,
  MTYPE_PIM_MRT,
  MTYPE_PIM_STATUS,
  MTYPE_PIM_RP,
  MTYPE_PIM_BSR,
  MTYPE_PIM_RP_SET,
  MTYPE_PIM_NEXTHOP,
  MTYPE_PIM_OIF,
  MTYPE_PIM_RP_XX,
  MTYPE_PIM_REG,
  MTYPE_PIM_XG_S_FCR,
  MTYPE_PIM_HELLO_ADDR,
  MTYPE_PIM_ST_RP_CONF,
  MTYPE_PIM_CRP,
  MTYPE_PIM_CRP_GRP_RNG,
  MTYPE_PIM_VIF_LOCAL_INFO,
  MTYPE_PIM_ANYCAST_RP,
  MTYPE_PIM_ANYCAST_RP_MEM,

  /* PIM-SM6 */
  MTYPE_PIM6,
  MTYPE_PIM6_VIF,
  MTYPE_PIM6_NEIGHBOR,
  MTYPE_PIM6_MIB_NEIGHBOR,
  MTYPE_PIM6_SG,
  MTYPE_PIM6_G,
  MTYPE_PIM6_SRC,
  MTYPE_PIM6_GROUP,
  MTYPE_PIM6_MRT,
  MTYPE_PIM6_STATUS,
  MTYPE_PIM6_RP,
  MTYPE_PIM6_BSR,
  MTYPE_PIM6_RP_SET,
  MTYPE_PIM6_NEXTHOP,
  MTYPE_PIM6_OIF,
  MTYPE_PIM6_RP_XX,
  MTYPE_PIM6_REG,
  MTYPE_PIM6_XG_S_FCR,
  MTYPE_PIM6_HELLO_ADDR,
  MTYPE_PIM6_ST_RP_CONF,
  MTYPE_PIM6_CRP,
  MTYPE_PIM6_CRP_GRP_RNG,
  MTYPE_PIM6_VIF_LOCAL_INFO,
  MTYPE_PIM6_ANYCAST_RP,
  MTYPE_PIM6_ANYCAST_RP_MEM,

  /* DVMRP */
  MTYPE_DVMRP,
  MTYPE_DVMRP_VIF,
  MTYPE_DVMRP_BITMAP,
  MTYPE_DVMRP_BITMAP_BLOCK,
  MTYPE_DVMRP_NBR,
  MTYPE_DVMRP_PRUNE,
  MTYPE_DVMRP_DSPS,
  MTYPE_DVMRP_DSPS_NBR,
  MTYPE_DVMRP_FCR,
  MTYPE_DVMRP_ROUTE,
  MTYPE_DVMRP_ROUTE_DS_STATE,
  MTYPE_DVMRP_TUNNEL_CONF,
  MTYPE_DVMRP_VIF_LOCAL_INFO,

  /* Layer 2 */
  MTYPE_NSM_BRIDGE,
#ifdef HAVE_DCB
  MTYPE_NSM_BRIDGE_DCB,
  MTYPE_NSM_DCB_IF,
  MTYPE_NSM_DCB_APPL_PRI,
#endif /* HAVE_DCB */

#if defined (HAVE_I_BEB) || defined (HAVE_B_BEB)

  MTYPE_NSM_BRIDGE_PBB,

#endif /*(HAVE_I_BEB) || (HAVE_B_BEB)*/
#ifdef HAVE_I_BEB
  MTYPE_NSM_BRIDGE_PBB_ICOMP,
  MTYPE_NSM_BRIDGE_PBB_CNP_NODE,
  MTYPE_NSM_BRIDGE_PBB_VIP_NODE,
  MTYPE_NSM_BRIDGE_PBB_PIP_NODE,
  MTYPE_NSM_BRIDGE_PBB_SID2VIP_NODE,
  MTYPE_NSM_BRIDGE_PBB_VIP2PIP_NODE,
  MTYPE_NSM_BRIDGE_PBB_SVLAN_BUNDLE,
#endif /*HAVE_I_BEB  */

#ifdef HAVE_B_BEB
  MTYPE_NSM_BRIDGE_PBB_BCOMP,
  MTYPE_NSM_BRIDGE_PBB_CBP_NODE,
#endif  /*HAVE_B_BEB*/
#ifdef HAVE_PBB_TE
  MTYPE_NSM_PBB_TE_VID_NODE,
  MTYPE_PBB_TE_VID,
#if defined HAVE_I_BEB && defined HAVE_B_BEB
  MTYPE_NSM_PBB_TE_INSTANCE_NODE,
  MTYPE_NSM_PBB_TE_ESP_NODE,
  MTYPE_PBB_TE_EPS_NODE,
  MTYPE_PBB_TE_ISID,
#if defined (HAVE_GMPLS) && defined (HAVE_GELS)
  MTYPE_PBB_TE_TESI_NAME_TO_ID_NODE,
  MTYPE_NSM_PBB_TE_RMAC_NODE,
#endif /* HAVE_GMPLS && HAVE_GELS */
#endif /* HAVE_I_BEB && HAVE_B_BEB */
#endif /* HAVE_PBB_TE */

#ifdef HAVE_G8031
  MTYPE_NSM_G8031_VLAN,
  MTYPE_G8031_PROTECTION_GROUP,
#endif /* HAVE_G8031 */

#ifdef HAVE_G8032
  MTYPE_NSM_G8032_VLAN,
  MTYPE_NSM_G8032_NODE,
  MTYPE_G8032_ATTRIB,
  MTYPE_G8032_SM,
  MTYPE_G8032_NODE,
  MTYPE_G8032_VLAN,
#endif /* HAVE_G8032*/

  MTYPE_NSM_BRIDGE_PORT,
  MTYPE_NSM_BRIDGE_MASTER,
  MTYPE_VLAN,
  MTYPE_VLAN_EVC_ID,
  MTYPE_NSM_BRIDGE_STATIC_FDB,
  MTYPE_NSM_BRIDGE_FDB_IFINFO,
  MTYPE_NSM_BRIDGE_STAT_FDB_CFG,
  MTYPE_STP_BRIDGE,
  MTYPE_STP_BRIDGE_PORT,
  MTYPE_STP_BRIDGE_CONFIG,
  MTYPE_STP_BRIDGE_CONFIG_FDB_LIST,
  MTYPE_RSTP_BRIDGE,
  MTYPE_RSTP_BRIDGE_PORT,
  MTYPE_RSTP_BRIDGE_CONFIG,
  MTYPE_RSTP_BRIDGE_CONFIG_FDB_LIST,
  MTYPE_MSTP_VLAN,
  MTYPE_MSTP_BRIDGE,
  MTYPE_MSTP_BRIDGE_NAME,
  MTYPE_MSTP_BRIDGE_INSTANCE,
  MTYPE_MSTP_PORT_INSTANCE,
  MTYPE_MSTP_BRIDGE_PORT,
  MTYPE_MSTP_MSTI_INFO,
  MTYPE_MSTP_BPDU_INST,
  MTYPE_MSTP_BRIDGE_CONFIG,
  MTYPE_MSTP_BRIDGE_CONFIG_FDB_LIST,
  MTYPE_MSTP_BRIDGE_CONFIG_INSTANCE_LIST,
#if (defined HAVE_I_BEB || defined HAVE_B_BEB )
  MTYPE_MSTP_BRIDGE_PBB_VIP_NODE,
#endif
  MTYPE_VLAN_MSTP_CONFIG,

  /* ONMD */
  MTYPE_ONMD_GLOBALS,
  MTYPE_ONMD_MASTER,
  MTYPE_ONM_INTERFACE,
  MTYPE_ONM_CLIENT_HANDLER,
  MTYPE_ONM_CLIENT,
  MTYPE_ONM_SERVER_ENTRY,
  MTYPE_ONM_SERVER_CLIENT,
  MTYPE_ONM_SERVER,
  MTYPE_ONM_PENDING_MSG,
  MTYPE_ONM_MSG_QUEUE,
  MTYPE_ONM_MSG_QUEUE_BUF,

  /* 802.1x */
  MTYPE_8021X_GLOBALS,
  MTYPE_8021X_MASTER,
  MTYPE_8021X_PORT,
  MTYPE_8021X_RADIUS,

  /*MAC-based authentication Enhancement*/
  MTYPE_MAC_AUTH_PORT,

#ifdef HAVE_USER_HSL
  MTYPE_HSL_SERVER_ENTRY,
  MTYPE_HSL_BRIDGE,
#endif /* HAVE_USER_HSL */

#ifdef HAVE_AXELX
  MTYPE_HSL_AXEL_IF,
  MTYPE_HSL_AXEL_FDB,
#endif /* HAVE_AXELX */

#ifdef HAVE_MARVELL_LS
  MTYPE_HSL_SOHO_MVL_IF,
  MTYPE_HSL_SOHO_MVL_FDB,
#endif /* HAVE_MARVELL_LS */

  MTYPE_LACP_INSTANCE,
  MTYPE_LACP_AGGREGATOR,
  MTYPE_LACP_LINK,
  MTYPE_LACP_ADMIN_KEY_ELEMENT,
  MTYPE_GARP_GID,
  MTYPE_GARP_GID_PORT,
  MTYPE_GARP_GID_MACHINE,
  MTYPE_GARP_GIP,
  MTYPE_NSM_L2_MCAST,
  MTYPE_NSM_L2_MCAST_GRP_REC,
  MTYPE_NSM_L2_MCAST_SRC_REC,

  MTYPE_GMRP,
  MTYPE_NSM_VLAN_CLASSIFIER_GROUP,
  MTYPE_NSM_VLAN_CLASSIFIER_RULE,
  MTYPE_NSM_VLAN_CLASS_IF_GROUP,
  MTYPE_NSM_VLAN_CLASS_TMP_GROUP,
  MTYPE_NSM_VLAN_CLASS_TMP_RULE,
  MTYPE_NSM_CVLAN_REG_TAB,
  MTYPE_NSM_VLAN_DBL_VID_KEY,
  MTYPE_NSM_VLAN_PRO_EDGE_SWCTX,
  MTYPE_NSM_VLAN_SVLAN_INFO,
  MTYPE_NSM_VLAN_SVLAN_PORT_INFO,
  MTYPE_NSM_VLAN_BITMAP,
  MTYPE_NSM_UNI_BW_PROFILE,
  MTYPE_NSM_INGRESS_UNI_BW_PROFILE,
  MTYPE_NSM_EGRESS_UNI_BW_PROFILE,
  MTYPE_NSM_INGRESS_EVC_BW_PROFILE,
  MTYPE_NSM_EGRESS_EVC_BW_PROFILE,
  MTYPE_NSM_INGRESS_EVC_COS_BW_PROFILE,
  MTYPE_NSM_EGRESS_EVC_COS_BW_PROFILE,
  MTYPE_NSM_UNI_EVC_BW,
  MTYPE_NSM_EFM_OAM_IF,
  MTYPE_NSM_LLDP_IF,
  MTYPE_NSM_L2_OAM_MASTER,
  MTYPE_GMRP_VLAN,
  MTYPE_GMRP_PORT,
  MTYPE_GMRP_PORT_INSTANCE,
  MTYPE_GMRP_PORT_CONFIG,
  MTYPE_GMRP_GMD,
  MTYPE_GMRP_GMD_ENTRY,
  MTYPE_GMRP_BRIDGE,

  MTYPE_GVRP,
  MTYPE_GVRP_PORT,
  MTYPE_GVRP_PORT_CONFIG,
  MTYPE_GVRP_GVD,
  MTYPE_GVRP_GVD_ENTRY,
  MTYPE_GVRP_CONFIG_PORTS,
  MTYPE_L2_SNMP_FDB,
  MTYPE_FLOW_CONTROL_ENTRY,
  MTYPE_PORT_MIRROR_ENTRY,
  MTYPE_BCAST_SUPPRESS_ENTRY,
  MTYPE_VLAN_DATABASE,
  MTYPE_BRIDGE_VLAN_CONFIG,
  MTYPE_VLAN_CONFIG_ENTRY,
  MTYPE_XSTP_INTERFACE,
  MTYPE_PORT_INSTANCE_LIST,

#ifdef HAVE_IMI
  /* IMI */
  MTYPE_IMI,
  MTYPE_IMI_MASTER,
  MTYPE_IMI_STRING,
  MTYPE_IMI_SERVER,
  MTYPE_IMI_SERVER_CLIENT,
  MTYPE_IMI_SERVER_ENTRY,
  MTYPE_IMI_LINE,
  MTYPE_IMI_SERV,
  MTYPE_IMI_EXTAPI,
  MTYPE_IMI_WEB,
  MTYPE_IMI_DNS,
  MTYPE_IMI_DHCP,
  MTYPE_IMI_DHCP_POOL,
  MTYPE_IMI_DHCP_RANGE,
  MTYPE_IMI_DHCP_CLIENT,
  MTYPE_IMI_PPPOE,
  MTYPE_IMI_NAT_POOL,
  MTYPE_IMI_RULE,
  MTYPE_IMI_VIRTUAL_SERVER,
  MTYPE_IMI_VIRTUAL_SERVER_DESC,
  MTYPE_IMI_NTP_MASTER,
  MTYPE_IMI_NTP_AUTH_KEY,
  MTYPE_IMI_NTP_TRUSTED_KEY,
  MTYPE_IMI_NTP_NEIGHBOR,
  MTYPE_IMI_CONFIG,
  MTYPE_IMI_STATE,
  MTYPE_IMI_STATE_LINE,
#endif /* HAVE_IMI */
  MTYPE_IMI_CFG_CMD,

  /* PAL workspace */
  MTYPE_CFG_HANDLE,
  MTYPE_LOG_HANDLE,
  MTYPE_LOG_NAME,
  MTYPE_SOCK_HANDLE,

#ifdef HAVE_INTEL
  MTYPE_L3_NPF_NEXTHOP,
  MTYPE_L3_NPF_NHOP_ARRAY,
  MTYPE_L3_NPF_PREFIX,
#endif /* HAVE_INTEL */

  MTYPE_HOST,
  MTYPE_COMMAND_NODE,
  MTYPE_DISTRIBUTE,
  MTYPE_DISTSTR,
  MTYPE_ZLOG,
  MTYPE_IF_DESC,
  MTYPE_IF_RMAP,
  MTYPE_IF_RMAP_NAME,
  MTYPE_SOCKUNION,
  MTYPE_ZGLOB,

  /* default if something is wrong with input type */
  MTYPE_UNKNOWN,

#ifdef HAVE_CRX
  MTYPE_CRX_MESSAGE_HANDLER,
  MTYPE_CRX_PEER,
  MTYPE_CRX_CONFIG_DATA,
  MTYPE_CRX_IF,
  MTYPE_CRX_INFO,
  MTYPE_CRX,
#endif /* HAVE_CRX */

#ifdef HAVE_VRX
  MTYPE_IF_VRX_INFO,
#endif /* HAVE_VRX */
  MTYPE_LDP_ID,
#ifdef HAVE_RMOND
  MTYPE_RMON,
#endif /* HAVE_RMOND */
#ifdef HAVE_IPSEC
  MTYPE_IPSEC_CRYPTO_MAP,
  MTYPE_IPSEC_TRANSFORM_SET,
  MTYPE_IPSEC,
  MTYPE_IPSEC_ISAKMP,
  MTYPE_IPSEC_SESSION_KEY,
  MTYPE_IPSEC_PEER_ADDR,
  MTYPE_IPSEC_MASTER,
  MTYPE_IPSEC_CRYPTO_BUNDLE,
#endif /* HAVE_IPSEC */

#ifdef HAVE_FIREWALL
  MTYPE_FIREWALL_MASTER,
  MTYPE_FIREWALL_GROUP,
#endif /* HAVE_FIREWALL */

#ifdef HAVE_HA
  MTYPE_CAL,
  MTYPE_CAL_TXN,
  MTYPE_CAL_ACT,
  MTYPE_CAL_CDR,
  MTYPE_CAL_EVENT,
#ifdef HAVE_ENEA_ELEMENT
  MTYPE_ENEA_DATA,
#endif
#ifdef HAVE_OPEN_SAF
  MTYPE_OSAF_BMAP,
  MTYPE_OSAF_DEL_REC,
  MTYPE_OSAF_SECT,
  MTYPE_OSAF_DATA,
  MTYPE_OSAF_LUDATA,
#endif
#endif /* HAVE_HA */

  MTYPE_FM,
  MTYPE_FM_LIB,

  MTYPE_LIB_VREP,

  MTYPE_COMMSG,

  MTYPE_ONM_BRIDGE,
  MTYPE_ONM_VLAN_BMP,
  MTYPE_ONM_VLAN,
  MTYPE_LLDP_IF,
  MTYPE_LLDP_MASTER,
  MTYPE_LLDP_MSG_BUF,
  MTYPE_REMOTE_LLDP,
  MTYPE_REMOTE_VLAN,

  MTYPE_EFM_MASTER,
  MTYPE_EFM_IF,
  MTYPE_EFMOAM,
  MTYPE_EFM_MSG_BUF,
  MTYPE_EFM_EVLOG_ENTRY,

  MTYPE_CFM_MASTER,
  MTYPE_CFM_MD,
  MTYPE_CFM_MA,
  MTYPE_CFM_MEP,
  MTYPE_CFM_CC,
  MTYPE_CFM_LB,
  MTYPE_CFM_LT,
  MTYPE_CFM_FA,
  MTYPE_CFM_FRAME,
  MTYPE_CFM_PORT,
  MTYPE_CFM,
  MTYPE_CFM_LTM,
  MTYPE_CFM_LTR_PDU,
  MTYPE_CFM_HEADER,
  MTYPE_CFM_LTM_REPLY,
  MTYPE_CFM_MSG_BUF,
  MTYPE_CFM_FNG,
  MTYPE_CFM_IF,
  MTYPE_CFM_RMEP,
  MTYPE_CFM_MIP,
  MTYPE_CFM_LTQ,
  MTYPE_CFM_ERRCCM,
  MTYPE_CFM_PROCESS,
#if defined HAVE_CFM_Y1731 || defined HAVE_PBB_TE
  MTYPE_CFM_LBR,
#endif /* HAVE_CFM || HAVE_PBB_TE */
#ifdef HAVE_CFM_Y1731
  MTYPE_CFM_LM,
  MTYPE_CFM_DUAL_LM,
  MTYPE_CFM_LM_COUNT_INST,
  MTYPE_CFM_1DM_TX,
  MTYPE_CFM_1DM_RX,
  MTYPE_CFM_1DM_RX_FRAME,
  MTYPE_CFM_DMM,
  MTYPE_CFM_DMM_FRAME,
  MTYPE_CFM_AIS,
  MTYPE_CFM_AIS_RMEP_INST,
  MTYPE_CFM_AIS_DEFECT_CONDITION,
  MTYPE_CFM_SERVER_MEP,
  MTYPE_CFM_SERVER_MEP_MSG_BUF,
  MTYPE_CFM_LCK,
  MTYPE_CFM_TST,
  MTYPE_CFM_TPUT_RX,
  MTYPE_CFM_MCC,
  MTYPE_CFM_EXM,
  MTYPE_CFM_VSM,
#endif /* HAVE_CFM_Y1731 */
#if defined HAVE_CFM && defined HAVE_PBB_TE
  MTYPE_CFM_PBB_TE_SID_VLAN,
  MTYPE_CFM_PBB_TE_VLAN,
#if defined HAVE_I_BEB && defined HAVE_B_BEB
  MTYPE_ONM_PBB_TE_INSTANCE,
  MTYPE_ONM_PBB_TE_ESP_COMPONENT,
  MTYPE_ONM_PBB_TE_PNP_IF_INDEX,
#endif /* HAVE_I_BEB && HAVE_B_BEB  */
#endif /* HAVE_CFM && HAVE_PBB_TE */
#if defined HAVE_CFM && (defined HAVE_I_BEB || defined HAVE_B_BEB)
  MTYPE_CFM_PBB_PORT_INFO,
  MTYPE_CFM_PBB_ISID_BVID_MAP,
  MTYPE_CFM_PBB_ISID_ON_BRIDGE,


#endif /* (HAVE_CFM && (defined HAVE_I_BEB || defined HAVE_B_BEB)) */
  MTYPE_CFM_VID_INFO,
  MTYPE_CFM_DEFAULT_MD_LEVEL_TBL,
  MTYPE_CFM_DEFAULT_MD_LEVEL_TBL_ENTRY,
  MTYPE_CFM_VID_ACTIVE_LEVELS,
  MTYPE_CFM_CONFIG_ERROR,
  MTYPE_ONM_PE_PORT,
#ifdef HAVE_SMI
  /** SMI SERVER **/
  MTYPE_SMISERVER_ENTRY,
  MTYPE_SMISERVER_CLIENT,
  MTYPE_SMISERVER,
  MTYPE_SMI_MSG_QUEUE,
  MTYPE_SMI_MSG_QUEUE_BUF,
  MTYPE_SMICLIENT_HANDLER,
  MTYPE_SMICLIENT,
  MTYPE_SMICLIENT_DUMMYMSG,
  MTYPE_SMICLIENT_IF,
  MTYPE_MSTP_GLOBAL,
  /** SMI CLIENT **/
  MTYPE_SMICLIENT_GLOBAL,
  MTYPE_SMI_PENDING_MSG,
#endif /* HAVE_SMI */

#if defined (HAVE_BFD) || defined (HAVE_MPLS_OAM)
  /* BFD related */
  MTYPE_BFD,
  MTYPE_BFD_MASTER,
  MTYPE_BFD_NOTIFIER,
  MTYPE_BFD_INTERFACE,
  MTYPE_BFD_MHOP_SESS_INFO,
  MTYPE_BFD_SESSION_PROTO_INFO,
  MTYPE_BFD_SESSION,
  MTYPE_BFD_SESSION_FWD,
  MTYPE_BFD_SESSION_ADDL_PARAMS,
  /* BFD server.  */
  MTYPE_BFD_SERVER,
  MTYPE_BFD_SERVER_ENTRY,
  MTYPE_BFD_MSG_QUEUE,
  MTYPE_BFD_MSG_QUEUE_BUF,
  /* BFD client library.  */
  MTYPE_BFD_CLIENT,
  MTYPE_BFD_CLIENT_HANDLER,
  MTYPE_BFD_PENDING_MSG,
#endif /* HAVE_BFD || HAVE_MPLS_OAM */

  #ifdef HAVE_VLOGD
  MTYPE_VLOG_GLOBAL,
  MTYPE_VLOG_SRV_ENTRY,
  MTYPE_VLOG_SRV,
  MTYPE_VLOG_TERM,
  MTYPE_VLOG_VR,
  MTYPE_VLOG_CLIENT,
  MTYPE_VLOG_PAL,
  MTYPE_VLOG_FNAME,
#endif /* HAVE_VLOGD */

#ifdef HAVE_LMP
  MTYPE_LMP,
  MTYPE_LMP_MASTER,
  MTYPE_LMP_CC,
  MTYPE_LMP_TELINK,
  MTYPE_LMP_DLINK,
  MTYPE_LMP_DLINK_HASH,
  MTYPE_LMP_DLINK_TEST,
  MTYPE_LMP_ADJ,
  MTYPE_LMP_DL_OBJ,
  MTYPE_LMP_DL_SUBOBJ_ENCODE,
  MTYPE_LMP_DL_SUBOBJ_WAVELENGTH,
  MTYPE_LMP_TMP,
  MTYPE_LMP_IF,
  MTYPE_LMP_TELINK_MSG,
  MTYPE_LMP_TELINK_HASH,
  MTYPE_LMP_FM,
#endif /* HAVE_LMP */

#ifdef HAVE_PBB_TE
  MTYPE_PBB_TE_APS_GROUPS,
#endif /*HAVE_PBB_TE*/

#ifdef HAVE_ELMID
  MTYPE_ELMI_GLOBAL,
  MTYPE_ELMI_MASTER,
  MTYPE_ELMI_BRIDGE,
  MTYPE_ELMI_VLAN_BMP,
  MTYPE_ELMI_VLAN,
  MTYPE_ELMI_INTERFACE,
  MTYPE_ELMI_PORT,
  MTYPE_ELMI_EVC,
  MTYPE_ELMI_CEVLAN_EVC,
  MTYPE_ELMI_UNI,
  MTYPE_ELMI_BW,
#endif /* HAVE_ELMID */

  MTYPE_MAX             /* 612 - Must be last & should be largest. */
};

/* Function prototypes. */
modbmap_t memory_active_modules (void);
int memory_init (int);
int memory_finish (void);
void memory_set_lg (void *);
void memory_unset_lg (void *);

#ifdef MEMMGR
/* Malloc Fault Handler Prototypes */
void *mfh_malloc (int, int, char *, int);
void *mfh_calloc (int, int, char *, int);
void *mfh_realloc (void *, int, int, char *, int);
char *mfh_strdup (const char *, int, char *, int);

/* Memory API mapping.  */
#define XMALLOC(type,size)      mfh_malloc (size, type, __FILE__, __LINE__)
#define XCALLOC(type,size)      mfh_calloc (size, type, __FILE__,  __LINE__)
#define XFREE(type,ptr)         memmgr_free (type, ptr,  __FILE__,  __LINE__)
#define XREALLOC(type,ptr,size) mfh_realloc (ptr, size, type,  __FILE__,  __LINE__)
#define XSTRDUP(type,str)       mfh_strdup (str, type, __FILE__,  __LINE__)
#else

struct memory_global
{
  u_int32_t max_mem_size;
  struct lib_globals *zg;
};

void memory_set_zg (void *);
void memory_unset_zg (void *);

/* Malloc Fault Handler Prototype */
void *mfh_malloc (enum memory_type, size_t);
void *mfh_calloc (enum memory_type, size_t);
void *mfh_realloc (enum memory_type, void *, size_t);
char *mfh_strdup (enum memory_type, const char *);

#define XMALLOC(type,size)      mfh_malloc (type, size)
#define XCALLOC(type,size)      mfh_calloc (type, size)
#define XFREE(type,ptr)         pal_mem_free (type, ptr)
#define XREALLOC(type,ptr,size) mfh_realloc (type, ptr, size)
#define XSTRDUP(type,str)       mfh_strdup (type, str)
#endif /* MEMMGR */

struct lib_globals;

void RecordMemFailureFault (struct lib_globals *);
void xlate_groupid_from_proto (int protocol, u_int16_t *groupId);

#endif /* _PACOS_MEMORY_H */