Smurf Combat
Copyright (C) 1993, 1994, 1995, 2019 Laurence Maar
laurencemaar@gmail.com
https://www.facebook.com/laurencemaar/
https://www.linkedin.com/in/laurencemaar/
https://github.com/laurencemaar/
https://sourceforge.net/u/laurencemaar/

-----

*Nix port done by Stephen Hurd (aka Deuce) in 2005
Deuce@nix.synchro.net
http://doors.bbsdev.net/
https://sourceforge.net/u/deuce/
http://wiki.synchro.net/person:deuce

-----

As of October 11, 2019:

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

-----

Notes from October 11, 2019:

This program was originally compiled using Borland Turbo C++ 2.0.

In order to re-compile this program, you will need to:
1) Interpret the "Project File" to determine which files need to be included in your project.
2) Make sure you include the OpenDoors library.
   It may require some work in order to figure out how to make this work on a modern compiler.
3) Some functions such as those provided in conio.h may not exist in all modern compilers.

-----

The information below is from the last release back in 1994

 ----------------------------------------------------------------------------

 SYNCHRONET UPDATE: If you have been using CHAIN.TXT, change your Drop File
 to DOOR.SYS.  This error which originates in SYCNHRONET causes the program
 to think you're calling in remotely,  and thus drops the sysop when he/she
 tries to logon.

 ----------------------------------------------------------------------------

 NOTICE! Smurf Combat requires a fossil driver to operate, as noted by the
 correct bath file example shown below. Included in this version or
 upgrade of Smurf Combat is the fossil driver BNUxxxxxx.ZIP This must
 either be installed as a device driver or run in the batch file as
 shown below or else your system may crash or simply not work.

 ----------------------------------------------------------------------------

 >> Synchronet SHOULD NOT use the following BATCH file example

 SAMPLE.BAT      <--- Sample batch file to run Smurf Combat via WWiV
 cd\bbs\smurf         [Goto Smurf Combat Dir]
 copy \bbs\chain.txt  [Copy User Information File]

 bnu                  [Fossil Driver Required]
	 ***OR***     [Fossil Driver Required]
 x00                  [Fossil Driver Required]

 smurf                [Execute Program]
 cd\bbs               [Return to System]
 ^Z                   [Control + Z, Release, Enter]

 >> This batch file is created in the 'BBS Main Directory' specified by
    running 'C:\> SMURF SETUP' and is saved as SMURF.BAT

 ----------------------------------------------------------------------------

>> Synchronet Setup

Name			Smurf Combat 1.5
Startup Dir		C:\BBS\SMURF          (your choice - Dir w/ SMURF.EXE)
Command Line (Normal)   SMURF                 (Run Executive ONLY)

  NOTE: Insure that you have a fossil drive already installed, or to
	install one, simply edit you autoexec.bat to run 'BNU'. A copy
	of 'BNU' is included and should be in this TAZ directory.
  SYNCHRONET: Synchronet functions best with X00.SYS installed as a
	device in your CONFIG.SYS with LOCKED BAUD RATES.

Clean-Up                [None]
ANSI Req		No
Multiuser		No
I/O			No
Shrink			Yes
Modify			No
WWiV Color Codes	No
BBS Drop File		GAP -  DOOR.SYS		(Synchronet MUST use DOOR.SYS)
Place Drop File		Start-up Directory

 ----------------------------------------------------------------------------

Smurf Combat
Copyright (C) 1993, 1994, 1995, 2019 Laurence Maar
laurencemaar@gmail.com
https://www.facebook.com/laurencemaar/
https://www.linkedin.com/in/laurencemaar/
https://github.com/laurencemaar/
https://sourceforge.net/u/laurencemaar/

 ----------------------------------------------------------------------------








 NOTE: If the above file just scrolled by your screen, type:

 C:\BBS\SMURF\>  type README.DOC | more

 to pause in between screen-fulls...










