/* 
	Generates Hex tile
*/


#include "HexTile.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AHexTile::AHexTile()
{
	// init root comp and tile mesh 
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tile Mesh"));
	TileMesh->SetupAttachment(RootComponent);
}