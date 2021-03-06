/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 * rmfd
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2015 Safran Passenger Innovations
 *
 * Author: Aleksander Morgado <aleksander@aleksander.es>
 */

#ifndef RMFD_STATS_H
#define RMFD_STATS_H

#include <glib.h>

typedef enum {
    RMFD_STATS_RECORD_TYPE_START,
    RMFD_STATS_RECORD_TYPE_PARTIAL,
    RMFD_STATS_RECORD_TYPE_FINAL,
} RmfdStatsRecordType;

typedef struct _RmfdStatsContext RmfdStatsContext;

RmfdStatsContext *rmfd_stats_setup        (const gchar         *path,
                                           const gchar         *context_name);
void              rmfd_stats_record       (RmfdStatsContext    *ctx,
                                           RmfdStatsRecordType  type,
                                           GDateTime           *system_time,
                                           guint64              rx_bytes,
                                           guint64              tx_bytes,
                                           const gchar         *radio_interface,
                                           gint8                rssi,
                                           guint16              mcc,
                                           guint16              mnc,
                                           guint16              lac,
                                           guint32              cid);
void              rmfd_stats_teardown     (RmfdStatsContext    *ctx);

guint             rmfd_stats_get_year     (RmfdStatsContext *ctx);
guint             rmfd_stats_get_month    (RmfdStatsContext *ctx);
guint64           rmfd_stats_get_rx_bytes (RmfdStatsContext *ctx);
guint64           rmfd_stats_get_tx_bytes (RmfdStatsContext *ctx);

#endif /* RMFD_STATS_H */
