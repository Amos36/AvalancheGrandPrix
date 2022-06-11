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
// Last Updated: 06/09/22
// 
// Author(s): Jordan R. Douglas
void UItemController::ActivateHeldItem(FVector uPlayer, AActor* aItem, bool bIsBeingHeld)
{
	//uMesh->SetRelativeTransform(uPlayerMesh->GetRelativeTransform());
	aItem->SetActorLocation(uPlayer);
	
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

// Function: Store Held Item
// Description: Helps store the item to the Player that interacts with a Mystery Box
//	so that it may be called later with ActivateHeldItem().
// 
// Date Created: 06/07/22
// Last Updated: 06/09/22
// 
// Author(s): Jordan R. Douglas
void UItemController::StoreHeldItem(AActor* aItem)
{

}


// Called when the game starts
void UItemController::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UItemController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

