// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Inv_PlayerController.generated.h"

class UInputAction;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class PROINVENTORY_API AInv_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UFUNCTION()
	void PrimaryInteract();
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TArray<UInputMappingContext*> DefaultIMCs;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<UInputAction> PrimaryInteraction;
	
};
