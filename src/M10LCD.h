/*
###############################################################################
# Copyright (c) 2018, PulseRain Technology LLC
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License (LGPL) as
# published by the Free Software Foundation, either version 3 of the License,
# or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
###############################################################################
*/

#ifndef M10LCD_H
#define M10LCD_H

#include "Arduino.h"

#define LCD_CSR_CMD  0
#define LCD_CSR_DAT  1
#define LCD_CSR_RST  2

typedef struct {
    void (*reset) () __reentrant;
    void (*writeCMD)(uint8_t) __reentrant;
    void (*writeDAT) (uint8_t) __reentrant;
} LCD_STRUCT;


extern const LCD_STRUCT LCD;

#endif
