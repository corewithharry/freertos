#******************************************************************************
#
# Makefile - Rules for building the driver library and examples.
#
# Copyright (c) 2005,2006 Luminary Micro, Inc.  All rights reserved.
#
# Software License Agreement
#
# Luminary Micro, Inc. (LMI) is supplying this software for use solely and
# exclusively on LMI's Stellaris Family of microcontroller products.
#
# The software is owned by LMI and/or its suppliers, and is protected under
# applicable copyright laws.  All rights are reserved.  Any use in violation
# of the foregoing restrictions may subject the user to criminal sanctions
# under applicable laws, as well as to civil liability for the breach of the
# terms and conditions of this license.
#
# THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
# OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
# LMI SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
# CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
#
#******************************************************************************

include makedefs

RTOS_SOURCE_DIR = ../../Source
DEMO_SOURCE_DIR = ../Common/Minimal

CFLAGS += -DSTM32F429_439xx -DUSE_STDPERIPH_DRIVER
CFLAGS += -I. -I${RTOS_SOURCE_DIR}/include -I${RTOS_SOURCE_DIR}/portable/GCC/ARM_CM4F -I../Common/include
CFLAGS += -ILibraries/STM32F4xx_StdPeriph_Driver/inc -ILibraries/CMSIS/Include
CFLAGS += -IUtilities/STM32F429I-Discovery -IUtilities/Common

VPATH = ${RTOS_SOURCE_DIR}:${RTOS_SOURCE_DIR}/portable/MemMang:${RTOS_SOURCE_DIR}/portable/GCC/ARM_CM4F:${DEMO_SOURCE_DIR}:Libraries/STM32F4xx_StdPeriph_Driver/src:Utilities/STM32F429I-Discovery


OBJS = ${COMPILER}/main.o \
      ${COMPILER}/system_stm32f4xx.o \
      ${COMPILER}/list.o \
      ${COMPILER}/queue.o \
      ${COMPILER}/tasks.o \
      ${COMPILER}/timers.o \
      ${COMPILER}/port.o \
      ${COMPILER}/heap_1.o \
      ${COMPILER}/flash.o \
      ${COMPILER}/BlockQ.o \
      ${COMPILER}/GenQTest.o \
      ${COMPILER}/PollQ.o \
      ${COMPILER}/QPeek.o \
      ${COMPILER}/integer.o	\
      ${COMPILER}/semtest.o \
      ${COMPILER}/recmutex.o \
      ${COMPILER}/misc.o \
      ${COMPILER}/stm32f4xx_dma2d.o \
      ${COMPILER}/stm32f4xx_fmc.o \
      ${COMPILER}/stm32f4xx_gpio.o \
      ${COMPILER}/stm32f4xx_i2c.o \
      ${COMPILER}/stm32f4xx_ltdc.o \
      ${COMPILER}/stm32f4xx_rcc.o \
      ${COMPILER}/stm32f4xx_spi.o \
      ${COMPILER}/stm32f4xx_tim.o \
      ${COMPILER}/stm32f429i_discovery_lcd.o \
      ${COMPILER}/stm32f429i_discovery_sdram.o

INIT_OBJS = ${COMPILER}/startup_stm32f429_439xx.o

LIBS = -lc

#
# The default rule, which causes init to be built.
#
all: ${COMPILER}           \
     ${COMPILER}/RTOSDemo.axf \
	 
#
# The rule to clean out all the build products
#

clean:
	@rm -rf ${COMPILER} ${wildcard *.bin} RTOSDemo.axf
	
#
# The rule to create the target directory
#
${COMPILER}:
	@mkdir ${COMPILER}

${COMPILER}/RTOSDemo.axf: ${INIT_OBJS} ${OBJS} ${LIBS}
LDSCRIPT_RTOSDemo=STM32F429ZI_FLASH.ld

#
#
# Include the automatically generated dependency files.
#
-include ${wildcard ${COMPILER}/*.d} __dummy__


	 



