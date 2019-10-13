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
/* SYSOP Maintenance Code: !-S-Y-S-O-P-!                         REGISTA   */
/* REMOTE Maintenance Code: !-SIX-NINE-|                         MODULE    */
/*                                                                         */
/***************************************************************************/
/* SMURF.nnn (Personal) SMURF.Dnn (Documentation)                          */
/* !  Standard Operation Codes                                             */
/* !# Extended Testing Codes, Value Increment                              */
/* !@ Extended Testing Codes, Smurf Increment                              */
/* // Specialized To-Local Codes                                           */
/***************************************************************************/

#include<stream.h>
#include<alloc.h>
#include<conio.h>
#include<stdlib.h>
#include"smurfreg.h"

void __REG__main(void){
  char code[40],name[80],cod;
  FILE *stream;
    printf("\n\r");
    printf("Enter Registration Code: ");gets(code);
    printf("Enter Registration Name: ");gets(name);
/*
    printf("Enter Intermediate Code: ");
cin >> name[0];cod=atoi(name[0]);
if(cod>0)for(cyc=0;cyc<cod;cyc++){
    printf("Name %d: ",cyc);scanf("%39s", name[cyc]);}
    fprintf(stream,"%s",name[0]);
if(cod>1)for(cyc=1;cyc<cod;cyc++)    fprintf(stream," %s",name[cyc]);
*/
  stream=fopen("SMURFREG.NFO","w+");
    fprintf(stream,"%s",name);
    fprintf(stream,"\n\r%s\n\r",code);
  fclose(stream);
}

void notdone(void){
mustregister();if(statis){od_set_colour(L_BLUE,D_BLACK);od_printf("\n\rSorry, but this function is not complete as of.\n\n\r");}
}

void mustregister(void){if(!statis){
  /*
  od_clr_scr();
  od_printf("Sorry to interrupt your fun like this but your Sysop didn't\n\r");
  od_printf("register this version of SMURF COMBAT yet!               \n\n\r");
  od_printf("In order for this function to be orperative, your Sysop has\n\r");
  od_printf("to pay the one time, VERY low registration cost of $9!!! \n\n\r");
  od_printf("Consider the advantages,  plain out no more waits,  and ALL\n\r");
  od_printf("the functions work 100 percent!\n\n\r");
  */
  //sleep(5);
  //pause();
}}

void registerme(void){
if(0){ // if(!statis){
	od_clr_scr();
	nl();
	nl();
  od_set_colour(15,0);
  od_printf("Sorry to interrupt your fun like this but your Sysop didn't\n\r");
  od_printf("register this version of SMURF COMBAT yet! OHMYGOD! So, I'd\n\r");
  od_printf("like to take .21 minutes to remind you that it took 10,000+\n\r");
  od_printf("minutes of day-in-day-out work to complete this game.\n\n\r");
  od_set_colour(11,0);
/*
  cyc=0;
    do{
	cyc++;od_printf("                 *** $9 ***\r");delay(200);
	cyc++;od_printf("                ONLY $9!   \r");delay(200);
	cyc++;od_printf("registration is only $9!   \r");delay(200);
    }while(cyc<3);
//  sleep(1);
*/
  od_set_colour(10,0);
  od_printf("\n\n\rThanks for your time, I hope you appreciate mine.\n\n\r");
//  sleep(2);
  }
}

void checkkey(void)                                              /* Main program function */
   {
   FILE *fp;                           /* File pointer for REGISTER.KEY file */
   unsigned long supplied_key;                       /* Key supplied by user */
   unsigned long correct_key;                    /* Correct registration key */

   if((fp=fopen("SMURFREG.NFO","r"))!=NULL)              /* Try to open file */
      {                                                     /* If successful */
      fgets(registered_name,200,fp);                  /* read name from file */
      if(registered_name[strlen(registered_name)-1]=='\n')
	 registered_name[strlen(registered_name)-1]='\0';

      fscanf(fp,"%lu",&supplied_key);                  /* read key from file */

      fclose(fp);                                              /* Close file */

      bp(registered_name,909);        /* Calculate correct key */
      correct_key=rcount;

      if(correct_key==supplied_key)       /* Compare correct & supplied keys */
	 {                                          /* If they are identical */
	 registeredxx=1;           /* Then switch program into registered mode */
	 }
      }

   sprintf(registered_name, "Freeware via Laurence Maar GPLv2");

   if(registeredxx==1)statis=1;                                   /* If registered mode */
//      {                                  /* Display registration information */
//      printf("This program is registered to: %s\n",registered_name);
//      }
//   else if(registeredxx==0)                       /* If not in registered mode */
//      {                                  /* Display unregistered information */
//      printf("This program is UNREGISTERED!!!\n");
//      }pause();

   registeredxx=1;
   statis=1;
}






void bp(char *registration_string, unsigned int security_code){
char tempstring[201];int cyc;
    strset(tempstring,0);
      sprintf(tempstring,"%s",registration_string);
      for(cyc=0;cyc<strlen(tempstring);cyc++){
      rcount=rcount+tempstring[cyc]*security_code;
      }
}
