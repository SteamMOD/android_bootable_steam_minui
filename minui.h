/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _MINUI_H_
#define _MINUI_H_

typedef void* gr_surface;
typedef unsigned short gr_pixel;

#define GR_TEXT_ALIGN_TOP 1
#define GR_TEXT_ALIGN_CENTER 0
#define GR_TEXT_ALIGN_BOTTOM -1
#define GR_TEXT_ALIGN_LEFT 1
#define GR_TEXT_ALIGN_RIGHT -1

#define BYTES_PER_PIXEL 4

int gr_init(void);
void gr_exit(void);

int gr_fb_width(void);
int gr_fb_height(void);
gr_pixel *gr_fb_data(void);
void gr_flip(void);

void gr_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void gr_fill(int x, int y, int w, int h);
int gr_text_align(int x, int y, int ax, int ay, int baseline, const char *s);
int gr_text(int x, int y, const char *s);
int gr_measure(const char *s);
void gr_line(int x, int y, int x2, int y2, int w);
void gr_point(int x, int y, int w);
void gr_crop(int x, int y, int x2, int y2);

void gr_blit(gr_surface source, int sx, int sy, int w, int h, int dx, int dy);
unsigned int gr_get_width(gr_surface surface);
unsigned int gr_get_height(gr_surface surface);

void gr_blend(int enable);
gr_surface gr_create_surface(void);
void gr_free_surface(gr_surface surface);
void gr_save_active_surface(gr_surface surface);
// input event structure, include <linux/input.h> for the definition.
// see http://www.mjmwired.net/kernel/Documentation/input/ for info.
struct input_event;

int ev_init(void);
void ev_exit(void);
int ev_get(struct input_event *ev, int wait_amount);

// Resources

// Returns 0 if no error, else negative.
int res_create_surface(const char* name, gr_surface* pSurface);
void res_free_surface(gr_surface surface);

#endif
