// Copyright Epic Games, Inc. All Rights Reserved.


#include "FPSProjectGameModeBase.h"
#include "Blueprint/UserWidget.h"

//void AFPSProjectGameModeBase::StartPlay()
//{
//    Super::StartPlay();
//
//    check(GEngine != nullptr);
//
//    // 显示调试消息五秒。 
//    // 参数中的-1"键"值类型参数能防止该消息被更新或刷新。
//    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));
//
//}

void AFPSProjectGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    ChangeMenuWidget(StartingWidgetClass);
}

void AFPSProjectGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (CurrentWidget != nullptr)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (NewWidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}