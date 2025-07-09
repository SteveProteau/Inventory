#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Inv_ItemFragment.generated.h"

USTRUCT(BlueprintType)
struct FInv_ItemFragment
{
	GENERATED_BODY()

	// Rule of 5 - If defining a virtual destructor these defaults are not created automatically.
	// Ensures class behaves correctly in scenarios involving copying, moving, and destruction

	// 0. Default constructor (not part of rule of 5)
	FInv_ItemFragment() {}

	// 1. Copy constructor
	FInv_ItemFragment(const FInv_ItemFragment&) = default;

	// 2. Copy assignment operator
	FInv_ItemFragment& operator=(const FInv_ItemFragment&) = default;

	// 3. Move constructor
	FInv_ItemFragment(FInv_ItemFragment&&) = default;

	// 4. Move assignment operator
	FInv_ItemFragment& operator=(FInv_ItemFragment&&) = default;

	// 5. Destructor
	virtual ~FInv_ItemFragment() {}

	// Fragment ID (I made tags const references)
	const FGameplayTag& GetFragmentTag() const { return FragmentTag; }
	void SetFragmentTag(const FGameplayTag& Tag) { FragmentTag = Tag; }

private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FGameplayTag FragmentTag = FGameplayTag::EmptyTag;
};

USTRUCT(BlueprintType)
struct FInv_GridFragment : public FInv_ItemFragment
{
	GENERATED_BODY()

	FIntPoint GetGridSize() const { return GridSize; }
	void SetGridSize(const FIntPoint& Size) { GridSize = Size; }
	float GetGridPadding() const { return GridPadding; }
	void SetGridPadding(float Padding) { GridPadding = Padding; }

private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FIntPoint GridSize{1, 1};

	// Icon padding in grid
	UPROPERTY(EditAnywhere, Category = "Inventory")
	float GridPadding{0.f};
};

USTRUCT(BlueprintType)
struct FInv_ImageFragment : public FInv_ItemFragment
{
	GENERATED_BODY()

	UTexture2D* GetIcon() const { return Icon; }

private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TObjectPtr<UTexture2D> Icon{nullptr};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	FVector2D IconDimensions{44.f, 44.f};
};

USTRUCT(BlueprintType)
struct FInv_StackableFragment : public FInv_ItemFragment
{
	GENERATED_BODY()

	int32 GetMaxStackSize() const { return MaxStackSize; }
	int32 GetStackCount() const { return StackCount; }

private:

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 MaxStackSize{1};

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 StackCount{1};
};
