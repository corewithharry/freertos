/*
    FreeRTOS V6.1.0 - Copyright (C) 2010 Real Time Engineers Ltd.

    ***************************************************************************
    *                                                                         *
    * If you are:                                                             *
    *                                                                         *
    *    + New to FreeRTOS,                                                   *
    *    + Wanting to learn FreeRTOS or multitasking in general quickly       *
    *    + Looking for basic training,                                        *
    *    + Wanting to improve your FreeRTOS skills and productivity           *
    *                                                                         *
    * then take a look at the FreeRTOS books - available as PDF or paperback  *
    *                                                                         *
    *        "Using the FreeRTOS Real Time Kernel - a Practical Guide"        *
    *                  http://www.FreeRTOS.org/Documentation                  *
    *                                                                         *
    * A pdf reference manual is also available.  Both are usually delivered   *
    * to your inbox within 20 minutes to two hours when purchased between 8am *
    * and 8pm GMT (although please allow up to 24 hours in case of            *
    * exceptional circumstances).  Thank you for your support!                *
    *                                                                         *
    ***************************************************************************

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
    ***NOTE*** The exception to the GPL is included to allow you to distribute
    a combined work that includes FreeRTOS without being obliged to provide the
    source code for proprietary components outside of the FreeRTOS kernel.
    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details. You should have received a copy of the GNU General Public
    License and the FreeRTOS license exception along with FreeRTOS; if not it
    can be viewed here: http://www.freertos.org/a00114.html and also obtained
    by writing to Richard Barry, contact details for whom are available on the
    FreeRTOS WEB site.

    1 tab == 4 spaces!

    http://www.FreeRTOS.org - Documentation, latest information, license and
    contact details.

    http://www.SafeRTOS.com - A version that is certified for use in safety
    critical systems.

    http://www.OpenRTOS.com - Commercial support, development, porting,
    licensing and training services.
*/

/*-----------------------------------------------------------
 * Simple parallel port IO routines.
 *-----------------------------------------------------------*/

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/* ST library functions. */
#include "stm32l152_eval.h"

#define partstMAX_OUTPUT_LED 4

/*-----------------------------------------------------------*/

void vParTestInitialise( void )
{
	/* Configure the output LEDs.   Note that JP18 and JP19 must be closed on
	the Eval board for LED3 and LED4 to work. */
	STM_EVAL_LEDInit( LED1 );
	STM_EVAL_LEDInit( LED2 );
	STM_EVAL_LEDInit( LED3 );
	STM_EVAL_LEDInit( LED4 );
	STM_EVAL_LEDOff( LED1 );
	STM_EVAL_LEDOff( LED2 );
	STM_EVAL_LEDOff( LED3 );
	STM_EVAL_LEDOff( LED4 );	
}
/*-----------------------------------------------------------*/

void vParTestSetLED( unsigned portBASE_TYPE uxLED, signed portBASE_TYPE xValue )
{
	vTaskSuspendAll();
	{
		if( xValue != pdFALSE )
		{
			switch( uxLED )
			{
				case 0: STM_EVAL_LEDOn( LED1 );
						break;
	
				case 1: STM_EVAL_LEDOn( LED2 );
						break;
	
				case 2: STM_EVAL_LEDOn( LED3 );
						break;
	
				case 3: STM_EVAL_LEDOn( LED4 );
						break;					
			}
		}
		else
		{
			switch( uxLED )
			{
				case 0: STM_EVAL_LEDOff( LED1 );
						break;
	
				case 1: STM_EVAL_LEDOff( LED2 );
						break;
	
				case 2: STM_EVAL_LEDOff( LED3 );
						break;
	
				case 3: STM_EVAL_LEDOff( LED4 );
						break;					
			}
		}
	}
	xTaskResumeAll();
}
/*-----------------------------------------------------------*/

void vParTestToggleLED( unsigned portBASE_TYPE uxLED )
{
	vTaskSuspendAll();
	{
		switch( uxLED )
		{
			case 0: STM_EVAL_LEDToggle( LED1 );
					break;

			case 1: STM_EVAL_LEDToggle( LED2 );
					break;

			case 2: STM_EVAL_LEDToggle( LED3 );
					break;

			case 3: STM_EVAL_LEDToggle( LED4 );
					break;					
		}
	}
	xTaskResumeAll();
}
/*-----------------------------------------------------------*/

