#include "CoreMinimal.h"


namespace DSPProcessing
{
    namespace AudioUtils
    {
        constexpr float Eps = 1.e-8f;

        FORCEINLINE float MapFromNormalizedRange(float value, float minRange, float maxRange)
        {
            return minRange + value * (maxRange - minRange);
        }

        // Vectorized vars/functions
        struct alignas(16) AlignedFloat4 // Taken from UE5
        {
            float V[4];

            FORCEINLINE AlignedFloat4(const VectorRegister& Vec)
            {
                VectorStoreAligned(Vec, V);
            }

            FORCEINLINE float operator[](int32 Index) const { return V[Index]; }
            FORCEINLINE float& operator[](int32 Index) { return V[Index]; }

            FORCEINLINE VectorRegister ToVectorRegister() const
            {
                return VectorLoadAligned(V);
            }
        };

        const VectorRegister& VMinusOnes = GlobalVectorConstants::FloatMinusOne;
        const VectorRegister& VZeros     = GlobalVectorConstants::FloatZero;
        const VectorRegister& VOneHalf   = GlobalVectorConstants::FloatOneHalf;
        const VectorRegister& VOnes      = GlobalVectorConstants::FloatOne;
        const VectorRegister& VTwos      = GlobalVectorConstants::FloatTwo;
        const VectorRegister& VEps       = GlobalVectorConstants::SmallLengthThreshold;

        const VectorRegister VThrees = MakeVectorRegister(3.0f, 3.0f, 3.0f, 3.0f);

        FORCEINLINE VectorRegister VectorClampMinusOneToOne(const VectorRegister& Vec)
        {
            //Out = FMath::Clamp(Out, -1.0f, 1.0f);
            return VectorMax(VectorMin(Vec, VOnes), VMinusOnes);
        }

        FORCEINLINE void VectorMix(const VectorRegister& In, const VectorRegister& MixAmount, VectorRegister& Out)
        {
            //Out = Out * Mix + (1.0f - Mix) * In;
            const VectorRegister One_Minus_Mix      = VectorSubtract(VOnes, MixAmount);
            const VectorRegister One_Minus_Mix_x_In = VectorMultiply(One_Minus_Mix, In);
            Out = VectorMultiplyAdd(Out, MixAmount, One_Minus_Mix_x_In);
        }
    }
}