//=============================================================================//
//
// Purpose: Restored beta weapons
//
// $NoKeywords: $
//=============================================================================//
#ifndef BETA_WEAPONS
#define BETA_WEAPONS

#ifdef _WIN32
#pragma once
#endif

#include "weapon_hl2mpbasehlmpcombatweapon.h"

//=============================================================================//
// Purpose: Restored flare gun
//=============================================================================//
#ifdef CLIENT_DLL
#define CWeaponFlare C_WeaponFlare
#endif

#define FLARE_PROJECTILE_MODEL "props_junk/flare.mdl"
class CWeaponFlare : public CBaseHL2MPCombatWeapon
{
	DECLARE_CLASS( CWeaponFlare, CBaseHL2MPCombatWeapon );
public:

	CWeaponFlare();
	~CWeaponFlare();

	DECLARE_NETWORKCLASS(); 
	DECLARE_PREDICTABLE();

	void	Precache( void );

	void	PrimaryAttack( void );
	virtual float GetFireRate( void ) { return 2.5; };

	void	DecrementAmmo( CBaseCombatCharacter *pOwner );

	bool	Deploy( void );
	bool	Holster( CBaseCombatWeapon *pSwitchingTo = NULL );
	bool	Reload( void );
	bool	WeaponShouldBeLowered( void );
	bool	Lower( void );

	bool	CanHolster( void );

	int		GetMinBurst() { return 1; }
	int		GetMaxBurst() { return 1; }
	float	GetMinRestTime() { return 4.0; }
	float	GetMaxRestTime() { return 4.0; }

	bool	HasAnyAmmo( void );
	
#ifdef CLIENT_DLL

	// We need to render opaque and translucent pieces
	virtual RenderGroup_t	GetRenderGroup( void ) {	return RENDER_GROUP_TWOPASS;	}

	virtual void	NotifyShouldTransmit( ShouldTransmitState_t state );
	virtual int		DrawModel( int flags );
	virtual void	ViewModelDrawn( C_BaseViewModel *pBaseViewModel );
	virtual bool	IsTranslucent( void );

	void			InitBeam( void );
	void			GetWeaponAttachment( int attachmentId, Vector &outVector, Vector *dir = NULL );
	void			DrawEffects( void );
//	void			DrawLaserDot( void );

	CMaterialReference	m_hSpriteMaterial;	// Used for the laser glint
	CMaterialReference	m_hBeamMaterial;	// Used for the laser beam
	Beam_t				*m_pBeam;			// Laser beam temp entity

#endif	//CLIENT_DLL

#ifndef CLIENT_DLL
	DECLARE_ACTTABLE();
#endif

private:
	
	CWeaponFlare( const CWeaponFlare & );
};

#endif //BETA_WEAPONS
