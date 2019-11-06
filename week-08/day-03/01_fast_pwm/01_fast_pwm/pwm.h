#ifndef PWM_H_
#define PWM_H_

#include <stdint.h>

typedef enum pwm_type {
	FAST,
	PHASE_CORRECT
} pwm_type_t;

void init(pwm_type_t type);
void set_duty(uint8_t duty);

#endif