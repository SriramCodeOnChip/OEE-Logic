/*
 * RTC_TON.c
 *
 *  Created on: May 23, 2020
 *      Author: Sriram
 */

#include <RTC_TONms.h>

void RTC_TONms_Update(RTC_TONms *ton, uint32_t CurrentTime)
{
	if (ton-> IN)                                                      // If the timer is enabled:
	{
		if(!ton->SET)
		{                                                              // First activation: initialize startTime
		ton->StartTime = CurrentTime;                                  // Capture the start time stamp
		ton->SET = true;                                               // Mark timer as initialized
		}

		uint32_t elapsed = CurrentTime - ton->StartTime;               // Calculate raw elapsed time
		if (elapsed > ton->PT)                                         // Cap elapsed time at PT to avoid overflow
		{
			ton->ET = ton->PT;                                         // ET cannot exceed PT
		}
		else
		{
			ton->ET = elapsed;
		}                                                              // Use actual elapsed time
		ton->Q = (ton->ET >= ton->PT);                                 // Set output Q when ET >= PT

	}
	else
	{                                                                  // If the timer is disabled:
		ton->SET = false;                                              // Reset initialization flag
		ton->Q = false;                                                // Turn off output
		ton->ET = 0;                                                   // Reset elapsed time
	}
}
