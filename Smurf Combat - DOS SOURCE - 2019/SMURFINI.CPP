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
/* SYSOP Maintenance Code: !-S-Y-S-O-P-!                          IniPlay  */
/* REMOTE Maintenance Code: !-SIX-NINE-|                           Module  */
/*                                                                         */
/***************************************************************************/

#include"smurfext.h"





void newplayer(int x){
char inputline[1][80];char logname[13];
if(x==1){  if(noplayers>97)toomany();
	   thisuserno=noplayers++;inuser=thisuserno;
   od_control.user_screen_length=23;
    od_clr_scr();sprintf(logname,"SMURF.%03i",thisuserno);stream = fopen(logname, "w+");fclose(stream);
     od_clear_keybuffer();
     od_set_colour(D_CYAN,D_BLACK);
     od_send_file("SMURFDAT.D01");
    nl();pause();                                               }
    od_clr_scr();
     od_set_colour(D_CYAN,D_BLACK);
     od_send_file("SMURFDAT.D02");
    nl();pause();
getname:;strset(smurfname[thisuserno],0);
     od_set_attrib(SD_RED);
     od_printf("Enter in your smurf name (i.e. WARRIOR SMURF) of 28 character or less.\n\r");
     od_set_colour(L_YELLOW,D_BLACK);od_printf(": ");
     od_set_attrib(SD_GREEN);
     od_input_str(inputline[0],25,32,167);
     sprintf(smurfname[thisuserno],"%s",strupr(inputline[0]));
for(cyc=0;cyc+1<noplayers;cyc++){od_set_attrib(SD_GREEN);if(strcmp(smurfname[cyc],smurfname[thisuserno])==0){od_set_colour(L_CYAN,D_BLACK);od_printf("Same name found in rebel roster!!!\n\n\n\r");goto getname;}}
    od_set_attrib(SD_CYAN);
if(strlen(inputline[0])<2){od_printf("Aborted . . . (Minimum 2 character input)\n\r");pause();od_exit(10,FALSE);}
    od_printf("Is this cool? ");
  do{
    bbsinkey=od_get_key(TRUE);
    od_set_colour(D_CYAN,D_BLACK);
    if(bbsinkey=='N' || bbsinkey=='n'){od_printf("Nope");nl();nl();nl();goto getname;}
    } while(bbsinkey!='Y' && bbsinkey!='y');
od_printf("Yea");
gettext:;strset(smurftext[thisuserno],0);
     od_set_attrib(SD_RED);
     od_printf("\n\n\n\rWhen someone wins you in a fight, what do you want to say? (i.e. I'LL BE BACK!)\n\r");
     od_set_colour(L_YELLOW,D_BLACK);od_printf(": ");
     od_set_attrib(SD_GREEN);
     od_input_str(inputline[0],70,32,167);
     sprintf(smurftext[thisuserno],"%s",inputline[0]);
    od_set_attrib(SD_CYAN);
    od_printf("Is this cool? ");
  do{
    bbsinkey=od_get_key(TRUE);
    od_set_colour(D_CYAN,D_BLACK);
    if(bbsinkey=='N' || bbsinkey=='n'){od_printf("Nope");nl();nl();nl();goto gettext;}
    } while(bbsinkey!='Y' && bbsinkey!='y');
od_printf("Yea");
     sprintf(realname[thisuserno],"%s",od_control.user_name);
     realnumb[thisuserno]=od_control.user_num;
     sprintf(smurfweap[thisuserno],"%s",defweapon[0]);
     sprintf(smurfarmr[thisuserno],"%s",defarmor[0]);
     sprintf(smurfettename[thisuserno],"None");
     smurfettelevel[thisuserno]=0;
     smurfweapno[thisuserno]=0;smurfarmrno[thisuserno]=0;
     sprintf(smurfconf[thisuserno],"%s",defconfine[0]);
     smurfconfno[thisuserno]=0;
     smurfhost[thisuserno][0]=255;
     smurfhost[thisuserno][1]=255;
     smurfhost[thisuserno][2]=255;
     smurfhost[thisuserno][3]=255;
     smurfhost[thisuserno][4]=255;
     smurfhost[thisuserno][5]=255;
     smurfhost[thisuserno][6]=255;
     smurfhost[thisuserno][7]=255;
     smurfhost[thisuserno][8]=255;
     smurfhost[thisuserno][9]=255;
     smurflevel[thisuserno]=1;
     smurfexper[thisuserno]=0;
     smurfmoney[thisuserno]=random(2000)+500; smurfbankd[thisuserno]=0;
     smurffights[thisuserno]=3;
     smurfwin[thisuserno]  =0;   smurflose[thisuserno] =0;
     smurfhp[thisuserno]   =16;  smurfhpm[thisuserno]  =16;
     smurfstr[thisuserno]  =12;  smurfspd[thisuserno]  =12;
     smurfint[thisuserno]  =12;  smurfcon[thisuserno]  =12;
     smurfbra[thisuserno]  =12;  smurfchr[thisuserno]  =12;
     smurfturns[thisuserno]=defturns;
     __morale[thisuserno]=3;__ettemorale[thisuserno]=0;
//  stream = fopen("SMURF.LOG", "a+");
//  fprintf(stream, "\n\n\rNew Player : #%5i ",od_control.user_num);fprintf(stream, "%s ... ",realname[thisuserno]);fprintf(stream, "%s\n\r",smurfname[thisuserno]);
//  fclose(stream);
   od_control.user_screen_length=999;
	  asksex();
	  savegame();
 for(cyc=0;cyc<hcount;cyc++){
  if((holder[cyc]==thisuserno) || (hostage[cyc]==thisuserno)){
    hostage[cyc]=255;holder[cyc]=255;
  }
 }

 writehostage();
 stealmoney();

    od_send_file("SMURFNEW.NFO");
    pause();
    od_send_file("SMURFDAT.D0Z");
    pause();
    od_send_file("SMURFDAT.D0M");
    pause();

if(x==2){od_clr_scr();
	 od_send_file("SMURFDAT.D05");
	 sleep(3);
	 od_exit(10,FALSE);
	 }
}

void writeSGL(void){/*
  stream = fopen("SMURFLOG.NFO", "a+");
     fprintf(stream, "%i6",od_control.user_num);
     fprintf(stream, "%i9",od_control.user_security);
     fprintf(stream, "%03i",od_control.user_sex);
     for(cyc=0;cyc<40;cyc++)fprintf(stream, "%03i",od_control.user_name[cyc]);
     for(cyc=0;cyc<40;cyc++)fprintf(stream, "%03i",od_control.user_handle[cyc]);
     for(cyc=0;cyc<20;cyc++)fprintf(stream, "%03i",od_control.user_homephone[cyc]);
     for(cyc=0;cyc<20;cyc++)fprintf(stream, "%03i",od_control.user_dataphone[cyc]);
     fprintf(stream,"135");
     for(cyc=0;cyc<16;cyc++)fprintf(stream, "%03i",od_control.user_password[cyc]);
     fprintf(stream,"135");
     for(cyc=0;cyc<16;cyc++)fprintf(stream, "%03i",od_control.user_logonpassword[cyc]);
     fprintf(stream,"135");
  fclose(stream);
*/}





