/* Copyright (c) 2005-2007 John P. Costella.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software")
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included 
** in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
** OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING
** FROM, OUT OF, OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
**
**
** costella_image_rgb_triple.h: 
**
**   Set up pixel structure for RGB triples, such as for Windows 24-bit BMP 
**   files, in which components are stored in contiguous byte order 
**   BGRBGRBGR....
**
**   Written in ANSI C.
*/



/* Include file only once.
*/

#ifndef _COSTELLA_IMAGE_RGB_TRIPLE_H_
#define _COSTELLA_IMAGE_RGB_TRIPLE_H_



/* Typedefs.
*/

typedef COSTELLA_UB* COSTELLA_IMAGE_GRAY;
typedef COSTELLA_UB* COSTELLA_IMAGE_ALPHA;
typedef COSTELLA_UB* COSTELLA_IMAGE_COLOR;

typedef COSTELLA_UB* COSTELLA_IMAGE_GRAY_PIXEL;
typedef COSTELLA_UB* COSTELLA_IMAGE_ALPHA_PIXEL;

typedef struct 
{
  COSTELLA_UB* pubRY;  
  COSTELLA_UB* pubGCb;
  COSTELLA_UB* pubBCr;
}
COSTELLA_IMAGE_COLOR_PIXEL;



/* Macros.
*/

#define COSTELLA_IMAGE_GRAY_IS_SAME( lig1, lig2 ) \
  ( (lig1) == (lig2) )

#define COSTELLA_IMAGE_ALPHA_IS_SAME( lia1, lia2 ) \
  ( (lia1) == (lia2) )

#define COSTELLA_IMAGE_COLOR_IS_SAME( lic1, lic2 ) \
  ( (lic1) == (lic2) )


#define COSTELLA_IMAGE_GRAY_PIXEL_ASSIGN( ligpRight, ligpLeft ) \
  ( (ligpLeft) = (ligpRight) )

#define COSTELLA_IMAGE_ALPHA_PIXEL_ASSIGN( liapRight, liapLeft ) \
  ( (liapLeft) = (liapRight) )

#define COSTELLA_IMAGE_COLOR_PIXEL_ASSIGN( licpRight, licpLeft ) \
  ( (licpLeft).pubRY = (licpRight).pubRY, (licpLeft).pubGCb = \
    (licpRight).pubGCb, (licpLeft).pubBCr = (licpRight).pubBCr )


#define COSTELLA_IMAGE_GRAY_PIXEL_SET_TOP_LEFT( ligp, lig, udWidth, \
    udHeight, sdRowStride ) \
  ( (ligp) = (lig) )

#define COSTELLA_IMAGE_ALPHA_PIXEL_SET_TOP_LEFT( liap, lia, udWidth, \
    udHeight, sdRowStride ) \
  ( (liap) = (lia) )

#define COSTELLA_IMAGE_COLOR_PIXEL_SET_TOP_LEFT( licp, lic, udWidth, \
    udHeight, sdRowStride ) \
  ( (licp).pubRY = (lic) + 2, (licp).pubGCb = (lic) + 1, (licp).pubBCr = \
    (lic) )


#define COSTELLA_IMAGE_GRAY_PIXEL_MOVE_LEFT( ligp ) \
  ( (ligp)-- )

#define COSTELLA_IMAGE_ALPHA_PIXEL_MOVE_LEFT( liap ) \
  ( (liap)-- )

#define COSTELLA_IMAGE_COLOR_PIXEL_MOVE_LEFT( licp ) \
  ( (licp).pubRY -= 3, (licp).pubGCb -= 3, (licp).pubBCr -= 3 )


#define COSTELLA_IMAGE_GRAY_PIXEL_MOVE_RIGHT( ligp ) \
  ( (ligp)++ )

#define COSTELLA_IMAGE_ALPHA_PIXEL_MOVE_RIGHT( liap ) \
  ( (liap)++ )

#define COSTELLA_IMAGE_COLOR_PIXEL_MOVE_RIGHT( licp ) \
  ( (licp).pubRY += 3, (licp).pubGCb += 3, (licp).pubBCr += 3 )


#define COSTELLA_IMAGE_GRAY_PIXEL_MOVE_UP( ligp, lsdRowStride ) \
  ( (ligp) -= (lsdRowStride) )

