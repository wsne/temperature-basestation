/*
 * Copyright (c) 2006 Intel Corporation
 * All rights reserved.
 *
 * This file is distributed under the terms in the attached INTEL-LICENSE     
 * file. If you do not find these files, copies can be found by writing to
 * Intel Research Berkeley, 2150 Shattuck Avenue, Suite 1300, Berkeley, CA, 
 * 94704.  Attention:  Intel License Inquiry.
 */

// @author David Gay

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

enum {
	/* Number of readings per message. If you increase this, you may have to
	   increase the message_t size. */
	NREADINGS = 10,
	NAVERAGES = 10,

	/* Default sampling period. */
	DEFAULT_INTERVAL = 256,

	AM_TEMPERATURE = 0x93,

	CONVERSION_D1 = 3960, /* VDD = 3V */
	CONVERSION_D2 = 1 /* 14 bits */
};

typedef nx_struct temperature {
	nx_uint16_t version; /* Version of the interval. */
	nx_uint16_t interval; /* Samping period. */
	nx_uint16_t id; /* Mote id of sending mote. */
	nx_uint16_t count; /* The readings are samples count * NREADINGS onwards */
	nx_uint16_t averages[NAVERAGES]; /* The last last NAVERAGES samples. Each
										average has a "resolution" of
										NREADINGS. */

} temperature_t;

#endif
