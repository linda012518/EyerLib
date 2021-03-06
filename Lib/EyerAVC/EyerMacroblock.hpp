#ifndef EYERLIB_EYERMACROBLOCK_HPP
#define EYERLIB_EYERMACROBLOCK_HPP

#include "EyerBitStream.hpp"
#include "EyerSPS.hpp"
#include "EyerPPS.hpp"
#include "EyerSLICEHeader.hpp"
#include "MB_TYPE.hpp"
#include "EyerCoeff4x4Block.hpp"

namespace Eyer
{
    class EyerMacroblock {
    public:
        EyerMacroblock(int _mbIndex);
        ~EyerMacroblock();

        int Parse(EyerBitStream & bs, EyerSPS & _sps, EyerPPS & _pps, EyerSLICEHeader & _sliceHeader);

    private:
        int MbPred       (EyerBitStream & bs);
        int Residual     (EyerBitStream & bs, int startIdx, int endIdx);

        int ResidualLuma (EyerBitStream & bs, int startIdx, int endIdx);

        int ResidualBlockCavlc(EyerBitStream & bs, int blockX, int blockY, int startIdx, int endIdx);

        int GetNumberCurrent(int x, int y);
        int GetNeighborAvailable(bool & available_top, bool & available_left, int & topIndex, int & leftIndex, int blockIndexX, int blockIndexY);

        int GetTopNeighborCoeffNum(int topIdx, int blockX, int blockY);
        int GetLeftNeighborCoeffNum(int leftIdx, int blockX, int blockY);

        int get_coeff_level(EyerBitStream & bs, int &level, int levelIdx, int trailingOnes, int suffixLength);

        int get_total_zeros(EyerBitStream & bs, int & totalZeros, int totalZeros_vlcIdx);

        int get_run_before(EyerBitStream & bs, int & runBefore, int runBefore_vlcIdx);
    private:
        EyerSPS sps;
        EyerPPS pps;
        EyerSLICEHeader sliceHeader;

        int mbIndex = 0;

        uint8_t transform_size_8x8_flag = 0;

        MB_TYPE mbType = MB_TYPE::I_NxN;
        uint32_t CodedBlockPatternLuma = 0;
        uint32_t CodedBlockPatternChroma = 0;

        uint32_t intra_chroma_pred_mode = 0;

        EyerCoeff4x4Block lumaResidual[4][4];
    };
}


#endif //EYERLIB_EYERMACROBLOCK_HPP
