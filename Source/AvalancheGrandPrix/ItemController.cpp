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


// Function: Activate Held Item
// Description: Used to spawn the item and determine where and how it spawns.
// 
// Date Created: 06/07/22
// Last Updated: 06/18/22
// 
// Author(s): Jordan R. Douglas
void UItemController::ActivateHeldItem(FVector uSpawnPosition, AActor* aItem, bool bIsBeingHeld)
{
	if (HeldItem == nullptr)
		return;

	if (bIsBeingHeld)
	{
		//If the Action Key is being held, then the item spawns behind the Player.
		//NOTE! Some items will have no need to spawn behind the Player.
		aItem->SetActorLocation(-uSpawnPosition);
	}
	else
	{
		aItem->SetActorLocation(uSpawnPosition);
	}
	HeldItem = nullptr;
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
// Last Updated: 06/18/22
// 
// Author(s): Jordan R. Douglas
void UItemController::SetHeldItem(TSubclassOf<class AActor> aHeldItem)
{
	HeldItem = aHeldItem;
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

