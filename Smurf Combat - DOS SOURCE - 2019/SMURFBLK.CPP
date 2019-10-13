/*
Smurf Combat
Copyright (C) 1993, 1994, 2019 Laurence Maar
laurencemaar@gmail.com
https://www.facebook.com/laurencemaar/
https://www.linkedin.com/in/laurencemaar/
*/

/*
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/***************************************************************************/
/*                                                                         */
/*   sss                       fff     ccc                 b               */
/*  s   s                     f   f   c   c                b               */
/*  s                         f       c                    b               */
/*   sss  mmm mmm  u   u r rr  fff    c      ooo  mmm mmm   bbb  aaa  ttt  */
/*      s m  m   m u   u rr   f       c     o   o m  m   m b   b a  a  t   */
/*  s   s m  m   m u  uu r    f       c   c o   o m  m   m b   b aaaa  t   */
/*   sss  m  m   m  uu u r    f        ccc   ooo  m  m   m  bbb  a  a  t   */
/*                                                                         */
/* SYSOP Maintenance Code: !-S-Y-S-O-P-!                         BLOCKADE  */
/* REMOTE Maintenance Code: !-SIX-NINE-|                         BLOCKADE  */
/*                                                                         */
/***************************************************************************/

extern char * get_blk_err_msg(int num);





char * get_blk_err_msg(int num)
{
  char *sp;
  static char *blk_err_msgs[] = {
    "No error",                          /*  0  */
    "No memory for buffer",              /*  1  */
    "Error opening file",                /*  2  */
    "No memory for file buffering",
    "File buffering failure",            /*  4  */
    "Fseek error",
    "Error reading data block",          /*  6  */
    "Invalid data block info",
    "Error reading file",                /*  8  */
    "Error reading file",                /*  9  */
    "Error reading file",                /* 10  */
    "Check Value error",                 /* 11  */
    "File size error",                   /* 12  */
    "Invalid error number" };            /* 13  */

   if (num == -1) num = 11;
   if (num == -2) num = 12;
   if ((num < 0) || (num > 12))  num = 13;    /* out of range */
   sp = blk_err_msgs[num];
   return(sp);
  }
