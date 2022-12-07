/*
 * watchdog.h
 * brief:
 * 		this source configures the watchdog, setups it refresh time
 * 		and can tell how many times the system was restarted.
 *
 *  Created on: Oct 2, 2022
 *      Author: Laura García
 */

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

// initialize and setups the watchdog, it need a to be fed before 100ms
void setup_watchdog(void);
// feeds the watchdog
void refresh_watchdog(void);
// returns the number of resets the watchdog has done
uint16_t get_reset_count(void);

#endif /* WATCHDOG_H_ */
