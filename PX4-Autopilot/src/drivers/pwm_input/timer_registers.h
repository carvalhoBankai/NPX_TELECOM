/****************************************************************************
 *
 *   Copyright (C) 2019 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file timer_registers.h
 *
 * Get architecture-specific timer register defines.
 * Usage:
 * #define INPUT_TIMER <timer>
 * #include "timer_registers.h"
 * # define <xy>_TIMER_BASE      TIMER_BASE
 * # define <xy>_TIMER_CLOCK     TIMER_CLOCK
 * # define <xy>_TIMER_POWER_REG TIMER_CLOCK_POWER_REG
 * # define <xy>_TIMER_POWER_BIT TIMER_CLOCK_POWER_BIT
 * # define <xy>_TIMER_VECTOR    TIMER_IRQ_REG
 *
 */

#include <px4_platform_common/px4_config.h>

#ifndef INPUT_TIMER
# error "need to define INPUT_TIMER to use this header"
#endif

#ifdef TIMER_BASE
#undef TIMER_BASE
#endif
#ifdef TIMER_CLOCK_POWER_REG
#undef TIMER_CLOCK_POWER_REG
#endif
#ifdef TIMER_CLOCK_POWER_BIT
#undef TIMER_CLOCK_POWER_BIT
#endif
#ifdef TIMER_CLOCK
#undef TIMER_CLOCK
#endif
#ifdef TIMER_IRQ_REG
#undef TIMER_IRQ_REG
#endif



#if defined(CONFIG_ARCH_CHIP_STM32H7)

#if   INPUT_TIMER == 1
# define TIMER_BASE	STM32_TIM1_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB2ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB2ENR_TIM1EN
# define TIMER_IRQ_REG	STM32_IRQ_TIMCC
# define TIMER_CLOCK	STM32_APB2_TIM1_CLKIN
#elif INPUT_TIMER == 2
# define TIMER_BASE	STM32_TIM2_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB1LENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB1LENR_TIM2EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM2
# define TIMER_CLOCK	STM32_APB1_TIM2_CLKIN
#elif INPUT_TIMER == 3
# define TIMER_BASE	STM32_TIM3_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB1LENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB1LENR_TIM3EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM3
# define TIMER_CLOCK	STM32_APB1_TIM3_CLKIN
#elif INPUT_TIMER == 4
# define TIMER_BASE	STM32_TIM4_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB1LENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB1LENR_TIM4EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM4
# define TIMER_CLOCK	STM32_APB1_TIM4_CLKIN
#elif INPUT_TIMER == 5
# define TIMER_BASE	STM32_TIM5_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB1LENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB1LENR_TIM5EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM5
# define TIMER_CLOCK	STM32_APB1_TIM5_CLKIN
#elif INPUT_TIMER == 8
# define TIMER_BASE	STM32_TIM8_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB2ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB2ENR_TIM8EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM8CC
# define TIMER_CLOCK	STM32_APB2_TIM8_CLKIN
#elif INPUT_TIMER == 12
# define TIMER_BASE	STM32_TIM12_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB1LENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB1LENR_TIM12EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM12
# define TIMER_CLOCK	STM32_APB1_TIM12_CLKIN
#else
# error INPUT_TIMER must be a value between 1 and 12
#endif


#else // F4, F7

#if   INPUT_TIMER == 1
# define TIMER_BASE	STM32_TIM1_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB2ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB2ENR_TIM1EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM1CC
# define TIMER_CLOCK	STM32_APB2_TIM1_CLKIN
#elif INPUT_TIMER == 2
# define TIMER_BASE	STM32_TIM2_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB1ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB1ENR_TIM2EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM2
# define TIMER_CLOCK	STM32_APB1_TIM2_CLKIN
#elif INPUT_TIMER == 3
# define TIMER_BASE	STM32_TIM3_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB1ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB1ENR_TIM3EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM3
# define TIMER_CLOCK	STM32_APB1_TIM3_CLKIN
#elif INPUT_TIMER == 4
# define TIMER_BASE	STM32_TIM4_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB1ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB1ENR_TIM4EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM4
# define TIMER_CLOCK	STM32_APB1_TIM4_CLKIN
#elif INPUT_TIMER == 5
# define TIMER_BASE	STM32_TIM5_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB1ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB1ENR_TIM5EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM5
# define TIMER_CLOCK	STM32_APB1_TIM5_CLKIN
#elif INPUT_TIMER == 8
# define TIMER_BASE	STM32_TIM8_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB2ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB2ENR_TIM8EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM8CC
# define TIMER_CLOCK	STM32_APB2_TIM8_CLKIN
#elif INPUT_TIMER == 9
# define TIMER_BASE	STM32_TIM9_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB2ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB2ENR_TIM9EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM1BRK
# define TIMER_CLOCK	STM32_APB2_TIM9_CLKIN
#elif INPUT_TIMER == 10
# define TIMER_BASE	STM32_TIM10_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB2ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB2ENR_TIM10EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM1UP
# define TIMER_CLOCK	STM32_APB2_TIM10_CLKIN
#elif INPUT_TIMER == 11
# define TIMER_BASE	STM32_TIM11_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB2ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB2ENR_TIM11EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM1TRGCOM
# define TIMER_CLOCK	STM32_APB2_TIM11_CLKIN
#elif INPUT_TIMER == 12
# define TIMER_BASE	STM32_TIM12_BASE
# define TIMER_CLOCK_POWER_REG	STM32_RCC_APB1ENR
# define TIMER_CLOCK_POWER_BIT	RCC_APB1ENR_TIM12EN
# define TIMER_IRQ_REG	STM32_IRQ_TIM8BRK
# define TIMER_CLOCK	STM32_APB1_TIM12_CLKIN
#else
# error INPUT_TIMER must be a value between 1 and 12
#endif

#endif
