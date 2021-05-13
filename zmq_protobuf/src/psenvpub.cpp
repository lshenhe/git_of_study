//
//  Pubsub envelope publisher
//  Note that the zhelpers.h file also provides s_sendmore
//

#include "zhelpers.hpp"
#include "examples.pb.h"


int main () 
{
    //  Prepare our context and publisher
    zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind("tcp://*:5563");

    auto msg_str = std::make_shared<Chatter>();
    


    while (1) 
    {
        //  Write two messages, each with an envelope and content
        s_sendmore (publisher, "A");
        msg_str->set_message("We don't want to see this");
        std::string msgA;
        msg_str->SerializeToString(&msgA);
        s_send (publisher, msgA);

        s_sendmore (publisher, "B");
        msg_str->set_message("We would like to see this");
        std::string msgB;
        msg_str->SerializeToString(&msgB);
        s_send (publisher, msgB);

        std::cout << "send" << std::endl;
        sleep (1);
    }
    return 0;
}
