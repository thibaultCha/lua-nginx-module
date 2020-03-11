
/*
 * Copyright (C) Yichun Zhang (agentzh)
 */


#ifndef _NGX_HTTP_LUA_API_H_INCLUDED_
#define _NGX_HTTP_LUA_API_H_INCLUDED_


#include <nginx.h>
#include <ngx_core.h>
#include <ngx_http.h>

#include <lua.h>
#include <stdint.h>


/* Public API for other Nginx modules */


#define ngx_http_lua_version 10016


typedef struct {
    uint8_t         type;

    union {
        int         b; /* boolean */
        lua_Number  n; /* number */
        ngx_str_t   s; /* string */
    } value;

} ngx_http_lua_value_t;


typedef struct {
    int          len;
    /* this padding hole on 64-bit systems is expected */
    u_char      *data;
} ngx_http_lua_ffi_str_t;


lua_State *ngx_http_lua_get_global_state(ngx_conf_t *cf);

ngx_http_request_t *ngx_http_lua_get_request(lua_State *L);

ngx_int_t ngx_http_lua_add_package_preload(ngx_conf_t *cf, const char *package,
    lua_CFunction func);


#endif /* _NGX_HTTP_LUA_API_H_INCLUDED_ */

/* vi:set ft=c ts=4 sw=4 et fdm=marker: */
