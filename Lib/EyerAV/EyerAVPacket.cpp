#include "EyerAVAV.hpp"

extern "C"{
#include <libavformat/avformat.h>
}

#include "EyerAVPacketPrivate.hpp"

namespace Eyer
{
    EyerAVPacket::EyerAVPacket()
    {
        piml = new EyerAVPacketPrivate();

        piml->packet = av_packet_alloc();
        av_init_packet(piml->packet);
    }

    EyerAVPacket::~EyerAVPacket()
    {
        if (piml->packet != nullptr) {
            av_packet_free(&piml->packet);
            piml->packet = nullptr;
        }

        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }

    EyerAVPacket::EyerAVPacket(const EyerAVPacket & avpacket)
    {
        *this = avpacket;
    }

    EyerAVPacket & EyerAVPacket::operator = (const EyerAVPacket & avpacket)
    {
        piml->isLastPacket = avpacket.piml->isLastPacket;
        piml->ptsSec = avpacket.piml->ptsSec;

        if (piml->packet != nullptr) {
            av_packet_free(&piml->packet);
            piml->packet = nullptr;
        }

        piml->packet = av_packet_clone(avpacket.piml->packet);

        return *this;
    }

    int EyerAVPacket::RescaleTs( Eyer::EyerAVRational & _codecTimebase, Eyer::EyerAVRational & _streamTimebase)
    {
        AVRational codecTimebase;
        codecTimebase.num = _codecTimebase.num;
        codecTimebase.den = _codecTimebase.den;

        AVRational streamTimebase;
        streamTimebase.num = _streamTimebase.num;
        streamTimebase.den = _streamTimebase.den;

        av_packet_rescale_ts(piml->packet, codecTimebase, streamTimebase);
        return 0;
    }

    int EyerAVPacket::GetStreamId()
    {
        return piml->packet->stream_index;
    }

    uint64_t EyerAVPacket::GetPTS()
    {
        return piml->packet->pts;
    }

    double EyerAVPacket::GetSecPTS()
    {
        return piml->ptsSec;
    }

    uint64_t EyerAVPacket::GetDTS()
    {
        return piml->packet->dts;
    }

    int EyerAVPacket::SetPTS(uint64_t pts)
    {
        piml->packet->pts = pts;
        return 0;
    }
    
    int EyerAVPacket::SetDTS(uint64_t dts)
    {
        piml->packet->dts = dts;
        return 0;
    }

    int EyerAVPacket::SetStreamId(int id)
    {
        piml->packet->stream_index = id;
        return 0;
    }

    int EyerAVPacket::IsLast()
    {
        return piml->isLastPacket;
    }

    int EyerAVPacket::SetLast()
    {
        piml->isLastPacket = 1;
        return 0;
    }

    int EyerAVPacket::GetSize()
    {
        return piml->packet->size;
    }

    unsigned char * EyerAVPacket::GetDataPtr()
    {
        return piml->packet->data;
    }

    int EyerAVPacket::SetDataPtr(uint8_t * data)
    {
        piml->packet->data = data;
        return 0;
    }
}