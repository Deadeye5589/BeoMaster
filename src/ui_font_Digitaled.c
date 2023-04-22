/*******************************************************************************
 * Size: 42 px
 * Bpp: 8
 * Opts: --bpp 8 --size 42 --font C:\Users\Succubus\Documents\SquareLine\assets\LCDPhone2.ttf -o C:\Users\Succubus\Documents\SquareLine\assets\ui_font_Digitaled.c --format lvgl -r 0x2D -r 0x30-0x39 --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_DIGITALED
#define UI_FONT_DIGITALED 1
#endif

#if UI_FONT_DIGITALED

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002D "-" */
    0x0, 0xc3, 0xfd, 0x9f, 0x46, 0xf2, 0x93, 0x55,
    0xf3, 0x7a, 0x67, 0xf3, 0x6c, 0x75, 0xf2, 0x5e,
    0xb, 0xff, 0xff, 0xe3, 0x83, 0xff, 0xd7, 0x93,
    0xff, 0xbb, 0xab, 0xff, 0xab, 0xbb, 0xff, 0x9b,
    0xc, 0xff, 0xff, 0xe4, 0x84, 0xff, 0xd8, 0x94,
    0xff, 0xbc, 0xac, 0xff, 0xac, 0xbc, 0xff, 0x9c,
    0x1, 0xd1, 0xfe, 0xac, 0x53, 0xf6, 0xa0, 0x62,
    0xf7, 0x86, 0x78, 0xf8, 0x77, 0x87, 0xf8, 0x68,

    /* U+0030 "0" */
    0x0, 0x0, 0x0, 0x2, 0xc1, 0xfb, 0x92, 0x4d,
    0xec, 0x79, 0x5e, 0xed, 0x6b, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1c, 0xff, 0xff, 0xd8,
    0x94, 0xff, 0xbc, 0xac, 0xff, 0xac, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1c, 0xff, 0xff,
    0xd7, 0x94, 0xff, 0xbb, 0xac, 0xff, 0xab, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xd6,
    0xfa, 0x9d, 0x60, 0xf3, 0x83, 0x75, 0xf4, 0x74,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x43, 0x66, 0x3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x20, 0x71, 0x18, 0x0, 0x6, 0xf5, 0xff,
    0x49, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xac, 0xff, 0x95, 0x0, 0xc, 0xff,
    0xff, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbc, 0xff, 0x9c, 0x0, 0x7,
    0xfd, 0xff, 0x49, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xb5, 0xff, 0x95, 0x0,
    0x0, 0x4b, 0x66, 0x5, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x29, 0x70, 0x1c,
    0x0, 0x1, 0xb8, 0xe5, 0x26, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x61, 0xee, 0x70, 0x6f, 0xef,
    0x61, 0x0, 0xc, 0xff, 0xff, 0x50, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xac, 0xff, 0xac, 0xbc,
    0xff, 0x9c, 0x0, 0xb, 0xff, 0xff, 0x4f, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xab, 0xff, 0xab,
    0xbb, 0xff, 0x9b, 0x0, 0x1, 0xb4, 0xcf, 0x21,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x65, 0xd9,
    0x65, 0x73, 0xd8, 0x58, 0x0, 0x0, 0x57, 0x98,
    0x4b, 0x0, 0x0, 0x0, 0x1d, 0x89, 0x36, 0x0,
    0x0, 0x0, 0x2d, 0x8a, 0x26, 0x0, 0x8, 0xfa,
    0xff, 0xe0, 0x0, 0x0, 0x0, 0x8b, 0xff, 0xb8,
    0x0, 0x0, 0x0, 0xb2, 0xff, 0x98, 0x0, 0xc,
    0xff, 0xff, 0xe4, 0x0, 0x0, 0x0, 0x94, 0xff,
    0xbc, 0x0, 0x0, 0x0, 0xbc, 0xff, 0x9c, 0x0,
    0x5, 0xf8, 0xff, 0xd6, 0x0, 0x0, 0x0, 0x86,
    0xff, 0xae, 0x0, 0x0, 0x0, 0xae, 0xff, 0x8e,
    0x0, 0x0, 0x37, 0x83, 0x27, 0x0, 0x23, 0x6,
    0xb, 0x48, 0x14, 0x0, 0x0, 0x0, 0x17, 0x6e,
    0xd, 0x0, 0x3, 0xe1, 0xff, 0xc6, 0x5d, 0xff,
    0xba, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x93,
    0xff, 0x7e, 0x0, 0xc, 0xff, 0xff, 0xe4, 0x84,
    0xff, 0xd8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbc, 0xff, 0x9c, 0x0, 0xc, 0xff, 0xff, 0xe4,
    0x84, 0xff, 0xd8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xbc, 0xff, 0x9c, 0x0, 0x4, 0xf0, 0xff,
    0xcc, 0x6c, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa4, 0xff, 0x84, 0x0, 0x0, 0x2d,
    0x77, 0x20, 0x0, 0x23, 0x9, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5, 0x49, 0x2e, 0x0, 0x4,
    0xe9, 0xff, 0xd1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x10, 0xf6, 0xfe, 0x23,
    0xc, 0xff, 0xff, 0xe4, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0xff, 0xff,
    0x34, 0x9, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x21, 0xff,
    0xff, 0x30, 0x0, 0x6f, 0x9a, 0x58, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0x7c, 0x82, 0x4, 0x0, 0x0, 0x0, 0x0, 0x36,
    0xd6, 0x81, 0x42, 0xd8, 0x6a, 0x52, 0xe1, 0xcb,
    0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x83, 0xff, 0xd7, 0x93, 0xff, 0xbb, 0xab, 0xff,
    0xff, 0x43, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x84, 0xff, 0xd8, 0x94, 0xff, 0xbc, 0xac,
    0xff, 0xff, 0x44, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x54, 0xf7, 0xa2, 0x63, 0xf8, 0x87,
    0x79, 0xfc, 0xeb, 0x21, 0x0, 0x0, 0x0,

    /* U+0031 "1" */
    0x0, 0x0, 0x0, 0x0, 0x4b, 0xeb, 0x84, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x94,
    0xff, 0xc8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x94, 0xff, 0xc7, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 0xf3, 0x8e,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x4a, 0x7f, 0x30,
    0x13, 0x6f, 0x2a, 0x0, 0x0, 0x0, 0x0, 0x11,
    0xfb, 0xff, 0xd1, 0x84, 0xff, 0xc1, 0x0, 0x0,
    0x0, 0x0, 0x1c, 0xff, 0xff, 0xd8, 0x94, 0xff,
    0xc8, 0x0, 0x0, 0x0, 0x0, 0x15, 0xff, 0xff,
    0xd1, 0x8d, 0xff, 0xc1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x53, 0x76, 0x34, 0x19, 0x6f, 0x2e, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4f,
    0xed, 0x89, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x94, 0xff, 0xc8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x93, 0xff, 0xc7,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x52, 0xd8, 0x7c, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1c, 0x88, 0x3c, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8a, 0xff,
    0xc4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x94, 0xff, 0xc8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x86, 0xff, 0xba, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa,
    0x6c, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6c, 0xff, 0xaa, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x94, 0xff, 0xc8,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x94, 0xff, 0xc8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7c, 0xff, 0xb0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x61,
    0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x76, 0xff, 0xb5, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x94, 0xff, 0xc8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x91,
    0xff, 0xc4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2b, 0x94, 0x48, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x36, 0xd6, 0x81, 0x41, 0xd8, 0x74,
    0x4e, 0xe1, 0xcb, 0x16, 0x0, 0x83, 0xff, 0xd7,
    0x93, 0xff, 0xc7, 0xa3, 0xff, 0xff, 0x43, 0x0,
    0x84, 0xff, 0xd8, 0x94, 0xff, 0xc8, 0xa4, 0xff,
    0xff, 0x44, 0x0, 0x54, 0xf7, 0xa2, 0x62, 0xf8,
    0x93, 0x72, 0xfc, 0xeb, 0x21,

    /* U+0032 "2" */
    0x0, 0x0, 0x0, 0x2, 0xc1, 0xfb, 0x92, 0x4d,
    0xec, 0x79, 0x5e, 0xed, 0x6b, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1c, 0xff, 0xff, 0xd8,
    0x94, 0xff, 0xbc, 0xac, 0xff, 0xac, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1c, 0xff, 0xff,
    0xd7, 0x94, 0xff, 0xbb, 0xac, 0xff, 0xab, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xd6,
    0xfa, 0x9d, 0x60, 0xf3, 0x83, 0x75, 0xf4, 0x74,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x43, 0x66, 0x3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x20, 0x71, 0x18, 0x0, 0x6, 0xf5, 0xff,
    0x49, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xac, 0xff, 0x95, 0x0, 0xc, 0xff,
    0xff, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbc, 0xff, 0x9c, 0x0, 0x7,
    0xfd, 0xff, 0x49, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xb5, 0xff, 0x95, 0x0,
    0x0, 0x4b, 0x66, 0x5, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x29, 0x70, 0x1c,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xef,
    0x61, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbc,
    0xff, 0x9c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbb, 0xff, 0x9b, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x73, 0xd8, 0x58, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x25,
    0x8a, 0x2e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xa2, 0xff, 0xa8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xac, 0xff, 0xac, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x9e, 0xff, 0x9e, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x24, 0x3, 0x10, 0x49, 0x10, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x6e, 0xff, 0x9e, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x94, 0xff, 0xbc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x94, 0xff, 0xbc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7d, 0xff, 0xa4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0x3b, 0x12, 0x1, 0x24, 0x5,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x66, 0xff, 0xc5, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x84, 0xff, 0xd8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x81, 0xff, 0xd4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0x93,
    0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xa2, 0xe8, 0x8c, 0x36,
    0xd6, 0x81, 0x42, 0xd8, 0x6a, 0x52, 0xe1, 0xcb,
    0x19, 0xb6, 0xc4, 0xe, 0xb, 0xff, 0xff, 0xe3,
    0x83, 0xff, 0xd7, 0x93, 0xff, 0xbb, 0xab, 0xff,
    0xff, 0x67, 0xff, 0xff, 0x33, 0xc, 0xff, 0xff,
    0xe4, 0x84, 0xff, 0xd8, 0x94, 0xff, 0xbc, 0xac,
    0xff, 0xff, 0x68, 0xff, 0xff, 0x34, 0x1, 0xd2,
    0xfe, 0xae, 0x54, 0xf7, 0xa2, 0x63, 0xf8, 0x87,
    0x79, 0xfc, 0xeb, 0x2e, 0xe0, 0xe6, 0x16,

    /* U+0033 "3" */
    0x0, 0xb4, 0xe2, 0x26, 0xc1, 0xfb, 0x92, 0x4d,
    0xec, 0x79, 0x5e, 0xed, 0x6b, 0x6b, 0xed, 0x5d,
    0x0, 0xc, 0xff, 0xff, 0x6c, 0xff, 0xff, 0xd8,
    0x94, 0xff, 0xbc, 0xac, 0xff, 0xac, 0xbc, 0xff,
    0x9c, 0x0, 0xc, 0xff, 0xff, 0x6b, 0xff, 0xff,
    0xd7, 0x94, 0xff, 0xbb, 0xac, 0xff, 0xab, 0xbc,
    0xff, 0x9b, 0x0, 0x1, 0xcd, 0xea, 0x2f, 0xd6,
    0xfa, 0x9d, 0x60, 0xf3, 0x83, 0x75, 0xf4, 0x74,
    0x84, 0xf4, 0x66, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1a, 0x71,
    0x1e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9c,
    0xff, 0xa5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xac, 0xff, 0xac, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xa5, 0xff, 0xa5, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x23, 0x70, 0x22, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x50, 0xed, 0x7e, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x94, 0xff, 0xbc, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x93, 0xff, 0xbb, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x53, 0xd8, 0x72, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x25,
    0x8a, 0x2e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xa2, 0xff, 0xa8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xac, 0xff, 0xac, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x9e, 0xff, 0x9e, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x10, 0x49, 0x10, 0x2, 0x25,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x93,
    0xff, 0x7e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbc, 0xff, 0x9c, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xbc, 0xff, 0x9c, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa4, 0xff, 0x84, 0x0, 0x0, 0x1c,
    0x4c, 0x15, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5, 0x49, 0x2e, 0x0, 0x4,
    0xe9, 0xff, 0xd1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x10, 0xf6, 0xfe, 0x23,
    0xc, 0xff, 0xff, 0xe4, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0xff, 0xff,
    0x34, 0x9, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x21, 0xff,
    0xff, 0x30, 0x0, 0x6f, 0x9a, 0x58, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0x7c, 0x82, 0x4, 0x0, 0x0, 0x0, 0x0, 0x36,
    0xd6, 0x81, 0x42, 0xd8, 0x6a, 0x52, 0xe1, 0xcb,
    0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x83, 0xff, 0xd7, 0x93, 0xff, 0xbb, 0xab, 0xff,
    0xff, 0x43, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x84, 0xff, 0xd8, 0x94, 0xff, 0xbc, 0xac,
    0xff, 0xff, 0x44, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x54, 0xf7, 0xa2, 0x63, 0xf8, 0x87,
    0x79, 0xfc, 0xeb, 0x21, 0x0, 0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x5e, 0xed, 0x6b, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xac, 0xff, 0xac, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xac, 0xff, 0xab, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x75, 0xf4, 0x74, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x14,
    0x70, 0x25, 0x1a, 0x71, 0x1e, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x85,
    0xff, 0xb5, 0x9c, 0xff, 0xa5, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x94,
    0xff, 0xbc, 0xac, 0xff, 0xac, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8d,
    0xff, 0xb5, 0xa5, 0xff, 0xa5, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1a,
    0x6f, 0x29, 0x23, 0x70, 0x22, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4, 0xc5, 0xfc, 0x97, 0x0,
    0x0, 0x0, 0x61, 0xee, 0x70, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1c, 0xff, 0xff, 0xd8, 0x0,
    0x0, 0x0, 0xac, 0xff, 0xac, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1b, 0xff, 0xff, 0xd7, 0x0,
    0x0, 0x0, 0xab, 0xff, 0xab, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6, 0xbd, 0xde, 0x89, 0x0,
    0x0, 0x0, 0x65, 0xd9, 0x65, 0x0, 0x0, 0x0,
    0x0, 0x57, 0x98, 0x4b, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x25, 0x8a, 0x2e, 0x0, 0x0, 0x0,
    0x8, 0xfa, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa2, 0xff, 0xa8, 0x0, 0x0, 0x0,
    0xc, 0xff, 0xff, 0xe4, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xac, 0xff, 0xac, 0x0, 0x0, 0x0,
    0x5, 0xf8, 0xff, 0xd6, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x9e, 0xff, 0x9e, 0x0, 0x0, 0x0,
    0x0, 0x37, 0x83, 0x27, 0x0, 0x23, 0x6, 0x0,
    0x24, 0x3, 0x11, 0x6e, 0x12, 0x2, 0x25, 0x0,
    0x3, 0xe1, 0xff, 0xc6, 0x5d, 0xff, 0xba, 0x6e,
    0xff, 0x9e, 0x83, 0xff, 0x8e, 0x93, 0xff, 0x7e,
    0xc, 0xff, 0xff, 0xe4, 0x84, 0xff, 0xd8, 0x94,
    0xff, 0xbc, 0xac, 0xff, 0xac, 0xbc, 0xff, 0x9c,
    0xc, 0xff, 0xff, 0xe4, 0x84, 0xff, 0xd8, 0x94,
    0xff, 0xbc, 0xac, 0xff, 0xac, 0xbc, 0xff, 0x9c,
    0x4, 0xf0, 0xff, 0xcc, 0x6c, 0xff, 0xc0, 0x7d,
    0xff, 0xa4, 0x94, 0xff, 0x94, 0xa4, 0xff, 0x84,
    0x0, 0x10, 0x2a, 0xa, 0x0, 0x23, 0x9, 0x1,
    0x24, 0x5, 0xb, 0x6a, 0x35, 0x5, 0x24, 0x2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8d, 0xff, 0xff, 0x31, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xac, 0xff, 0xff, 0x44, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa9, 0xff, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x38, 0x98, 0x87, 0x9, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x52, 0xe1, 0xcb, 0x16, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xab, 0xff, 0xff, 0x43, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xac, 0xff, 0xff, 0x44, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x79, 0xfc, 0xeb, 0x21, 0x0, 0x0,

    /* U+0035 "5" */
    0x0, 0xb4, 0xe2, 0x26, 0xc1, 0xfb, 0x92, 0x4d,
    0xec, 0x79, 0x5e, 0xed, 0x6b, 0x6b, 0xed, 0x5d,
    0x0, 0xc, 0xff, 0xff, 0x6c, 0xff, 0xff, 0xd8,
    0x94, 0xff, 0xbc, 0xac, 0xff, 0xac, 0xbc, 0xff,
    0x9c, 0x0, 0xc, 0xff, 0xff, 0x6b, 0xff, 0xff,
    0xd7, 0x94, 0xff, 0xbb, 0xac, 0xff, 0xab, 0xbc,
    0xff, 0x9b, 0x0, 0x1, 0xcd, 0xea, 0x2f, 0xd6,
    0xfa, 0x9d, 0x60, 0xf3, 0x83, 0x75, 0xf4, 0x74,
    0x84, 0xf4, 0x66, 0x0, 0x0, 0x43, 0x66, 0x3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xf5, 0xff,
    0x49, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0xff,
    0xff, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7,
    0xfd, 0xff, 0x49, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x4b, 0x66, 0x5, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xb8, 0xe5, 0x2a, 0xc5, 0xfc, 0x97,
    0x50, 0xed, 0x7e, 0x61, 0xee, 0x70, 0x0, 0x0,
    0x0, 0x0, 0xc, 0xff, 0xff, 0x6c, 0xff, 0xff,
    0xd8, 0x94, 0xff, 0xbc, 0xac, 0xff, 0xac, 0x0,
    0x0, 0x0, 0x0, 0xb, 0xff, 0xff, 0x6b, 0xff,
    0xff, 0xd7, 0x93, 0xff, 0xbb, 0xab, 0xff, 0xab,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xb4, 0xcf, 0x27,
    0xbd, 0xde, 0x89, 0x53, 0xd8, 0x72, 0x65, 0xd9,
    0x65, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2d, 0x8a, 0x26, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xb2, 0xff, 0x98, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xbc, 0xff, 0x9c, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xae, 0xff, 0x8e,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x17, 0x6e,
    0xd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x93,
    0xff, 0x7e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbc, 0xff, 0x9c, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xbc, 0xff, 0x9c, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa4, 0xff, 0x84, 0x0, 0x0, 0x1c,
    0x4c, 0x15, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5, 0x49, 0x2e, 0x0, 0x4,
    0xe9, 0xff, 0xd1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x10, 0xf6, 0xfe, 0x23,
    0xc, 0xff, 0xff, 0xe4, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0xff, 0xff,
    0x34, 0x9, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x21, 0xff,
    0xff, 0x30, 0x0, 0x6f, 0x9a, 0x58, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0x7c, 0x82, 0x4, 0x0, 0x0, 0x0, 0x0, 0x36,
    0xd6, 0x81, 0x42, 0xd8, 0x6a, 0x52, 0xe1, 0xcb,
    0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x83, 0xff, 0xd7, 0x93, 0xff, 0xbb, 0xab, 0xff,
    0xff, 0x43, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x84, 0xff, 0xd8, 0x94, 0xff, 0xbc, 0xac,
    0xff, 0xff, 0x44, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x54, 0xf7, 0xa2, 0x63, 0xf8, 0x87,
    0x79, 0xfc, 0xeb, 0x21, 0x0, 0x0, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4d,
    0xec, 0x79, 0x5e, 0xed, 0x6b, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x94, 0xff, 0xbc, 0xac, 0xff, 0xac, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x94, 0xff, 0xbb, 0xac, 0xff, 0xab, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x60, 0xf3, 0x83, 0x75, 0xf4, 0x74,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x4a, 0x7f, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x11, 0xfb, 0xff, 0xd1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1c, 0xff, 0xff, 0xd8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x15, 0xff, 0xff, 0xd1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x53, 0x76, 0x34, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xb8, 0xe5, 0x26, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xc, 0xff, 0xff, 0x50, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xb, 0xff, 0xff, 0x4f, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xb4, 0xcf, 0x21,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x57, 0x98,
    0x4b, 0x16, 0x87, 0x44, 0x1d, 0x89, 0x36, 0x25,
    0x8a, 0x2e, 0x0, 0x0, 0x0, 0x0, 0x8, 0xfa,
    0xff, 0xe0, 0x7a, 0xff, 0xd4, 0x8b, 0xff, 0xb8,
    0xa2, 0xff, 0xa8, 0x0, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xff, 0xe4, 0x84, 0xff, 0xd8, 0x94, 0xff,
    0xbc, 0xac, 0xff, 0xac, 0x0, 0x0, 0x0, 0x0,
    0x5, 0xf8, 0xff, 0xd6, 0x76, 0xff, 0xc9, 0x86,
    0xff, 0xae, 0x9e, 0xff, 0x9e, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x37, 0x83, 0x27, 0x7, 0x47, 0x1b,
    0xb, 0x48, 0x14, 0x10, 0x49, 0x10, 0x2, 0x25,
    0x0, 0x0, 0x3, 0xe1, 0xff, 0xc6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x93,
    0xff, 0x7e, 0x0, 0xc, 0xff, 0xff, 0xe4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbc, 0xff, 0x9c, 0x0, 0xc, 0xff, 0xff, 0xe4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xbc, 0xff, 0x9c, 0x0, 0x4, 0xf0, 0xff,
    0xcc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa4, 0xff, 0x84, 0x0, 0x0, 0x2d,
    0x77, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5, 0x49, 0x2e, 0x0, 0x4,
    0xe9, 0xff, 0xd1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x10, 0xf6, 0xfe, 0x23,
    0xc, 0xff, 0xff, 0xe4, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0xff, 0xff,
    0x34, 0x9, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x21, 0xff,
    0xff, 0x30, 0x0, 0x6f, 0x9a, 0x58, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0x7c, 0x82, 0x4, 0x0, 0x0, 0x0, 0x0, 0x36,
    0xd6, 0x81, 0x42, 0xd8, 0x6a, 0x52, 0xe1, 0xcb,
    0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x83, 0xff, 0xd7, 0x93, 0xff, 0xbb, 0xab, 0xff,
    0xff, 0x43, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x84, 0xff, 0xd8, 0x94, 0xff, 0xbc, 0xac,
    0xff, 0xff, 0x44, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x54, 0xf7, 0xa2, 0x63, 0xf8, 0x87,
    0x79, 0xfc, 0xeb, 0x21, 0x0, 0x0, 0x0,

    /* U+0037 "7" */
    0x0, 0xb4, 0xe2, 0x26, 0xc1, 0xfb, 0x92, 0x4d,
    0xec, 0x79, 0x5e, 0xed, 0x6b, 0x6b, 0xed, 0x5d,
    0xc, 0xff, 0xff, 0x6c, 0xff, 0xff, 0xd8, 0x94,
    0xff, 0xbc, 0xac, 0xff, 0xac, 0xbc, 0xff, 0x9c,
    0xc, 0xff, 0xff, 0x6b, 0xff, 0xff, 0xd7, 0x94,
    0xff, 0xbb, 0xac, 0xff, 0xab, 0xbc, 0xff, 0x9b,
    0x1, 0xcd, 0xea, 0x2f, 0xd6, 0xfa, 0x9d, 0x60,
    0xf3, 0x83, 0x75, 0xf4, 0x74, 0x84, 0xf4, 0x66,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x71, 0x18,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xac, 0xff, 0x95,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xbc, 0xff, 0x9c,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xb5, 0xff, 0x95,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x29, 0x70, 0x1c,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x61, 0xee, 0x70, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xac, 0xff, 0xac, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xab, 0xff, 0xab, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x65, 0xd9, 0x65, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1d,
    0x89, 0x36, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8b,
    0xff, 0xb8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x94,
    0xff, 0xbc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x86,
    0xff, 0xae, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x23, 0x6, 0xb,
    0x48, 0x14, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x5d, 0xff, 0xba, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x84, 0xff, 0xd8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x84, 0xff, 0xd8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6c, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0x5e, 0x1b, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x66, 0xff, 0xc5, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x84, 0xff, 0xd8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x81, 0xff, 0xd4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x24, 0x93, 0x50, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x36, 0xd6, 0x81, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x83, 0xff, 0xd7, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x84, 0xff, 0xd8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x54, 0xf7, 0xa2, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x0, 0x0, 0x2, 0xc1, 0xfb, 0x92, 0x4d,
    0xec, 0x79, 0x5e, 0xed, 0x6b, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1c, 0xff, 0xff, 0xd8,
    0x94, 0xff, 0xbc, 0xac, 0xff, 0xac, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1c, 0xff, 0xff,
    0xd7, 0x94, 0xff, 0xbb, 0xac, 0xff, 0xab, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xd6,
    0xfa, 0x9d, 0x60, 0xf3, 0x83, 0x75, 0xf4, 0x74,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x43, 0x66, 0x3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x20, 0x71, 0x18, 0x0, 0x6, 0xf5, 0xff,
    0x49, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xac, 0xff, 0x95, 0x0, 0xc, 0xff,
    0xff, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbc, 0xff, 0x9c, 0x0, 0x7,
    0xfd, 0xff, 0x49, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xb5, 0xff, 0x95, 0x0,
    0x0, 0x4b, 0x66, 0x5, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x29, 0x70, 0x1c,
    0x0, 0x1, 0xb8, 0xe5, 0x26, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xef,
    0x61, 0x0, 0xc, 0xff, 0xff, 0x50, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbc,
    0xff, 0x9c, 0x0, 0xb, 0xff, 0xff, 0x4f, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbb, 0xff, 0x9b, 0x0, 0x1, 0xb4, 0xcf, 0x21,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x73, 0xd8, 0x58, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x16, 0x87, 0x44, 0x1d, 0x89, 0x36, 0x25,
    0x8a, 0x2e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7a, 0xff, 0xd4, 0x8b, 0xff, 0xb8,
    0xa2, 0xff, 0xa8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x84, 0xff, 0xd8, 0x94, 0xff,
    0xbc, 0xac, 0xff, 0xac, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x76, 0xff, 0xc9, 0x86,
    0xff, 0xae, 0x9e, 0xff, 0x9e, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xd, 0x34, 0x8, 0x7, 0x47, 0x1b,
    0xb, 0x48, 0x14, 0x10, 0x49, 0x10, 0x2, 0x25,
    0x0, 0x0, 0x3, 0xe1, 0xff, 0xc6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x93,
    0xff, 0x7e, 0x0, 0xc, 0xff, 0xff, 0xe4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbc, 0xff, 0x9c, 0x0, 0xc, 0xff, 0xff, 0xe4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xbc, 0xff, 0x9c, 0x0, 0x4, 0xf0, 0xff,
    0xcc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa4, 0xff, 0x84, 0x0, 0x0, 0x2d,
    0x77, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5, 0x49, 0x2e, 0x0, 0x4,
    0xe9, 0xff, 0xd1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x10, 0xf6, 0xfe, 0x23,
    0xc, 0xff, 0xff, 0xe4, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0xff, 0xff,
    0x34, 0x9, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x21, 0xff,
    0xff, 0x30, 0x0, 0x6f, 0x9a, 0x58, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0x7c, 0x82, 0x4, 0x0, 0x0, 0x0, 0x0, 0x36,
    0xd6, 0x81, 0x42, 0xd8, 0x6a, 0x52, 0xe1, 0xcb,
    0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x83, 0xff, 0xd7, 0x93, 0xff, 0xbb, 0xab, 0xff,
    0xff, 0x43, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x84, 0xff, 0xd8, 0x94, 0xff, 0xbc, 0xac,
    0xff, 0xff, 0x44, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x54, 0xf7, 0xa2, 0x63, 0xf8, 0x87,
    0x79, 0xfc, 0xeb, 0x21, 0x0, 0x0, 0x0,

    /* U+0039 "9" */
    0x0, 0x0, 0x0, 0x2, 0xc1, 0xfb, 0x92, 0x4d,
    0xec, 0x79, 0x5e, 0xed, 0x6b, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1c, 0xff, 0xff, 0xd8, 0x94,
    0xff, 0xbc, 0xac, 0xff, 0xac, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1c, 0xff, 0xff, 0xd7, 0x94,
    0xff, 0xbb, 0xac, 0xff, 0xab, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x8, 0xd6, 0xfa, 0x9d, 0x60,
    0xf3, 0x83, 0x75, 0xf4, 0x74, 0x0, 0x0, 0x0,
    0x0, 0x43, 0x66, 0x3, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x71, 0x18,
    0x6, 0xf5, 0xff, 0x49, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xac, 0xff, 0x95,
    0xc, 0xff, 0xff, 0x50, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xbc, 0xff, 0x9c,
    0x7, 0xfd, 0xff, 0x49, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xb5, 0xff, 0x95,
    0x0, 0x4b, 0x66, 0x5, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x29, 0x70, 0x1c,
    0x1, 0xb8, 0xe5, 0x26, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xef, 0x61,
    0xc, 0xff, 0xff, 0x50, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xbc, 0xff, 0x9c,
    0xb, 0xff, 0xff, 0x4f, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xbb, 0xff, 0x9b,
    0x1, 0xb4, 0xcf, 0x21, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x73, 0xd8, 0x58,
    0x0, 0x0, 0x0, 0x0, 0x16, 0x87, 0x44, 0x1d,
    0x89, 0x36, 0x25, 0x8a, 0x2e, 0x2d, 0x8a, 0x26,
    0x0, 0x0, 0x0, 0x0, 0x7a, 0xff, 0xd4, 0x8b,
    0xff, 0xb8, 0xa2, 0xff, 0xa8, 0xb2, 0xff, 0x98,
    0x0, 0x0, 0x0, 0x0, 0x84, 0xff, 0xd8, 0x94,
    0xff, 0xbc, 0xac, 0xff, 0xac, 0xbc, 0xff, 0x9c,
    0x0, 0x0, 0x0, 0x0, 0x76, 0xff, 0xc9, 0x86,
    0xff, 0xae, 0x9e, 0xff, 0x9e, 0xae, 0xff, 0x8e,
    0x0, 0x0, 0x0, 0x0, 0x7, 0x47, 0x1b, 0xb,
    0x48, 0x14, 0x10, 0x49, 0x10, 0x17, 0x6e, 0xd,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x93, 0xff, 0x7e,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xbc, 0xff, 0x9c,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xbc, 0xff, 0x9c,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xa4, 0xff, 0x84,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8, 0x45, 0x31, 0x5, 0x24, 0x2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8d, 0xff, 0xff, 0x31, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xac, 0xff, 0xff, 0x44, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa9, 0xff, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x38, 0x98, 0x87, 0x9, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x36, 0xd6, 0x81, 0x42,
    0xd8, 0x6a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x83, 0xff, 0xd7, 0x93,
    0xff, 0xbb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x84, 0xff, 0xd8, 0x94,
    0xff, 0xbc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x54, 0xf7, 0xa2, 0x63,
    0xf8, 0x87, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 318, .box_w = 16, .box_h = 4, .ofs_x = -1, .ofs_y = 14},
    {.bitmap_index = 64, .adv_w = 318, .box_w = 17, .box_h = 31, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 591, .adv_w = 318, .box_w = 11, .box_h = 31, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 932, .adv_w = 318, .box_w = 17, .box_h = 31, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1459, .adv_w = 318, .box_w = 17, .box_h = 31, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1986, .adv_w = 318, .box_w = 16, .box_h = 31, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 2482, .adv_w = 318, .box_w = 17, .box_h = 31, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 3009, .adv_w = 318, .box_w = 17, .box_h = 31, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 3536, .adv_w = 318, .box_w = 16, .box_h = 31, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 4032, .adv_w = 318, .box_w = 17, .box_h = 31, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 4559, .adv_w = 318, .box_w = 16, .box_h = 31, .ofs_x = -1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 0, 0, 1, 2, 3, 4, 5,
    6, 7, 8, 9, 10
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 45, .range_length = 13, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 13, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 8,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Digitaled = {
#else
lv_font_t ui_font_Digitaled = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 31,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -6,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_DIGITALED*/
