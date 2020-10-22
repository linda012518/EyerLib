#ifndef EYERLIB_EYERMP4_HPP
#define EYERLIB_EYERMP4_HPP

#include "EyerMP4Box.hpp"
#include "EyerMP4Box_ftyp.hpp"
#include "EyerMP4Box_moov.hpp"
#include "EyerMP4Box_mvhd.hpp"
#include "EyerMP4Box_trak.hpp"
#include "EyerMP4Box_tkhd.hpp"
#include "EyerMP4Box_edts.hpp"
#include "EyerMP4Box_mdia.hpp"
#include "EyerMP4Box_mdhd.hpp"
#include "EyerMP4Box_hdlr.hpp"
#include "EyerMP4Box_minf.hpp"
#include "EyerMP4Box_stbl.hpp"
#include "EyerMP4Box_mvex.hpp"
#include "EyerMP4Box_trex.hpp"
#include "EyerMP4Box_mehd.hpp"

namespace Eyer{
    class EyerMP4 {
    public:
        EyerMP4();
        ~EyerMP4();
    };
}


#endif //EYERLIB_EYERMP4_HPP
