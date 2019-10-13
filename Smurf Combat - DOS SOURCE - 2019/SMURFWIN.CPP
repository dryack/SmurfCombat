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
/* SYSOP Maintenance Code: !-S-Y-S-O-P-!                          WinGame  */
/* REMOTE Maintenance Code: !-SIX-NINE-|                           Module  */
/*                                                                         */
/***************************************************************************/

#include"smurfext.h";





void writeD0E(void){
  stream=fopen("SMURFDAT.D0E","w+");
  fprintf(stream,"%s",smurfname[thisuserno]);
  fclose(stream);
}

void wingame(void){
  struct date d;getdate(&d);
  od_clr_scr();
    od_control.user_screen_length=999;
    od_send_file("SMURFDAT.D0A");     pause();
    od_send_file("SMURFDAT.D0B");     sleep(5);
    od_send_file("SMURFDAT.D0C");     sleep(5);
    od_send_file("SMURFDAT.D0D");     pause();    writeD0E();
    sprintf(__saveversion,"w0%02dw",d.da_mon+1);savegame();
    od_send_file("SMURFDAT.D0Z");
    pause();
  od_exit(10,FALSE);
}

void wongame(void){char intext[4];
  struct date d;getdate(&d);
  stream = fopen("SMURF.SGM", "r+");
  fscanf(stream,"%3s",intext); //noplayers=atoi(intext);
  fscanf(stream,"%2s",intext); //save blanks
  fscanf(stream,"%2s",intext); //save month
  fclose(stream);
  if(d.da_mon>atoi(intext) || d.da_mon<atoi(intext)-1){od_clr_scr();od_printf("Rerolling game, please hold...");__NEW__main();__DAY__main();return;}
  od_set_colour(15,0);
  od_clr_scr();
    nl();
    nl();
    od_printf("The game has been won, but there will be other lands and\n\r");
    od_printf("and other worlds to be conquered...\n\n\r");
    od_printf("Until then?\n\r");
    od_printf("Ask any authorized member of management to reroll\n\r");
    od_set_colour(L_RED,D_BLACK);
    od_printf("Smurf Combat...\n\n\r");
    od_set_colour(L_GREEN,D_BLACK);
    od_send_file("SMURFDAT.D0E");
    od_printf("... ");
    od_set_colour(D_GREEN,D_BLACK);
    od_printf("some heros will never be forgotten...\n\n\n\r");
    pause();
    od_send_file("SMURFDAT.D0Z");
    pause();
    od_send_file("SMURFDAT.D0M");
    pause();
  od_exit(10,FALSE);
}






















