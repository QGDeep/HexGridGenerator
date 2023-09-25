/* 
	Manages the overall grids that are spawned and specifies the length and
	width of the grid spawned and the type of grid spawned.
 */

#include "HexGridManager.h"
#include "HexTile.h"

// Sets default values
AHexGridManager::AHexGridManager()
{
	
}

// Called when the game starts or when spawned
void AHexGridManager::BeginPlay()
{
	Super::BeginPlay();

	// set grid width and height
	HexGrid2D.SetNumZeroed(GridWidth);
	for (int32 i = 0; i < HexGrid2D.Num(); i++) {
		HexGrid2D[i].SetNumZeroed(GridHeight);
	}


	// Generate grid using for loops
	for (int32 y = 0; y < GridHeight; y++) {

		for (int32 x = 0; x < GridWidth; x++) {
			/*
			Check if tile will be spawned on an odd row
			If yes, offset the tile on its y and x axis 
			Otherwise, just offset it on its x axis
			*/
			const bool Oddrow = y % 2 == 1;
			const float xPos = Oddrow ? (x * TileHorizontalOffset) + OddrowHorizontalOffset : x * TileHorizontalOffset;
			const float yPos = y * TileVerticalOffset;

			// choose the tile to spawn and spawn it
			TSubclassOf<AHexTile> SpawnTile;
			AHexTile* NewTile;
			if (FMath::RandRange(0.f, 1.f) <= ChanceOfWater) {
				SpawnTile = WaterTile;
				NewTile = GetWorld()->SpawnActor<AHexTile>(SpawnTile, FVector(xPos, yPos, -15), FRotator::ZeroRotator);
			}
			else if (FMath::RandRange(0.f, 1.f) <= ChanceOfMountain) {
				SpawnTile = MountainTile;
				NewTile = GetWorld()->SpawnActor<AHexTile>(SpawnTile, FVector(xPos, yPos, 15), FRotator::ZeroRotator);
			}
			else if (FMath::RandRange(0.f, 1.f) <= ChanceOfDessert) {
				SpawnTile = DesertTile;
				NewTile = GetWorld()->SpawnActor<AHexTile>(SpawnTile, FVector(xPos, yPos, 0), FRotator::ZeroRotator);
			}
			else if (FMath::RandRange(0.f, 1.f) <= ChanceOfSnow) {
				SpawnTile = SnowTile;
				NewTile = GetWorld()->SpawnActor<AHexTile>(SpawnTile, FVector(xPos, yPos, 0), FRotator::ZeroRotator);
			}
			else {
				SpawnTile = GrassTile;
				NewTile = GetWorld()->SpawnActor<AHexTile>(SpawnTile, FVector(xPos, yPos, 0), FRotator::ZeroRotator);
			}

			//AHexTile* NewTile = GetWorld()->SpawnActor<AHexTile>(SpawnTile, FVector(xPos, yPos, 1), FRotator::ZeroRotator);
			
			// give the tile its index and add to 2D array
			NewTile->TileIndex = FIntPoint(x, y);
			NewTile->SetActorLabel(FString::Printf(TEXT("Tile_%d-%d"), x, y));
			HexGrid2D[x][y] = NewTile;
		}
	}
	
}