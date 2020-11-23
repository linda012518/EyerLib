#include "SIPProcessMessage.hpp"

namespace Eyer
{
    int SIPProcessMessage::Process(struct eXosip_t * excontext, eXosip_event_t * je)
    {
        osip_body_t * dest = NULL;
        osip_message_get_body(je->request, 0, &dest);
        if(dest != NULL){
            printf("wwwwwwww::::%s\n", dest->body);
        }

        osip_message_t * answer = NULL;
        eXosip_message_build_answer (excontext, je->tid, 200, &answer);
        eXosip_message_send_answer (excontext, je->tid, 200, answer);

        // eXosip_call_build_request()
        printf("xxxxx:%s\n", je->textinfo);

        osip_message_t * request = NULL;
        eXosip_message_build_request(excontext, &request,"MESSAGE", "sip:34020000001320000001@192.168.2.101:5060", "sip:ServerA@Server", NULL);

        eXosip_message_send_request(excontext, request);

        if(request != NULL){
            char * str = NULL;
            size_t strlen = 0;
            osip_message_to_str(request, &str, &strlen);
            printf("%s\n", str);
        }

        return 0;
    }
}