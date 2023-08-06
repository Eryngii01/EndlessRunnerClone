// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "CPP_InputConfigData.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API UCPP_InputConfigData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UInputAction* InputMoveSideways;
};
