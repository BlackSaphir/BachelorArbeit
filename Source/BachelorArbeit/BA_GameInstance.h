// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "BA_GameInstance.generated.h"

/**
 *
 */
UCLASS()
class BACHELORARBEIT_API UBA_GameInstance : public UGameInstance
{
	GENERATED_BODY()

		UBA_GameInstance(const FObjectInitializer& ObjectInitializer);


	// Functions
	virtual void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnStartOnlineGameComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionComplete(bool bWasSuccessful);

	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
	void StartSession();

	bool HostSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLan, bool bIsPresence, int32 MaxNumPlayers);
	void FindSession(TSharedPtr<const FUniqueNetId> UserId, bool bIsLan, bool bIsPresence);



	// Variables
	TSharedPtr<class FOnlineSessionSettings> SessionSettings;
	TSharedPtr<class FOnlineSessionSearch> SessionSearch;

	// Delegates
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
	FOnFindSessionsCompleteDelegate OnFindSessionCompleteDelegate;
	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;
	FOnFindSessionsCompleteDelegate OnFindSessionCompleteDelegate;


	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FDelegateHandle	OnStartSessionCompleteDelegateHandle;
	FDelegateHandle OnFindSessionCompleteDelegateHandle;
	FDelegateHandle OnJoinSessionCompleteDelegateHandle;
	FDelegateHandle OnDestroySessionCompeteDelegateHandle;
	FDelegateHandle OnFindSessionCompleteDelegateHandle;

};
