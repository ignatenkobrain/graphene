/* graphene-rect.h: Rectangular type
 *
 * Copyright © 2014  Emmanuele Bassi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __GRAPHENE_RECT_H__
#define __GRAPHENE_RECT_H__

#if !defined(GRAPHENE_H_INSIDE) && !defined(GRAPHENE_COMPILATION)
#error "Only graphene.h can be included directly."
#endif

#include "graphene-types.h"
#include "graphene-point.h"

G_BEGIN_DECLS

#define GRAPHENE_RECT_INIT(x,y,w,h) \
  { { x, y }, { w, h } }

struct _graphene_rect_t
{
  graphene_point_t origin;
  graphene_size_t size;
};

GRAPHENE_AVAILABLE_IN_1_0
graphene_rect_t *       graphene_rect_alloc             (void);
GRAPHENE_AVAILABLE_IN_1_0
void                    graphene_rect_free              (graphene_rect_t       *r);
GRAPHENE_AVAILABLE_IN_1_0
graphene_rect_t *       graphene_rect_init              (graphene_rect_t       *r,
                                                         float                  x,
                                                         float                  y,
                                                         float                  width,
                                                         float                  height);
GRAPHENE_AVAILABLE_IN_1_0
graphene_rect_t *       graphene_rect_init_from_rect    (graphene_rect_t       *r,
                                                         const graphene_rect_t *src);

GRAPHENE_AVAILABLE_IN_1_0
gboolean                graphene_rect_equal             (const graphene_rect_t *a,
                                                         const graphene_rect_t *b);
GRAPHENE_AVAILABLE_IN_1_0
graphene_rect_t *       graphene_rect_normalize         (graphene_rect_t       *r);
GRAPHENE_AVAILABLE_IN_1_0
void                    graphene_rect_get_center        (const graphene_rect_t *r,
                                                         graphene_point_t      *p);
GRAPHENE_AVAILABLE_IN_1_0
void                    graphene_rect_get_top_left      (const graphene_rect_t *r,
                                                         graphene_point_t      *p);
GRAPHENE_AVAILABLE_IN_1_0
void                    graphene_rect_get_top_right     (const graphene_rect_t *r,
                                                         graphene_point_t      *p);
GRAPHENE_AVAILABLE_IN_1_0
void                    graphene_rect_get_bottom_right  (const graphene_rect_t *r,
                                                         graphene_point_t      *p);
GRAPHENE_AVAILABLE_IN_1_0
void                    graphene_rect_get_bottom_left   (const graphene_rect_t *r,
                                                         graphene_point_t      *p);
GRAPHENE_AVAILABLE_IN_1_0
float                   graphene_rect_get_x             (const graphene_rect_t *r);
GRAPHENE_AVAILABLE_IN_1_0
float                   graphene_rect_get_y             (const graphene_rect_t *r);
GRAPHENE_AVAILABLE_IN_1_0
float                   graphene_rect_get_width         (const graphene_rect_t *r);
GRAPHENE_AVAILABLE_IN_1_0
float                   graphene_rect_get_height        (const graphene_rect_t *r);

GRAPHENE_AVAILABLE_IN_1_0
void                    graphene_rect_union             (const graphene_rect_t *a,
                                                         const graphene_rect_t *b,
                                                         graphene_rect_t       *res);
GRAPHENE_AVAILABLE_IN_1_0
gboolean                graphene_rect_intersection      (const graphene_rect_t *a,
                                                         const graphene_rect_t *b,
                                                         graphene_rect_t       *res);
GRAPHENE_AVAILABLE_IN_1_0
gboolean                graphene_rect_contains_point    (const graphene_rect_t  *r,
                                                         const graphene_point_t *p);
GRAPHENE_AVAILABLE_IN_1_0
gboolean                graphene_rect_contains_rect     (const graphene_rect_t  *a,
                                                         const graphene_rect_t  *b);
GRAPHENE_AVAILABLE_IN_1_0
void                    graphene_rect_offset            (graphene_rect_t        *r,
                                                         float                   d_x,
                                                         float                   d_y);
GRAPHENE_AVAILABLE_IN_1_0
void                    graphene_rect_inset             (graphene_rect_t        *r,
                                                         float                   d_x,
                                                         float                   d_y);
GRAPHENE_AVAILABLE_IN_1_0
void                    graphene_rect_round_to_pixel    (graphene_rect_t        *r);
GRAPHENE_AVAILABLE_IN_1_0
void                    graphene_rect_interpolate       (const graphene_rect_t  *a,
                                                         const graphene_rect_t  *b,
                                                         double                  factor,
                                                         graphene_rect_t        *res);

G_END_DECLS

#endif /* __GRAPHENE_RECT_H__ */