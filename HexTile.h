/* 
	Hex tile header file.
*/
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.generated.h"

// forward dec static mesh class
class UStaicMeshComponent;

// enumeration for tile types
UENUM()
enum class EHexTileType : uint8
{
	INVALID, // when no values are selected
	GRASS,
	WATER,
	MOUNTAIN,
	DESERT,
	SNOW,
	MAX UMETA(Hidden) // don't show in editor
};

UCLASS()
class HEXGRIDGENERATOR_API AHexTile : public AActor
{
	GENERATED_BODY()
	

public:
	// stores the tile index value in a grid
	UPROPERTY(VisibleInstanceOnly, Category = "Tile")
	FIntPoint TileIndex;

protected:
	// define hex tile type enum 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
	EHexTileType TileType;

	// define tile mesh component (used for every tile type once)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
	UStaticMeshComponent* TileMesh;

public:	
	// Sets default values for this actor's properties
	AHexTile();
};
