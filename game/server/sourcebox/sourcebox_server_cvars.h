#include "cbase.h"
#include "convar.h"
#ifdef _WIN32
  #pragma once
#endif

ConVar sv_enspmod("sv_speedmodifier_enable", "0", FCVAR_NOTIFY, "Enable speed modifier? (sv_speedmodifier)", true, 0, true, 1);
ConVar sv_spmod("sv_speedmodifier", "950", FCVAR_NOTIFY, "Speed modifier value");
