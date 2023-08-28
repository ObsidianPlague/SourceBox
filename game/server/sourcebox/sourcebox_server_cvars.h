#include "cbase.h"
#include "convar.h"
#ifdef _WIN32
  #pragma once
#endif

ConVar quakemode("sv_quake", "0", FCVAR_NOTIFY, "Enable Quake(tm) mode?", true, 0, true, 1);
