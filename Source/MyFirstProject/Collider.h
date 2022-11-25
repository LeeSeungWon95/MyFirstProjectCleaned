// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Collider.generated.h"

UCLASS()
class MYFIRSTPROJECT_API ACollider : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnyWhere, Category = "Mesh")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnyWhere, Category = "Mesh")
	class USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnyWhere, Category = "Mesh")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnyWhere, Category = "Mesh")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnyWhere, Category = "Movement")
	class UColliderMovementComponent* OurMovementComponent;

	virtual UPawnMovementComponent* GetMovementComponent() const override;

	FORCEINLINE UStaticMeshComponent* GetMeshComponent() { return MeshComponent; }
	FORCEINLINE void SetMeshComponent(UStaticMeshComponent* Mesh) { MeshComponent = Mesh; }

	FORCEINLINE USphereComponent* GetSphereComponent() { return SphereComponent; }
	FORCEINLINE void SetSphereComponent(USphereComponent* Sphere) { SphereComponent = Sphere; }

	FORCEINLINE UCameraComponent* GetCameraComponent() { return Camera; }
	FORCEINLINE void SetCameraComponent(UCameraComponent* InCamera) { Camera = InCamera; }

	FORCEINLINE USpringArmComponent* GetSpringArmComponent() { return SpringArm; }
	FORCEINLINE void SetSpringArmComponent(USpringArmComponent* InSpringArm) { SpringArm = InSpringArm; }


private:
	void MoveForward(float Input);
	void MoveRight(float Input);

	void CameraYaw(float AxisValue);
	void CameraPitch(float AxisValue);

	FVector2D CameraInput;
};
