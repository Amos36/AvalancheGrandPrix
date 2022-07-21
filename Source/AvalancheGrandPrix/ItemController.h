// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemController.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class AVALANCHEGRANDPRIX_API UItemController : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UItemController();
	/*struct CharacterItem
	{
		char cItemName; //Name of the Item
		int nItemID;	//ID of the Item
		int nPlayerID;	//Which Player has it (useful for determining if a UI will interact with script)
	};*/

private:
	UFUNCTION(BlueprintCallable, Category = "Item Handling")
		void DetermineItem(int WhichPool, int WhichItemFromPool);

	UFUNCTION(BlueprintCallable, Category = "Item Handling")
		void ActivateHeldItem(FVector uSpawnPosition, AActor* aItem, bool bIsBeingHeld);

	UFUNCTION(BlueprintCallable, Category = "Item Handling")
		void ShowHeldItemUI(AActor* aItem, bool bIsAPlayer);

	UFUNCTION(BlueprintCallable, Category = "Item Handling")
		void SetHeldItem(TSubclassOf<AActor> aHeldItem, FVector ItemPositionAdjustment, int ItemID);

	UFUNCTION(BlueprintCallable, Category = "Item Handling")
		TSubclassOf<class AActor> GetHeldItem();

	UFUNCTION(BlueprintCallable, Category = "Item Handling")
		void SetItemTimer(float fItemTimer);

	UFUNCTION(BlueprintCallable, Category = "Item Handling")
		bool ReduceItemTimer(float deltaTime);

	FVector uAdjustSpawn;

	float fItemTimeLimit;
	int nItemValue = -1;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FVector ItemSpawnFront;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		TSubclassOf<AActor> HeldItem;

	//UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	// ConstructorHelpers::FObjectFinder<TSubclassOf<AActor>> TestActo(TSubclassOf<AActor>("Blueprint'/ Game / VehicleBP / Blueprints / Mystery_Box_BPs / Green_Snowball.Green_Snowball'"));

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<TSubclassOf<AActor>> Items;
};
