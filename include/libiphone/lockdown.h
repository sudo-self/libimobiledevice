/**
 * @file libiphone/lockdown.h
 * @brief Communcation with the lockdown device daemon
 * \internal
 *
 * Copyright (c) 2008 Zach C. All Rights Reserved.
 * Copyright (c) 2009 Martin S. All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef LOCKDOWN_H
#define LOCKDOWN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <libiphone/libiphone.h>

/* Error Codes */
#define LOCKDOWN_E_SUCCESS                    0
#define LOCKDOWN_E_INVALID_ARG               -1
#define LOCKDOWN_E_INVALID_CONF              -2
#define LOCKDOWN_E_PLIST_ERROR               -3
#define LOCKDOWN_E_PAIRING_FAILED            -4
#define LOCKDOWN_E_SSL_ERROR                 -5
#define LOCKDOWN_E_DICT_ERROR                -6
#define LOCKDOWN_E_START_SERVICE_FAILED      -7
#define LOCKDOWN_E_NOT_ENOUGH_DATA           -8
#define LOCKDOWN_E_SET_VALUE_PROHIBITED      -9
#define LOCKDOWN_E_GET_VALUE_PROHIBITED     -10
#define LOCKDOWN_E_REMOVE_VALUE_PROHIBITED  -11
#define LOCKDOWN_E_MUX_ERROR                -12
#define LOCKDOWN_E_ACTIVATION_FAILED        -13
#define LOCKDOWN_E_PASSWORD_PROTECTED       -14

#define LOCKDOWN_E_UNKNOWN_ERROR           -256

typedef int16_t lockdownd_error_t;

struct lockdownd_client_int;
typedef struct lockdownd_client_int *lockdownd_client_t;

/* Interface */
lockdownd_error_t lockdownd_client_new(iphone_device_t device, lockdownd_client_t *client, const char *label);
lockdownd_error_t lockdownd_client_free(lockdownd_client_t client);
void lockdownd_client_set_label(lockdownd_client_t client, const char *label);
lockdownd_error_t lockdownd_query_type(lockdownd_client_t client, char **type);
lockdownd_error_t lockdownd_get_value(lockdownd_client_t client, const char *domain, const char *key, plist_t *value);
lockdownd_error_t lockdownd_set_value(lockdownd_client_t client, const char *domain, const char *key, plist_t value);
lockdownd_error_t lockdownd_remove_value(lockdownd_client_t client, const char *domain, const char *key);
lockdownd_error_t lockdownd_start_service(lockdownd_client_t client, const char *service, int *port);
lockdownd_error_t lockdownd_stop_session(lockdownd_client_t client);
lockdownd_error_t lockdownd_send(lockdownd_client_t client, plist_t plist);
lockdownd_error_t lockdownd_recv(lockdownd_client_t client, plist_t *plist);
lockdownd_error_t lockdownd_pair(lockdownd_client_t client, char *host_id);
lockdownd_error_t lockdownd_validate_pair(lockdownd_client_t client, char *host_id);
lockdownd_error_t lockdownd_unpair(lockdownd_client_t client, char *host_id);
lockdownd_error_t lockdownd_activate(lockdownd_client_t client, plist_t activation_record);
lockdownd_error_t lockdownd_deactivate(lockdownd_client_t client);
lockdownd_error_t lockdownd_get_device_uuid(lockdownd_client_t control, char **uuid);
lockdownd_error_t lockdownd_get_device_name(lockdownd_client_t client, char **device_name);
lockdownd_error_t lockdownd_enter_recovery(lockdownd_client_t client);
lockdownd_error_t lockdownd_goodbye(lockdownd_client_t client);

#ifdef __cplusplus
}
#endif

#endif