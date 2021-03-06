#ifndef EYERLIB_EYERBITSTREAM_HPP
#define EYERLIB_EYERBITSTREAM_HPP

#include <stdint.h>
#include <stdio.h>
#include "EyerCore/EyerCore.hpp"
#include "MB_PART_PRED_MODE.hpp"

namespace Eyer
{
    class EyerBitStream {
    public:
        EyerBitStream(EyerBuffer & buffer);
        EyerBitStream(uint8_t * buf, size_t size);
        ~EyerBitStream();

        uint32_t bs_read_u8();
        uint32_t bs_read_u(int n);
        uint32_t bs_peek_u(int n);
        uint32_t bs_read_u1();

        void bs_skip_u(int n);
        void bs_skip_u1();

        uint32_t bs_read_ue();
        int32_t bs_read_se();

        int32_t bs_read_me(int ChromaArrayType, MB_PART_PRED_MODE predMode);

        uint32_t bs_read_ae();

        int bs_eof();

        bool bs_byte_aligned();

        bool more_data();

    public:
        uint8_t * start;
        uint8_t * p;
        uint8_t * end;
        int bits_left;
    };
}

#endif //EYERLIB_EYERBITSTREAM_HPP
