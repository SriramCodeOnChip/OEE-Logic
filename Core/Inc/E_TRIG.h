/*
 * E_TRIG.h
 *
 *  Created on: May 23, 2020
 *      Author: Sriram
 */

#ifndef INC_E_TRIG_H_
#define INC_E_TRIG_H_

#include <stdbool.h>

typedef struct {
	bool Q;                     // Rising Output Pulse (1 if input raising edge detected)
	bool FT_Q;                  // Falling Output Pulse (1 if input falling edge detected))
	bool Stat_Bit;              // Last Cycles input State
}E_TRIG;

void E_TRIG_Update(E_TRIG *trig, bool clk);

#endif /* INC_E_TRIG_H_ */
