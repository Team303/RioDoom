// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// DESCRIPTION:
//	Refresh (R_*) module, global header.
//	All the rendering/drawing stuff is here.
//
//-----------------------------------------------------------------------------

#ifndef __R_LOCAL__
#define __R_LOCAL__

// Binary Angles, sine/cosine/atan lookups.
#include "headless_doom/tables.h"

// Screen size related parameters.
#include "headless_doom/doomdef.h"

// Include the refresh/render data structs.
#include "headless_doom/r_data.h"



//
// Separate header file for each module.
//
#include "headless_doom/r_main.h"
#include "headless_doom/r_bsp.h"
#include "headless_doom/r_segs.h"
#include "headless_doom/r_plane.h"
#include "headless_doom/r_data.h"
#include "headless_doom/r_things.h"
#include "headless_doom/r_draw.h"

#endif		// __R_LOCAL__
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