#define COSTELLA_IMAGE_ALPHA_PIXEL_MOVE_UP( liap, lsdRowStride ) \
  ( (liap) -= (lsdRowStride) )

#define COSTELLA_IMAGE_COLOR_PIXEL_MOVE_UP( licp, lsdRowStride ) \
  ( (licp).pubRY -= (lsdRowStride), (licp).pubGCb -= (lsdRowStride), \
   (licp).pubBCr -= (lsdRowStride) )


#define COSTELLA_IMAGE_GRAY_PIXEL_MOVE_DOWN( ligp, lsdRowStride ) \
  ( (ligp) += (lsdRowStride) )

#define COSTELLA_IMAGE_ALPHA_PIXEL_MOVE_DOWN( liap, lsdRowStride ) \
  ( (liap) += (lsdRowStride) )

#define COSTELLA_IMAGE_COLOR_PIXEL_MOVE_DOWN( licp, lsdRowStride ) \
  ( (licp).pubRY += (lsdRowStride), (licp).pubGCb += (lsdRowStride), \
    (licp).pubBCr += (lsdRowStride) )


#define COSTELLA_IMAGE_COLOR_PIXEL_MOVE_LEFT_TWO( licp ) \
  ( (licp).pubRY -= 6, (licp).pubGCb -= 6, (licp).pubBCr -= 6 )

#define COSTELLA_IMAGE_COLOR_PIXEL_MOVE_RIGHT_TWO( licp ) \
  ( (licp).pubRY += 6, (licp).pubGCb += 6, (licp).pubBCr += 6 )

#define COSTELLA_IMAGE_COLOR_PIXEL_MOVE_UP_TWO( licp, lsdDoubleRowStride ) \
  ( (licp).pubRY -= (lsdDoubleRowStride), (licp).pubGCb -= \
    (lsdDoubleRowStride), (licp).pubBCr -= (lsdDoubleRowStride) )

#define COSTELLA_IMAGE_COLOR_PIXEL_MOVE_DOWN_TWO( licp, lsdDoubleRowStride \
    ) \
  ( (licp).pubRY += (lsdDoubleRowStride), (licp).pubGCb += \
    (lsdDoubleRowStride), (licp).pubBCr += (lsdDoubleRowStride) )


#define COSTELLA_IMAGE_GRAY_PIXEL_GET_Y( ligp ) \
  ( *(ligp) )

#define COSTELLA_IMAGE_ALPHA_PIXEL_GET_A( liap ) \
  ( *(liap) )

#define COSTELLA_IMAGE_COLOR_PIXEL_GET_R_Y( licp ) \
  ( *(licp).pubRY )

#define COSTELLA_IMAGE_COLOR_PIXEL_GET_G_CB( licp ) \
  ( *(licp).pubGCb )

#define COSTELLA_IMAGE_COLOR_PIXEL_GET_B_CR( licp ) \
  ( *(licp).pubBCr )


#define COSTELLA_IMAGE_GRAY_PIXEL_SET_Y( ligp, lubY ) \
  ( *(ligp) = (lubY) )

#define COSTELLA_IMAGE_ALPHA_PIXEL_SET_A( liap, lubA ) \
  ( *(liap) = (lubA) )

#define COSTELLA_IMAGE_COLOR_PIXEL_SET_R_Y( licp, lubRY ) \
  ( *(licp).pubRY = (lubRY) )

#define COSTELLA_IMAGE_COLOR_PIXEL_SET_G_CB( licp, lubGCb ) \
  ( *(licp).pubGCb = (lubGCb) )
  
#define COSTELLA_IMAGE_COLOR_PIXEL_SET_B_CR( licp, lubBCr ) \
  ( *(licp).pubBCr = (lubBCr) )

#define COSTELLA_IMAGE_COLOR_PIXEL_SET_RGB_YCBCR( licp, lubRY, lubGCb, \
    lubBCr ) \
  ( COSTELLA_IMAGE_COLOR_PIXEL_SET_R_Y( licp, lubRY ), \
  COSTELLA_IMAGE_COLOR_PIXEL_SET_G_CB( licp, lubGCb ), \
  COSTELLA_IMAGE_COLOR_PIXEL_SET_B_CR( licp, lubBCr ) )



/* File is now included.
*/

#endif



/* Copyright (c) 2005-2007 John P. Costella.
**
** End of file.
*/