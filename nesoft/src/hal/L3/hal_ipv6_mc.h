/* Copyright (C) 2004  All Rights Reserved. */

#ifndef _HAVE_IPV6_MC_H_
#define _HAVE_IPV6_MC_H_

/* 
   Name: hal_ipv6_mc_init
   
   Description:
   This API initializes the IPv6 multicast table for the specified FIB ID.

   Parameters:
   IN -> fib - FIB ID

   Returns:
   HAL_IP_FIB_NOT_EXIST
   < 0 on error
   HAL_SUCCESS
*/
int
hal_ipv6_mc_init (int fib);

/* 
   Name: hal_ipv6_mc_deinit
   
   Description:
   This API deinitializes the IPv6 multicast table for the specified 
   FIB ID.

   Parameters:
   IN -> fib - FIB ID

   Returns:
   HAL_IP_FIB_NOT_EXIST
   < 0 on error
   HAL_SUCCESS
*/
int
hal_ipv6_mc_deinit (int fib);

/* 
   Name: hal_ipv6_mc_pim_init
   
   Description:
   This API starts PIM routing for the specified FIB ID.

   Parameters:
   IN -> fib - FIB ID

   Returns:
   HAL_IP_FIB_NOT_EXIST
   < 0 on error
   HAL_SUCCESS
*/
int
hal_ipv6_mc_pim_init (int fib);

/* 
   Name: hal_ipv6_mc_pim_deinit
   
   Description:
   This API stops PIM routing for the specified FIB ID.

   Parameters:
   IN -> fib - FIB ID

   Returns:
   HAL_IP_FIB_NOT_EXIST
   < 0 on error
   HAL_SUCCESS
*/
int
hal_ipv6_mc_pim_deinit (int fib);

/* 
   Name: hal_ipv6_mc_get_max_vifs

   Description:
   This API gets the maximum number of VIFs supported.

   Parameters:
   IN -> vifs - max VIFs

   Returns:
   < 0 on error
   HAL_SUCCESS
*/
int
hal_ipv6_mc_get_max_vifs (int *vifs);

/*
  Name: hal_ipv6_mc_vif_add

  Description:
  This API creates a VIF.

  Parameters:
  IN -> vif_index - VIF index
  IN -> phy_ifindex - Physical interface index
  IN -> flags - VIF type

  Returns:
  < 0 on error
  HAL_SUCCESS
*/
int
hal_ipv6_mc_vif_add (u_int32_t vif_index, u_int32_t phy_ifindex, 
    u_int16_t flags);

/*
  Name: hal_ipv6_mc_vif_delete

  Description:
  This API deletes a VIF.

  Parameters:
  IN -> vif_index - VIF index

  Returns:
  < 0 on error
  HAL_SUCCESS
*/
int
hal_ipv6_mc_vif_delete (u_int32_t vif_index);

/* 
   Name: hal_ipv6_mc_vif_addr_add

   Description:
   Add an address to a configured VIF.

   Parameters:
   IN -> index - VIF index
   IN -> addr - address to add
   IN -> subnet - subnet address to add
   IN -> broadcast - broadcast address to add
   IN -> peer - peer address to add

   Returns:
   HAL_IPV6_MC_VIF_NOTEXISTS
   < 0 on error
   HAL_SUCCESS
*/
int
hal_ipv6_mc_vif_addr_add (unsigned int index,
                          struct pal_in6_addr *addr,
                          struct pal_in6_addr *subnet,
                          struct pal_in6_addr *broadcast,
                          struct pal_in6_addr *peer);

/* 
   Name:
   hal_ipv6_mc_vif_addr_delete

   Description:
   Deletes an address from a configured VIF.

   Parameters:
   IN -> index - VIF index
   IN -> addr - address to delete

   Returns:
   HAL_IPV6_MC_VIF_NOTEXISTS
   HAL_IPV6_MC_VIF_ADDRESS_NOTFOUND
   HAL_SUCCESS
*/
int
hal_ipv6_mc_vif_addr_delete (unsigned int index, struct pal_in6_addr *addr);


/*
  Name: hal_ipv6_mc_vif_set_physical_if

  Description:
  This API sets the physical interface index to a configured VIF.

  Parameters:
  IN -> index - VIF index
  IN -> ifindex - physical interface index

  Returns:
  HAL_IPV6_MC_VIF_NOTEXISTS
  HAL_IPV6_MC_IF_NOTEXISTS
  HAL_SUCCESS
*/
int
hal_ipv6_mc_vif_set_physical_if (unsigned int index, unsigned int ifindex);

