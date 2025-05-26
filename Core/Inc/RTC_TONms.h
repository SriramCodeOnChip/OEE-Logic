/*
 * RTC_TONms.h
 *
 *  Created on: May 23, 2020
 *      Author: sriram
 */

#ifndef INC_RTC_TONMS_H_
#define INC_RTC_TONMS_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct {
	bool IN;                       // Timer enable input (true = start timer)
	uint32_t PT;                   // Preset time (milliseconds to wait)
	bool Q;                        // Timer output (true when ET >= PT)
	uint32_t ET;                   // Elapsed time (capped at PT)
	bool SET;                      // Internal flag to track if timer is initialized
	uint32_t StartTime;            // Time stamp when the timer was started

} RTC_TONms;

// Updates the timer state. Call this periodically (e.g., in a loop).
void RTC_TONms_Update(RTC_TONms *ton, uint32_t currentTime);

#endif /* INC_RTC_TONMS_H_ */
