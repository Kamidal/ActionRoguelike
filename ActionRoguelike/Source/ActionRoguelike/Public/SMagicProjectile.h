// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SMagicProjectile.generated.h"
class USphereComponent;
class UProjectilemovementComponent;
class UParticalSystemComponent;

UCLASS()
class ACTIONROGUELIKE_API ASMagicProjectile : public AActor//继承actor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASMagicProjectile();

protected:
	UPROPERTY(VisibleAnywhere)
		USphereComponent* SphereComp;//球体组件

	UPROPERTY(VisibleAnywhere)
		UProjectilemovementComponent* movementComp;//投射物运动组件，给出速度，直线运动
	
	UPROPERTY(VisibleAnywhere)
		UParticalSystemComponent* EffectComp;//粒子系统组件
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