/* 
   Name: hal_ipv6_mc_vif_set_flags

   Description:
   This API sets the VIF flags of a configured VIF.

   Parameters:
   IN -> index - VIF index
   IN -> is_pim_register - true if the VIF is a PIM register interface 
   IN -> is_p2p - true if the VIF is a point-to-point interface
   IN -> is_loopback - true if the VIF is a loopback interface
   IN -> is_multicast - true if the VIF is a multicast interface
   IN -> is_broadcast - true if the VIF is a broadcast interface

   Returns:
   HAL_IPV6_MC_VIF_NOTEXISTS
   < 0 on other errors
   HAL_SUCCESS
*/
int
hal_ipv6_mc_vif_set_flags (unsigned int ifindex,
                           unsigned char is_pim_register,
                           unsigned char is_p2p,
                           unsigned char is_loopback,
                           unsigned char is_multicast,
                           unsigned char is_broadcast);


/* 
   Name: hal_ipv6_mc_set_min_ttl_threshold

   Description:
   Set the minimum TTL a multicast packet must have to be forwarded on this
   virtual interface.

   Parameters:
   IN -> index - VIF index
   IN -> ttl - TTL threshold

   Returns:
   HAL_IPV6_MC_VIF_NOTEXITS
   HAL_SUCCESS
*/
int
hal_ipv6_mc_set_min_ttl_threshold (unsigned int ifindex, unsigned char ttl);

/* 
   Name: hal_ipv6_mc_get_min_ttl_threshold

   Description:
   Get the minimum TTL a multicast packet will be to be forwarded on this
   virtual interface.

   Parameters:
   IN -> index - VIF index
   IN -> ttl - TTL threshold

   Returns:
   HAL_IPV6_MC_VIF_NOTEXISTS
   HAL_SUCCESS
*/
int
hal_ipv6_mc_get_min_ttl_threshold (unsigned int index, unsigned char ttl);

/* 
   Name: hal_ipv6_mc_set_max_rate_limit

   Description:
   Set the maximum multicast bandwidth rate allowed on this virtual interface.

   Parameters:
   IN -> index - VIF index
   IN -> rate_limit - rate limit

   Returns:
   HAL_IPV6_MC_VIF_NOTEXISTS
   HAL_SUCCESS
*/
int
hal_ipv6_mc_set_max_rate_limit (unsigned int index, 
                                unsigned int rate_limit);

/* 
   Name: hal_ipv6_mc_get_max_rate_limit

   Description:
   Set the maximum multicast bandwidth rate allowed on this virtual interface.

   Parameters:
   IN -> index - VIF index
   IN -> rate_limit - rate limit

   Returns:
   HAL_IPV6_MC_VIF_NOTEXISTS
   HAL_SUCCESS
*/
int
hal_ipv6_mc_get_max_rate_limit (unsigned int index, 
                                unsigned int rate_limit);


/* 
   Name: hal_ipv6_mc_add_mfc 

   Description:
   Install/modify a Multicast Forwarding Cache (MFC). If the MFC entry
   (source, group) is not found a new one will be created; otherwise
   the existing entry will be modified.

   Parameters:
   IN -> source - source 
   IN -> group - group
   IN -> iif_vif_index - MFC incoming interface index
   IN -> num_olist - Number of unsigned 32-bit elements in the olist bitmap
   IN -> olist - A array of vif indices in olist

   Returns:
   HAL_IPV6_MC_MFC
   HAL_SUCCESS
*/
int
hal_ipv6_mc_add_mfc (struct hal_in6_addr *source, struct hal_in6_addr *group,
                     u_int32_t iif_vif_index, u_int32_t num_olist, 
                     u_int16_t *olist);

/* 
   Name: hal_ipv6_mc_delete_mfc

   Description:
   Delete a Multicast Forwarding Cache (MFC) entry.

   Parameters:
   IN -> source - source
   IN -> group - group

   Returns:
   < 0 error
   HAL_SUCCESS
*/
int
hal_ipv6_mc_delete_mfc (struct hal_in6_addr *source, 
    struct hal_in6_addr *group);


/* 
   Name: hal_ivp4_mc_get_sg_count

   Description:
   This API gets the various counters per (S, G) entry.

   Parameters:
   IN -> src - source address
   IN -> grp - group addresss
   IN -> iif_vif - incoming VIF
   IN -> pktcnt - packet count
   IN -> bytecnt - byte count
   IN -> wrong_vif - wrong VIFs

   Returns:
   < 0 on error
   HAL_SUCCESS
*/
int
hal_ipv6_mc_get_sg_count (struct hal_in6_addr *source, 
                          struct hal_in6_addr *group,
                          u_int32_t iif_vif,
                          u_int32_t *pktcnt,
                          u_int32_t *bytecnt,
                          u_int32_t *wrong_vif);

#endif /* _HAVE_IPV6_MC_H_ */
