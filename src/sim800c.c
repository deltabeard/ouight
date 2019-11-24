/**
 * Library to operate the SIM800C modem over UART serial communication.
 * Copyright (C) 2019 Mahyar Koshkouei
 * This program is released under GPLv3 only.
 */

#include "sim800c.h"

#include <string.h>

enum modem_unsol_stat_e sim800c_process_string(const char *in)
{
	/* If statements in order of decreasing occurrence. */
	if(strncmp(in, "RING", 4) == 0)
		return INCOMING_CALL;

	if(strncmp(in, "RDY", 3) == 0)
		return READY;

	if(strncmp(in, "NORMAL POWER DOWN", 17) == 0)
		return NORMAL_POWER_DOWN;

	return UNKNOWN;
}
