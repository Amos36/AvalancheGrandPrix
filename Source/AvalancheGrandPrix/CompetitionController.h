// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CompetitionController.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class AVALANCHEGRANDPRIX_API UCompetitionController : public UActorComponent
{
	GENERATED_BODY()

private:
	int CurrentPlaceInRace; //What Place the Player is currently in from 1 - 8;

	UFUNCTION(BlueprintCallable, Category = "Competition Handlers")
		void SetCurrentPlaceInRace(int Position);

	UFUNCTION(BlueprintCallable, Category = "Competition Handlers")
		int GetCurrentPlaceInRace();

	UFUNCTION(BlueprintCallable, Category = "Competition Handlers")
		void CheckIfPassingIsValid(AActor* YourPosition, AActor* OpponentPosition);

public:
	// Sets default values for this component's properties
	UCompetitionController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
