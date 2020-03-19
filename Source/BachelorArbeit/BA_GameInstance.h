// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Online.h"
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
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	virtual void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);


	bool HostSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLan, bool bIsPresence, int32 MaxNumPlayers);
	void FindSession(TSharedPtr<const FUniqueNetId> UserId, bool bIsLan, bool bIsPresence);
	bool JoiningSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, const FOnlineSessionSearchResult SearchResult);

	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
		void StartOnlineSession();

	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
		void FindOnlineSession();

	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
		void JoinOnlineSession();

	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
		void DestroyOnlineSession();

	// Variables

public:

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Multiplayer")
		bool CanJoinSession;

private:


	TSharedPtr<class FOnlineSessionSettings> SessionSettings;
	TSharedPtr<class FOnlineSessionSearch> SessionSearch;

	// Delegates
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;

	FOnFindSessionsComplete OnFindSessionsComplete;
	

	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FDelegateHandle	OnStartSessionCompleteDelegateHandle;
	FDelegateHandle OnSearchSessionsCompleteDelegateHandle;
	FDelegateHandle OnFindSessionsCompleteDelegateHandle;
	FDelegateHandle OnJoinSessionCompleteDelegateHandle;
	FDelegateHandle OnDestroySessionCompeteDelegateHandle;

};
