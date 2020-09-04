#ifndef EYE_LIB_EYERSEGMENTTEMPLATE_HPP
#define EYE_LIB_EYERSEGMENTTEMPLATE_HPP

#include "EyerCore/EyerCore.hpp"

namespace Eyer{
    class EyerSegmentTemplate {
    public:
        EyerSegmentTemplate();
        ~EyerSegmentTemplate();

        EyerSegmentTemplate(const EyerSegmentTemplate & segmentTemplate);

        EyerSegmentTemplate & operator = (const EyerSegmentTemplate & segmentTemplate);

        int LoadFromXML(void * node);

        EyerString & GetInitialization();
        int SetInitialization(char * str);
    private:
        EyerString initialization;
    };
}



#endif //EYE_LIB_EYERSEGMENTTEMPLATE_HPP
