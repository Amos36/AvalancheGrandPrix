// Fill out your copyright notice in the Description page of Project Settings.


#include "CompetitionController.h"

// Sets default values for this component's properties
UCompetitionController::UCompetitionController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Function: Set Current Place In Race
// Description: Set the current Placement of the Player in the race. This is mainly
//	 to be used in special circumstances, such as starting the race itself.
// 
// Date Created: 07/02/22
// Last Updated: 07/03/22
// 
// Author(s): Jordan R. Douglas
void UCompetitionController::SetCurrentPlaceInRace(int Position)
{
	CurrentPlaceInRace = Position;
}

// Function: Get Current Place In Race
// Description: Checks to see the current placement in the race that the Player is
//	in and returns it for data use.
// 
// Date Created: 07/02/22
// Last Updated: 07/03/22
// 
// Author(s): Jordan R. Douglas
int UCompetitionController::GetCurrentPlaceInRace()
{
	return CurrentPlaceInRace;
}

// Function: Get Item Priority
// Description: Returns the Item Pool that the Character pulls from.
// 1 = 6th - 8th Place in the Race
// 2 = 2nd - 5th Place in the Race
// 3 = 1st Place in the Race
// 
// Date Created: 07/19/22
// Last Updated: 07/19/22
// 
// Author(s): Jordan R. Douglas
int UCompetitionController::GetItemPriority()
{
	if (CurrentPlaceInRace < 5)
	{
		// 1 = 6th - 8th Place in the Race
		return 1;
	}

	if (CurrentPlaceInRace < 1)
	{
		// 2 = 2nd - 5th Place in the Race
		return 2;
	}

	if (CurrentPlaceInRace == 1)
	{
		// 3 = 1st Place in the Race
		return 3;
	}

	else
	{
		//ERROR, we should not reach this point
		return 0;
	}
}

// Function: Check If Passing Is Valid
// Description: Perform a check to see if the current Player has passed the opposing 
//	Character. It will be called on both sides and should result in either the Player
//	having their current Position swap with the target or they stay neutral due to not
//	being in the minimal "passing distance" range.
// 
// Date Created: 07/02/22
// Last Updated: 07/05w/22
// 
// Author(s): Jordan R. Douglas
void UCompetitionController::CheckIfPassingIsValid(AActor* YourPosition, AActor* OpponentPosition)
{
	//We need to determine who is further ahead when this is called
	if (YourPosition->GetActorLocation().Y > OpponentPosition->GetActorLocation().Y && 
		YourPosition->FindComponentByClass<UCompetitionController>()->GetCurrentPlaceInRace() < OpponentPosition->FindComponentByClass<UCompetitionController>()->GetCurrentPlaceInRace())
	{
		int YourPlacement = YourPosition->FindComponentByClass<UCompetitionController>()->GetCurrentPlaceInRace();
		YourPosition->FindComponentByClass<UCompetitionController>()->SetCurrentPlaceInRace(OpponentPosition->FindComponentByClass<UCompetitionController>()->GetCurrentPlaceInRace());
		OpponentPosition->FindComponentByClass<UCompetitionController>()->SetCurrentPlaceInRace(YourPlacement);
	}
}

// Called when the game starts
void UCompetitionController::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UCompetitionController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

