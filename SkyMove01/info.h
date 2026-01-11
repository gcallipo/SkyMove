/* 
 * THIS IS THE SkyMove project:   https://github.com/gcallipo/SkyMove
 NOTE: 
 *  This Firmware is based on original RAto project with some modifications.
 *
 * CREDITS CREDITS CREDITS
 *
 * RAto v 0.5  Arduino code to move telescope eq mount Right Ascension at
 *             1x and detect button press to cycle among speeds 1x->8x->-6x
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * How to calculate STEP_DELAY to drive motor at right speed to follow stars
 * 
 * Worm Ratio  144		// 144 eq5/exos2, 135 heq5, 130 eq3-2
 * Pulley/Gear Ratio 2.5	// depends on your pulley setup e.w. 40T/16T = 2.5 
 * Steps per revolution  400	// or 200, usually
 * Microstep 32			// make sure to enable pins in driver
 *
 * Steps per degree  12800 	// WormRatio*OtherRatio*StepsPerRevolution*Microsteps/360
 *                         	// = number of microsteps to rotate the scope by 1 degree
 *
 * STEP_DELAY  18699  // 1000000*((23*60*60+56*60+4)/360)/stepsPerDegree
 *                    // = microseconds to advance a microstep
 *                    // 23*60*60+56*60+4 is the number of secs for earth 360deg rotation
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  by gspeed @ astronomia.com / qde / cloudynights.com forum           
 *  Wirings: https://mappite.org/stars/RAto-drv8825.png
 *  This code or newer versions at https://mappite.org/stars/RAto.ino 
 *  
 *  This code is free software under GPL v3 License use at your risk and fun ;)
 *
 * UPDATE: new project aGotino can be used for just RA tracking as well
 *         check for updates on
 *         https://github.com/mappite/aGotino
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * How to calculate STEP_DELAY to drive motor at right speed to follow stars
 * 
 * Worm Ratio  144		// 144 eq5/exos2, 135 heq5, 130 eq3-2
 * Pulley/Gear Ratio 2.5	// depends on your pulley setup e.w. 40T/16T = 2.5 
 * Steps per revolution  400	// or 200, usually
 * Microstep 32			// make sure to enable pins in driver
 *
 * Steps per degree  12800 	// WormRatio*OtherRatio*StepsPerRevolution*Microsteps/360
 *                         	// = number of microsteps to rotate the scope by 1 degree
 *
 * STEP_DELAY  18699  // 1000000*((23*60*60+56*60+4)/360)/stepsPerDegree
 *                    // = microseconds to advance a microstep
 *                    // 23*60*60+56*60+4 is the number of secs for earth 360deg rotation
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 */
