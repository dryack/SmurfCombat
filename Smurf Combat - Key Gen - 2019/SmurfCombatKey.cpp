/*
Smurf Combat - Key Generator
Copyright (C) 2019 Laurence Maar

laurencemaar@gmail.com
https://www.facebook.com/laurencemaar/
https://www.linkedin.com/in/laurencemaar/

This program will generate a file named SMURFREG.NFO. Put this file in your install directory.

If necessary, this source code can be modified to change the value of "tempstring" in order to
change the display name.
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

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
	printf("\nSmurf Combat - Key Generator\n");
	printf("Copyright (C) 2019 Laurence Maar\n");
	printf("laurencemaar@gmail.com\n");
	printf("https://www.facebook.com/laurencemaar/\n");
	printf("https://www.linkedin.com/in/laurencemaar/\n\n");

	printf("This program will generate a file named SMURFREG.NFO. Put this file in your install directory.\n\n");

	int rcount=0;
	int security_code=909;
	int mylength;
	char tempstring[201];
	int cyc;

	sprintf(tempstring,"Freeware via Laurence Maar GPLv2 as of October 11, 2019");

	// Un-comment this code to allow to generating a custom registration name
	//printf("Registration Name : ");
	//gets(tempstring);

	mylength = strlen(tempstring);

	for(cyc=0;cyc<mylength;cyc++){
		rcount=rcount+tempstring[cyc]*security_code;
	}

	printf("Name = %s\n",tempstring);
	printf("Key  = %i\n\n",rcount);

	FILE *stream;

	stream=fopen("SMURFREG.NFO","w+");
	fprintf(stream,"%s",tempstring);
	fprintf(stream,"\n\r%i\n\r",rcount);
	fclose(stream);

	system("pause");

	return 0;
}
