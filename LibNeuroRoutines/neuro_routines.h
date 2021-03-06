/**
 * Copyright (c) 2018 Henadzi Matuts
 */

#ifndef _NEURO_ROUTINES_H
#define _NEURO_ROUTINES_H

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LIBNEURO
#define LIBNEUROAPI __declspec(dllexport)
#else
#define LIBNEUROAPI __declspec(dllimport)
#endif

#pragma pack(push, 2)

typedef struct imh_hdr_t {
	uint16_t dx;
	uint16_t dy;
	uint16_t width;
	uint16_t height;
} imh_hdr_t;

typedef struct resource_t {
	int file;
	char *name;
	long offset;
	size_t size;
} resource_t;

typedef enum spite_chain_index_t {
	SCI_CURSOR = 0,
	SCI_DIALOG = 2,
	SCI_DIALOG_BUBBLE = 3,
	SCI_CHARACTER = 4,
	SCI_LEVEL_BG = 9,
	SCI_BACKGRND = 10,
	SCI_TOTAL = 11
} spite_chain_index_t;

typedef struct sprite_layer_t {
	uint8_t flags; /* 1st bit - active, 5th bit - opaque */
	uint8_t update;
	uint16_t left;
	uint16_t top;
	uint16_t new_left;
	uint16_t new_top;
	imh_hdr_t sprite_hdr;
	uint8_t *sprite_pixels;
	imh_hdr_t _sprite_hdr;
	uint8_t *_sprite_pixels;
} sprite_layer_t;

typedef struct dialog_item_t {
	uint16_t left;
	uint16_t top;
	uint16_t right;
	uint16_t bottom;
	uint16_t unknown; /* index? */
	char letter;
} dialog_item_t;

typedef struct neuro_dialog_t {
	uint16_t left;
	uint16_t top;
	uint16_t right;
	uint16_t bottom;

	uint16_t inner_left;
	uint16_t inner_top;
	uint16_t inner_right;
	uint16_t inner_bottom;

	uint16_t _inner_left;
	uint16_t _inner_top;
	uint16_t _inner_right;
	uint16_t _inner_bottom;

	uint16_t flags;

	uint16_t items_count;
	dialog_item_t items[16];

	uint16_t width;
	uint8_t *pixels;
} neuro_dialog_t;

typedef struct bih_hdr_t {
	uint16_t unknown[3];
	uint16_t text_offset;
} bih_hdr_t;

typedef struct bg_animation_control_table_t {
	uint16_t total_frames;
	uint8_t *first_sleep_offt;
	uint8_t *first_frame_offt;
	uint16_t sleep;
	uint16_t curr_frame;
} bg_animation_control_table_t;

typedef struct anh_hdr_t {
	uint16_t anh_entries;
	/* first entry hdr */
} anh_hdr_t;

typedef struct anh_entry_hdr_t {
	uint16_t entry_size;
	uint16_t total_frames;
	uint16_t first_frame_sleep;
	/* another frames sleep values */
	/* followed by animation frames itself */
} anh_entry_hdr_t;

/*
 * Resource tables.
 */
LIBNEUROAPI extern resource_t g_res_imh[29];
LIBNEUROAPI extern resource_t g_res_pic[56];
LIBNEUROAPI extern resource_t g_res_bih[10];
LIBNEUROAPI extern resource_t g_res_anh[22];

/*
 * Font table.
 */
LIBNEUROAPI extern uint8_t cp437_font[1024];

/*
 * Decompression routines.
 */
LIBNEUROAPI int decompress_imh(uint8_t *src, uint8_t *dst);
LIBNEUROAPI int decompress_pic(uint8_t *src, uint8_t *dst);
LIBNEUROAPI int decompress_bih(uint8_t *src, uint8_t *dst);
LIBNEUROAPI int decompress_anh(uint8_t *src, uint8_t *dst);

//LIBNEUROAPI int asm_decompress(decomp_t *imh, uint8_t *dst);
LIBNEUROAPI int huffman_decompress(uint8_t *src, uint8_t *dst);
LIBNEUROAPI int decode_rle(uint8_t *src, uint32_t len, uint8_t *dst);

/*
 * Text routines.
 */
LIBNEUROAPI void build_character(char c, uint8_t *dst);
LIBNEUROAPI void build_string(char *string, uint32_t w, uint32_t h,
		uint32_t l, uint32_t t, uint8_t *dst);

/*
 * Drawing routines.
 */
LIBNEUROAPI void build_text_frame(uint32_t h, uint32_t w, imh_hdr_t *dst);

/*
 * Dialog box control.
 */
LIBNEUROAPI void build_dialog_frame(neuro_dialog_t *dialog,
					uint16_t left, uint16_t top, uint16_t w, uint16_t h,
					uint16_t flags, uint8_t *pixels);

LIBNEUROAPI void build_dialog_text(neuro_dialog_t *dialog,
					char *text, uint16_t x_offt, uint16_t y_offt);

LIBNEUROAPI void build_dialog_item(neuro_dialog_t *dialog,
					uint16_t x_offt, uint16_t y_offt, uint16_t w,
					uint16_t item_num, char c);

LIBNEUROAPI void select_dialog_item(neuro_dialog_t *_dialog,
					dialog_item_t *item, int select);

LIBNEUROAPI void unselect_dialog_items(neuro_dialog_t *dialog);

/*
* Sound stuff.
*/
LIBNEUROAPI int build_track_waveform(int track_num, uint8_t *waveform, int len);

#ifdef __cplusplus
}
#endif

#pragma pack(pop)
#endif
