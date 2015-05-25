// -*- C++ -*-
//===========================================================================
/* Time-stamp: <2015-05-09 14:00:21 by jiangtao> */

/* @file Namespace.h
 * $Id: Namespace.h 2015-02-27 06:00:52 jiangtao 
 *
 * @author:Stone Jiang<jiangtao@tao-studio.net>
 */
//===========================================================================

#ifndef NAMESPACE_H
#define NAMESPACE_H

#ifdef __cplusplus
#define NS_GP_CLIENT_BEGIN   namespace GP_Client {
#define NS_GP_CLIENT_END     };
#define USING_NS_GP_CLIENT  using namespace GP_Client
#define NS_GP_CLIENT        ::GP_Client
#else
#define NS_GP_CLIENT_BEGIN   
#define NS_GP_CLIENT_END     
#define USING_NS_GP_CLIENT  
#define NS_GP_CLIENT
#endif


#endif /* NAMESPACE_H */
