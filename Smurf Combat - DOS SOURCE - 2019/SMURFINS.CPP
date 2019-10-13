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
/* SYSOP Maintenance Code: !-S-Y-S-O-P-!		        SERVICES   */
/* REMOTE Maintenance Code: !-SIX-NINE-|                          MODULE   */
/*                                                                         */
/***************************************************************************/

#include "smurfext.h"





void stealmoney(void){
  do{
  od_control.user_screen_length=24;
  od_clr_scr();
    od_printf("@\x0c       [ Instructions Menu ]\n\n\r");
    od_printf("@\x03   [1] Basics Of Smurf Combat\n\r");
    od_printf("@\x03   [2] How To Gain Levels and Fight\n\r");
    od_printf("@\x03   [3] Smurf Combat History\n\r");
    nl();
    od_printf("@\x0a   Which [1-3,Q]: ? ");
    od_set_colour(3,0);

  bbsinkey=od_get_key(TRUE);od_clr_scr();
  if(bbsinkey=='1')od_send_file("SMURFDAT.D09");
  else if(bbsinkey=='2')od_send_file("SMURFDAT.D0X");
  else if(bbsinkey=='3')__mess(13);
  else bbsinkey='Q';
  pause();
  }while(bbsinkey!='Q');
  od_control.user_screen_length=999;
}



void killsmurf(int numba){char oldname[40];unsigned long lvl;
if(random(2)==1)
  sprintf(oldname,"SPIRIT %-1.22s",smurfname[numba]);
else
  sprintf(oldname,"%-1.17s REINCARNATE",smurfname[numba]);
  strset(smurfname[numba],0);
  sprintf(smurfname[numba],oldname);
  realnumb[numba]=0;
  smurflevel[numba]=random(26)+5;lvl=smurflevel[numba];
  smurfmoney[numba]=lvl*20000;
  smurfhpm[numba]=lvl*13+100;
  smurfhp[numba]=smurfhpm[numba];
  smurfexper[numba]=defexper[lvl];
  smurfconfno[numba]=random(4)+1;
  strset(smurfweap[numba],0);
  strset(smurfarmr[numba],0);
  strset(smurfettename[numba],0);
  sprintf(smurfweap[numba],"Necromancy");smurfweapno[numba]=random(5)+14;
  sprintf(smurfarmr[numba],"Fire Sphere");smurfarmrno[numba]=random(5)+16;
  sprintf(smurfettename[numba],"Ghost");__ettemorale[numba]=random(200)+75;smurfettelevel[numba]=random(6)+3;
savegame();
}
