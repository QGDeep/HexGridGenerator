/* 
	Grid Manager header file.
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexGridManager.generated.h"

class AHexTile;
UCLASS()
class HEXGRIDGENERATOR_API AHexGridManager : public AActor
{
	GENERATED_BODY()

protected:
	// create a 2d array with a pointer to the tiles
	// using the hex tile class
	TArray<TArray<AHexTile*>> HexGrid2D;

	// An array of meshes used for randomly spawning tiles
	//TArray<AHexTile> MeshArray;
	//TArray <float> ChanceArray;

	// total width of the grid
	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 GridWidth;

	// total height of the grid
	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 GridHeight;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float TileHorizontalOffset;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float TileVerticalOffset;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float OddrowHorizontalOffset;

	// types of tiles to spawn
	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> GrassTile;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> WaterTile;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> MountainTile;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> DesertTile;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> SnowTile;

	// chances of spawning tile other than grass (default)
	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	float ChanceOfWater;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	float ChanceOfMountain;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	float ChanceOfDessert;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	float ChanceOfSnow;
	
public:	
	// Sets default values for this actor's properties
	AHexGridManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
