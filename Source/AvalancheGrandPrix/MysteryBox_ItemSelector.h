// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class AVALANCHEGRANDPRIX_API MysteryBox_ItemSelector
{
public:
	MysteryBox_ItemSelector();
	~MysteryBox_ItemSelector();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Value of Items")
		int TotalValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Value of Items")
		int Item1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Value of Items")
		int Item2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Value of Items")
		int Item3;
};
