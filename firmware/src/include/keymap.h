/* Copyright 2020 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>
#include "revised.h"
#include "keycodes.h"

#define NK 0x0000
#define R(n)  ((uint16_t)((KC_ ## n) << 8) | 0x01)  
#define M(n)  ((uint16_t)((n) << 8) | 0x02)
#define F(n)  ((uint16_t)((n) << 8) | 0x04)
#define FS(n) ((uint16_t)((n) << 8) | 0x06)
#define FR(n) ((uint16_t)((n) << 8) | 0x07)
#define FK(n) ((uint16_t)((n) << 8) | 0x0A)

#define REG_FN(reg, fn) (reg | ((uint16_t)fn) << 8)

#define LCTL 0x01
#define LSFT 0x02
#define LALT 0x04
#define LGUI 0x08
#define RCTL 0x10
#define RSFT 0x20
#define RALT 0x40
#define RGUI 0x80

#define KEYMAP_ANSI( \
    esc, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12,          \
    grv,  n1, n2, n3, n4, n5, n6, n7, n8, n9, n0, min, eql, bkp,     \
    tab,   q,  w,  e,  r,  t,  y,  u,  i,  o,  p,  lbr, rbr, bsl,    \
    cap,    a,  s,  d,  f,  g,  h,  j,  k,  l,  sem, quo, ent,       \
    lsf,     z,  x,  c,  v,  b,  n,  m, com, dot, sls, rsf, up,      \
    lct, fn, pi, lal,         spc,           ral, rct, lef, dn, rht) \
    { \
        /*       R0   R1   R2   R3   R4   R5   R6   R7 */ \
        /*C0*/  NK,  NK,  NK,  rct, NK,  lct, NK,  NK,  \
        /*C1*/  q,   n1,  z,   a,   grv, tab, esc, cap,  \
        /*C2*/  e,   n3,  c,   d,   f2,  f3,  f4,  f1,   \
        /*C3*/  NK,  NK,  NK,  NK,  NK,  NK,  pi,  NK,   \
        /*C4*/  r,   n4,  v,   f,   n5,  t,   g,   b,    \
        /*C5*/  w,   n2,  x,   s,   f5,  f6,  f7,  f8,   \
        /*C6*/  i,   n8,  com, k,   NK,  rbr, NK,  NK,   \
        /*C7*/  NK,  NK,  NK,  NK,  fn,  NK,  NK,  NK,   \
        /*C8*/  u,   n7,  m,   j,   n6,  y,   h,   n,    \
        /*C9*/  rsf, NK,  lsf, NK,  NK,  NK,  NK,  NK,   \
        /*C10*/ p,   n0,  sls, sem, min, lbr, quo, eql,  \
        /*C11*/ o,   n9,  dot, l,   f9,  f10, f11, f12,  \
        /*C12*/ NK,  NK,  NK,  NK,  NK,  NK,  NK,  NK,   \
        /*C13*/ NK,  lal, NK,  NK,  NK,  NK,  NK,  ral,  \
        /*C14*/ up,  dn,  spc, ent, bsl, NK,  bkp, NK,   \
        /*C15*/ lef, rht, NK,  NK,  NK,  NK,  NK,  NK,   \
        /*C16*/ NK,  NK,  NK,  NK,  NK,  NK,  NK,  NK,   \
        /*C17*/ NK,  NK,  NK,  NK,  NK,  NK,  NK,  NK    \
    }

#define KEYMAP_ISO( \
    esc, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12,          \
    grv,  n1, n2, n3, n4, n5, n6, n7, n8, n9, n0, min, eql, bkp,     \
    tab,    q,  w,  e,  r,  t,  y,  u,  i,  o,  p,  lbr, rbr, ent,   \
    cap,     a,  s,  d,  f,  g,  h,  j,  k,  l,  sem, quo, bsl,      \
    lsf, nub, z,  x,  c,  v,  b,  n,  m, com, dot, sls, rsf, up,     \
    lct, fn, pi, lal,         spc,           ral, rct, lef, dn, rht) \
    { \
        NK,  fn,  pi,  NK,  NK,  lct, NK,  NK, \
        NK,  NK,  NK,  lsf, cap, tab, NK,  NK, \
        NK,  NK,  NK,  NK,  NK,  NK,  NK,  NK, \
        NK,  nub, a,   q,   NK,  grv, esc, NK, \
        lal, z,   s,   w,   n1,  NK,  f1,  NK, \
        NK,  x,   d,   e,   n2,  NK,  f2,  NK, \
        NK,  c,   f,   r,   n3,  NK,  f3,  NK, \
        NK,  v,   g,   t,   n4,  NK,  f4,  NK, \
        NK,  b,   h,   y,   n5,  NK,  f5,  NK, \
        NK,  n,   j,   u,   n6,  f7,  f6,  NK, \
        NK,  m,   k,   i,   n8,  n7,  f8,  NK, \
        NK,  com, l,   o,   n9,  f10, f9,  NK, \
        NK,  dot, sem, p,   min, n0,  f11, NK, \
        NK,  sls, quo, lbr, eql, NK,  f12, NK, \
        spc, rsf, bsl, rbr, bkp, ent, NK,  NK, \
        ral, rct, lef, up,  dn,  rht, NK,  NK, \
        NK,  NK,  NK,  NK,  NK,  NK,  NK,  NK, \
        NK,  NK,  NK,  NK,  NK,  NK,  NK,  NK  \
    }