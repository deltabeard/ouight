#include "minctest.h"
#include "sim800c.h"

#include <stdlib.h>

#define FAKE_TELEPHONE_NUMBER "+447700900407"

/**
 * If the connected processor receives data from the SIM800C modem when were
 * weren't expecting it, we recognise this as an "unsolicited result code" as
 * described in Section 19.3 of the SIM800 Series AT Command Manual.
 *
 * The user implementation is expected to catch this unsolicited data, and send
 * it to the sim800c library to process what it was.
 *
 * This tests that unsolicited result codes are processed properly.
 */
void sim800c_unsolicited_test(void)
{
	const char *in[] = {
		/* Call waiting. */
		//"+CCWA: \"" FAKE_TELEPHONE_NUMBER "\",161,\"Fake Number\"",
		//"+CLIP: \"" FAKE_TELEPHONE_NUMBER "\",\"???\",1,\"Fake Number\",0",
		/* SMS received and stored in memory location 1. */
		"+CMTI: \"SM\",1",
		/* Network update time zone. */
		//"+CTZV: \"\"",
		/* Network updated Daylight Saving Time to no adjustment.*/
		"DST: 0",
		/* Incoming call. */
		"RING",
		/* The SIM800C module powered down. */
		"NORMAL POWER DOWN",
		/* The input voltage dipped too low, forcing the modem to turn
		 * off. */
		"UNDER-VOLTAGE POWER DOWN",
		/* The input votlage is getting too low. */
		"UNDER-VOLTAGE WARNING",
		/* The input voltage was too high. Check your circuit or surge
		 * occured. */
		"OVER-VOLTAGE POWER DOWN",
		/* The input voltage is getting dangerously high. */
		"OVER-VOLTAGE WARNING",
		/* A charger was attached to the modem. */
		"CHARGE-ONLY MODE",
		/* Power On Reset (POR) was completed. (Not shown if autobauding
		 * is activated). */
		"RDY"
	};

	enum modem_unsol_stat_e exp[] = {
		UNKNOWN,
		RECEIVED_SMS,
		DST_UPDATED,
		INCOMING_CALL,
		NORMAL_POWER_DOWN,
		UNDERVOLTAGE_POWER_DOWN,
		UNDERVOLTAGE_WARNING,
		OVERVOLTAGE_POWER_DOWN,
		OVERVOLTAGE_WARNING,
		CHARGEONLY_MODE,
		READY
	};

	for(unsigned i = 0; i < sizeof(in)/sizeof(*in); i++)
	{
		lequal(sim800c_process_string(in[i]), exp[i]);
	}
}

int main(void)
{
	lrun("Unsolicited Result Code", sim800c_unsolicited_test);
	lresults();
	return lfails != 0;
}
