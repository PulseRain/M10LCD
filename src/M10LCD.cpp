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

#include "M10LCD.h"


//----------------------------------------------------------------------------
// lcd_write_cmd()
//
// Parameters:
//      data : byte to be sent out, for ST7735 controller
//
// Return Value:
//      None
//
// Remarks:
//      call this function to send command for ST7735 controller,
//      (4 Serial Line interface)
//----------------------------------------------------------------------------

static void lcd_write_cmd (uint8_t data) __reentrant
{
    LCD_CSR = LCD_CSR_CMD;
    LCD_DATA = data;
    nop_delay (5);
    while(LCD_CSR == 0);
} // End of lcd_write_cmd()

//----------------------------------------------------------------------------
// lcd_write_dat()
//
// Parameters:
//      data : byte to be sent out, for ST7735 controller
//
// Return Value:
//      None
//
// Remarks:
//      call this function to send data for ST7735 controller,
//      (4 Serial Line interface)
//----------------------------------------------------------------------------

static void lcd_write_dat (uint8_t data) __reentrant
{
    LCD_CSR = LCD_CSR_DAT;
    LCD_DATA = data;
    nop_delay (5);
    while(LCD_CSR == 0);
} // End of lcd_write_dat()

//----------------------------------------------------------------------------
// lcd_reset()
//
// Parameters:
//      None
//
// Return Value:
//      None
//
// Remarks:
//      call this function to hard reset ST7735
//----------------------------------------------------------------------------

static void lcd_reset () __reentrant
{
    LCD_CSR = LCD_CSR_RST;
    delay(50);
    LCD_CSR = 0;
    delay(50);
} // End of lcd_reset()

const LCD_STRUCT LCD = {
    .reset = lcd_reset,
    .writeCMD = lcd_write_cmd,
    .writeDAT = lcd_write_dat
};

