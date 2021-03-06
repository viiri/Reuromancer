#include "neuro_routines.h"
#include <string.h>

void build_dialog_frame(neuro_dialog_t *dialog,
		uint16_t left, uint16_t top, uint16_t w, uint16_t h,
		uint16_t flags, uint8_t *pixels)
{
	dialog->flags = flags;

	dialog->left = left;
	dialog->top = top;
	dialog->right = left + w - 1;
	dialog->bottom = top + h - 1;

	dialog->inner_left = dialog->left + 8;
	dialog->inner_top = dialog->top + 8;
	dialog->inner_right = dialog->right - 8;
	dialog->inner_bottom = dialog->bottom - 8;

	memmove(&dialog->_inner_left,
		&dialog->inner_left, sizeof(uint16_t) * 4);

	dialog->items_count = 0;

	dialog->width = w / 2;
	dialog->pixels = pixels;

	build_text_frame(h, w, (imh_hdr_t*)pixels);
}

void build_dialog_text(neuro_dialog_t *dialog,
		char *text, uint16_t x_offt, uint16_t y_offt)
{
	uint16_t w = dialog->width * 2;
	uint16_t h = dialog->bottom - dialog->top + 1;
	uint16_t l = dialog->inner_left - dialog->left + x_offt;
	uint16_t t = dialog->inner_top - dialog->top + y_offt;
	uint8_t *p = (uint8_t*)dialog->pixels;

	build_string(text, w, h, l, t, p + sizeof(imh_hdr_t));
}

void build_dialog_item(neuro_dialog_t *dialog,
		uint16_t x_offt, uint16_t y_offt, uint16_t w,
		uint16_t item_num, char c)
{
	if (item_num > 15)
	{
		return;
	}

	dialog_item_t *item = &dialog->items[dialog->items_count];

	memset(item, 0, sizeof(dialog_item_t));

	item->left = dialog->inner_left + x_offt;
	item->top = dialog->inner_top + y_offt;
	item->right = item->left + w - 1;
	item->bottom = item->top + 7;
	item->unknown = item_num;
	item->letter = c;

	dialog->items_count++;
}

void select_dialog_item(neuro_dialog_t *_dialog,
		dialog_item_t *item, int select)
{
	imh_hdr_t *dialog = (imh_hdr_t*)_dialog->pixels;
	uint8_t *pixels = (uint8_t*)dialog + sizeof(imh_hdr_t);
	uint32_t item_left = (item->left - _dialog->left) / 2;
	uint32_t item_top = item->top - _dialog->top;
	uint32_t item_right = (item->right - _dialog->left) / 2;
	uint32_t item_bottom = item->bottom - _dialog->top;

	if (pixels[item_top * dialog->width + item_right] == (select ? 0xFF : 0x00))
	{
		for (uint16_t h = item_top; h <= item_bottom; h++)
		{
			for (uint16_t w = item_left; w <= item_right; w++)
			{
				pixels[h * dialog->width + w] ^= 0xFF;
			}
		}
	}
}

void unselect_dialog_items(neuro_dialog_t *dialog)
{
	for (uint16_t i = 0; i < dialog->items_count; i++)
	{
		select_dialog_item(dialog, &dialog->items[i], 0);
	}
}
