/*
**
** Project:  Wildland Fire Investment Planning System
** Purpose:  Data management application.
** Author:   Kyle Shannon <kyle at pobox dot com>
**
** THIS SOFTWARE WAS DEVELOPED AT THE ROCKY MOUNTAIN RESEARCH STATION (RMRS)
** MISSOULA FIRE SCIENCES LABORATORY BY EMPLOYEES OF THE FEDERAL GOVERNMENT 
** IN THE COURSE OF THEIR OFFICIAL DUTIES. PURSUANT TO TITLE 17 SECTION 105 
** OF THE UNITED STATES CODE, THIS SOFTWARE IS NOT SUBJECT TO COPYRIGHT 
** PROTECTION AND IS IN THE PUBLIC DOMAIN. RMRS MISSOULA FIRE SCIENCES 
** LABORATORY ASSUMES NO RESPONSIBILITY WHATSOEVER FOR ITS USE BY OTHER 
** PARTIES,  AND MAKES NO GUARANTEES, EXPRESSED OR IMPLIED, ABOUT ITS QUALITY, 
** RELIABILITY, OR ANY OTHER CHARACTERISTIC.
**
** This is free and unencumbered software released into the public domain.
**
** Anyone is free to copy, modify, publish, use, compile, sell, or
** distribute this software, either in source code form or as a compiled
** binary, for any purpose, commercial or non-commercial, and by any
** means.
**
** In jurisdictions that recognize copyright laws, the author or authors
** of this software dedicate any and all copyright interest in the
** software to the public domain. We make this dedication for the benefit
** of the public at large and to the detriment of our heirs and
** successors. We intend this dedication to be an overt act of
** relinquishment in perpetuity of all present and future rights to this
** software under copyright law.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
** OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
** OTHER DEALINGS IN THE SOFTWARE.
**
** For more information, please refer to <http://unlicense.org>
**
*/

#include <stdio.h>
#include <stdlib.h>

#include "sqlite3.h"

#define EQUAL(a,b) strcmp(a,b)==0

#define SQLITE_CREATE_RW SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE

void Usage()
{
    printf( "wfips [--help] [--fig-path path] data_path\n");
}

static int
LoadDispatchLocations( sqlite3 *db )
{
    return SQLITE_OK;
}

static int
LoadDispatchLogic( sqlite3 *db )
{
    return SQLITE_OK;
}

static int
LoadFig( sqlite3 *db )
{
    return SQLITE_OK;
}

static int
LoadFwas( sqlite3 *db )
{
    return SQLITE_OK;
}

static int
LoadDispatchLocations( sqlite3 *db )
{
    return SQLITE_OK;
}

int main( int argc, char *argv[] )
{
    int i;
    const char *pszDb;
    sqlite3 *db;
    int rc;
    i = 1;
    while( i < argc )
    {
        if(EQUAL( argv[i], "--help" ) )
        {
            Usage();
        }
    }

    rc = sqlite3_open_v2( "fig.db", &db, SQLITE_CREATE_RW, NULL );
    rc = LoadFig( db );

    return rc;
}

