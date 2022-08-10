#pragma once

#define CUSTOM_CODES_BASE_INDEX SAFE_RANGE


enum custom_keycodes {

	//────────────── NULL KEY ──────────────
	//used when no action is required
	NULL_KEY = CUSTOM_CODES_BASE_INDEX, //SAFE_RANGE = 23849
    TILDE
};

static bool accent = false;

bool print_ene( void );

bool handle_accent(uint16_t keycode);
void interrupt_mods( void );