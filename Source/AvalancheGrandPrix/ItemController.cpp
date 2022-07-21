// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemController.h"

// Sets default values for this component's properties
UItemController::UItemController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

void UItemController::DetermineItem(int WhichPool, int WhichItemFromPool)
{
	switch (WhichPool)
	{
		//BEST ITEM POOL
	case 0:
	{
		switch (WhichItemFromPool)
		{
		case 0:
		{
			HeldItem = Items[1]; //Blue Snowball
			nItemValue = 1;
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("items[1] is ") + FString(Items[1].Get()->GetDefaultObject()->GetFName().ToString()));
			break;
		}
		default:
			break;
		}
		break;
	}
	//GREAT ITEM POOL
	case 1:
	{
		switch (WhichItemFromPool)
		{
		case 0:
		{
			HeldItem = Items[2]; //Rocket Booster
			nItemValue = 2;
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("items[2] is ") + FString(Items[2].Get()->GetDefaultObject()->GetFName().ToString()));
			break;
		}
		default:
			break;
		}
		break;
	}
	//COMMON ITEM POOL
	case 2:
	{
		switch (WhichItemFromPool)
		{
		case 0:
		{
			HeldItem = Items[0]; //Green Snowball
			nItemValue = 0;
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, TEXT("items[0] is ") + FString(Items[0].Get()->GetDefaultObject()->GetFName().ToString()));
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}

// Function: Activate Held Item
// Description: Used to spawn the item and determine where and how it spawns.
// 
// Date Created: 06/07/22
// Last Updated: 06/18/22
// 
// Author(s): Jordan R. Douglas
void UItemController::ActivateHeldItem(FVector uSpawnPosition, AActor* aItem, bool bIsBeingHeld)
{
	if (HeldItem == nullptr || nItemValue == -1)
		return;

	if (bIsBeingHeld)
	{
		//If the Action Key is being held, then the item spawns behind the Player.
		//NOTE! Some items will have no need to spawn behind the Player.
		aItem->SetActorLocation(-uSpawnPosition + uAdjustSpawn);
	}
	else
	{
		aItem->SetActorLocation(uSpawnPosition + uAdjustSpawn);
	}

	if (nItemValue == 3)
	{
		aItem->SetActorLocation(-uSpawnPosition + uAdjustSpawn);
	}

	HeldItem = nullptr;
	uAdjustSpawn = FVector::ZeroVector;
	nItemValue = -1;
}

// Function: Show Held Item UI
// Description: Checks to see if it is interacting with a Controlled Player before
//	telling the system what graphic to use for the UI slot.
// 
// Date Created: 06/07/22
// Last Updated: 06/09/22
// 
// Author(s): Jordan R. Douglas
void UItemController::ShowHeldItemUI(AActor* aItem, bool bIsAPlayer)
{
	if (!bIsAPlayer)
		return;
}

// Function: Set Held Item
// Description: Helps store the item to the Player that interacts with a Mystery Box
//	so that it may be called later with ActivateHeldItem().
// 
// Date Created: 06/07/22
// Last Updated: 07/18/22
// 
// Author(s): Jordan R. Douglas
void UItemController::SetHeldItem(TSubclassOf<class AActor> aHeldItem, FVector ItemPositionAdjustment, int ItemID)
{
	HeldItem = aHeldItem;
	uAdjustSpawn = ItemPositionAdjustment;
	nItemValue = ItemID;
}

// Function: Get Held Item
// Description: Finds Held Item and returns the information on what Actor
//	(the Item in this case) it needs to return for reference.
// 
// Date Created: 06/18/22
// Last Updated: 06/18/22
// 
// Author(s): Jordan R. Douglas
TSubclassOf<class AActor> UItemController::GetHeldItem()
{
	return HeldItem;
}

// Function: Set Item Timer
// Description: Set the timer for the Item in use as to not have it activate
// forever. Used for items like the Rocket Booster and Mind Freeze.
// 
// Date Created: 07/17/22
// Last Updated: 07/17/22
// 
// Author(s): Jordan R. Douglas
void UItemController::SetItemTimer(float fItemTimer)
{
	fItemTimeLimit = fItemTimer;
}

// Function: Reduce Item Timer
// Description: Called whenever we have a valid Item Timer above 0. Each time
// this function is called, it reduces the timer by either deltaTime or a custom
// reducer that is greater than 0. This function will return false if the Timer
// has not reached 0 or less, and true if it has reached 0 or less seconds.
// 
// Date Created: 07/17/22
// Last Updated: 07/17/22
// 
// Author(s): Jordan R. Douglas
bool UItemController::ReduceItemTimer(float deltaTime)
{
	//Did the timer finish?
	if (fItemTimeLimit <= 0.0f)
		return true;

	//If it did not, let us reduce the current Timer and return false
	fItemTimeLimit = fItemTimeLimit - deltaTime;
	return false;
}

// Called when the game starts
void UItemController::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UItemController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

