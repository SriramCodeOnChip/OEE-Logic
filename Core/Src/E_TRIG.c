/*
 * E_TRIG.c
 *
 *  Created on: May 23, 2020
 *      Author: Sriram
 */

#include <E_TRIG.h>

void E_TRIG_Update(E_TRIG *trig, bool clk)
{
	trig->Q = clk && !(trig->Stat_Bit);
	trig->FT_Q = trig->Stat_Bit && !clk;
	trig->Stat_Bit = clk;
}
