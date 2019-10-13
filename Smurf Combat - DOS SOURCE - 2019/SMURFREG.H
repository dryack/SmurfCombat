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

#include<opendoor.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
void bp(char *registration_string, unsigned int security_code);
unsigned long rcount=0;
extern char registeredxx;
extern char registered_name[201];
extern void notdone(void);
extern void mustregister(void);
extern void registerme(void);
extern int statis,cyc;
extern void nl(void);
extern void pause(void);
