#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <neuro_routines.h>
#include <SFML\Window\Event.h>
#include <SFML\System\Clock.h>
#include <stdint.h>

extern sfClock *g_timer;

int cursor_dialog_item_hit_test(int item, neuro_dialog_t *dialog);
void update_cursor();

sfKeyCode handle_sfml_text_input(uint32_t u32_char, char *string, uint32_t size);

#endif
