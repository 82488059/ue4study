// Copyright Epic Games, Inc. All Rights Reserved.


#include "QuickStartGameModeBase.h"

#include "Blueprint/UserWidget.h"

#include "Logging/LogVerbosity.h"
//[Header]
//
//DECLARE_LOG_CATEGORY_EXTERN£¨NewLogCategoryNameGlobal,Warning,All£©;
//[CPP]
//
//DEFINE_LOG_CATEGORY£¨NewLogCategoryNameGlobal£©;

//DEFINE_LOG_CATEGORY_STATIC(LogTemp1, Warning, All)


void AQuickStartGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    ChangeMenuWidget(StartingWidgetClass);
}

void AQuickStartGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (NewWidgetClass != nullptr)
    {
        FString name = NewWidgetClass->GetName();
        UE_LOG(LogTemp, Warning,  TEXT("%s"), *name);
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, name);
        }

        if ("MainMenu_C" == name)
        {
            if (LevelWidget != nullptr)
            {
                LevelWidget->RemoveFromViewport();
                LevelWidget = nullptr;
            }
            if (NewGameWidget != nullptr)
            {
                NewGameWidget->RemoveFromViewport();
                NewGameWidget = nullptr;
            }
            if (MainMenuWidget != nullptr)
            {
                MainMenuWidget->RemoveFromViewport();
                MainMenuWidget = nullptr;
            }
            MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
            if (MainMenuWidget != nullptr)
            {
                MainMenuWidget->AddToViewport();
            }
        }
        else
        {
            if (MainMenuWidget != nullptr)
            {
                MainMenuWidget->RemoveFromViewport();
                MainMenuWidget = nullptr;
            }
            if ("NewGameMenu_C" == name)
            {
                if (NewGameWidget != nullptr)
                {
                    NewGameWidget->RemoveFromViewport();
                    NewGameWidget = nullptr;
                }
                if (LevelWidget != nullptr)
                {
                    LevelWidget->RemoveFromViewport();
                    LevelWidget = nullptr;
                }
                LevelWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
                if (LevelWidget != nullptr)
                {
                    LevelWidget->AddToViewport();
                }
                NewGameWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
                if (NewGameWidget != nullptr)
                {
                    NewGameWidget->AddToViewport();
                }
            }
        }
    }
    else
    {
        if (LevelWidget != nullptr)
        {
            LevelWidget->RemoveFromViewport();
            LevelWidget = nullptr;
        }
        if (NewGameWidget != nullptr)
        {
            NewGameWidget->RemoveFromViewport();
            NewGameWidget = nullptr;
        }
        if (MainMenuWidget != nullptr)
        {
            MainMenuWidget->RemoveFromViewport();
            MainMenuWidget = nullptr;
        }
    }

}